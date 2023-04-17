SELECT DISTINCT num AS ConsecutiveNums
FROM (
  SELECT num, id - ROW_NUMBER() OVER (ORDER BY num, id) AS rnk
  FROM Logs
  ) AS t
GROUP BY num, rnk
HAVING COUNT(*) >= 3;