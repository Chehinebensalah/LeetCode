SELECT 
    request_at AS day, 
    round(
        sum(CASE WHEN status != 'completed' THEN 1.00 ELSE 0 END) 
        /
        count(*)
        ,2 ) as [Cancellation Rate]
FROM trips T 
JOIN Users Cl on T.client_id = Cl.users_id AND Cl.banned = 'No'
JOIN Users Dr on T.driver_id = Dr.users_id AND Dr.banned = 'No'
WHERE T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at