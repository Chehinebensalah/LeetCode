WITH Processed_data AS (
    SELECT 
        d.name AS Department, 
        e.name AS Employee, 
        e.salary,
        DENSE_RANK() OVER(PARTITION BY e.departmentId ORDER BY e.salary DESC) AS  highest_salary
    FROM Employee e
    JOIN Department d ON e.departmentId = d.id
)
SELECT  Department,
        Employee,
        Salary
FROM Processed_data
WHERE highest_salary <=3 
