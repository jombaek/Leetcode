SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
  SELECT sales_id
  FROM Orders
  WHERE com_id IN (
    SELECT com_id
    FROM Company
    WHERE name = 'RED'
  )
);

SELECT sp.name
FROM Orders o
INNER JOIN Company c ON o.com_id = c.com_id AND c.name = 'RED'
RIGHT JOIN SalesPerson sp ON o.sales_id = sp.sales_id
WHERE c.name IS NULL;