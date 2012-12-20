#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
	//Y = sqrt(15 * x^2 + 32 * x + 40)
	//find x when Y >= 30

	long x = 0;
	long A = 15;
	long B = 32;
	long C = 40;
	long S = 30;
	float part;

	_asm {
		finit
	m1:	inc		x
		fild	x
		fmul	ST, ST
		fimul	A
		fstp	part
		fild	x
		fimul	B
		fadd	part
		fiadd	C
		fsqrt
		fstp	part
		fld		part
		ficom	S
		fstsw	AX
		sahf
		jc		m1
	}

	std::cout << x << std::endl;
	system("pause");

	return EXIT_SUCCESS;
}