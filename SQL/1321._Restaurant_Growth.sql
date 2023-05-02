SELECT t1.visited_on,
  SUM(t2.day_sum) AS amount,
  ROUND(AVG(t2.day_sum), 2) AS average_amount
FROM (
  SELECT visited_on, SUM(amount) AS day_sum
  FROM Customer
  GROUP BY visited_on
) t1, (
  SELECT visited_on, SUM(amount) AS day_sum
  FROM Customer
  GROUP BY visited_on
) t2
WHERE DATEDIFF(t1.visited_on, t2.visited_on) BETWEEN 0 AND 6
GROUP BY t1.visited_on
HAVING COUNT(t2.visited_on) = 7;