#include "Gateway.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading;

void Gateway::run()
{
	while (true)
		if (queue->Count != 0)
		{
			Thread::Sleep(3000);
			queue->Dequeue()->execute();
		}
}
