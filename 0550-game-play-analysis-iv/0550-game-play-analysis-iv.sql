/* Write your T-SQL query statement below */
WITH TEMP AS (
    SELECT player_id, MIN(event_date) AS event_date
    FROM Activity 
    GROUP BY player_id
)
SELECT 
    ROUND(
        cast( COUNT(T.player_id) AS DECIMAL(10,2) )
        / cast( COUNT( DISTINCT A.player_id) AS DECIMAL(10,2) ),
        2
    ) As fraction 
FROM TEMP T 
RIGHT JOIN Activity A 
ON A.event_date = DATEADD(day, 1,T.event_date )
and A .player_id = T.player_id;
