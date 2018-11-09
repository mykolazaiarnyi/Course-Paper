#pragma once
#include "IExecutable.h"
using namespace System::Collections::Generic;
using namespace System::Threading;

ref class Gateway
{
public:
	static Thread^ thread = gcnew Thread(gcnew ThreadStart(run));;
	static Queue<IExecutable^>^ queue = gcnew Queue<IExecutable^>();
	static void run();
};

