# Write your MySQL query statement below
select w.id
from Weather v JOIN 
Weather w on DATEDIFF(w.recordDate,v.recordDate) = 1
where w.temperature>v.temperature;