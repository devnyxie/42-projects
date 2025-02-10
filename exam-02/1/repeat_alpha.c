#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int times;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            times = 0;
            if ((argv[1][i] >= 65 && argv[1][i] <= 90))
            {
                while (times < argv[1][i] - 64)
                {
                    write (1, &argv[1][i], 1);
                    times++;
                }
            }
            if ((argv[1][i] >= 97 && argv[1][i] <= 122))
            {
                while (times < argv[1][i] - 96)
                {
                    write (1, &argv[1][i], 1);
                    times++;
                }
            }
            else
                write (1, &argv[1][i], 1);
            i++;
        }   
    }
    write (1, "\n", 1);
}