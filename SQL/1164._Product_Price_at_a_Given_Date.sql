WITH
  b AS (
    SELECT DISTINCT product_id
    FROM Products
  ),
  t AS (
    SELECT *,
    ROW_NUMBER() OVER(PARTITION BY product_id ORDER BY change_date DESC) AS row
    FROM Products
    WHERE change_date <= '2019-08-16'
  )

SELECT b.product_id, ISNULL(new_price, 10) AS price
FROM b
LEFT JOIN t ON b.product_id = t.product_id AND t.row = 1;