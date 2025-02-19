
select DISTINCT s.*  
from stadium s,stadium s1,stadium s2
where s.people >= 100 AND s1.people >= 100 AND s2.people >= 100
AND    (   (s.id - s1.id = 1 and s1.id - s2.id = 1) 
        or (s2.id -s1.id = 1 and s1.id - s.id = 1 ) 
        or (s1.id - s.id = 1 and s.id - s2.id = 1 ) 
        )
order by visit_date