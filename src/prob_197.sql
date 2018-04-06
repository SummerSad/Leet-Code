# Rising Temperature

SELECT cur.Id
FROM Weather pre JOIN Weather cur on datediff(cur.Date, pre.Date) = 1
WHERE cur.Temperature > pre.Temperature