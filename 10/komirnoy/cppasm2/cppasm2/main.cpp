#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    //An = 3 * n^2 - 5 * n + 12  >1500

    long N = 0;
    long S = 0;

    _asm {
    m1: mov     EAX, 3
        mul     N
        mul     N
        add     EAX, 12
        add     S, EAX
        mov     EAX, 5
        mul     N
        inc     N
        sub     S, EAX
        cmp     S, 1500
        jc      m1
    }

    std::cout << "Summ: " << S << std::endl;
    std::cout << "Num: " << N << std::endl;
    std::cout << std::getchar();

    return EXIT_SUCCESS;
}