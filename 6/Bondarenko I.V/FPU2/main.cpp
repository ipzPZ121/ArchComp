/*
�����-12-2 ���������� ���� ������������

������� 6

3.3.4.2 ����������� ���������� �������� ���������.

  */
  
void main() {
	long X = 0, B = 2, C = 10, Z = 100;
	float A = 3,5;
	
	_asm{
		finit				; ������� ��������� ������������
		fld1				; ������� ��� ���������� ��������� �����.
		m1:	inc		X		;����������� ���������
		fld		A		; �������� � ST(0) 3,5
		fmulp		ST(2),ST	; ���������� ��������� �������  3.5^x
		fimul ST(2),B ; ���������� 2*3.5^x
		
		
		fild		C ; 10
		fadd		ST,ST(2)	; 2*3.5^x+10
		fsqrt ST
		ficom		Z		; ��������� ����� � 100
		fstsw	AX		; ���������� �������� ���������  SW (FPU) � 
						; ��������  AX (CPU)
		sahf				;���������� �������� ����� �� � ���. ������
		jc		m1		; �������, ���� ����� ������ 100
	

	}
}