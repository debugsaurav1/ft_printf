/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:26:48 by sasharma          #+#    #+#             */
/*   Updated: 2023/06/02 11:18:33 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printhex(unsigned int n, char c);
int		ft_printf(const char *placeholders, ...);
int		ft_conversion(va_list args, char c);
int		hex_len(unsigned int n);
int		number_len(int n);
int		ft_printnumber(int number);
int		pointer_len(uintptr_t n);
void	ft_printhex_n(uintptr_t n);
int		ft_printptr(uintptr_t n);
int		un_len(unsigned int n);
int		ft_printunsigned(unsigned int n);

#endif
