# Write your MySQL query statement below
select Product.product_name,Sales.year,Sales.price from Sales JOIN Product ON Product.product_id=Sales.product_id