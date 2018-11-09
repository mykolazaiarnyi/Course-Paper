#pragma once
#include "IExecutable.h"
#include "Atm.h"

ref class TransferCommand :
	public IExecutable
{
private:
	long long _sender;
	long long _receiver;
	double _amount;
	Atm^ _atm;
public:
	TransferCommand(long long sender, long long receiver, double amount, Atm^ atm);
	virtual void execute() override;
};

