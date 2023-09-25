void	error_exit()
{
	write(1, "Error\n", 6);
}

int	valid_av(char **av, int size)
{
	int	i = 1;
	
	while(i < size)
	{
		
		printf("av0 %s\n", *av);
		if(is_digit(av[i]) != 0)
		{
			printf("returning 1");
			return (1);	
		}
		i++;
	}
	return (0);
}
int is_digit(char *av)
{
	int i = 0;
	while(av[i] != '\0')
	{
		printf("av0 %s\n", &av[i]);
		if (av[i] >= '0' && av[i] <= '9')
		{
			printf("iter");
			i++;
		}	
		else
			return (1);
	}
	return (0);
}

int main(int ac, char *av[])
{
	if (ac < 2 || valid_av(av, ac) != 0)
		error_exit();
	
	return (0);	
}