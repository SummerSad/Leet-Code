# Second Highest Salary
# Find MAX in set where that set < MAX everything

SELECT MAX(Salary) as SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT MAX(Salary)
                FROM Employee)