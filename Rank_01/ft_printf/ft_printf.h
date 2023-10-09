/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:55:27 by crebelo-          #+#    #+#             */
/*   Updated: 2023/05/04 13:55:27 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

void	ft_putchar_fd(char c, int fd, size_t *len);
void	ft_putnbr_fd(int n, int fd, size_t *len);
void	ft_putnbr_hex(unsigned int n, char *base, size_t *len);
void	ft_putstr_fd(char *s, int fd, size_t *len);
void	ft_putptr_hex(void *ptr, char *base, size_t *len);
void	ft_put_hex(unsigned long n, char *base, size_t *len);
void	ft_putunbr(unsigned int n, size_t *len);
size_t	ft_strlen(const char *s);

#endif