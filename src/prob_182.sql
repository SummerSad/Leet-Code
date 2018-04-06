# Duplicate Emails

SELECT DISTINCT p.Email
FROM Person p JOIN Person q on p.Email = q.Email
WHERE p.Id != q.Id

SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Id) > 1