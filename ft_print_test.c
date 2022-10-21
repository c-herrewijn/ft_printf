# include <stdio.h>
# include <stdarg.h>

void printer(char *input, ...);

int main(void)
{
	printer("aaa", 10, 11, 12);

	puts("tests..");
	printf("aaa", 1, 2, 3);
}

void printer(char *input, ...)
{
	va_list ap;

	va_start(ap, input);

	printf("int1 %d\n", va_arg(ap, int));
	printf("int2 %d\n", va_arg(ap, int));

	va_end(ap);
}
     