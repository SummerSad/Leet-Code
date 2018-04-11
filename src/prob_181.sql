-- Employees Earning More Than Their Managers

SELECT e.Name as Employee
FROM Employee e JOIN Employee ql on e.ManagerID = ql.Id
WHERE e.Salary > ql.Salary