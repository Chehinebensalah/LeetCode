/* Write your T-SQL query statement below */
select coalesce(
(select distinct salary 
from Employee order by salary DESC 
offset 1 rows 
FETCH NEXT 1 ROWS ONLY),null) as SecondHighestSalary;