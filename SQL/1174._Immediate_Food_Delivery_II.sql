WITH first_order_table AS (
  SELECT *
  FROM Delivery
  WHERE (customer_id, order_date) IN (
    SELECT customer_id, MIN(order_date) AS first_order
    FROM Delivery
    GROUP BY customer_id
  )
),
immediate_count (immediate) AS (
  SELECT COUNT(delivery_id)
  FROM first_order_table
  WHERE order_date = customer_pref_delivery_date
),
scheduled_count (scheduled) AS (
  SELECT COUNT(delivery_id)
  FROM first_order_table
  WHERE order_date <> customer_pref_delivery_date
)

SELECT ROUND(immediate / COUNT(delivery_id) * 100, 2) AS immediate_percentage
FROM immediate_count, first_order_table;


SELECT
    ROUND(SUM(IF(order_date = customer_pref_delivery_date, 1, 0)) / COUNT(DISTINCT customer_id) * 100, 2) AS immediate_percentage
FROM Delivery
WHERE (customer_id, order_date) IN (
    SELECT customer_id, MIN(order_date) AS first_order
    FROM Delivery
    GROUP BY customer_id
);