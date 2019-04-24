#include "Thread.h"
#include <Windows.h>

namespace Yaropolk::Trivial {
void Thread::Update()
{
	auto oldTime = ::timeGetTime();

	while (enabled)
	{
		auto newTime = ::timeGetTime();
		auto elapsedTime = (newTime - oldTime) * 0.001f;
		oldTime = newTime;

		Updating(elapsedTime);

		std::this_thread::sleep_for(std::chrono::milliseconds(dur));
	}
}
Thread::Thread()
	: dur{ 0 }
{
}


Thread::~Thread()
{
	Stop();
}

void Thread::Start()
{
	if (enabled)return;

	enabled = true;

	th = std::thread(&Thread::Update, this);
}

void Thread::Stop()
{
	if (!enabled) return;

	enabled = false;

	if (th.joinable())
		th.join();
}

}