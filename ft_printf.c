/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchalak <rchalak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:51:15 by rchalak           #+#    #+#             */
/*   Updated: 2024/06/20 18:12:13 by rchalak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
int	ft_putnbr_fd(int n, int fd)
{
	const char	*s;

	s = "-2147483648" ;
	if (n == -2147483648)
		ft_putstr_fd((char *) s, fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int check_format(char variadic, va_list list)
{
    if(variadic == 'c')
      ft_putchar_fd(va_arg(list, int),1);  
    else if(variadic == 's')
     ft_putstr_fd(va_arg(list, char*),1);
    // else if(variadic == 'p')
    
    else if(variadic == 'd')
    ft_putnbr_fd(va_arg(list, int), 1);
    // else if(variadic == 'i')
        
    // else if(variadic == 'u')
    
    // else if(variadic == 'x')
    
    // else if(variadic == 'X')

    // else if(variadic == '%')

}
int ft_printf(const char *format, ...)
{
    va_list list;
    int count;
    va_start(list,format);
    count = 0;
    while(*format)
    {
        if(*format == '%')
           count+= check_format(*(++format), list);
        else
        count+= write(1, format, 1);
        ++format;
    }
}
int main() {
  char *str = "Hello, world!"; // Test string
    int num = 123; // Test integer

    printf("Testing printf:\n");
    printf("String: %s\n", str); // Standard printf
    printf("Integer: %d\n", num); // Standard printf

    printf("\nTesting ft_printf:\n");
    ft_printf("String: %s\n", str); // Custom ft_printf implementation
    ft_printf("Integer: %d\n", num); 
}