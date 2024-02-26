#include <iostream>

int main()
{
	unsigned int A1 = 65535, A2 = 65535, A3 = 65535, B1 = 65535, B2 = 65535, B3 = 65535;
	int C1, C2, C3;
	_asm {
		mov edx, A3;
		add edx, B3;
		mov C3, edx;
	}
	_asm {
		mov edx, A2;
		add edx, B2;
		mov C2, edx;
		cmp C2, 65535;
		jbe dd;
	dd:
		sub C2, 100000;
		add C3, 1;
	}
	_asm {
		mov edx, A1;
		add edx, B1;
		mov C1, edx;
		cmp C1, 65535;
		jbe aa;
	aa:
		sub C1, 100000;
		add C2, 1;
	}
	std::cout << C3 << C2 << C1 << std::endl;
	std::cout << std::hex << C3 << std::endl << C2 << std::endl << C1;
	return 0;
}
