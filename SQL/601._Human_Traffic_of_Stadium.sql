WITH t
  AS (
    SELECT *, id - row_number() over(ORDER BY id) as id_diff
    FROM Stadium
    WHERE people >= 100
  )

SELECT id, visit_date, people
FROM t
WHERE id_diff IN (
  SELECT id_diff
  FROM t
  GROUP BY id_diff
  HAVING COUNT(*) >= 3
)
ORDER BY visit_date;