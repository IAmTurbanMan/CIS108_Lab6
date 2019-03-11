//Exercise 2: Strike that, Reverse it!
//found most of this here: http://www.firmcodes.com/write-a-program-to-reverse-a-string-using-stack-in-c/
#include <iostream>
#include <string>
#include <stack>
#include "Reverse.h"

using namespace std;

int main()
{
	//declare string
	char originalString[] = "Invention, my dear friends, is 93% perspiration, 6% electricity, 4% evaporation, and 2% butterscotch ripple";
	//call the function to reverse the string
	reverseString(originalString);

	printf(" %s\n", originalString);

	system("PAUSE");

	return 0;
}