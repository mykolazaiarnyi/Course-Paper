CREATE procedure updateMoney @Number bigint, @Amount smallmoney
as
	update Accounts set Money = Money - @Amount where Number = @Number 
