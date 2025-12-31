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
In the case where this repository is updated post-validation of the project, additional flags will be reflected in the overview section.  
See more: [Overview](#Overview-of-Deliverable).

## Instructions
Makefile: all, clean, subclean, fclean, re.

`git clone` the repository link into your directory of choice.  
Compile the library into an archive (`.a` file) with the command `make` in the directory where the Makefile resides.  
`make fclean` will remove all compiled files.

The additional rule `subclean` is added just to fclean the `libft` directory from the root directory should there ever be a need.  
The Makefile in this directory will also trigger the Makefile in the included `libft` directory (rules `all`, `fclean` and `re`). 


## Resources
Microsoft (via learn.microsoft.com) and Manual Documentations for the respective allowed functions and macros as preliminary research.

[Variadic Functions](https://en.wikipedia.org/wiki/Variadic_function)

### AI Usage
The only time AI was used in this project was ironically to walk through how to convert decimal to a base16 hexadecimal... I mean that both generously and self-depricatively.

## Overview of Deliverable
Just like with `libft`, we need to reproduce a reasonable amount of functionality from the `printf` function.  
The `va_arg` column denotes flags that have been used in the repos that will advance the list of arguments passed into the function.

<table><thead>
<tr><td colspan=5><strong>Project Basic Requirements</strong></td></tr>

<tr><td rowspan=5>Allowed Functions</td>
<td colspan=2>malloc, free, write</td>
<td colspan=2>Mostly used in <code>libft</code></td></tr>

<tr><td>va_start</td><td colspan=3>Denotes the <code>va_list</code> of arguments, starting after the first argument passed.<br/>
<code>printf("Some %str%ing I want to pass %in...",<code>basically, anything in here, delimited by the ',' char.</code>)</code></td></tr>

<tr><td>va_arg</td><td colspan=3>Returns the next argument in the specified <code>va_list</code> as the specified <code>type</code>.</td></tr>

<tr><td>va_copy</td><td colspan=3>Copies the indicated <code>va_start</code> to another <code>va_list</code> variable.</td></tr>

<tr><td>va_end</td><td colspan=3>End of the <code>va_list</code>. Basically a "Close" function.</td></tr>

<tr><td colspan=5>All of these follow the format of <code>%f</code>, where <code>f</code> represents the associated flag.</td></tr>

<tr><td colspan=5><hr/></td></tr>

<tr><td>Name</td><td>Flag</td><td>Type</td><td>Description</td><td>va_arg?</td></tr>
</thead>

<tr><td>Character</td>
<td><code>c</code></td>
<td rowspan=2><code>int</code> as <code>char</code></td>
<td>Outputs a single character.</td><td>YES</td></tr>

<tr><td><code>%</code> Percentage sign</td>
<td><code>%</code></td>
<td>Outputs the <code>%</code> character literal.<br/>
Yes... this must be escaped.</td><td>NO</td></tr>

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
<td>Outputs a TBA.</td></tr>
