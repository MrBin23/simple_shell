#include "shell.h"
/**
 * _fputs - prints string in a file descriptor
 * @fd: file descriptor
 * @str: string to be printed
 * Return: print char length
 */
int _fputs(int fd, const char *str)
{
	return (write(fd, str, _strlen(str)));
}

/**
 * fputs_num - prints a number in a file
 * @fd: file descriptor
 * @num: number to be printed
 * Return: character printed length
 */
int fputs_num(int fd, int num)
{
	int prints;

	prints = 0;
	if (!num)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		prints = 1;
		num *= -1;
	}
	return (prints + fputs_num_help(fd, num));
}

/**
 * _fprint - prints numbers and strings using format specifier
 * @fd: file descriptor
 * @format: format specifier
 * @...: multiple arguments
 * Return: number to be printed
 */
int _fprint(int fd, const char *format, ...)
{
	va_list my_args;
	int indx, prints, is_cent;

	va_start(my_args, format);
	indx = 0;
	prints = 0;
	is_cent = 0;

	while (format[indx])
	{
		if (format[indx] == '%')
			is_cent = 1;
		else
		{
			if (is_cent)
			{
				if (format[indx] == 'd')
					prints = prints + fput_num(fd, va_arg(my_args, int));
				else if (format[indx] == 's')
					prints = prints + _fput(fd, va_arg(my_args, char));
				else
					prints = prints + write(fd, format[indx - 1], 2);
			}
			else
				prints = prints + write(fd, format + indx, 1);
			is_cent = 0;
		}
		indx++;
	}
	va_end(my_args);
	return (prints);
}

/**
 * fputs_num_help - helps in printing number
 * @fd: file descriptor
 * @num: number to be printed
 * Return: number of digits printed
 */
int fputs_num_help(int fd, int num)
{
	int div;
	char ch;

	if (num == 0)
		return (0);

	div = fputs_num_help(fd, num / 10);
	ch = num % 10 + 48;
	write(fd, &ch, 1);
	return (1 + div);
}
