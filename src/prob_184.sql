# 184. Department Highest Salary

SELECT d.Name as Department, e.Name as Employee, e.Salary
FROM Employee e JOIN Department d on e.DepartmentId = d.Id
WHERE Salary >= (SELECT MAX(e2.Salary)
		FROM Employee e2
		WHERE e.DepartmentId = e2.DepartmentId)