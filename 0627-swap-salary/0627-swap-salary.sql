/* Write your T-SQL query statement below */

UPDATE SALARY 
SET sex = CASE 
            WHEN sex = 'f' THEN 'm'
            ELSE 'f' 
          END;