#include <iostream>
#include <string>
#include <stack>
#include "Reverse.h"

using namespace std;

void reverseString(char *p)
{
	stack<char> S;
	//push to stack
	for (int i = 0; i < strlen(p); i++)
	{
		S.push(p[i]);
	}
	//pop from stack
	for (int i = 0; i < strlen(p); i++)
	{
		p[i] = S.top();
		S.pop();
	}
}