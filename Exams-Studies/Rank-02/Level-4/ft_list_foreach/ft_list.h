/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:50:01 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/27 12:50:01 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef	struct s_list
{
	struct s_list	*next;
	void			*data;

}					t_list;
