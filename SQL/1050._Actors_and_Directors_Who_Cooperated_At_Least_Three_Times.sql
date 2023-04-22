SELECT actor_id, director_id
FROM (
  SELECT actor_id, director_id, COUNT(*) AS count
  FROM ActorDirector
  GROUP BY actor_id, director_id
) t
WHERE count >= 3;