# 185. Department Top Three Salaries
# Top 3 mean, only < 3 salary higher than your's
# salary can be duplicate 100, 90, 90

SELECT d.Name as Department, e.Name as Employee, e.Salary
FROM Employee e JOIN Department d on e.DepartmentId = d.Id
WHERE 3 > (SELECT COUNT(DISTINCT e2.Salary)
	FROM Employee e2
	WHERE e2.DepartmentId = e.DepartmentId
		AND e2.Salary > e.Salary)
ORDER BY d.Name, e.Salary desc