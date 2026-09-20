# Write your MySQL query statement below
select p.name
from Employee e join Employee p on e.managerId = p.id 
group by p.id,p.name
having count(e.id)>=5;