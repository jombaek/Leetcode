SELECT customer_number
FROM (
  SELECT customer_number, COUNT(order_number) AS count_of_order
  FROM Orders
  GROUP BY customer_number
  ORDER BY count_of_order DESC
) AS t
LIMIT 1;