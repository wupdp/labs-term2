
#include "header.h"

int main() {
    int x = 0;
    do {
        x = choose_ex();
        if (x == 1)
            start_ex(ex1, x);
        else if (x == 2)
            start_ex(ex2, x);
    } while (x != 0);

    return 0;
}