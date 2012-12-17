#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    // An = 3 * n^2 + 11  for n -> 4
    long N = 4;
    long REZ[7];

    _asm {
        lea     EBX, REZ
        mov     ECX, 7
    m1: mov     EAX, 3
        imul    N
        imul    N
        add     EAX, 11
        mov     dword ptr[EBX], EAX
        add     EBX, 4
        inc     N
        loop    m1
    }

    for(int i = 0; i < sizeof(REZ) / sizeof(long); i++) {
        std::cout << REZ[i] << std::endl;
    }

    std::cout << std::getchar();

    return EXIT_SUCCESS;
}
