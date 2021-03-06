#include "stdafx.h"
#include "Pz12Borodin.h"
PostfixNotation::~PostfixNotation()
{
	delete[] _next;
}

PostfixNotation* PostfixNotation::Push(PostfixNotation* head, char top)
 {
	 PostfixNotation* ptr = new PostfixNotation[sizeof(PostfixNotation)];
	 if (ptr == nullptr)
		 throw(std::runtime_error("No ptr"));
	 ptr->_top = top;
	 ptr->_next = head;

	 return ptr;
 }

 char PostfixNotation::Delete(PostfixNotation** head)
 {
	 PostfixNotation* ptr= new PostfixNotation[sizeof(PostfixNotation)];
	 char top;
	 if (*head == nullptr)
		 return '\0';
	 ptr = *head;
	 top = ptr->_top;
	 *head = ptr->_next;
	 return top;
 }

 int Priority(char symbol)
 {
	 switch (symbol)
	 {
	 case '*':
	 case '/':
		 return 3;

	 case '-':
	 case '+':
		 return 2;

	 case '(':
		 return 1;
	 }
 }

 std::string PostfixNotation::PolishNotation(std::string equation)
 {
	 PostfixNotation* operation=nullptr;
	 int pointer,i;
	char outstring[80];
	 i = pointer = 0;
	 while (equation[i] != '\0' && equation[i] != '=')
	 {
		 if (equation[i] == ')')
		 {
			 while ((operation->_top)!= '(')
			 {
				 outstring[pointer++] = Delete(&operation);
			 }
				 Delete(&operation);
		 }
		 if (equation[i] >= 'A' && equation[i] <= 'Z')
		 {
			 outstring[pointer++] = equation[i];
		 }
		 if (equation[i] >= '0' && equation[i] <= '9')
		 {
			 outstring[pointer++] = equation[i];
		 }
		 if (equation[i] >= 'a' && equation[i] <= 'z')
		 {
			 outstring[pointer++] = equation[i];
		 }
		 if (equation[i] == '(')
		 {
			 operation = Push(operation, '(');
		 }
		 if (equation[i] == '+' || equation[i] == '-' || equation[i] == '/' || equation[i] == '*')
		 {
			 if (operation == nullptr)
			 {
				 operation = Push(operation, equation[i]);
			 }
			 else
				 if (Priority(operation->_top) < Priority(equation[i]))
				 {
					 operation = Push(operation, equation[i]);
				 }
				 else
				 {
					 while ((operation != nullptr) && (Priority(operation->_top)) >= Priority(equation[i]))
					 {
						 outstring[pointer++] = Delete(&operation);
					 }
					 operation = Push(operation, equation[i]);
				 }
		 }
		 ++i;
	}
	 while (operation != nullptr)
	 {
		 outstring[pointer++] = Delete(&operation);
	 }
	 outstring[pointer] = '\0';
	 return outstring;
 }

 std::string PostfixNotation::DenotizationPolish(std::string equation)
 {
	 PostfixNotation* operation = nullptr;
	 int i = 0,z=0;
	 char data1, data2;
	 char t;
	 std::stack<char> stek;
	 std::string storage, outstring;

	 while (equation[i] != '\0')
	 {
		 if (equation[i] >= 'A' && equation[i] <= 'Z')
		 {
			 stek.push(equation[i]);
		 }
		 if (equation[i] >= '0' && equation[i] <= '9')
		 {
			 stek.push(equation[i]);
		 }
		 if (equation[i] >= 'a' && equation[i] <= 'z')
		 {
			 stek.push(equation[i]);
		 }
		 if (equation[i] == '+' || equation[i] == '-' || equation[i] == '/' || equation[i] == '*')
		 {
			 if (stek.size() > 1)
			 {
				 z = stek.size();
				 operation = Push(operation, equation[i]);
				 data1 = stek.top();
				 stek.pop();
				 data2 = stek.top();
				 stek.pop();
				 storage = data2;
				 storage += equation[i];
				 storage += data1;
				 if (outstring.empty())
					outstring = storage;
			 }
			 else if (Priority(operation->_top) >= Priority(equation[i]) && !(stek.empty()))
			 {
				 if (z > 2)
				 {
					 if (equation[i] == '/' || equation[i] == '-')
					 {
						 Delete(&operation);
						 operation = Push(operation, equation[i]);
						 std::string backet = outstring;
						 outstring = stek.top();
						 outstring += equation[i];
						 stek.pop();
						 outstring += '(';
						 outstring += backet;
						 outstring += ')';
					 }
					 else {
						 Delete(&operation);
						 operation = Push(operation, equation[i]);
						 std::string backet = outstring;
						 outstring = stek.top();
						 outstring += equation[i];
						 stek.pop();
						 outstring += backet;
					 }
				 }
				 else
				 {
					 Delete(&operation);
					 operation = Push(operation, equation[i]);
					 storage = equation[i];
					 storage += stek.top();
					 stek.pop();
					 outstring += storage;
				 }
			 }
			 else if (stek.empty() && !(storage.empty()) && outstring != storage)
			 {
				 if (Priority(operation->_top) < Priority(equation[i]) )
				 {
					 operation = Push(operation, equation[i]);
					 std::string backet = outstring;
					 outstring = '(';
					 outstring += backet;
					 outstring += ')';
					 outstring += equation[i];
					 outstring += '(';
					 outstring += storage;
					 outstring += ')';
				 }
				 else
				 {
					 operation = Push(operation, equation[i]);
					 if (operation->_top == '/' || operation->_top == '-')
					 {
						 
						 std::string backet = outstring;
						 outstring = '(';
						 outstring += backet;
						 outstring += ')';
						 outstring += equation[i];
						 outstring += '(';
						 outstring += storage;
						 outstring += ')';
					 }
					 else
					 {
						 outstring += equation[i];
						 outstring += storage;
					 }
				 }
			 }
			 else
			 {
				 if (z > 2 )
				 {
					 z = equation[i];
					 operation = Push(operation, equation[i]);
					 storage = outstring;
					 outstring = stek.top();
					 stek.pop();
					 outstring += equation[i];
					 outstring += '(';
					 outstring += storage;
					 outstring += ')';
					 storage.clear();
				 }
				 else 
				 {
					 operation = Push(operation, equation[i]);
					 storage = outstring;
					 outstring = '(';
					 outstring += storage;
					 outstring += ')';
					 outstring += equation[i];
					 outstring += stek.top();
					 stek.pop();
					 storage.clear();
				 }
			 }
		 }
		 ++i;
	 }
	 return outstring;
 }

 std::string PostfixNotation::Result(std::string equation)
 {
	 return DenotizationPolish(PolishNotation(equation));
 }
