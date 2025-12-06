// inserting into a string
//#include <iostream>
//#include <string>
#include <stdio.h>


/*
int main ()
{
	float i = 1.333;
	float ii = 1.3330;
	if (i == ii)
		std::cout << "Equal" << '\n';
	else
		std::cout << "Not Equal" << '\n';
		
	return 0;
}
*/
int main(void) {
    float a = 0.1f + 0.2f;
    float b = 0.3f;

    if (a == b)
        printf("EGAUX\n");
    else {
        printf("PAS EGAUX\n");
        printf("a = %.10f\n", a);
        printf("b = %.10f\n", b);
    }

    return 0;
}
