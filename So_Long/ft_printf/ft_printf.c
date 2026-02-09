/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:36:48 by romain            #+#    #+#             */
/*   Updated: 2024/06/15 09:57:46 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			value;
	va_list		args;

	if (!str)
		return (-1);
	i = 0;
	value = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			value = value + ft_types(str[++i], args);
		else
			value = value + ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (value);
}

int	ft_types(char c, va_list args)
{
	int	type;

	type = 0;
	if (c == 'c')
		type = ft_print_char(va_arg(args, int));
	else if (c == 's')
		type = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		type = ft_print_ptr(va_arg(args, unsigned long));
	else if ((c == 'd') || (c == 'i'))
		type = ft_print_int(va_arg(args, int));
	else if (c == 'u')
		type = ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (c == 'x')
		type = ft_print_hexa_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		type = ft_print_hexa_upper(va_arg(args, unsigned int));
	else if (c == '%')
		type = ft_print_char('%');
	return (type);
}

/* int	main(void)
{
	int	printed_chars;

	printed_chars = ft_printf("Hello, %s!\n", "world");
	printf("Printed characters: %d\n", printed_chars);
	ft_printf("Ft_Printedcharacters: %d\n\n", printed_chars);

	printed_chars = ft_printf("Character: %c\n", 'A');
	printf("Printed characters: %d\n", printed_chars);
	ft_printf("Ft_Printed characters: %d\n\n", printed_chars);

	printed_chars = ft_printf("Integer: %d\n", 12345);
	ft_printf("Printed characters: %d\n", printed_chars);
	ft_printf("Ft_Printed characters: %d\n\n", printed_chars);

	printed_chars = ft_printf("Unsigned Integer: %u\n", 12345);
	printf("Printed characters: %d\n", printed_chars);
	ft_printf("Ft_Printed characters: %d\n\n", printed_chars);

	printed_chars = ft_printf("Hex Lower: %x\n", 255);
	printf("Printed characters: %d\n", printed_chars);
	ft_printf("Ft_Printed characters: %d\n\n", printed_chars);

	printed_chars = ft_printf("Hex Upper: %X\n", 255);
	printf("Printed characters: %d\n", printed_chars);
	ft_printf("Ft_Printed characters: %d\n\n", printed_chars);

	printed_chars = ft_printf("Pointer: %p\n", (void*)0x12345678);
	printf("Printed characters: %d\n", printed_chars);
	ft_printf("Ft_Printed characters: %d\n\n", printed_chars);

	printed_chars = ft_printf("Percentage: %%\n");
	printf("Printed characters: %d\n", printed_chars);
	ft_printf("Ft_Printed characters: %d\n\n", printed_chars);

	return (0);
} */
