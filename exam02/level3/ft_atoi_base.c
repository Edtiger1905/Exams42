/* sub: creare una funzione che converte gli argomenti delle
stringhe(base N <= 16) in interi (base 10) e li ritorna.
 */

/* 1. funzione di supporto: conversione carattere -> cifra.
converte un carattere valido nella sua cifra numerica in 
base 'digits_in_base'. Ritorna -1 se non valido. */
int get_digit(char c, int digits_in_base)
{
    int max_digit;
    if(digits_in_base <= 10)
        max_digit = digits_in_base + '0';
    else
        max_digit = digits_in_base - 10 + 'a';
    if(c >= '0' && c <= '9' && c <= max_digit)
        return (c - '0');
    else if(c >= 'a' && c <= 'f' && c <= max_digit)
        return (10 + c - 'a');
    else if(c >= 'A' && c <= 'F' && c <= max_digit)
        return (10 + c - 'A');
    else
        return (-1);
}
/* 2. Funzione principale: converte una stringa che
rappresenta un numero in una base arbitraria 
(fino a base 16) in intero. */
int ft_atoi_base(const char *str, int str_base)
{
    int result;
    int sign;
    int digit;

    result = 0;
    sign = 1;
    /* 3. Gestione del segno */
    if(*str == '-')
    {
        sign = -1;
        ++str;
    }
    /* 4. conversione del numero: legge i caratteri 
    validi, li converte e costruisce il risultato finale. */
    digit = get_digit(*str, str_base);
    while(digit >= 0)
    {
        result = result * str_base;
        result = result + (digit * sign);
        ++str;
    }
    return (result);
} 