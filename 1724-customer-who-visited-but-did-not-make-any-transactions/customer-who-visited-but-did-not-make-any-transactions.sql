# Write your MySQL query statement below
select s.customer_id ,count(*) as count_no_trans
from Visits s left join
transactions t
ON t.visit_id = s.visit_id
where t.transaction_id is NULL
group by s.customer_id;
