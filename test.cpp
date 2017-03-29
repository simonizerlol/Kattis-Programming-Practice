#include <iostream>
using namespace std;
int getNumber()
{
	cin >> x
}
 
bool test(int x)
{
	if (x % 2 == 0)
		return 0;
	else
		return 1;
}
 
 
void print( int x)
{
	int x1, x2, x3, x4, x5,x6, x7, x8;
	x1 = x ;
	x2 = x1 / 2;
	x3 = x2 / 2;
	x4 = x3 / 2;
	x5 = x4 / 2;
	x6 = x5 / 2;
	x7 = x6 / 2;
	x8 = x7 / 2;
	std::cout << test(x8) << test(x7) << test(x6) << test(x5) << test(x4) << test(x3) << test(x2) << test(x1);
 
}
 
 
int main()
{
	int x;
	x = getNumber();
	print(x);
	return 0;
}