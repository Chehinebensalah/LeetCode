with cte as (
    Select buyer_id,
           count(buyer_id) as orders_in_2019
    from orders 
    where YEAR(order_date) = 2019
    group by buyer_id
)

select  u.user_id as buyer_id,
        u.join_date,
        count(c.orders_in_2019,0) as orders_in_2019
from users u 
left join cte c on u.user_id = c.buyer_id