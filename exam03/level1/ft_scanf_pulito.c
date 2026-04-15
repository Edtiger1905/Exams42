#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

static void skip_space(FILE *f)
{
    int c;
    while((c = fgetc(f)) != EOF && isspace(c))
    {
        if(c != EOF)
            ungetc(c, f);

    }
}
static int scan_char(FILE *f, va_list ap)
{
    int c;
    char *dest;

    c = fgetc(f);
    if(c == EOF)
    {
        if(ferror(f))
            return -1;
        else
            return 0;
    }
    dest = va_arg(ap, char *);
    *dest = (char)c;
    return 1;
}
static int scan_int(FILE *f, va_list ap)
{
    int c;
    int sign;
    int value;
    int digits;
    int *dest;

    sign = 1;
    value = 0;
    digits = 0;
    c = fgetc(f);
    if(c == EOF)
    {
        if(ferror(f))
            return(-1);
        else
            return(0);
    }
    if(c == '+' || c == '-')
    {
        if(c == '-')
            sign = -1;
    }
    else
        ungetc(c, f);
    while(isdigit(c = fgetc(f)))
    {
        value = value * 10 + (c - '0');
        digits++;
    }
    if(c != EOF)
        ungetc(c, f);
    if(ferror(f) || !digits)
    {
        if(ferror(f))
            return (-1);
        else
            return (0);
    }
    dest = va_arg(ap, int *);
    *dest = value * sign;
    return (1);
}
static int scan_string(FILE *f, va_list ap)
{
    int c;
    int n;
    char *s;

    n = 0;
    s = va_arg(ap, char *);
    while((c = fgetc(f)) != EOF && !isspace(c))
    {
        *s = (char)c;
        s++;
        n++;
    }
    if(c != EOF)
        ugetc(c, f);
    if(ferror(f) || !n)
    {
        if(ferror(f))
            return (-1);
        else
            return (0);
    }
    *s = '\0';
    return (1);
}
int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
    int nconv;
    int c;
    int ret;

    nconv = 0;
    c = fgetc(f);
    if(c == EOF)
        return (EOF);
    ungetc(c, f);
    while(*format)
    {
        if(format == '%')
        {
            format++;
            if(*format == 'd' || *format == 's')
                skip_space(f);
            if(*format == 'c')
                ret = scan_char(f, ap);
            else if(*format == 'd')
                ret = scan_int(f, ap);
            else if(*format == 's')
                ret = scan_string(f, ap);
            else
                break;
            if(ret != 1)
                break;
            nconv++;
        }
        else if(isspace(*format))
            skip_space(f);
        else
        {
            c = fgetc(f);
            if(c != *format)
            {
                if(c != EOF)
                    ungetc(c, f);
                break;
            }
        }
        format++;
    }
    if(ferror(f))
        return (EOF);
    else
        return (nconv);
}
int ft_scanf(const char *format, ...)
{
    va_list ap;
    int ret;

    va_start(ap, format);
    ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return (ret);
}
