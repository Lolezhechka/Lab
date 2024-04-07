#include <iostream>

int main()
{
	int sum(50), x, y;
	int A[8], B[8];
	_asm {
		mov x, 1
		mov esi, 0
		loop1:
		mov y, 1
			loop2 :
			mov eax, x
			mov ecx, x
			mov edx, y
			add eax, eax
			mov ebx, y
			add ebx, ebx
			add ebx, y
			add eax, ebx
			cmp eax, sum
			jne false
			mov A[esi], ecx
			mov B[esi], edx
			add esi, 4
			false:
		    add y,1
			cmp y,50
			jle loop2
			add x,1
			cmp x, 50
			jle loop1
	}

	for (int i = 0; i < 8; i++) {
		std::cout << 2 * A[i] << "+" << 3 * B[i] << "=50" << '\n';
	}
}