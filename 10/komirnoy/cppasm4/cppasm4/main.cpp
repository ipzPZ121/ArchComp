#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
	//Y = 3000 / (x^2 + 3,6 * x – 7,5), where x from 2 over step 2.7
	//finds 6 values of func.

	float REZ[6];
	float x = 2;
	long A = 3000;
	float B = 3.6;
	float C = 7.5;
	float part;
	float S = 2.7;
	long s = sizeof(float);

	_asm {
		lea		EBX, REZ
		mov		ECX, 6
	m1:	finit
		fld		x
		fmul	ST, ST
		fstp	part
		fld		x
		fmul	B
		fadd	part
		fsub	C
		fstp	part
		fild	A
		fdiv	part
		fstp	dword ptr[EBX]
		add		EBX, s
		fld		x
		fadd	S
		fstp	x
		loop m1
	}

	for(int i = 0; i < sizeof(REZ) / sizeof(float); i++) {
		std::cout << REZ[i] << " ";
	}

	std::cout << std::endl;
	system("pause");

	return EXIT_SUCCESS;
}