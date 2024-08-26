WITH temptab AS (
    SELECT departmentId ,
    max(salary) AS salary 
    FROM employee 
    GROUP BY departmentId 
)

SELECT 
    D.name AS Department, 
    E.name AS Employee ,
    E.salary AS Salary 
FROM employee E 
JOIN temptab T ON E.salary  = T.salary AND E.departmentId = T.departmentId 
JOIN Department D ON D.Id = T.departmentId    