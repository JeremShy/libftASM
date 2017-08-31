#include <string.h>
#include <libftasm.h>

int main()
{
	char pouet[240] = "coucou1234";

	ft_bzero(pouet, sizeof("coucou1234"));
}
