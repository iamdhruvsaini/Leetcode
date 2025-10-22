CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE L INT;
    SET L = N - 1; -- L is a local variable, not a session variable @L

    RETURN (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET L -- Use the local variable L directly
    );
END