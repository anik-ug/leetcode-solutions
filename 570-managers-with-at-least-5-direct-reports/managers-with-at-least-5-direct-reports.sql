# Write your MySQL query statement below
SELECT p.name
FROM Employee e
JOIN Employee p
    ON e.managerId = p.id
GROUP BY p.id, p.name
HAVING COUNT(e.id) >= 5;