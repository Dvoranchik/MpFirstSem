#pragma once
#include "Pz12BorodinApi.hpp"
class PostfixNotation
{
public:
	PZ12BORODIN_API ~PostfixNotation();
	PZ12BORODIN_API PostfixNotation* Push(PostfixNotation* head, char top);
	PZ12BORODIN_API char Delete(PostfixNotation** head);
	PZ12BORODIN_API std::string PolishNotation(std::string equation);
	PZ12BORODIN_API std::string DenotizationPolish(std::string equation);
	PZ12BORODIN_API std::string Result(std::string equation);
private:
	PostfixNotation* _next;
	char _top;
};

PZ12BORODIN_API int Priority(char symbol);