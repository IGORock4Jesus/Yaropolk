#pragma once

#include <thread>

#include "TrivialAPI.h"
#include "Event.h"

namespace Yaropolk::Trivial {

class TRIVIAL_API Thread
{
	std::thread th; // ����� ���
	int dur; // ����� �� ���������� ������
	bool enabled{ false };

	void Update();

public:
	Event<float> Updating; // ���������� ���������

	Thread();
	~Thread();

	void Start();
	void Stop();

	void SetDelay(int delay) { dur = delay; }
	int GetDelay() const { return dur; }
};

}