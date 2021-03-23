main()
{
	int a, b, i, t, n;

	a = 1;
	b = 1;
	i = 2;
	input(n);
	print(a);
	print(b);
	while (i < n)
	{
		t = b;
		b = a + b;
		print(b);
		a = t;
		i = i + 1;
	}
	/*int a,i;
	a=9;
	for(i=0;i<a;i++)
	{
		print(i);
	}*/
}
