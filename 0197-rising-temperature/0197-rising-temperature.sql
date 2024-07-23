select  w1.id 
FROM 
    Weather  w1
join Weather  w2
on DATEADD(DAY, -1, w1.recordDate) = w2.recordDate
where w1.temperature > w2.temperature