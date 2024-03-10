#include <iostream>
#include <cmath>
int main()
{
	int a,b = 12, c = 8, a1, a2,sum;
	std::cin >> a;
	_asm{
		mov ecx,b
		mov eax,1
		mov edx,a
	beg:
		mul a
		loop beg
		mov a1,eax
		mov ecx,c
		mov eax,1
	deg:
		mul a
		loop deg
		mov ebx,eax
		add ebx,a1
		add ebx,a
		mov sum,ebx
	}
	std::cout << sum<< std::endl;
	std::cout << std::pow(a, 12) + std::pow(a, 8) + a;
}