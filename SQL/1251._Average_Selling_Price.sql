SELECT p.product_id,
  ROUND(SUM(price * units) / SUM(units), 2) AS average_price
FROM Prices p 
INNER JOIN UnitsSold us ON p.product_id = us.product_id AND
  purchase_date BETWEEN start_date AND end_date
GROUP BY p.product_id