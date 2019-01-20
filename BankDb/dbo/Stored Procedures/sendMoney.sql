create procedure sendMoney @Sender bigint, @Receiver bigint, @Amount smallmoney
as
	update Accounts set Money = Money - @Amount where Number = @Sender 
	update Accounts set Money = Money + @Amount where Number = @Receiver
