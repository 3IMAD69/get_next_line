/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:30:07 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/21 09:30:11 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *s)
{
	char	*str;
	int		size;

	size = ft_strlen(s);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (0);
	str[size] = '\0';
	while (size--)
		str[size] = s[size];
	return (str);
}