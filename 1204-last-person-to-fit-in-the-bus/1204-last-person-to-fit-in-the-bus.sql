WITH CTE AS (
    SELECT 
        turn,
        SUM(weight) OVER (ORDER BY turn) AS cumulative_sum
    FROM 
        Queue
)
SELECT person_name 
FROM Queue 
WHERE turn = (
    SELECT TOP 1 turn 
    FROM CTE 
    WHERE cumulative_sum <= 1000
    ORDER BY 1 DESC
);
