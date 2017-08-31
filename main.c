#include <string.h>
#include <libftasm.h>
#include <stdio.h>
#include <ctype.h>

void	t_bzero()
{
	char mine1[240] = "coucou1234";
	char mine2[240] = "coucou1234";
	char mine3[240] = "coucou1234";

	char sys1[240] = "coucou1234";
	char sys2[240] = "coucou1234";
	char sys3[240] = "coucou1234";

	ft_bzero((void*)mine1, sizeof("coucou1234"));
	ft_bzero((void*)mine2 + 3, 1);
	ft_bzero((void*)mine3, 0);

	bzero((void*)sys1, sizeof("coucou1234"));
	bzero((void*)sys2 + 3, 1);
	bzero((void*)sys3, 0);

	if ((memcmp(mine1, sys1, sizeof(sys1)) != 0) ||
				memcmp(mine2, sys2, sizeof(sys2)) != 0 ||
				memcmp(mine3, sys3, sizeof(sys3)) != 0)
		printf("\e[38;5;1mERROR\e[39m while testing ft_bzero.\n");
	else
		printf("\e[38;5;2mSUCCESS\e[39m while testing ft_bzero\n");
}

void	t_strcat()
{
	char mine1[240] = "coucou";
	char mine2[240] = "coucou";
	char mine3[240] = "";

	char sys1[240] = "coucou";
	char sys2[240] = "coucou";
	char sys3[240] = "";

	if (ft_strcat(mine1, "123") != mine1)
	{
		printf("\e[38;5;1mERROR\e[39m while testing ft_strcat(first tests).\n");
		return;
	}
	if (ft_strcat(mine2, "") != mine2)
	{
		printf("\e[38;5;1mERROR\e[39m while testing ft_strcat.(first tests)\n");
		return;
	}
	if (ft_strcat(mine3, "123") != mine3)
	{
		printf("\e[38;5;1mERROR\e[39m while testing ft_strcat.(first tests)\n");
		return;
	}

	strcat(sys1, "123");
	strcat(sys2, "");
	strcat(sys3, "123");

	if ((memcmp(mine1, sys1, strlen(sys1)) != 0) ||
				(memcmp(mine2, sys2, strlen(sys2)) != 0) ||
				(memcmp(mine3, sys3, strlen(sys3)) != 0))
		printf("\e[38;5;1mERROR\e[39m while testing ft_strcat.\n");
	else
		printf("\e[38;5;2mSUCCESS\e[39m while testing ft_strcat\n");
}

void	t_isalpha()
{
	int i = -100;
	while (i < 300)
	{
		if (ft_isalpha(i) != isalpha(i))
		{
			printf("\e[38;5;1mERROR\e[39m while testing ft_isalpha.\n");
			return ;
		}
		i++;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_isalpha\n");
}

void	t_isdigit()
{
	int i = -100;
	while (i < 300)
	{
		if (ft_isdigit(i) != isdigit(i))
		{
			printf("\e[38;5;1mERROR\e[39m while testing ft_isdigit.\n");
			return ;
		}
		i++;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_isdigit\n");
}

void	t_isalnum()
{
	int i = -100;
	while (i < 300)
	{
		if (ft_isalnum(i) != isalnum(i))
		{
			printf("\e[38;5;1mERROR\e[39m while testing ft_isalnum.\n");
			return ;
		}
		i++;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_isalnum\n");
}

void	t_isascii()
{
	int i = -100;
	while (i < 300)
	{
		if (ft_isascii(i) != isascii(i))
		{
			printf("\e[38;5;1mERROR\e[39m while testing ft_isascii.\n");
			return ;
		}
		i++;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_isascii\n");
}

void	t_isprint()
{
	int i = -100;
	while (i < 300)
	{
		if (ft_isprint(i) != isprint(i))
		{
			printf("\e[38;5;1mERROR\e[39m while testing ft_isprint\n");
			return ;
		}
		i++;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_isprint\n");
}

void	t_toupper()
{
	int i = -100;
	while (i < 300)
	{
		if (ft_toupper(i) != toupper(i))
		{
			printf("\e[38;5;1mERROR\e[39m while testing ft_toupper\n");
			return ;
		}
		i++;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_toupper\n");
}

void	t_tolower()
{
	int i = -100;
	while (i < 300)
	{
		if (ft_tolower(i) != tolower(i))
		{
			printf("\e[38;5;1mERROR\e[39m while testing ft_tolower\n");
			return ;
		}
		i++;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_tolower\n");
}

void	t_strlen()
{
	if ((ft_strlen("") != strlen("")) ||
				(ft_strlen("ABC") != strlen("ABC")))
	{
		printf("\e[38;5;1mERROR\e[39m while testing ft_strlen\n");
		return ;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_strlen\n");
}


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_bzero();
	t_strcat();
	t_isalpha();
	t_isdigit();
	t_isalnum();
	t_isascii();
	t_isprint();
	t_toupper();
	t_tolower();

	ft_puts("coucou !");
	puts("coucou !");

	ft_puts("");
	puts("");

	t_strlen();
}
