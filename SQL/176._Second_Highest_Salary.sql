WITH salary_rank (salary, rnk)
    AS (
        SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC)
        FROM Employee
    )

SELECT MAX(salary) AS SecondHighestSalary
FROM salary_rank
WHERE rnk = 2;