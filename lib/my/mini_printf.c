/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** mini_printf
*/

#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);

void help_print(const char *format, int a, va_list list)
{
    if (format[a] == 'd' || format[a] == 'i') {
        my_put_nbr(va_arg(list, int));
    }

    if (format[a] == 'c'){
        my_putchar(va_arg(list, int));
    }

    if (format[a] == 's'){
        my_putstr(va_arg(list, char *));
    }

    if (format[a] == '%'){
        my_putchar('%');
    }
}

int mini_printf(const char *format, ...)
{
    int a = 0;
    va_list list;
    va_start(list, format);
    while (format[a] != '\0') {
        if (format[a] == '%') {
            a = a + 1;
            help_print(format, a, list);
        } else {
            my_putchar(format[a]);
        }
        a = a + 1;
    }
    va_end(list);
    return (0);
}
