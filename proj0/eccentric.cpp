#include <stdio.h>
#include <iostream>

/* BEGIN CHANGES */
#define V0 3 // has to be 3
#define V1 3 // has to be 3
#define V2 3 // can be any nonzero int
#define V3 3 // has to be 3

// the minimum number of distict values is 1
/* END CHANGES */

int main() {
    /* This is a print statement. Notice the little 'f' at the end!
    It might be worthwhile to look up how printf works for your future
    debugging needs... */
    std::cout << "Berkeley eccentrics:\n====================\n";

    /* for loop */
    for (int a = 0; a < V0; a++) {
        std::cout << "Happy ";
    }
    std::cout << "\n";

    /* switch statement
    *  DO NOT MODIFY THIS FUNCTION
    */
    switch (V1) {
        case 0:     std::cout << "Yoshua\n";
        case 1:     std::cout << "Triangle Man\n";  break;
        case 2:     std::cout << "Chinese Erhu Guy\n";
        case 3:     std::cout << "Yoshua\n";        break;
        case 4:     std::cout << "Dr. Jokemon\n";   break;
        case 5:     std::cout << "Hat Lady\n";
        default:    std::cout << "I don't know these people!\n";
    }

    /* ternary operator */
    const char* s = (V3 == 3) ? "Go" : "Boo";

    /* if statement */
    if (V2) {
        std::cout << "\n" << s << " BEARS!\n";
    } else  {
        std::cout << "\n" << s << " CARDINAL!\n";
    }

    return 0;
}
