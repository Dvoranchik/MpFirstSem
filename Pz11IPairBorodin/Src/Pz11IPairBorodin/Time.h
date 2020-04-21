#pragma once
#include "stdafx.h"
#include "Pz11IPairBorodinApi.hpp"
#include "IPair.h"
class Time : public IPair
{
public:
	PZ11IPAIRBORODIN_API Time() :_hours(0), _minutes(0) {}
	PZ11IPAIRBORODIN_API Time(int hours, int minutes);
	
	PZ11IPAIRBORODIN_API Time& operator=(const Time& other);
	PZ11IPAIRBORODIN_API Time operator+(const Time& other);
	PZ11IPAIRBORODIN_API Time operator*(const Time& other);

	PZ11IPAIRBORODIN_API Time(const Time& other);

	PZ11IPAIRBORODIN_API void SetTime(int hours,int minutes);

	PZ11IPAIRBORODIN_API int GetHours();
	PZ11IPAIRBORODIN_API int GetMinutes();

	PZ11IPAIRBORODIN_API static IPair *Load(std::ifstream& stream);
	PZ11IPAIRBORODIN_API virtual void Save(std::ostream& stream) override;

	PZ11IPAIRBORODIN_API virtual std::istream& Input(std::istream& stream) override;
	PZ11IPAIRBORODIN_API virtual std::ostream& Output(std::ostream& stream) override;

private:
	int _hours;
	int _minutes;
};
