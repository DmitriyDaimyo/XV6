/sieve of eratosthenes with threads

#include <user/user.h>


void func(int p)
{
	int buf[2];
	int a;
	int floor;
	read(p, &a, 4);
	printf("prime %d\n", a);
	floor = a;
	read(p, &a, 4);
	if (a == 0)
		exit(0);
	pipe(buf);
	if (fork() == 0)
	{
		close(buf[1]);
		func(buf[0]);
	}
	close(buf[0]);
	write(buf[1], &a, 4);
	while (1)
	{
		read(p, &a, 4);
		if (a == 0)
		{
			write(buf[1], &a, 4);
			wait((int *) 0);
			exit(0);
		}
		if (a % floor)
			write(buf[1], &a, 4);
	}
}

int main()
{
	int stop = 0;
	int n = 35;
	int buf[2];
	printf("prime %d\n", 2);
	pipe(buf);
	if (fork() == 0)
		func(buf[0]);
	for (int i = 3; i <= n; i++)
		if (i % 2)
		{
			write(buf[1], &i, 4);
		}
	write(buf[1], &stop, 4);
	wait((int *) 0);
	exit(0);
}
