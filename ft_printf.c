/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:25:21 by ssettle           #+#    #+#             */
/*   Updated: 2019/04/29 10:39:58 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//that one due had ... as a way to handle multiple formal parameters that havent been made yet

int	ft_printf(char *format, ...)
{
	int		count;
	va_list	ap;  //

	count = 0;
	va_start(ap, format); //va_start????
	while (*format != '\0')
	{
		//if (is_normal(*format))
		//{
			//dispatch_normal(&str);
			//count++;
		//}
		//else
		//	count += dispatch_flagged(&format, ap, 0);
	}
	va_end(ap);
	return(count);
}
