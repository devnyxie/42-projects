#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    if (argc == 3)
    {
        int number1 = atoi(argv[1]);
        int number2 = atoi(argv[2]);
        
        if (number1 > 0 && number2 > 0)
        {
            while (number1 != number2)
            {
                if (number1 > number2)
                    number1 = number1 - number2;
                else
                    number2 = number2 - number1;
            }
            printf("%d", number1);
        }
    }
    printf("\n");
}
