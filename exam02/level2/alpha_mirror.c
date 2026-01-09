
#include <unistd.h>

// Spiegazione:
// La funzione alpha_mirror trasforma ogni lettera in quella "speculare"
// rispetto all'alfabeto. Per ogni carattere della stringa:
// - se è una minuscola 'a'..'z': calcola mirror = 'z' - (c - 'a')
//   (es. 'a' -> 'z', 'b' -> 'y', ..., 'z' -> 'a').
// - se è una maiuscola 'A'..'Z': calcola mirror = 'Z' - (c - 'A')
//   (es. 'A' -> 'Z', 'B' -> 'Y', ..., 'Z' -> 'A').
// - altrimenti il carattere rimane invariato.
// Scrive ogni carattere risultante con write(1, ...).
// Il ciclo termina quando incontra il terminatore '\0'.
void alpha_mirror(char *str)
{
    char mirror;
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            mirror = 'z' - (str[i] - 'a');
        else if (str[i] >= 'A' && str[i] <= 'Z')
            mirror = 'Z' - (str[i] - 'A');
        else
            mirror = str[i];
        write(1, &mirror, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        alpha_mirror(argv[1]);
    write(1, "\n", 1);
    return (0);
}