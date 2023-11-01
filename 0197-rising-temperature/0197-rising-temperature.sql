# Write your MySQL query statement below
select e1.id from Weather e1,Weather e2 where  DATEDIFF(e1.recordDate, e2.recordDate) = 1 and e1.temperature>e2.temperature