//  Copyright 2022 jewfishc, trenamim, guinilic, brainych, plummero
#include <check.h>
#include "s21_string.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

START_TEST(s21_memchr_test) {
    const char str1[] = "Hello World";
    char str2 = 'W';
    const char str3[] = "Hello World";
    char str4 = 'W';
    ck_assert_str_eq(s21_memchr(str1, str2, 7), memchr(str3, str4, 7));
} END_TEST

START_TEST(s21_memcmp_test) {
    char str1[15] = "1234567890";
    char str2[15] = "1234567890";
    ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
} END_TEST

START_TEST(s21_memcmp_test_1) {
    char str1[15] = "12345";
    char str2[15] = "1234567890";
    ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
} END_TEST

START_TEST(s21_memcmp_test_2) {
    char str1[15] = "1234567890";
    char str2[15] = "12345";
    ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
} END_TEST

START_TEST(s21_memcpy_test) {
    char dst[100] = "";
    char src[] = "1234567890";
    char dst1[100] = "";
    char src1[] = "1234567890";
    ck_assert_str_eq(s21_memcpy(dst, src, 6), memcpy(dst1, src1, 6));
} END_TEST

START_TEST(s21_memmove_test) {
    char dst[] = "123";
    char src[] = "4567890";
    char dst1[] = "123";
    char src1[] = "4567890";
    ck_assert_str_eq(s21_memmove(dst, src, 3), memmove(dst1, src1, 3));
} END_TEST

START_TEST(s21_memmove_test_1) {
    char dst[] = ".........";
    char src[] = "12345";
    char dst1[] = ".........";
    char src2[] = "12345";
    ck_assert_str_eq(s21_memmove(dst, src, 5), memmove(dst1, src2, 5));
} END_TEST

START_TEST(s21_memset_test) {
    char src[] = "1234567890";
    char src_1[] = "1234567890";
    ck_assert_str_eq(s21_memset(src, '2', 10), memset(src_1, '2', 10));
} END_TEST

START_TEST(s21_strcat_test) {
    char str1[100] = "12345";
    const char str2[] = "67890";
    char str3[100] = "12345";
    const char str4[] = "67890";
    ck_assert_str_eq(s21_strcat(str1, str2), strcat(str3, str4));
} END_TEST

START_TEST(s21_strncat_test) {
    char str1[100] = "12345";
    const char str2[] = "67890";
    char str3[100] = "12345";
    const char str4[] = "67890";
    ck_assert_str_eq(s21_strncat(str1, str2, 3), strncat(str3, str4, 3));
} END_TEST

START_TEST(s21_strchr_test) {
    const char str1[7] = "aaaaab";
    char str2 = 'b';
    ck_assert_str_eq(s21_strchr(str1, str2), strchr(str1, str2));
} END_TEST

START_TEST(s21_strcmp_test) {
    char str1[] = "1234567890";
    char str2[] = "1234567890";
    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

START_TEST(s21_strncmp_test) {
    char str1[] = "1234567890";
    char str2[] = "2234567890";
    char str3[] = "1234567890";
    char str4[] = "2234567890";
    ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str3, str4, 5));
} END_TEST

START_TEST(s21_strcpy_test) {
    char dst[100] = "";
    const char src[10] = "12345";
    char dst1[100] = "";
    const char src2[10] = "12345";
    ck_assert_str_eq(s21_strcpy(dst, src), strcpy(dst1, src2));
} END_TEST

START_TEST(s21_strncpy_test) {
    char dst[100] = "aaaaaaaa";
    const char src[] = "1234567890";
    char dst1[100] = "aaaaaaaa";
    const char src2[] = "1234567890";
    ck_assert_str_eq(s21_strncpy(dst, src, 4), strncpy(dst1, src2, 4));
} END_TEST

START_TEST(s21_strcspn_test) {
    const char str1[] = "0123456";
    const char str2[] = "456";
    ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
} END_TEST

START_TEST(s21_strerror_test) {
    int x = 40;
    ck_assert_str_eq(s21_strerror(x), strerror(x));
} END_TEST

START_TEST(s21_strerror_test_1) {
    int x = -150;
    ck_assert_str_eq(s21_strerror(x), strerror(x));
} END_TEST

START_TEST(s21_strlen_test) {
    const char str1[] = "Name";
    ck_assert_int_eq(s21_strlen(str1), strlen(str1));
} END_TEST

START_TEST(s21_strpbrk_test) {
    const char str1[] = "Hello World";
    const char str2[] = "Wl";
    ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
} END_TEST

START_TEST(s21_strrchr_test) {
    const char str1[] = "Hello World";
    char str2 = 'l';
    ck_assert_str_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
} END_TEST

START_TEST(s21_strspn_test) {
    const char str1[] = "0123456";
    const char str2[] = "214";
    ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
} END_TEST

START_TEST(s21_strspn_test_1) {
    const char str1[] = "0123456";
    const char str2[] = "+/-";
    ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
} END_TEST

START_TEST(s21_strstr_test) {
    const char str1[] = "Hola, World";
    const char str2[] = " Wo";
    const char str3[] = "Hola, World";
    const char str4[] = " Wo";
    ck_assert_str_eq(s21_strstr(str1, str2), strstr(str3, str4));
} END_TEST

START_TEST(s21_strtok_test) {
    char str1[100] = ". . . . .";
    char str2[100] = ". . . . .";
    const char str[] = ".";
    char *eq1 = s21_strtok(str1, str);
    char *eq2 = strtok(str2, str);
    ck_assert_str_eq(eq1, eq2);
    while (eq1 && eq2) {
        ck_assert_str_eq(eq1, eq2);
        eq1 = s21_strtok(NULL, str);
        eq2 = strtok(NULL, str);
    }
} END_TEST

START_TEST(s21_strtok_test_1) {
    char str1[] = "!       A!B!C!D!E!!F!!G";
    char str2[] = "!       A!B!C!D!E!!F!!G";
    const char str[] = "+_! =";
    char *eq1 = s21_strtok(str1, str);
    char *eq2 = strtok(str2, str);
    ck_assert_str_eq(eq1, eq2);
    while (eq1 && eq2) {
        ck_assert_str_eq(eq1, eq2);
        eq1 = s21_strtok(NULL, str);
        eq2 = strtok(NULL, str);
    }
} END_TEST

START_TEST(s21_insert_test) {
    char str_1[] = "HELLO!\0";
    char src[] = "world\0";
    char *res = s21_insert(str_1, src, 4);
    ck_assert_pstr_eq(res, "HELworldLO!");
    free(res);
} END_TEST

START_TEST(s21_to_lower_test) {
    char src[] = "HELLO!\0";
    ck_assert_pstr_eq(s21_to_lower(src), "hello!");
} END_TEST

START_TEST(s21_to_lower_test_1) {
    char src[] = "1A2B3C4D5E!\0";
    ck_assert_pstr_eq(s21_to_lower(src), "1a2b3c4d5e!");
} END_TEST

START_TEST(s21_to_upper_test) {
    char str_1[] = "Hello world\0";
    ck_assert_pstr_eq(s21_to_upper(str_1), "HELLO WORLD");
} END_TEST

START_TEST(s21_to_upper_test_1) {
    char str_1[] = "q1w2e3\0";
    ck_assert_pstr_eq(s21_to_upper(str_1), "Q1W2E3");
} END_TEST

START_TEST(s21_trim_test) {
    const char str_1[] = "everybody are here";
    const char str_2[] = "er";
    ck_assert_pstr_eq(s21_trim(str_1, str_2), "verybody are h");
} END_TEST

START_TEST(s21_sprintf_test) {
    char tmp[100] = {'\0'};
    char tmk[100] = {'\0'};
    s21_sprintf(tmp, "%d", 0);
    sprintf(tmk, "%d", 0);
    ck_assert_str_eq(tmp, tmk);
} END_TEST

START_TEST(s21_sprintf_test_1) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%10.d", 0);
    sprintf(str1, "%10.d", 0);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_2) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "% 10.12d", 10);
    sprintf(str1, "% 10.12d", 10);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_3) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-10.2d", 999);
    sprintf(str1, "%-10.2d", 999);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_4) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%+.2d", 0);
    sprintf(str1, "%+.2d", 0);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_5) {
    char str[200] = {'\0'};
    char str1[200] = {'\0'};
    s21_sprintf(str, "%ld", 100000000000000);
    sprintf(str1, "%ld", 100000000000000);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_6) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%hd", 999999999);
    sprintf(str1, "%hd", 999999999);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_7) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%% %d", 9999);
    sprintf(str1, "%% %d", 9999);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_8) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%c%c", 'a', 'b');
    sprintf(str1, "%c%c", 'a', 'b');
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_9) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%3c%-5c", 'A', 'B');
    sprintf(str1, "%3c%-5c", 'A', 'B');
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_10) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%- 10.2i", 99);
    sprintf(str1, "%- 10.2i", 99);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_11) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-.2i", -1);
    sprintf(str1, "%-.2i", -1);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_12) {
    char str[200] = {'\0'};
    char str1[200] = {'\0'};
    s21_sprintf(str, "%li", 100000000000000);
    sprintf(str1, "%li", 100000000000000);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_13) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%hi", 999999999);
    sprintf(str1, "%hi", 999999999);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_14) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%.u", 0);
    sprintf(str1, "%.u", 0);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_15) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%10.u", 0);
    sprintf(str1, "%10.u", 0);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_16) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%10.2u", 0);
    sprintf(str1, "%10.2u", 0);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_17) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-10.2u", 0);
    sprintf(str1, "%-10.2u", 0);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_18) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-.2u", 0);
    sprintf(str1, "%-.2u", 0);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_19) {
    char str[256] = {'\0'};
    char str1[256] = {'\0'};
    long unsigned int x = 100000000000000;
    s21_sprintf(str, "%lu", x);
    sprintf(str1, "%lu", x);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_20) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%hu", 999999999);
    sprintf(str1, "%hu", 999999999);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_21) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-5u", 0);
    sprintf(str1, "%-5u", 0);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_22) {
    char str[256] = {'\0'};
    char str1[256] = {'\0'};
    double f = 143.750;
    s21_sprintf(str, "%-1.11f", f);
    sprintf(str1, "%-1.11f", f);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_23) {
    char str[256] = {'\0'};
    char str1[256] = {'\0'};
    long double f = 143.750;
    s21_sprintf(str, "%.14Lf", f);
    sprintf(str1, "%.14Lf", f);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_24) {
    char str[256] = {'\0'};
    char str1[256] = {'\0'};
    long double f = 143.750;
    s21_sprintf(str, "% 12Lf", f);
    sprintf(str1, "% 12Lf", f);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_25) {
    char str[256] = {'\0'};
    char str1[256] = {'\0'};
    long double f = 143.750;
    s21_sprintf(str, "%+12Lf", f);
    sprintf(str1, "%+12Lf", f);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_26) {
    char str[256] = {'\0'};
    char str1[256] = {'\0'};
    long double f = 111.5;
    s21_sprintf(str, "%.0Lf", f);
    sprintf(str1, "%.0Lf", f);
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_27) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-.5s", "CheckingInfo");
    sprintf(str1, "%-.5s", "CheckingInfo");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_28) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%5.11s", "CheckingInfo");
    sprintf(str1, "%5.11s", "CheckingInfo");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_29) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-20.5s", "CheckingInfo");
    sprintf(str1, "%-20.5s", "CheckingInfo");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_30) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-.30s", "CheckingInfo");
    sprintf(str1, "%-.30s", "CheckingInfo");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_31) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%10.2s", "Check");
    sprintf(str1, "%10.2s", "Check");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_32) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%10.2s", "CheckingInfo");
    sprintf(str1, "%10.2s", "CheckingInfo");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_33) {
    char str[100] = {'\0'};
    char str1[100] = {'\0'};
    s21_sprintf(str, "%-2.6s", "CheckingInfo");
    sprintf(str1, "%-2.6s", "CheckingInfo");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_34) {
    char str[100];
    char str1[100];
    s21_sprintf(str, "%%%+.d%.1u%+.i%+.f%.4s", 21, -42, 0xF1AC, -9191.1919, "Hello School!");
    sprintf(str1, "%%%+.d%.1u%+.i%+.f%.4s", 21, -42, 0xF1AC, -9191.1919, "Hello School!");
    ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_test_35) {
    char str1[256];
    char str2[256];
    char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681), sprintf(str2, format,
                    val, (unsigned)14, (unsigned short)1441, (unsigned)14414, (unsigned)9681));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_36) {
    char str1[256];
    char str2[256];
    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                    sprintf(str2, format, val, 'c', 'a', 'b', 'b'));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_37) {
    char str1[256];
    char str2[256];
    ck_assert_int_eq(
        s21_sprintf(str1, "%s%s%s%s%s", "My", " ", "Name", " is ", "Anton"),
        sprintf(str2, "%s%s%s%s%s", "My", " ", "Name", " is ", "Anton"));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_38) {
    char str1[256];
    char str2[256];
    ck_assert_int_eq(s21_sprintf(str1, "good"), sprintf(str2, "good"));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_39) {
    char str1[256];
    char str2[256];
    ck_assert_int_eq(
        s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
        sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_40) {
    char str1[256];
    char str2[256];
    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                    sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                    (unsigned)666, (unsigned)100));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_41) {
    char str1[256];
    char str2[256];
    ck_assert_int_eq(
        s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
        sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_42) {
    char str1[256];
    char str2[256];
    char format[] = "%li%ld%lu";
    ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                    sprintf(str2, format, 666666666666, 777, 111));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_43) {
    char str1[256];
    char str2[256];
    char format[] = "%hi%hd%hu";
    ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111), sprintf(str2, format, 666, -777, 111));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_44) {
    char str1[256];
    char str2[256];
    char format[] = "%+li%+lu%+d%+lf";
    ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                    sprintf(str2, format, -123, 321, -5555, -1213.123));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_45) {
    char str1[256];
    char str2[256];
    char format[] = "%-11.11li%-35.5lu%-3.5ld%33.12lf";
    ck_assert_int_eq(
        s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, 1.999999),
        sprintf(str2, format, 66666666666, 5555555555, 44444444444, 1.999999));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_46) {
    char str1[256];
    char str2[256];
    char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";
    ck_assert_int_eq(
        s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                    "Is it check or not?", 11),
        sprintf(str2, format, 'f', 21, 42, 666.666,
                    "Is it check or not?", 11));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_47) {
    char str1[256];
    char str2[256];
    char format[] = "%%%%%%%%";
    ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test_48) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char format[] = " %.10d ";
    sprintf(sp, format, LONG_MAX);
    s21_sprintf(s21, format, LONG_MAX);
    ck_assert_str_eq(sp, s21);
} END_TEST

START_TEST(s21_sprintf_test_49) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char format[] = " %.11d ";
    sprintf(sp, format, LONG_MIN);
    s21_sprintf(s21, format, LONG_MIN);
    ck_assert_str_eq(sp, s21);
} END_TEST

START_TEST(s21_sprintf_test_50) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char format[] = " %.12d ";
    sprintf(sp, format, UINT_MAX);
    s21_sprintf(s21, format, UINT_MAX);
    ck_assert_str_eq(sp, s21);
} END_TEST

START_TEST(s21_sprintf_test_51) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char format[] = " %.13ld ";
    sprintf(sp, format, ULONG_MAX);
    s21_sprintf(s21, format, ULONG_MAX);
    ck_assert_str_eq(sp, s21);
} END_TEST

START_TEST(s21_sprintf_test_52) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char format[] = " %.8d %.9d %.10d %.11d %.12d %.13d %.14d";
    sprintf(sp, format, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    s21_sprintf(s21, format, INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    ck_assert_str_eq(sp, s21);
} END_TEST

START_TEST(s21_sprintf_test_53) {
    char data1[100] = {'\0'};
    char data2[100] = {'\0'};
    char format[] = "{(% c)(% c)(%%)(% c)}";
    s21_sprintf(data1, format, 42, '1', 'H');
    sprintf(data2, format, 42, '1', 'H');
    ck_assert_str_eq(data1, data2);
} END_TEST

START_TEST(s21_sprintf_test_54) {
    char sp[100] = {'\0'};
    char s21_sp[100] = {'\0'};
    char format[] = "{  %c   %c   %c  }";
    s21_sprintf(s21_sp, format, '0', 0, '1');
    sprintf(sp, format, '0', 0, '1');
    ck_assert_str_eq(sp, s21_sp);
} END_TEST

START_TEST(s21_sprintf_test_55) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char  format[] = " s21NULL %s s21NULL ";
    s21_sprintf(s21, format, s21_NULL);
    sprintf(sp, format, s21_NULL);
    ck_assert_pstr_eq(sp, s21);
} END_TEST

START_TEST(s21_sprintf_test_56) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char  format[] = "%f Hello %f world %f";
    s21_sprintf(s21, format, 132456.00, -1245654.88, 168598.49);
    sprintf(sp, format, 132456.00, -1245654.88, 168598.49);
    ck_assert_pstr_eq(sp, s21);
} END_TEST

START_TEST(s21_sprintf_test_57) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char  format[] = "%20.f Hello %20.f world %20.f";
    s21_sprintf(s21, format, 132456.00, -1245654.88, 168598.49);
    sprintf(sp, format, 132456.00, -1245654.88, 168598.49);
    ck_assert_pstr_eq(sp, s21);
} END_TEST

START_TEST(s21_sprintf_test_58) {
    char sp[256] = {'\0'};
    char s21[256] = {'\0'};
    char  format[] = "%20.3f Hello %20.3f world %20.3f";
    s21_sprintf(s21, format, 132456.00, -1245654.88, 168598.49);
    sprintf(sp, format, 132456.00, -1245654.88, 168598.49);
    ck_assert_pstr_eq(sp, s21);
} END_TEST

Suite *suite_s21_memchr(void) {
    Suite *s;
    s = suite_create("s21_memchr");
    TCase *tc_memchr;
    tc_memchr = tcase_create("s21_memchr");
    tcase_add_test(tc_memchr, s21_memchr_test);
    suite_add_tcase(s, tc_memchr);
    return s;
}

Suite *suite_s21_memcmp(void) {
    Suite *s;
    s = suite_create("s21_memcmp");
    TCase *tc_memcmp;
    tc_memcmp = tcase_create("s21_memcmp");
    tcase_add_test(tc_memcmp, s21_memcmp_test);
    suite_add_tcase(s, tc_memcmp);
    return s;
}

Suite *suite_s21_memcmp_1(void) {
    Suite *s;
    s = suite_create("s21_memcmp");
    TCase *tc_memcmp;
    tc_memcmp = tcase_create("s21_memcmp");
    tcase_add_test(tc_memcmp, s21_memcmp_test_1);
    suite_add_tcase(s, tc_memcmp);
    return s;
}

Suite *suite_s21_memcmp_2(void) {
    Suite *s;
    s = suite_create("s21_memcmp");
    TCase *tc_memcmp;
    tc_memcmp = tcase_create("s21_memcmp");
    tcase_add_test(tc_memcmp, s21_memcmp_test_2);
    suite_add_tcase(s, tc_memcmp);
    return s;
}

Suite *suite_s21_memcpy(void) {
    Suite *s;
    s = suite_create("s21_memcpy");
    TCase *tc_memcpy;
    tc_memcpy = tcase_create("s21_memcpy");
    tcase_add_test(tc_memcpy, s21_memcpy_test);
    suite_add_tcase(s, tc_memcpy);
    return s;
}

Suite *suite_s21_memmove(void) {
    Suite *s;
    s = suite_create("s21_memmove");
    TCase *tc_memmove;
    tc_memmove = tcase_create("s21_memmove");
    tcase_add_test(tc_memmove, s21_memmove_test);
    suite_add_tcase(s, tc_memmove);
    return s;
}

Suite *suite_s21_memmove_1(void) {
    Suite *s;
    s = suite_create("s21_memmove");
    TCase *tc_memmove;
    tc_memmove = tcase_create("s21_memmove");
    tcase_add_test(tc_memmove, s21_memmove_test_1);
    suite_add_tcase(s, tc_memmove);
    return s;
}

Suite *suite_s21_memset(void) {
    Suite *s;
    s = suite_create("s21_memset");
    TCase *tc_memset;
    tc_memset = tcase_create("s21_memset");
    tcase_add_test(tc_memset, s21_memset_test);
    suite_add_tcase(s, tc_memset);
    return s;
}

Suite *suite_s21_strcat(void) {
    Suite *s;
    s = suite_create("s21_strcat");
    TCase *tc_strcat;
    tc_strcat = tcase_create("s21_strcat");
    tcase_add_test(tc_strcat, s21_strcat_test);
    suite_add_tcase(s, tc_strcat);
    return s;
}

Suite *suite_s21_strncat(void) {
    Suite *s;
    s = suite_create("s21_strncat");
    TCase *tc_strncat;
    tc_strncat = tcase_create("s21_strncat");
    tcase_add_test(tc_strncat, s21_strncat_test);
    suite_add_tcase(s, tc_strncat);
    return s;
}

Suite *suite_s21_strchr(void) {
    Suite *s;
    s = suite_create("s21_strchr");
    TCase *tc_strchr;
    tc_strchr = tcase_create("s21_strchr");
    tcase_add_test(tc_strchr, s21_strchr_test);
    suite_add_tcase(s, tc_strchr);
    return s;
}

Suite *suite_s21_strcmp(void) {
    Suite *s;
    s = suite_create("s21_strcmp");
    TCase *tc_strcmp;
    tc_strcmp = tcase_create("s21_strcmp");
    tcase_add_test(tc_strcmp, s21_strcmp_test);
    suite_add_tcase(s, tc_strcmp);
    return s;
}

Suite *suite_s21_strncmp(void) {
    Suite *s;
    s = suite_create("s21_strncmp");
    TCase *tc_strncmp;
    tc_strncmp = tcase_create("s21_strncmp");
    tcase_add_test(tc_strncmp, s21_strncmp_test);
    suite_add_tcase(s, tc_strncmp);
    return s;
}

Suite *suite_s21_strcpy(void) {
    Suite *s;
    s = suite_create("s21_strcpy");
    TCase *tc_strcpy;
    tc_strcpy = tcase_create("s21_strcpy");
    tcase_add_test(tc_strcpy, s21_strcpy_test);
    suite_add_tcase(s, tc_strcpy);
    return s;
}

Suite *suite_s21_strncpy(void) {
    Suite *s;
    s = suite_create("s21_strncpy");
    TCase *tc_strncpy;
    tc_strncpy = tcase_create("s21_strncpy");
    tcase_add_test(tc_strncpy, s21_strncpy_test);
    suite_add_tcase(s, tc_strncpy);
    return s;
}

Suite *suite_s21_strcspn(void) {
    Suite *s;
    s = suite_create("s21_strcspn");
    TCase *tc_strcspn;
    tc_strcspn = tcase_create("s21_strcspn");
    tcase_add_test(tc_strcspn, s21_strcspn_test);
    suite_add_tcase(s, tc_strcspn);
    return s;
}

Suite *suite_s21_strerror(void) {
    Suite *s;
    s = suite_create("s21_strerror");
    TCase *tc_strerror;
    tc_strerror = tcase_create("s21_strerror");
    tcase_add_test(tc_strerror, s21_strerror_test);
    suite_add_tcase(s, tc_strerror);
    return s;
}

Suite *suite_s21_strerror_1(void) {
    Suite *s;
    s = suite_create("s21_strerror");
    TCase *tc_strerror;
    tc_strerror = tcase_create("s21_strerror");
    tcase_add_test(tc_strerror, s21_strerror_test_1);
    suite_add_tcase(s, tc_strerror);
    return s;
}

Suite *suite_s21_strlen(void) {
    Suite *s;
    s = suite_create("s21_strlen");
    TCase *tc_strlen;
    tc_strlen = tcase_create("s21_strlen");
    tcase_add_test(tc_strlen, s21_strlen_test);
    suite_add_tcase(s, tc_strlen);
    return s;
}

Suite *suite_s21_strpbrk(void) {
    Suite *s;
    s = suite_create("s21_strpbrk");
    TCase *tc_strpbrk;
    tc_strpbrk = tcase_create("s21_strpbrk");
    tcase_add_test(tc_strpbrk, s21_strpbrk_test);
    suite_add_tcase(s, tc_strpbrk);
    return s;
}

Suite *suite_s21_strrchr(void) {
    Suite *s;
    s = suite_create("s21_strrchr");
    TCase *tc_strrchr;
    tc_strrchr = tcase_create("s21_strrchr");
    tcase_add_test(tc_strrchr, s21_strrchr_test);
    suite_add_tcase(s, tc_strrchr);
    return s;
}

Suite *suite_s21_strspn(void) {
    Suite *s;
    s = suite_create("s21_strspn");
    TCase *tc_strspn;
    tc_strspn = tcase_create("s21_strspn");
    tcase_add_test(tc_strspn, s21_strspn_test);
    suite_add_tcase(s, tc_strspn);
    return s;
}

Suite *suite_s21_strspn_1(void) {
    Suite *s;
    s = suite_create("s21_strspn");
    TCase *tc_strspn;
    tc_strspn = tcase_create("s21_strspn");
    tcase_add_test(tc_strspn, s21_strspn_test_1);
    suite_add_tcase(s, tc_strspn);
    return s;
}

Suite *suite_s21_strstr(void) {
    Suite *s;
    s = suite_create("s21_strstr");
    TCase *tc_strstr;
    tc_strstr = tcase_create("s21_strstr");
    tcase_add_test(tc_strstr, s21_strstr_test);
    suite_add_tcase(s, tc_strstr);
    return s;
}

Suite *suite_s21_strtok(void) {
    Suite *s;
    s = suite_create("s21_strtok");
    TCase *tc_strtok;
    tc_strtok = tcase_create("s21_strtok");
    tcase_add_test(tc_strtok, s21_strtok_test);
    suite_add_tcase(s, tc_strtok);
    return s;
}

Suite *suite_s21_strtok_1(void) {
    Suite *s;
    s = suite_create("s21_strtok");
    TCase *tc_strtok;
    tc_strtok = tcase_create("s21_strtok");
    tcase_add_test(tc_strtok, s21_strtok_test_1);
    suite_add_tcase(s, tc_strtok);
    return s;
}

Suite *suite_s21_to_lower(void) {
    Suite *s;
    s = suite_create("s21_to_lower");
    TCase *tc_to_lower;
    tc_to_lower = tcase_create("s21_to_lower");
    tcase_add_test(tc_to_lower, s21_to_lower_test);
    suite_add_tcase(s, tc_to_lower);
    return s;
}

Suite *suite_s21_to_lower_1(void) {
    Suite *s;
    s = suite_create("s21_to_lower");
    TCase *tc_to_lower;
    tc_to_lower = tcase_create("s21_to_lower");
    tcase_add_test(tc_to_lower, s21_to_lower_test_1);
    suite_add_tcase(s, tc_to_lower);
    return s;
}

Suite *suite_s21_to_upper(void) {
    Suite *s;
    s = suite_create("s21_to_upper");
    TCase *tc_to_upper;
    tc_to_upper = tcase_create("s21_to_upper");
    tcase_add_test(tc_to_upper, s21_to_upper_test);
    suite_add_tcase(s, tc_to_upper);
    return s;
}

Suite *suite_s21_to_upper_1(void) {
    Suite *s;
    s = suite_create("s21_to_upper");
    TCase *tc_to_upper;
    tc_to_upper = tcase_create("s21_to_upper");
    tcase_add_test(tc_to_upper, s21_to_upper_test_1);
    suite_add_tcase(s, tc_to_upper);
    return s;
}

Suite *suite_s21_insert(void) {
    Suite *s;
    s = suite_create("s21_insert");
    TCase *tc_insert;
    tc_insert = tcase_create("s21_insert");
    tcase_add_test(tc_insert, s21_insert_test);
    suite_add_tcase(s, tc_insert);
    return s;
}

Suite *suite_s21_trim(void) {
    Suite *s;
    s = suite_create("s21_trim");
    TCase *tc_trim;
    tc_trim = tcase_create("s21_trim");
    tcase_add_test(tc_trim, s21_trim_test);
    suite_add_tcase(s, tc_trim);
    return s;
}

Suite *suite_s21_sprintf(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_1(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_1);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_2(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_2);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_3(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_3);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_4(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_4);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_5(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_5);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_6(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_6);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_7(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_7);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_8(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_8);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_9(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_9);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_10(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_10);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_11(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_11);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_12(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_12);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_13(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_13);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_14(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_14);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_15(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_15);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_16(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_16);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_17(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_17);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_18(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_18);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_19(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_19);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_20(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_20);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_21(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_21);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_22(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_22);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_23(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_23);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_24(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_24);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_25(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_25);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_26(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_26);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_27(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_27);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_28(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_28);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_29(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_29);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_30(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_30);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_31(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_31);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_32(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_32);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_33(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_33);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_34(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_34);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_35(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_35);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_36(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_36);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_37(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_37);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_38(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_38);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_39(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_39);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_40(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_40);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_41(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_41);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_42(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_42);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_43(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_43);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_44(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_44);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_45(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_45);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_46(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_46);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_47(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_47);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_48(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_48);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_49(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_49);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_50(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_50);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_51(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_51);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_52(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_52);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_53(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_53);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_54(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_54);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_55(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_55);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_56(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_56);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_57(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_57);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

Suite *suite_s21_sprintf_58(void) {
    Suite *s;
    s = suite_create("s21_sprintf");
    TCase *tc_sprintf;
    tc_sprintf = tcase_create("s21_sprintf");
    tcase_add_test(tc_sprintf, s21_sprintf_test_58);
    suite_add_tcase(s, tc_sprintf);
    return s;
}

int suite_s21_funct(Suite *s) {
    int no_failed = 0;
    SRunner *runner;
    runner = srunner_create(s);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? 0 : 1;
}

int main(void) {
    suite_s21_funct(suite_s21_memchr());
    suite_s21_funct(suite_s21_memcmp());
    suite_s21_funct(suite_s21_memcmp_1());
    suite_s21_funct(suite_s21_memcmp_2());
    suite_s21_funct(suite_s21_memcpy());
    suite_s21_funct(suite_s21_memmove());
    suite_s21_funct(suite_s21_memmove_1());
    suite_s21_funct(suite_s21_memset());
    suite_s21_funct(suite_s21_strcat());
    suite_s21_funct(suite_s21_strncat());
    suite_s21_funct(suite_s21_strchr());
    suite_s21_funct(suite_s21_strcmp());
    suite_s21_funct(suite_s21_strncmp());
    suite_s21_funct(suite_s21_strcpy());
    suite_s21_funct(suite_s21_strncpy());
    suite_s21_funct(suite_s21_strcspn());
    suite_s21_funct(suite_s21_strerror());
    suite_s21_funct(suite_s21_strerror_1());
    suite_s21_funct(suite_s21_strlen());
    suite_s21_funct(suite_s21_strpbrk());
    suite_s21_funct(suite_s21_strrchr());
    suite_s21_funct(suite_s21_strspn());
    suite_s21_funct(suite_s21_strspn_1());
    suite_s21_funct(suite_s21_strstr());
    suite_s21_funct(suite_s21_strtok());
    suite_s21_funct(suite_s21_strtok_1());
    suite_s21_funct(suite_s21_to_lower());
    suite_s21_funct(suite_s21_to_lower_1());
    suite_s21_funct(suite_s21_to_upper());
    suite_s21_funct(suite_s21_to_upper_1());
    suite_s21_funct(suite_s21_insert());
    suite_s21_funct(suite_s21_trim());
    suite_s21_funct(suite_s21_sprintf());
    suite_s21_funct(suite_s21_sprintf_1());
    suite_s21_funct(suite_s21_sprintf_2());
    suite_s21_funct(suite_s21_sprintf_3());
    suite_s21_funct(suite_s21_sprintf_4());
    suite_s21_funct(suite_s21_sprintf_5());
    suite_s21_funct(suite_s21_sprintf_6());
    suite_s21_funct(suite_s21_sprintf_7());
    suite_s21_funct(suite_s21_sprintf_8());
    suite_s21_funct(suite_s21_sprintf_9());
    suite_s21_funct(suite_s21_sprintf_10());
    suite_s21_funct(suite_s21_sprintf_11());
    suite_s21_funct(suite_s21_sprintf_12());
    suite_s21_funct(suite_s21_sprintf_13());
    suite_s21_funct(suite_s21_sprintf_14());
    suite_s21_funct(suite_s21_sprintf_15());
    suite_s21_funct(suite_s21_sprintf_16());
    suite_s21_funct(suite_s21_sprintf_17());
    suite_s21_funct(suite_s21_sprintf_18());
    suite_s21_funct(suite_s21_sprintf_19());
    suite_s21_funct(suite_s21_sprintf_20());
    suite_s21_funct(suite_s21_sprintf_21());
    suite_s21_funct(suite_s21_sprintf_22());
    suite_s21_funct(suite_s21_sprintf_23());
    suite_s21_funct(suite_s21_sprintf_24());
    suite_s21_funct(suite_s21_sprintf_25());
    suite_s21_funct(suite_s21_sprintf_26());
    suite_s21_funct(suite_s21_sprintf_27());
    suite_s21_funct(suite_s21_sprintf_28());
    suite_s21_funct(suite_s21_sprintf_29());
    suite_s21_funct(suite_s21_sprintf_30());
    suite_s21_funct(suite_s21_sprintf_31());
    suite_s21_funct(suite_s21_sprintf_32());
    suite_s21_funct(suite_s21_sprintf_34());
    suite_s21_funct(suite_s21_sprintf_35());
    suite_s21_funct(suite_s21_sprintf_36());
    suite_s21_funct(suite_s21_sprintf_37());
    suite_s21_funct(suite_s21_sprintf_38());
    suite_s21_funct(suite_s21_sprintf_39());
    suite_s21_funct(suite_s21_sprintf_40());
    suite_s21_funct(suite_s21_sprintf_41());
    suite_s21_funct(suite_s21_sprintf_42());
    suite_s21_funct(suite_s21_sprintf_43());
    suite_s21_funct(suite_s21_sprintf_44());
    suite_s21_funct(suite_s21_sprintf_45());
    suite_s21_funct(suite_s21_sprintf_46());
    suite_s21_funct(suite_s21_sprintf_47());
    suite_s21_funct(suite_s21_sprintf_48());
    suite_s21_funct(suite_s21_sprintf_49());
    suite_s21_funct(suite_s21_sprintf_50());
    suite_s21_funct(suite_s21_sprintf_51());
    suite_s21_funct(suite_s21_sprintf_52());
    suite_s21_funct(suite_s21_sprintf_53());
    suite_s21_funct(suite_s21_sprintf_54());
    suite_s21_funct(suite_s21_sprintf_55());
    suite_s21_funct(suite_s21_sprintf_56());
    suite_s21_funct(suite_s21_sprintf_57());
    suite_s21_funct(suite_s21_sprintf_58());
    return 0;
}
