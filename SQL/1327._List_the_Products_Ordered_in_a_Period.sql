SELECT product_name, SUM(unit) AS unit
FROM Products
INNER JOIN Orders USING (product_id)
WHERE DATE_FORMAT(order_date, '%Y-%m') = '2020-02'
GROUP BY product_name
HAVING SUM(unit) >= 100;