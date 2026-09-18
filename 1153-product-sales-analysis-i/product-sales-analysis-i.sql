# Write your MySQL query statement below
select product_name, year, price
FROM Product p 
 join sales s
on p.product_id  = s.product_id ;