SELECT 
    id,
    CASE 
        WHEN p_id is null THEN 'Root'
        WHEN id in (select distinct(p_id) from Tree) THEN 'Inner'
        ELSE 'Leaf' 
    END AS [type]
FROM 
    Tree;
