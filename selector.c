#include <stdarg.h>
#include <unistd.h>
#include "main.h" 

/**
 * selector - Handles format specifiers
 * @format: The format specifier
 * @args: Variable arguments
 * @printed: Current count of printed characters
 *
 * Return: Updated count of printed characters
 */
int selector(const char *format, va_list args, int printed)
{
    switch (*format)
    {
        case 'c':
            _putchar(va_arg(args, int));
            printed++;
            break;
        case 's':
            {
                const char *str = va_arg(args, const char *);
                while (*str)
                {
                    _putchar(*str);
                    printed++;
                    str++;
                }
            }
            break;
        case '%':
            _putchar('%');
            printed++;
            break;
        default:
            _putchar('%');
            _putchar(*format);
            printed += 2;
    }
    return printed;
}

