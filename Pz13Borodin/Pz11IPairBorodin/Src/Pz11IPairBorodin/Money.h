#pragma once
#include "stdafx.h"
#include "IPair.h"
#include "Pz11IPairBorodinApi.hpp"
class Money : public IPair
{
public:
	PZ11IPAIRBORODIN_API Money() :_rubles(0), _pennies(0) {}
	PZ11IPAIRBORODIN_API Money(int rubles, int pennies);
	PZ11IPAIRBORODIN_API Money(const Money& other);

	PZ11IPAIRBORODIN_API Money& operator=(const Money& other);
	PZ11IPAIRBORODIN_API Money operator+(const Money& other);
	PZ11IPAIRBORODIN_API Money operator*(const Money& other);

	PZ11IPAIRBORODIN_API int GetRubles() const;
	PZ11IPAIRBORODIN_API int GetPennies() const;

	PZ11IPAIRBORODIN_API void SetMoney(int rubles, int pennies);

	PZ11IPAIRBORODIN_API static IPair *Load(std::ifstream& stream);
	PZ11IPAIRBORODIN_API virtual void Save(std::ostream& stream);

	PZ11IPAIRBORODIN_API virtual std::istream& Input(std::istream& stream) override;
	PZ11IPAIRBORODIN_API virtual std::ostream& Output(std::ostream& stream) override;

private:
	int _rubles;
	int _pennies;
};