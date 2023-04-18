SELECT d.name AS Department, e.name AS Employee, salary AS Salary
FROM Department d
LEFT JOIN Employee e ON d.id = e.departmentId
WHERE (departmentId, salary) IN (
    SELECT departmentId, MAX(salary) AS salary
    FROM Employee
    GROUP BY departmentId
);