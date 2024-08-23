/* Write your T-SQL query statement below */
SELECT C.customer_id
FROM customer C 
GROUP BY C.customer_id
HAVING COUNT(DISTINCT(C.product_key)) 
        =  
        (SELECT COUNT(DISTINCT(product_key)) FROM product ) 
