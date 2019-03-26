/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 03:56:40 by ikourkji          #+#    #+#             */
/*   Updated: 2019/02/21 21:54:55 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*not_numbers(long double n, int up)
{
	char	*ret;

	if (!(ret = ft_strnew(3)))
		return (0);
	if (ft_isnan(n))
	{
		ret[0] = (up) ? 'N' : 'n';
		ret[1] = (up) ? 'A' : 'a';
		ret[2] = (up) ? 'N' : 'n';
		return (ret);
	}
	ret[0] = (up) ? 'I' : 'i';
	ret[1] = (up) ? 'N' : 'n';
	ret[2] = (up) ? 'F' : 'f';
	return (ret);
}

static int	cheap_pow(int val, int pow)
{
	int	ret;

	ret = 1;
	while (pow-- > 0)
		ret *= val;
	return (ret);
}

/*
** static int	round_up(int n)
** {
** 	int	tmp;
** 	int	flag;
**
** 	tmp = n / 10;
** 	flag = 0;
** 	if (n % 10 == 9 && tmp % 10 == 9)
** 		flag = 1;
** 	n += flag;
** 	n /= 100;
** 	if (tmp % 10 > 4 && !flag)
** 		n++;
** 	return (n);
** }
*/

static void	place_dec(int i, char *ret, int dec)
{
	while (i > -1)
	{
		ret[i--] = (dec % 10) + '0';
		dec /= 10;
	}
}

/*
** i is uintmax to chop for dlen
*/

static char	*ftoa(long double f, int prec, int dot)
{
	uintmax_t	dec;
	uintmax_t	frac;
	char		*ret;
	int			dlen;
	uintmax_t	i;

	dec = f;
	frac = prec ? (f - dec) * cheap_pow(10, prec) + 0.5 : 0;
	dec += ((f - dec) * 10 > 4 && !frac) ? 1 : 0;
	i = dec;
	dlen = 1;
	while (i > 9 && dlen++)
		i /= 10;
	if (!(ret = ft_strnew(dlen + prec + 1)))
		return (0);
	place_dec(dlen - 1, ret, dec);
	(frac || dot) ? ret[dlen++] = '.' : 0;
	i = dlen + prec - 1;
	while (i > (unsigned)dlen - 1)
	{
		ret[i--] = frac ? (frac % 10) + '0' : '0';
		frac /= 10;
	}
	return (ret);
}

/*
** The method above *works*, but for small input. (small here meaning int-size)
** What floats are good for is very large or very small numbers.
** We're unlikely to be printing at that scale, but if we were?
** This is a bad solution. An int won't be able to store the number.
** For a better solution, see Grisu for something fast and less inaccurate
** https://www.cs.tufts.edu/~nr/cs257/archive/florian-loitsch/printf.pdf
** https://github.com/google/double-conversion/blob/master/
** double-conversion/fast-dtoa.cc
** or Dragon4 for something slower but least inaccurate
** http://kurtstephens.com/files/p372-steele.pdf
** optimization by Gay: https://ampl.com/REFS/rounding.pdf
** See Ryan Jucket's blog for a pretty good explanation of the whys
** http://www.ryanjuckett.com/programming/printing-floating-point-numbers/
*/

void		pf_float(t_vars *v)
{
	long double	f;
	char		*str;
	int			ng;

	f = (v->flags & F_LL) ? va_arg(v->args, long double) :\
		(double)va_arg(v->args, double);
	(v->prec == 0 && !(v->flags & F_PREC)) ? v->prec = 6 : 0;
	ng = (f < 0) ? -1 : 1;
	f *= ng;
	if (!(str = (ft_isnan(f) || ft_isinf(f)) ? not_numbers(f, v->flags & F_UP)\
				: ftoa(f, v->prec, v->flags & F_CONV)))
		return ;
	v->clen = ft_strlen(str);
	v->pad = v->min - v->clen;
	(ng == -1 || v->flags & F_SIGN || v->flags & F_BLANK) ? v->pad -= 1 : 0;
	while (!(v->flags & F_RPAD) && v->pad-- > 0)
		pf_placechar(v, ' ');
	(ng == -1) ? pf_placechar(v, '-') : 0;
	if ((v->flags & F_SIGN || v->flags & F_BLANK) && ng != -1)
		v->flags & F_SIGN ? pf_placechar(v, '+') : pf_placechar(v, ' ');
	while (*str)
		pf_placechar(v, *str++);
	while (v->pad-- > 0)
		pf_placechar(v, ' ');
	free(str - v->clen);
}
