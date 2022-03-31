int check_double(char *str, char c , int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void ft_inter(char *str, char *str1)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str1[j])
		{
			if (str[i] == str1[j])
			{
				if (check_double(str, str[i], i))
				{
					write(1, &str[i], 1);
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_inter(av[1],av[2]);
	}
}