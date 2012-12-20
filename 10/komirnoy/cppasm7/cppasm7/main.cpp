#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
	//Y = 3^(cos x), find 6 values of func, where x from 10 step 8

	int A = 3;
	int n = 10;
	int f = 180;
	int step = 8;
	float REZ[6];
	int o = 1;
	int s = sizeof(float);
	float part;

	_asm {
		lea		EBX, REZ
		mov		ECX, 6
	m1:	finit
		fld1
		fild	A
		fyl2x
		fstp	part
		fldpi
		fimul	n
		fidiv	f
		fcos
		fmul	part
		f2xm1
		fiadd	o
		fstp	dword ptr[EBX]
		add		EBX, s
		fild	n
		fiadd	step
		fstp	n
		loop m1
	}

	for(int i = 0; i < sizeof(REZ) / s; i++) {
		std::cout << REZ[i] << " ";
	}

	std::cout << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}