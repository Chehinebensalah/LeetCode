CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    if(@N <= 0)
    begin
        return null;
    end

    RETURN (
        select distinct salary from Employee 
        order by salary desc 
        offset @N - 1 rows
        fetch next 1 rows only
    );
END