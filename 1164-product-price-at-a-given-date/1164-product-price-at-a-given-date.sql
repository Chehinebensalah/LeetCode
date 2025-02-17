/* Write your T-SQL query statement below */
with extracted_data as (
    select product_id, max(change_date) as date
    from products 
    where change_date <= '2019-08-16'
    group by product_id
)
select e.product_id , 
       case 
        when p.new_price is null then 10 
        else p.new_price end 
       as [price] 
from extracted_data e 
left join products p on  e.date = p.change_date and e.product_id = p.product_id 
union 
select 
        product_id,
        10 as price 
from products
where product_id not in (select product_id from extracted_data)