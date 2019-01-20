alter procedure checkMoney @Number bigint, @Amount smallmoney
as
	select 1 where exists(select Number from Accounts where Number = @Number and Money >= @Amount)
	--if((select sum(Money - @Amount) as dif from Accounts where Number = @Number)>=0) select 1; else select 0
