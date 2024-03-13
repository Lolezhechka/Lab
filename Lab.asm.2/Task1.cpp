#include <iostream>

int main()
{
	int x, y(2), result;
	std::cout << "enter x" << '\n';
	std::cin >> x;
	//(x^5 + 2 * (x^2 - 4) + x) / x^3
	std::cout << int((pow(x, 5) + 2 * (pow(x, 2) - 4) + x) / pow(x, 3));
	_asm {
		mov eax, x
		mul x
		mul x
		mul x
		mul x
		mov ebx, eax
		mov eax, x
		mul x
		sub eax, 4
		mul y
		add ebx, x
		add ebx, eax
		mov eax, ebx
		cdq
		div x
		cdq
		div x
		cdq
		div x
		mov result, eax
	}
	std::cout << std::endl << result;
}