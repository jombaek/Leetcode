SELECT product_id, year AS first_year, quantity, price
FROM Sales
INNER JOIN Product USING (product_id)
WHERE (product_id, year) IN (
  SELECT product_id, MIN(year)
  FROM Sales
  GROUP BY product_id
);