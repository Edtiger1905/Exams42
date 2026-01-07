/* sub: fare una funzione che determina se il numero dato e' una potenza di 2
la funzione ritorna 1 se il numero e' potenza di 2,senno' ritorna 0 */

#include <unistd.h>

int     is_power_of_2(unsigned int n)
{
/* 1. se il numero è 0, non è una potenza di 2 */
    if (n == 0)
        return (0);
/* 2. continua a dividere il numero per 2 finché non raggiunge 1 */
/* 3. se il numero non è divisibile per 2, non è una potenza di 2
e ritorna 0 */
    while (n > 1)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
        return (0);
    }
/* 4. se e' divisibile per 2, ritorna 1 */
    return (1);
}