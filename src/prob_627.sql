# Swap Salary

UPDATE salary
    	SET sex = CASE
        	WHEN sex = 'm' THEN 'f'
        	ELSE 'm'
        	END
    	WHERE sex in ('m', 'f')