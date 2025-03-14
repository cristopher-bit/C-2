#include <iostream>
using namespace std;

int factorial_no(const int & n)
{
	if (n==0)
	{
		return 1;
	}
	return n * factorial_no(n-1);
}

int main()
{
	int num;
	cout<<"Enter Number: ";
	cin>>num;

	cout<<"Factorial of  "<<num<<" is: "<<factorial_no(num);
	cout<<endl;
	cout<<"value of num after factorial called: "<<num<<endl;

	return 0;
}
