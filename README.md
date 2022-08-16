# lib_string

## Introduction

- Implementation of the string.h library with additions on language C.

- The string.h library is the main C library for string processing. Project developed of standard using gcc compiler.

- The C programming language has a set of functions implementing operations on strings (character strings and byte strings) in its standard library. Various operations, such as copying, concatenation, tokenization and searching are supported.
- For character strings, the standard library uses the convention that strings are null-terminated: a string of n characters is represented as an array of n + 1 elements, the last of which is a "NULL" character. The only support for strings in the programming language proper is that the compiler translates quoted string constants into null-terminated strings.

## Description of the implemented functions of the string.h library

The project includes:
| No. | Function | Description |
| ------ | ------ | ------ |
| 1 | void *memchr(const void *str, int c, size_t n) | Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. |
| 2 | int memcmp(const void *str1, const void *str2, size_t n) | Compares the first n bytes of str1 and str2. |
| 3 | void *memcpy(void *dest, const void *src, size_t n) | Copies n characters from src to dest. |
| 4 | void *memmove(void *dest, const void *src, size_t n) | Another function to copy n characters from src to dest. |
| 5 | void *memset(void *str, int c, size_t n) | Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. |
| 6 | char *strcat(char *dest, const char *src) | Appends the string pointed to, by src to the end of the string pointed to by dest. |
| 7 | char *strncat(char *dest, const char *src, size_t n) | Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. |
| 8 | char *strchr(const char *str, int c) | Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. |
| 9 | int strcmp(const char *str1, const char *str2) | Compares the string pointed to, by str1 to the string pointed to by str2. |
| 10 | int strncmp(const char *str1, const char *str2, size_t n) | Compares at most the first n bytes of str1 and str2. |
| 11 | char *strcpy(char *dest, const char *src) | Copies the string pointed to, by src to dest. |
| 12 | char *strncpy(char *dest, const char *src, size_t n) | Copies up to n characters from the string pointed to, by src to dest. |
| 13 | size_t strcspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. |
| 14 | char *strerror(int errnum) | Searches an internal array for the error number errnum and returns a pointer to an error message string. You need to declare macros containing arrays of error messages for mac and linux operating systems. Error descriptions are available in the original library. Checking the current OS is carried out using directives. |
| 15 | size_t strlen(const char *str) | Computes the length of the string str up to but not including the terminating null character. |
| 16 | char *strpbrk(const char *str1, const char *str2) | Finds the first character in the string str1 that matches any character specified in str2. |
| 17 | char *strrchr(const char *str, int c) | Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. |
| 18 | size_t strspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters in str2. |
| 19 | char *strstr(const char *haystack, const char *needle) | Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. |
| 20 | char *strtok(char *str, const char *delim) | Breaks string str into a series of tokens separated by delim. |
| 21 | int sprintf(char *str, const char *format, ...) | Sends formatted output to a string pointed to, by str. |
| 22 | void *to_upper(const char *str) | Returns a copy of string (str) converted to uppercase. In case of any error, return NULL |
| 23 | void *to_lower(const char *str) | Returns a copy of string (str) converted to lowercase. In case of any error, return NULL |
| 24 | void *insert(const char *src, const char *str, size_t start_index) | Returns a new string in which a specified string (str) is inserted at a specified index position (start_index) in the given string (src). In case of any error, return NULL |
| 25 | void *trim(const char *src, const char *trim_chars) | Returns a new string in which all leading and trailing occurrences of a set of specified characters (trim_chars) from the given string (src) are removed. In case of any error, return NULL |


### Sprintf specifiers

| No. | Specifier | sprintf output | sscanf output |
| --- | --- | --- | --- |
| 1 | c | Character | Character |
| 2 | d | Signed decimal integer | Signed decimal integer |
| 3 | i | Signed decimal integer | Signed integer (may be decimal, octal or hexadecimal) |
| 4 | f | Decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 5 | s | String of characters | String of characters |
| 6 | u | Unsigned decimal integer | Unsigned decimal integer |
| 7 | % | Character % | Character % |

### Sprintf flags

| No. | Flags | Description |
| --- | --- | --- |
| 1 | - | Left-justify within the given field width; Right justification is the default (see width sub-specifier). |
| 2 | + | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a -ve sign. |
| 3 | (space) | If no sign is going to be written, a blank space is inserted before the value. |
| 4 | .number | For integer specifiers (d, i, u) − precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For f specifiers − this is the number of digits to be printed after the decimal point. For s − this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. For c type − it has no effect. When no precision is specified for specifiers f the default one is 6. When no precision is specified for all other kind of specifiers, the default is 1. If the period is specified without an explicit value for precision, 0 is assumed. |
| 5 | 0 | Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier). |
| 6 | h | The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, u). |
| 7 | l | The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, u), and as a wide character or wide character string for specifiers c and s. |
| 8 | L | The argument is interpreted as a long double (only applies to floating point specifiers − f). |

## Information about implemented library 

- The library developed in C language of C11 standard using gcc compiler   
- Functions developed as a static library (with the header file s21_string.h)
- The library developed according to the principles of structured programming
- There are prefix "s21" before each function"
- There are implemented platform-specific errors arrays, as it was mentioned in the description of the strerror function.
- Library functions have full coverage with unit-tests with the check.h library
- Unit-tests check the results of my implementation by comparing them with the implementation of the standard math.h library
- Unit tests cover at least 90% of each function (checked using gcovr)
- Use Makefile for building the library and tests (the targets: _all, clean, test, s21_math.a, gcov_report_) 

All code is the property of Anton Tuzov.
