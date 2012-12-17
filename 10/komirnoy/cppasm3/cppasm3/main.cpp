#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[]) {
    // sorts array of 11 elem by desc
    srand(time(NULL));

    long x[11];
    unsigned int variant = 0;

    std::cout << "Would you like to manually type any integers or let will fill it automatically?" << std::endl;

    do {
        std::cout << "Type your variant of type (1 - manually or 2 - automatically): ";
        std::cin >> variant;
    } while(variant == 0 || variant > 2);

    std::cout << std::endl;

    if(variant == 1) {
        for(int i = 0; i < sizeof(x) / sizeof(long); i++) {
            std::cout << "Input x[" << i << "] : ";
            std::cin >> x[i];
        }
    } else if(variant == 2) {
        for(int i = 0; i < sizeof(x) / sizeof(long); i++) {
            x[i] = rand() % 100;
            std::cout << x[i] << " ";
            _sleep(500);
        }
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Original array: " << std::endl;
    for(int i = 0; i < sizeof(x) / sizeof(long); i++) {
        std::cout << x[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    _asm {
        mov     EDX, 11
    m3: lea     EBX, x
        mov     ECX, EDX
    m2: mov     EAX, dword ptr[EBX]
        add     EBX, 4
        cmp     EAX, dword ptr[EBX]
        jg      m1
        xchg    dword ptr[EBX], EAX
        mov     dword ptr[EBX - 4], EAX
    m1: loop    m2
        dec     EDX
        jnz     m3
    }

    std::cout << "Sorted array: " << std::endl;
    for(int i = 0; i < sizeof(x) / sizeof(long); i++) {
        std::cout << x[i] << " ";
    }

    std::cout << std::endl;
    std::cin.ignore();
    std::cout << std::getchar();
    
    return EXIT_SUCCESS;
}