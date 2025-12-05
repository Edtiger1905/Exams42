// deve stampare n volte il corrispondente alfabetico numerico della lettera

// a = a, b = bb, c = ccc,etc...
#include <unistd.h>

void repeat_alpha(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] <= 'z'))
        {
            count = (str[i] - 'a') + 1;
        }
        else if ((str[i] >= 'A' && str[i] <= 'Z'))
        {
            count = (str[i] - 'A') + 1;
        }
        else
            write(1, &str[i], 1);
        while (count > 0)
            {
                write(1, &str[i], 1);
                count--;
            }
        i++;
        }
}
int main(int argc, char **argv)
{
    if(argc == 2)
        repeat_alpha(argv[1]);
    write(1, "\n", 1);
    return (0);
}



