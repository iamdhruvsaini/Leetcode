# Write your MySQL query statement below
SELECT e1.name as Employee FROM
 employee AS e1 INNER JOIN employee as e2
 ON e1.managerId=e2.id 
 WHERE e1.salary > e2.salary;