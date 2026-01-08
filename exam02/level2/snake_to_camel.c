/* sub:  prendere una stringa nel formato snake_case e trasformarlo
in quello lowerCamelCase*/
#include <unistd.h>

int main(int ac,char **av)
{
   int i;

   i = 0;
   if(ac == 2)
   {
    /* ciclo di elaborazione della stringa:
    -ciclo per mandare avanti la stringa fino al null terminator
    -controlla se c'e' il '_',se lo trova manda avanti la stringa 
    per saltare il '_' e converte in ascii la lettera da minuscola
    a maiuscola
    -scrive la stringa modificata carattere per carattere
    */
    while(av[1][i] != '\0')
    {
        if(av[1][i] == '_')
        {
            i++;
            av[1][i] = av[1][i] - 32;
        }
        write(1, &av[1][i], 1);
        i++;
    }
   }
   write(1, "\n", 1);
}