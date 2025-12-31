/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thtay <thtay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:04:07 by thtay             #+#    #+#             */
/*   Updated: 2025/12/30 16:04:08 by thtay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
//#include "ft_printf.h" //uncomment this on evals

void test_type(char *tstr)
{
	ft_printf ("\n%s\n", tstr);
	ft_printf ("----\t----\t----\t----\t----\t----\n");
}

// void tester(char *str, ...)
// {
// 	va_list control;
// 	va_start(control, str);
// }

//we all know what we're in for... right?
int main(void)
{
	int reality = 0, expectation = 0;


	//basic
	test_type("Basic Tests");

	expectation	=    printf("1E: Hello world!\n");
	reality		= ft_printf("1R: Hello world!\n");
	printf("Diff: %i\n\n", expectation - reality);

	//Test 2 --> empty string
	printf("2: empty string test\n");
	expectation	=    printf("");
	reality		= ft_printf("");
	printf("\nDiff: %i\n\n", expectation - reality);

	//Test 3 --> NULL string (ERROR)
	printf("3: NULL string ERROR test\n");
	expectation	=    printf(NULL);
	reality		= ft_printf(NULL);
	printf("\nDiff: %i\n\n", expectation - reality);

	
	//Test   --> incomplete flag/call
	//Normally, printf will not compile, so this is just
	//a demonstration since behaviour would be undefined.
	//This implementation breaks after printing if any.
	test_type("Incomplete Flag");

	// // compiling test
	// printf ("%");

	printf("incomplete ERROR test 1\n");
	reality		= ft_printf("%");
	printf("\nExpected behaviour is undefined\nValue: %i\n\n", reality);

	printf("incomplete ERROR test 2\n");
	reality		= ft_printf("test%");
	printf("\nValue: %i\n\n", reality);


	// <%>
	test_type("%% char Tests");
	
	expectation =    printf("1E: %%\n");
	reality     = ft_printf("1R: %%\n");
	printf("Diff: %i\n\n", expectation - reality);


	//char
	test_type("Character Tests %c");

	expectation =    printf("1E: %c\n", 'c');
	reality     = ft_printf("1R: %c\n", 'c');
	printf("Diff: %i\n\n", expectation - reality);

	//Test 2 --> \0 (NUL-ter)
	expectation =    printf("2E: %c\n", 0);
	reality     = ft_printf("2R: %c\n", 0);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("3E: %c\n", 128);
	reality     = ft_printf("3R: %c\n", 128);
	printf("Diff: %i\n\n", expectation - reality);

	//Test 4 --> rolling overflow
	expectation =    printf("4E: %c\n", 298);
	reality     = ft_printf("4R: %c\n", 298);
	printf("Diff: %i\n\n", expectation - reality);

	//Test 5 --> rolling underflow
	expectation =    printf("5E: %c\n", -200);
	reality     = ft_printf("5R: %c\n", -200);
	printf("Diff: %i\n\n", expectation - reality);

	//Test 6 --> % literal
	expectation =    printf("6E: %c\n", '%');
	reality     = ft_printf("6R: %c\n", '%');
	printf("Diff: %i\n\n", expectation - reality);


	//string
	test_type("String Tests %s");
	reality = ft_printf("%s", "Fun fact: all the \"Test Headers\" use the %s flag.\n");
	reality += ft_printf("%s", "So, let's just get in to the fun stuff.\n\n");
	printf("Expected: 91 | Value: %i\n\n", reality);

	//hexadecimal lower && int
	test_type("Hexadecimal (L) %x && Integer Tests %i");

	expectation =    printf("1E: %i || %x\n", 420, 420);
	reality     = ft_printf("1R: %i || %x\n", 420, 420);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("2E: %i || %x\n", 0, 0);
	reality     = ft_printf("2R: %i || %x\n", 0, 0);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("3E: %i || %x\n", 64222, 64222);
	reality     = ft_printf("3R: %i || %x\n", 64222, 64222);
	printf("Diff: %i\n\n", expectation - reality);


	//hexadecimal upper && int (d)
	test_type("Hexadecimal (U) %X && Decimal Tests %d");

	expectation =    printf("1E: %d || %X\n", 420, 420);
	reality     = ft_printf("1R: %d || %X\n", 420, 420);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("2E: %d || %X\n", 0, 0);
	reality     = ft_printf("2R: %d || %X\n", 0, 0);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("3E: %d || %X\n", 64222, 64222);
	reality     = ft_printf("3R: %d || %X\n", 64222, 64222);
	printf("Diff: %i\n\n", expectation - reality);
}
