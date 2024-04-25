#include <iostream>
#include <string.h>

class Plarer{
public:
	int a,b;
	int spead;
	void move_e(int x,int y){
		a+=x*spead;
		b+=y*spead;
	}
};

int main(){
	Plarer plarer;
	plarer.a = 3;
	plarer.b = 5;
	plarer.spead = 4;
	std::cout<< plarer.a << '\n' << plarer.b << '\n' << plarer.spead << '\n';
	plarer.move_e(2,-3);
	std::cout<< plarer.a << '\n' << plarer.b << '\n' << plarer.spead;
}