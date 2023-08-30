/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:17:33 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/01 17:17:33 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
    while (*str != '\0')
    {
        write(1, *&str, 1);
        *str++;
    }
    write(1, "\n", 1);
}

// int main()
// {
//     char    *str = "this is a sentence";
//     ft_putstr(str);
//     return 0;
// }
