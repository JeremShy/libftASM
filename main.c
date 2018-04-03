#include <string.h>
#include <libftasm.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

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

void	t_memset()
{
	char mine1[12];
	char mine2[12];
	char mine3[12];
	char mine4[12];

	char sys1[12];
	char sys2[12];
	char sys3[12];
	char sys4[12];

	bzero(mine1, sizeof(mine1));
	bzero(mine2, sizeof(mine2));
	bzero(mine3, sizeof(mine3));
	bzero(mine4, sizeof(mine4));

	bzero(sys1, sizeof(sys1));
	bzero(sys2, sizeof(sys2));
	bzero(sys3, sizeof(sys3));
	bzero(sys4, sizeof(sys4));

	if ((memcmp(ft_memset(mine1, 'a', sizeof(sys1)), memset(sys1, 'a', sizeof(sys1)), sizeof(sys1)) != 0) ||
				(memcmp(ft_memset(mine2, 0, sizeof(sys2)), memset(sys2, 0, sizeof(sys2)), sizeof(sys2)) != 0) ||
				(memcmp(ft_memset(mine3, 3, 0), memset(sys3, 3, 0), sizeof(sys3)) != 0) ||
				(memcmp(ft_memset(mine4, 1, 4), memset(sys4, 1, 4), sizeof(sys4)) != 0))
	{
		printf("\e[38;5;1mERROR\e[39m while testing ft_memset\n");
		return ;
	}
	if ((memcmp(mine1, sys1, sizeof(sys1)) != 0) ||
				(memcmp(mine2, sys2, sizeof(sys2)) != 0) ||
				(memcmp(mine3, sys3, sizeof(sys3)) != 0) ||
				(memcmp(mine4, sys4, sizeof(sys4)) != 0))
	{
		printf("\e[38;5;1mERROR\e[39m while testing ft_memset\n");
		return ;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_memset\n");
}

void	t_memcpy()
{
	char mine1[12];
	char mine2[12];
	char mine3[12];
	char mine4[12];

	char sys1[12];
	char sys2[12];
	char sys3[12];
	char sys4[12];

	bzero(mine1, sizeof(mine1));
	bzero(mine2, sizeof(mine2));
	bzero(mine3, sizeof(mine3));
	bzero(mine4, sizeof(mine4));

	bzero(sys1, sizeof(sys1));
	bzero(sys2, sizeof(sys2));
	bzero(sys3, sizeof(sys3));
	bzero(sys4, sizeof(sys4));

	if ((memcmp(ft_memcpy(mine1, "123456", sizeof("123456")), memcpy(sys1, "123456", sizeof("123456")), sizeof(sys1)) != 0) ||
				(memcmp(ft_memcpy(mine2, "", sizeof("")), memcpy(sys2, "", sizeof("")), sizeof(sys2)) != 0) ||
				(memcmp(ft_memcpy(mine3, "caca", 2), memcpy(sys3, "caca", 2), sizeof(sys3)) != 0) ||
				(memcmp(ft_memcpy(mine4, "creepymama", sizeof("creepymama")), memcpy(sys4, "creepymama", sizeof("creepymama")), sizeof(sys4)) != 0))
	{
		printf("\e[38;5;1mERROR\e[39m while testing ft_memcpy\n");
		return ;
	}
	if ((memcmp(mine1, sys1, sizeof(sys1)) != 0) ||
				(memcmp(mine2, sys2, sizeof(sys2)) != 0) ||
				(memcmp(mine3, sys3, sizeof(sys3)) != 0) ||
				(memcmp(mine4, sys4, sizeof(sys4)) != 0))
	{
		printf("\e[38;5;1mERROR\e[39m while testing ft_memcpy\n");
		return ;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_memcpy\n");
}

void	t_strdup()
{
	if ((memcmp(ft_strdup("pouetpouet"), strdup("pouetpouet"), sizeof("pouetpouet"))) ||
				(memcmp(ft_strdup(""), strdup(""), sizeof(""))) ||
				(memcmp(ft_strdup("a"), strdup("a"), sizeof("a"))) ||
				(memcmp(ft_strdup("blblblblbl"), strdup("blblblblbl"), sizeof("blblblblbl"))))
	{
		printf("ft_strdupgnagna - %s\n", ft_strdup("pouetpouet"));
		printf("\e[38;5;1mERROR\e[39m while testing ft_strdup\n");
		return ;
	}
	printf("\e[38;5;2mSUCCESS\e[39m while testing ft_strdup\n");
}
//
// void	t_cat()
// {
// 	char	buf[6];
// 	int	r;
//
// 	while ((r = read(0, buf, 5)) > 0)
// 	{
// 		write(1, buf, r);
// 	}
// }


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// t_bzero();
	// t_strcat();
	// t_isalpha();
	// t_isdigit();
	// t_isalnum();
	// t_isascii();
	// t_isprint();
	// t_toupper();
	// t_tolower();
	//
	// ft_puts("coucou !");
	// puts("coucou !");
	//
	// ft_puts("");
	// puts("");
	//
	// t_strlen();
	// t_memset();
	// t_memcpy();
	// t_strdup();
	// ft_cat(0);
	char	buf1[10];
	char	buf2[10];
	char	str[] = "AAAA";

	memset(buf1, 'B', 9);
	memset(buf2, 'B', 9);
	buf1[4] = '\0';
	buf2[4] = '\0';
	strcat(buf1, str);
	ft_strcat(buf2, str);
	if (!memcmp(buf1, buf2, 9))
	{
		return(0);
	}
	printf("ERROR !!!\n");
	printf("sys : \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d - ", buf1[i]);
	}
	printf("\n");
	printf("mine : \n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d - ", buf2[i]);
	}
	printf("\n");
}
