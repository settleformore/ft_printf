/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssettle <ssettle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:33:44 by ssettle           #+#    #+#             */
/*   Updated: 2019/09/07 17:11:18 by ssettle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Conversion for i and d. Really only has a difference if you are using scanf.
*/

char		*prec(t_opts options, char *str)
{
	char *new_str;
	int len;
    int z_len;
	int new_len;

	new_str = pf_strdup(str);
	len = pf_strlen(str);
    z_len = options.precision;
	new_str[z_len] = '\0';
	if (options.precision > len)
    {
		pf_memset(new_str, '0', z_len);
		new_len = z_len - len;
        pf_strncpy(&new_str[new_len], str, len);
    }
	free(str);
	return(new_str);
}

char    *pf_append_int(char *subject, char *insert, int pos) // never used
{
    char    *new_str;
    char    *buf;
    int     len;
    
    buf = pf_strnew(pf_strlen(subject));
    pf_strncpy(buf, subject, pos); 
    len = pf_strlen(buf);
    pf_strcpy(buf + len, insert);
    len += pf_strlen(insert);
    pf_strcpy(buf + len, subject + pos);
    new_str = pf_strcpy(subject, buf);
	free(subject);
    return(new_str);
}

char    *padding_nbr(t_opts options, char *str)
{
    int     wd_len;
    int     len;
    int     new_len;
    char    *new_str;
	
    new_len = 0;
    len = pf_strlen(str);
    wd_len = options.width_field;
    new_str = pf_strdup(str);
    pf_memset(new_str, ' ', wd_len);
    new_str[wd_len] = '\0';
    wd_len = options.flags.plus ? wd_len - 1 : wd_len;
    if (options.flags.zero >= 1)
        pf_memset(new_str, '0', wd_len);    
    if (options.flags.minus >= 1)
        pf_strncpy(new_str, str, len);
    else
        new_len = wd_len - len;
        pf_strncpy(&new_str[new_len], str, len);
	free(str);
    return(new_str);
}

void	pf_putnbr(int n)
{
	if (n == -2147483648)
	{
		pf_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = -n;
		pf_putchar('-');
	}
	if (n >= 10)
	{
		pf_putnbr(n / 10);
		pf_putnbr(n % 10);
	}
	else
		pf_putchar(n + 48);
}

int     convert_int(t_opts options, va_list ap)
{
    char        *str;
	// char		*new_str;
    int         len;
    int32_t     num;

    num = options.content_size > 0 ? va_arg(ap, int64_t) : va_arg(ap, int32_t);
    str = options.content_size > 0 ? 
        pf_itoa_l(num) : pf_itoa(num);
    len = pf_strlen(str);
    if (options.precision > len)
		str = prec(options, str);
    if (options.width_field > len)
        str  = padding_nbr(options, str);
    if (options.flags.plus == 1 && num > 0)
        pf_append(str, "+", 0);
	else if (options.flags.space == 1 && num > 0)
		str = pf_append(str, " ", 0);
    // num < 0 ?  pf_putstr(pf_append(str, "-", 0)) : 
    pf_putstr(str);
    len = pf_strlen(str);
    free(str);
    return(len);
}