# Write your MySQL query statement below
SELECT email from Person GROUP BY email having COUNT(email)>1;