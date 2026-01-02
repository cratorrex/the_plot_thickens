*This project has been created as part of the 42 curriculum by thtay*.

## Description 
### ft_printf - Because ft_putnbr() and ft_putstr() aren’t enough
This project aims to recreate many parts of the original printf function with the use of `Variadic Functions` on top of our `libft` library. Once this project has been completed, will `ft_printf` be allowed to be used in our deliverables of projects.  
`printf` is a flexible function that prints out a string to the console (standard output or `STDOUT`) with formatting options in the form of flags, that trail a single `%` character/sign. Each flag `%c` `%s` etc will be replaced by whatever it's respective **variadic argument** in order is passed into the function.

An additional functionality of `printf` is that it returns the amount of `BYTES` that has been written to `STDOUT`

Example code:
```c
int	bytes_written;

bytes_written = ft_printf("Hello world%c %s %i.%%", '!', "Hope you have a wonderful", 2026);
//STDOUT Output expected:
//Hello world! Hope you have a wonderful 2026.%

//Expected value of bytes_written: 45
```
It is good to remember that this implementation of printf does not handle all the flags of the common printf function, but rather the following flags:  
`c` `s` `i` `d` `u` `p` `x` `X` `%`  
In the case where this repository is updated post-validation of the project, additional flags will be reflected in the [Overview](#Overview-of-Deliverable) section.  

## Instructions
Makefile: all, clean, subclean, fclean, re.

`git clone` the repository link into your directory of choice.  
Compile the library into an archive (`.a` file) with the command `make` in the directory where the Makefile resides.  
`make fclean` will remove all compiled files.

The additional rule `subclean` is added just to fclean the `libft` directory from the root directory should there ever be a need.  
The Makefile in this directory will also trigger the Makefile in the included `libft` directory (rules `all`, `fclean` and `re`). 


## Resources
Microsoft (via learn.microsoft.com) and Manual Documentations for the respective allowed functions and macros as preliminary research.  
- [printf](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l)  
  - [Format Specification](https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions)
  - [Variable argument lists](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start)  
    - [Argument access](https://learn.microsoft.com/en-us/cpp/c-runtime-library/argument-access)
  - [`errno` / `EINVAL` flag](https://learn.microsoft.com/en-us/cpp/c-runtime-library/errno-constants) 
    > Look for value 22 in the table...
	> Additionally, since all of these are errors to some capacity, they will not be considered.

[printf(3) - man](https://linux.die.net/man/3/printf)  
[Variadic Functions - Wikipedia](https://en.wikipedia.org/wiki/Variadic_function)

### AI Usage
The only time AI was used in this project was ironically to walk through how to convert decimal to a base16 hexadecimal... I mean that both generously and self-depricatively.

## Overview of Deliverable
Just like with `libft`, we need to reproduce a reasonable amount of functionality from the `printf` function.  
The `va_arg` column denotes flags that have been used in the repos that will advance the list of arguments passed into the function.

<table>
<tr><td colspan=5><strong>Project Basic Requirements</strong></td></tr>

<tr><td rowspan=5>Allowed Functions</td>
<td colspan=2>malloc, free, write</td>
<td colspan=2>Mostly used in <code>libft</code></td></tr>

<tr><td>va_start</td><td colspan=3>Sets the pointer to the start of the <code>va_list</code> passed.</td></tr>

<tr><td>va_arg</td><td colspan=3>Returns the next argument in the <code>va_list</code> as the specified <code>type</code>.</td></tr>

<tr><td>va_copy</td><td colspan=3>Copies the <code>va_list</code>.</td></tr>

<tr><td>va_end</td><td colspan=3>End of the <code>va_list</code>.</td></tr>

<tr><td colspan=5>All of these follow the format of <code>%f</code>, where <code>f</code> represents the associated flag.</td></tr></table>

<hr/>

<table><thead>
<tr><td>Name</td><td>Flag</td><td>Type</td><td>Description</td><td>va_arg?</td></tr>
</thead>

<tr><td>Character</td>
<td><code>c</code></td>
<td rowspan=2><code>int</code> as <code>char</code></td>
<td>Outputs a single character.</td><td>YES</td></tr>

<tr><td><code>%</code> Percentage sign</td>
<td><code>%</code></td>
<td>Outputs the <code>%</code> character literal.<br/>
Yes... this must be escaped as <code>%%</code>.</td><td>NO</td></tr>

<tr><td>String</td>
<td><code>s</code></td>
<td><code>char *</code></td>
<td>Outputs a literal string.</td><td rowspan=7>YES</td></tr>

<tr><td>Integer</td>
<td><code>i</code></td>
<td rowspan=2><code>int</code></td>
<td rowspan=3>Outputs a number as a string.</td></tr>

<tr><td>Decimal</td>
<td><code>d</code></td>

<tr><td>Unsigned Integer</td>
<td><code>u</code></td>
<td rowspan=3><code>unsigned int</code></td></tr>

<tr><td>Hexadecimal (Lower)</td>
<td><code>x</code></td>
<td>Converts the given integer into a <code>BASE16</code> hexadecimal. Outputs the hex digits in <code>lowercase</code>.</td></tr>

<tr><td>Hexadecimal (Upper)</td>
<td><code>X</code></td>
<td>Converts the given integer into a <code>BASE16</code> hexadecimal. Outputs the hex digits in <code>UPPERCASE</code>.</td></tr>

<tr><td>Pointer Value</td>
<td><code>p</code></td>
<td>TBA</td>
<td>Outputs a TBA.</td></tr></table>

### Edge Case and Error Handling
These errors were also handled against the expected output of the actual printf.

```c
//1. Basic NULL
ft_printf(NULL); //Expected -1
```

```c
//2. Incomplete Flag (%\0)
ft_printf("%");
ft_printf("any amount of text %");
//Expected for all -1

//This is tame compared to Case 5... 
//Since this wasn't necessarily part of the requirement,
//I considered both as errors (-1).
//Wait until you hear that this is actually error (-22).
```

```c
//3. String NULL
ft_printf("%s", NULL); 
//Expected to print "(null)" verbatim.
//Consequently adding 6 to the return value.
```

```c
//4. Integer NULL (incl. unsigned)
ft_printf("%i, %d, %x, %X.", NULL, NULL, NULL, NULL); 
//Expected all to print "0", resulting in the following output.
//"0, 0, 0, 0."
```

```c
//5. Invalid Flag (%?)

//Invalid flags by the interpreter is treated as an error by printf,
//but execution is allowed to continue.
//Regardless, since it is an error,
//this repository's implementation will return -1.

ft_printf("p%q");
ft_printf("p%q", "a");
//printf expected both returns -1 and print "p"

ft_printf("p%y");
ft_printf("p%y", "a");
//printf expected both returns 3 and print "p%y"

ft_printf("q%yt%q");
ft_printf("q%yt%q", "a", "a");
//printf expected both returns 5 and print "q%yt%"
```

```c
//
ft_printf(); //
```