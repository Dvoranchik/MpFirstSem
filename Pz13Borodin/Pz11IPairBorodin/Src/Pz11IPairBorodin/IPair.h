#pragma once
#include "Pz11IPairBorodinApi.hpp"
class IPair
{
public:
	PZ11IPAIRBORODIN_API virtual ~IPair() {};

	PZ11IPAIRBORODIN_API virtual void Save(std::ostream& stream) = 0;
	PZ11IPAIRBORODIN_API static IPair *Load(std::ifstream& stream); 

	PZ11IPAIRBORODIN_API virtual std::istream& Input(std::istream& stream) = 0;
	PZ11IPAIRBORODIN_API virtual std::ostream& Output(std::ostream& stream)= 0;
};


