#include <unistd.h>
#include <stdlib.h>

// Calcola quanti caratteri occorrono per rappresentare la stringa di input
// in snake_case (senza contare il terminatore).
// Regola: ogni carattere conta 1; se si incontra una maiuscola non in posizione 0,
// serve un carattere in più per inserire il '_' prima della lettera convertita.
int snake_len(char *str)
{
    int len; //
    int i;

    len = 0;
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z' && i != 0)
            len++;
        len++;
        i++;
    }
    return (len);
}

// Converte una stringa CamelCase in snake_case allocando e restituendo
// una nuova stringa. Per ogni maiuscola (eccetto la prima) inserisce '_'
// e la corrispondente minuscola; copia gli altri caratteri invariati.
// Nota: la funzione alloca memoria che il chiamante deve liberare.
char *camel_to_snake(char *str)
{
    char *snake;
    int len;
    int i;
    int j;

    len = snake_len(str);
    snake = (char *)malloc(len + 1);
    i = 0;
    j = 0;
    while(j <= len)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (i != 0)
                snake[j++] = '_';
            snake[j] = str[i] + 32;
        }
        else
            snake[j] = str[i];
        j++;
        i++;
    }
    snake[j] = '\0';
    return (snake);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int len;
        char *out;

        len = snake_len(av[1]);
        out = camel_to_snake(av[1]);
        write(1, out, len);
        free(out); /* libera la memoria allocata da camel_to_snake */
    }
    write(1, "\n", 1);
    return (0);
}