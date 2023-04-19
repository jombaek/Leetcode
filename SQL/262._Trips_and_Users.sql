SELECT request_at AS Day,
  ROUND(SUM(IF(status LIKE 'cancelled%', 1, 0)) / COUNT(status), 2) AS 'Cancellation Rate'
FROM Trips t
LEFT JOIN Users u1 ON t.client_id = u1.users_id
LEFT JOIN Users u2 ON t.driver_id = u2.users_id
WHERE u1.banned <> 'YES' AND u2.banned <> 'YES'
  AND (Request_at BETWEEN '2013-10-01' AND '2013-10-03')
GROUP BY request_at
ORDER BY Day;