SELECT ROUND(COUNT(a.player_id) / COUNT(t.player_id), 2) AS fraction
FROM (
  SELECT player_id, MIN(event_date) AS first_login
  FROM Activity
  GROUP BY player_id
) AS t
LEFT JOIN Activity a ON t.player_id = a.player_id
  AND t.first_login = a.event_date - 1;