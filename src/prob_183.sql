-- 183. Customers Who Never Order

SELECT c.Name as Customers
FROM Customers c LEFT JOIN Orders o on c.Id = o.CustomerId
WHERE o.Id IS NULL