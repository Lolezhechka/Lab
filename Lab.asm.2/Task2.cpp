#include <iostream>

int main()
{
	int x, count(0), y(10), z(2), res;
	std::cin >> x;
	if (x <= 0) {
		std::cout << "hell nah" << "\n";
	}
	_asm {
		mov eax, x
		xd :
		inc count
			cdq
			div y
			cmp edx, 0
			jne xd

			dec count
			mov ecx,count
			mov eax,0
			mov ebx,x
			loop1:
			mul y
			mov res,eax
			mov eax,ebx
			div y
			add res,edx
			mov ebx,eax
			mov eax,res
			loop loop1
			sub eax,x
			mov res,eax
	}
	std::cout << res << std::endl;
	if (res != 0) {
		std::cout << "Nonsymetric" << std::endl;
	}
	else {
		std::cout << "Symetric" << std::endl;
	}
	std::cout << count;
}