#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
	//Y = 5 * arcSin(3 * cos 25 * sin 25)
	//get a value of func and convert to degree

	long A = 5;
	long B = 3;
	long D = 25;
	long F = 180;
	long S = 1;
	float Y;

	_asm {
		finit
		fldpi
		fimul	D
		fidiv	F
		fsincos
		fmul	ST, ST(1)
		fimul	B
		fld		ST(0)
		fstp	ST(1)
		fmul	ST, ST
		fld1
		fsubr
		fsqrt
		fpatan
		fimul	A
		fimul	F
		fstp	Y
		fldpi
		fdivr	Y
		fstp	Y
	}

	std::cout << Y << std::endl;
	std::cout << "I don\'t know how to solve it any other way but answer: 450-362.82505000022619i" << std::endl;
	std::cout << "And this exercise is very difficult." << std::endl;
	std::cout << std::endl;
	system("pause");

	return EXIT_SUCCESS;
}