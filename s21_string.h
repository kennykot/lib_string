//  Copyright 2022 jewfishc, trenamim, guinilic, brainych, plummero
#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#define s21_NULL ((void *)0)

typedef long unsigned s21_size_t;

void *s21_memchr(const void *memptr, int val, s21_size_t num);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char* str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_err_itoa(int num, char* unk_err);
int s21_is_in_char(const char c, const char* str);
int s21_sprintf(char *buf, const char *fmt, ...);
int s21_is_dig(int c);
int s21_max(int a, int b);
char s21_to_char(int i);
int s21_atoi(char *str);
char *s21_uint_to_string(unsigned long long num, long int floating);
char *s21_int_to_string(long int num, long int floating);
char *s21_add_spaces(char *dest, int width, int left_padding);
char *s21_add_sign(char *dest, char *src, int sign_display,
               int space_instead_sign, long double number);
char *s21_add_zero(char *dest, char *src, int floating);
void s21_release_flags(int *format, int *left_padding, int *sign_display,
                   int *space_instead_sign, int *width, int *floating,
                   int *h_flag, int *l_flag, int *L_flag);
char* s21_float_to_string(long double num, int floating);

#endif  //  SRC_S21_STRING_H_
