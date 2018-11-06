#include "DBConnecter.h"
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

static DBConnecter::DBConnecter()
{
	connection->Open();
	SqlDataReader^ rdr = checkValidCommand->ExecuteReader();
	while (rdr->Read())
		accounts->Add(Convert::ToInt64(rdr[0]), Convert::ToInt32(rdr[1]));
	connection->Close();

	checkMoneyCommand->CommandType = CommandType::StoredProcedure;
	checkMoneyCommand->Parameters->Add(gcnew SqlParameter("@Number", nullptr));
	checkMoneyCommand->Parameters->Add(gcnew SqlParameter("@Amount", nullptr));

	updateMoneyCommand->CommandType = CommandType::StoredProcedure;
	updateMoneyCommand->Parameters->Add(gcnew SqlParameter("@Number", nullptr));
	updateMoneyCommand->Parameters->Add(gcnew SqlParameter("@Amount", nullptr));

	sendMoneyCommand->CommandType = CommandType::StoredProcedure;
	sendMoneyCommand->Parameters->Add(gcnew SqlParameter("@Sender", nullptr));
	sendMoneyCommand->Parameters->Add(gcnew SqlParameter("@Receiver", nullptr));
	sendMoneyCommand->Parameters->Add(gcnew SqlParameter("@Amount", nullptr));
}

bool^ DBConnecter::checkValid(long long number, int pin, System::Windows::Forms::Control^ messageTarget)
{
	if (accounts->ContainsKey(number))
		if (accounts[number] == pin)
			return true;
		else
		{
			messageTarget->Text = "Wrong PIN";
			return false;
		}
	else
	{
		messageTarget->Text = "Wrong card number";
		return false;
	}
}

bool^ DBConnecter::checkMoney(long long number, double amount)
{
	try {
		connection->Open();
		checkMoneyCommand->Parameters["@Number"]->Value = number;
		checkMoneyCommand->Parameters["@Amount"]->Value = amount;
		SqlDataReader^ rdr = checkMoneyCommand->ExecuteReader();
		rdr->Read();
		int rtrn = Convert::ToInt32(rdr[0]);
		connection->Close();
		return (rtrn == 1) ? true : false;
	}
	catch (Exception^ e)
	{
		connection->Close();
		throw e;
	}
}

void DBConnecter::updateMoney(long long number, double amount)
{
	connection->Open();
	updateMoneyCommand->Parameters["@Number"]->Value = number;
	updateMoneyCommand->Parameters["@Amount"]->Value = amount;
	updateMoneyCommand->ExecuteNonQuery();
	connection->Close();
}

void DBConnecter::sendMoney(long long sender, long long receiver, double amount)
{
	connection->Open();
	sendMoneyCommand->Parameters["@Sender"]->Value = sender;
	sendMoneyCommand->Parameters["@Receiver"]->Value = receiver;
	sendMoneyCommand->Parameters["@Amount"]->Value = amount;
	sendMoneyCommand->ExecuteNonQuery();
	connection->Close();
}

bool^ DBConnecter::exists(long long number)
{
	return accounts->ContainsKey(number);
}