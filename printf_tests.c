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
	test_type("Basic Test");

	expectation	=    printf("1E: Hello world!\n");
	reality		= ft_printf("1R: Hello world!\n");
	printf("Diff: %i\n\n", expectation - reality);

	//Test 2 --> empty string
	printf("2: empty string test\n");
	expectation	=    printf("");
	reality		= ft_printf("");
	printf("\nExpected: %i\nReality: %i\n\n", expectation, reality);
	

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
	reality = ft_printf("%s", "Fun fact: all the \"Test Headers\" \
use the %s flag.\nSo, let's just get in to the fun stuff.\n\n");
	printf("Expected: 91 | Value: %i\n\n", reality);

	printf("NULL String (not NULL input though!)\n");
	expectation =    printf("1E: %s\n", NULL);
	reality     = ft_printf("1R: %s\n", NULL);
	printf("Diff: %i\n\n", expectation - reality);




	//hexadecimal lower && int
	test_type("Hexadecimal (L) %x && Integer Tests %i, %d\
\n%i is the same as %d...");

	expectation =    printf("1E: %i || %x\n", 420, 420);
	reality     = ft_printf("1R: %i || %x\n", 420, 420);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("2E: %i || %x\n", 0, 0);
	reality     = ft_printf("2R: %i || %x\n", 0, 0);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("3E: %i || %x\n", 64222, 64222);
	reality     = ft_printf("3R: %i || %x\n", 64222, 64222);
	printf("Diff: %i\n\n", expectation - reality);

	// Test 4 --> NULL Test
	printf("NULL Test\n");
	expectation =    printf("4E: %i || %x\n", NULL, NULL);
	reality     = ft_printf("4R: %i || %x\n", NULL, NULL);
	printf("Diff: %i\n\n", expectation - reality);

	// Test 5 --> unsigned negative vs signed negative
	printf("Negative / uUnderflow Test \n");
	expectation =    printf("5E: %i || %x\n", -1, -1);
	reality     = ft_printf("5R: %i || %x\n", -1, -1);
	printf("Diff: %i\n\n", expectation - reality);

	// Test 6 --> Overflow
	printf("Overflow Test \n");
	expectation =    printf("6E: %i || %x\n", INT_MAX + 1, INT_MAX + 1);
	reality     = ft_printf("6R: %i || %x\n", INT_MAX + 1, INT_MAX + 1);
	printf("Diff: %i\n\n", expectation - reality);
	
	// Test 7 --> Underflow
	printf("Underflow Test \n");
	expectation =    printf("7E: %i || %x\n", INT_MIN - 1, INT_MIN - 1);
	reality     = ft_printf("7R: %i || %x\n", INT_MIN - 1, INT_MIN - 1);
	printf("Diff: %i\n\n", expectation - reality);


	//hexadecimal upper && int (d)
	test_type("Hexadecimal (U) %X && Unsigned INT Tests %u");

	expectation =    printf("1E: %d || %X\n", 420, 420);
	reality     = ft_printf("1R: %d || %X\n", 420, 420);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("2E: %d || %X\n", 0, 0);
	reality     = ft_printf("2R: %d || %X\n", 0, 0);
	printf("Diff: %i\n\n", expectation - reality);

	expectation =    printf("3E: %d || %X\n", 64222, 64222);
	reality     = ft_printf("3R: %d || %X\n", 64222, 64222);
	printf("Diff: %i\n\n", expectation - reality);

	// Test 4 --> NULL Test
	expectation =    printf("4E: %d || %X\n", NULL, NULL);
	reality     = ft_printf("4R: %d || %X\n", NULL, NULL);
	printf("Diff: %i\n\n", expectation - reality);



/////  ////   ////    ///   ////      /////  /////   ////  /////   ////    /
//     /   /  /   /  /  //  /   /       /    //     //       /    //       /
////   ////   ////   / / /  ////        /    ////    ///     /     ///   /////
//     /   /  /   /  //  /  /   /       /    //        //    /       //   ///  
/////  /   /  /   /   ///   /   /       /    /////  ////     /    ////     /

	//Error Tests
	test_type("Error Tests.\nExpected value is -1 \
and function does not print.");

	//Test 1 --> NULL input (ERROR)
	test_type("1: NULL input");
	expectation	=    printf(NULL);
	reality		= ft_printf(NULL);
	printf("\nExpected: %i\nReality: %i\n\n", expectation, reality);

	
	//Test   --> incomplete flag/call
	//Normally, printf will give a warning, so this is just
	//a demonstration since behaviour would be undefined.
	//This implementation should return a -1 before printing if any.
	test_type("2: Incomplete Flag");

	// compiling test
	expectation = printf ("%");
	printf ("Expected value for below: %i\n\n", expectation);

	printf("incomplete ERROR test 1\n");
	reality		= ft_printf("%");
	printf("\nValue: %i\n\n", reality);

	printf("incomplete ERROR test 2\n");
	expectation =    printf("Ex: test%");
	reality		= ft_printf("Re: test%");
	printf("\nValue: %i\n\n", reality);

	//??????????
	printf("incomplete ERROR test 3a\n");
	expectation =    printf("Ex: p%q");
	reality		= ft_printf("Re: p%q");
	printf("\nExpected: %i\nReality: %i\n\n", expectation, reality);

	printf("incomplete ERROR test 3b\n");
	expectation =    printf("Ex: p%y");
	reality		= ft_printf("Re: p%y");
	printf("\nExpected: %i\nReality: %i\n\n", expectation, reality);

	printf("incomplete ERROR test 3c\n");
	expectation =    printf("Ex: q%yt%q");
	reality		= ft_printf("Re: q%yt%q");
	printf("\nExpected: %i\nReality: %i\n\n", expectation, reality);

}
