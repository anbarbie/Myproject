/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbarbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:33:15 by antbarbi          #+#    #+#             */
/*   Updated: 2018/08/16 20:00:09 by antbarbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		assign_malloc(int res, int end, char *nbr)
{
	int	i;

	i = 0;
	while (res > 0)
	{
		res = res / end;
		i++;
	}
	if (nbr[0] == '-')
		i += 2;
	else
		i += 1;
	return (i);
}

char	*rev_tab(char *tab)
{
	int		i;
	char	tmp;
	int		j;

	if (tab[0] == '-')
		i = 1;
	else
		i = 0;
	j = ft_strlen(tab) - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
	return (tab);
}

int		mini_atoi(int res, char *nbr, int start)
{
	int i;

	if (nbr[0] == '-')
		i = 1;
	else
		i = 0;
	while (nbr[i] != '\0')
	{
		res = res * start + (nbr[i] - 48);
		i++;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*tab;
	int		i;
	int		res;

	res = 0;
	res = mini_atoi(res, nbr, ft_strlen(base_from));
	tab = (char *)malloc(sizeof(char) *
			assign_malloc(res, ft_strlen(base_to), nbr));
	if (nbr[0] == '-')
	{
		tab[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (res > 0)
	{
		tab[i] = base_to[res % ft_strlen(base_to)];
		res = res / ft_strlen(base_to);
		i++;
	}
	tab[i] = '\0';
	return (rev_tab(tab));
}
