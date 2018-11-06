#pragma once
#include<map>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;

ref class DBConnecter
{
private:
	static SqlConnection^ connection = gcnew SqlConnection("Data Source=DESKTOP-RUOJK26;Initial Catalog=Bank;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;ApplicationIntent=ReadWrite;MultiSubnetFailover=False");
	static SqlCommand^ checkValidCommand = gcnew SqlCommand("select * from selectAll", connection);
	static SqlCommand^ checkMoneyCommand = gcnew SqlCommand("checkMoney", connection);
	static SqlCommand^ updateMoneyCommand = gcnew SqlCommand("updateMoney", connection);
	static SqlCommand^ sendMoneyCommand = gcnew SqlCommand("sendMoney", connection);
	static Dictionary<long long, int>^ accounts = gcnew Dictionary<long long, int>();
public:
	static DBConnecter();
	static bool^ checkValid(long long number, int pin, System::Windows::Forms::Control^ messageTarget);
	static bool^ checkMoney(long long number, double amount);
	static void updateMoney(long long number, double amount);
	static void sendMoney(long long sender, long long receiver, double amount);
	static bool^ exists(long long number);
};
