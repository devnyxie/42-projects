void sort_int_tab(int *tab, unsigned int size)
{
	int i;
	int	swap;
	
	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + ])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}