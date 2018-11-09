#pragma once
#include "IExecutable.h"
#include "Atm.h"
ref class WithdrawCommand :
	public IExecutable
{
	long long _number;
	double _amount;
	Atm^ _atm;
public:
	WithdrawCommand(long long number, double amount, Atm^ atm);
	virtual void execute() override;
};

