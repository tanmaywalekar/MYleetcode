# Write your MySQL query statement below
select Employee.name,Bonus.bonus from Employee LEFT join Bonus ON Employee.empId=Bonus.empId WHERE bonus<1000 OR bonus is NULL