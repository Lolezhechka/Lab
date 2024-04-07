#include <iostream>
int main()
{
	int a, b,a1,b1,m(1),GCD;
	std::cin >> a1;
	std::cin >> b1;
	_asm {
		mov eax,a1
		mov ecx,-1
		cmp eax,0
		js negativ
		negativ:
		mul ecx
		mov a1,eax
		mov m,-1
	}
	_asm {
		mov eax, a1
		mov ebx, b1
		loop1:
		cmp eax, ebx
			je done
			jg continue
			sub ebx, eax
			jmp loop1
			continue:
		sub eax, ebx
			jmp loop1
			done:
		mov GCD, eax
	}
	_asm {
		mov eax,a1
		mov ebx,GCD
		cdq
		div ebx
		mov ebx,m
		mul ebx
		mov a,eax
	}
	_asm {
		mov eax, b1
		mov ebx, GCD
		cdq
		div ebx
		mov b, eax
	}
	std::cout << a << std::endl << b << std::endl << m <<std::endl << GCD;
	return 0;
}
