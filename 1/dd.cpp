#include <iostream>
#include <string.h>

void print(double x) // print takes a double parameter
{
	std::cout << x/2 << '\n';
}

void incletase (int& su){
	su++;
}

int main()
{
	char* buffer = new char [8];
	memset(buffer,2,8);
	char** ptr = &buffer;

	int a = 4;
	//int& ret = a;
	incletase(a);
	std::cout << *buffer << a << std::endl; 

	delete[] buffer;
	std::cin.get();
	return 0;
}