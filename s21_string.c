//  Copyright 2022 jewfishc, trenamim, guinilyc, brainych, plummero
#include "s21_string.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#define LINUX_ERR_CNT 134
#define MAC_ERR_CNT 89
#define LIN_ERR(num) linux_e[num]
#define MAC_ERR(num) mac_e[num]
char linux_e[135][50] = {"Unknown error ",
                "Success",
                "Operation not permitted",
                "No such file or directory",
                "No such process",
                "Interrupted system call",
                "Input/output error",
                "No such device or address",
                "Argument list too long",
                "Exec format error",
                "Bad file descriptor",
                "No child processes",
                "Resource temporarily unavailable",
                "Cannot allocate memory",
                "Permission denied",
                "Bad address",
                "Block device required",
                "Device or resource busy",
                "File exists",
                "Invalid cross-device link",
                "No such device",
                "Not a directory",
                "Is a directory",
                "Invalid argument",
                "Too many open files in system",
                "Too many open files",
                "Inappropriate ioctl for device",
                "Text file busy",
                "File too large",
                "No space left on device",
                "Illegal seek",
                "Read-only file system",
                "Too many links",
                "Broken pipe",
                "Numerical argument out of domain",
                "Numerical result out of range",
                "Resource deadlock avoided",
                "File name too long",
                "No locks available",
                "Function not implemented",
                "Directory not empty",
                "Too many levels of symbolic links",
                "Resource temporarily unavailable",
                "No message of desired type",
                "Identifier removed",
                "Channel number out of range",
                "Level 2 not synchronized",
                "Level 3 halted",
                "Level 3 reset",
                "Link number out of range",
                "Protocol driver not attached",
                "No CSI structure available",
                "Level 2 halted",
                "Invalid exchange",
                "Invalid request descriptor",
                "Exchange full",
                "No anode",
                "Invalid request code",
                "Invalid slot",
                "Resource deadlock avoided",
                "Bad font file format",
                "Device not a stream",
                "No data available",
                "Timer expired",
                "Out of streams resources",
                "Machine is not on the network",
                "Package not installed",
                "Object is remote",
                "Link has been severed",
                "Advertise error",
                "Srmount error",
                "Communication error on send",
                "Protocol error",
                "Multihop attempted",
                "RFS specific error",
                "Bad message",
                "Value too large for defined data type",
                "Name not unique on network",
                "File descriptor in bad state",
                "Remote address changed",
                "Can not access a needed shared library",
                "Accessing a corrupted shared library",
                ".lib section in a.out corrupted",
                "Attempting to link in too many shared libraries",
                "Cannot exec a shared library directly",
                "Invalid or incomplete multibyte or wide character",
                "Interrupted system call should be restarted",
                "Streams pipe error",
                "Too many users",
                "Socket operation on non-socket",
                "Destination address required",
                "Message too long",
                "Protocol wrong type for socket",
                "Protocol not available",
                "Protocol not supported",
                "Socket type not supported",
                "Operation not supported",
                "Protocol family not supported",
                "Address family not supported by protocol",
                "Address already in use",
                "Cannot assign requested address",
                "Network is down",
                "Network is unreachable",
                "Network dropped connection on reset",
                "Software caused connection abort",
                "Connection reset by peer",
                "No buffer space available",
                "Transport endpoint is already connected",
                "Transport endpoint is not connected",
                "Cannot send after transport endpoint shutdown",
                "Too many references: cannot splice",
                "Connection timed out",
                "Connection refused",
                "Host is down",
                "No route to host",
                "Operation already in progress",
                "Operation now in progress",
                "Stale file handle",
                "Structure needs cleaning",
                "Not a XENIX named type file",
                "No XENIX semaphores available",
                "Is a named type file",
                "Remote I/O error",
                "Disk quota exceeded",
                "No medium found",
                "Wrong medium type",
                "Operation canceled",
                "Required key not available",
                "Key has expired",
                "Key has been revoked",
                "Key was rejected by service",
                "Owner died",
                "State not recoverable",
                "Operation not possible due to RF-kill",
                "Memory page has hardware error"};

char mac_e[90][50] = {"Unknown error: ",
                "Success",
                "Operation not permitted",
                "No such file or directory",
                "No such process",
                "Interrupted system call",
                "Input/output error",
                "Device not configured",
                "Argument list too long",
                "Exec format error",
                "Bad file descriptor",
                "No child processes",
                "Resource deadlock avoided",
                "Cannot allocate memory",
                "Permission denied",
                "Bad address",
                "Block device required",
                "Device busy",
                "File exists",
                "Cross-device link",
                "Operation not supported by device",
                "Not a directory",
                "Is a directory",
                "Invalid argument",
                "Too many open files in system",
                "Too many open files",
                "Inappropriate ioctl for device",
                "Text file busy",
                "File too large",
                "No space left on device",
                "Illegal seek",
                "Read-only file system",
                "Too many links",
                "Broken pipe",
                "Numerical argument out of domain",
                "Result too large",
                "Resource temporarily unavailable",
                "Operation now in progress",
                "Operation already in progress",
                "Socket operation on non-socket",
                "Destination address required",
                "Message too long",
                "Protocol wrong type for socket",
                "Protocol not available",
                "Protocol not supported",
                "Socket type not supported",
                "Operation not supported",
                "Protocol family not supported",
                "Address family not supported by protocol family",
                "Address already in use",
                "Can't assign requested address",
                "Network is down",
                "Network is unreachable",
                "Network dropped connection on reset",
                "Software caused connection abort",
                "Connection reset by peer",
                "No buffer space available",
                "Socket is already connected",
                "Socket is not connected",
                "Can't send after socket shutdown",
                "Too many references: can't splice",
                "Operation timed out",
                "Connection refused",
                "Too many levels of symbolic links",
                "File name too long",
                "Host is down",
                "No route to host",
                "Directory not empty",
                "Too many processes",
                "Too many users",
                "Disc quota exceeded",
                "Stale NFS file handle",
                "Too many levels of remote in path",
                "RPC struct is bad",
                "RPC version wrong",
                "RPC prog. not avail",
                "Program version wrong",
                "Bad procedure for program",
                "No locks available",
                "Function not implemented",
                "Inappropriate file type or format",
                "Authentication error",
                "Need authenticator",
                "Device power is off",
                "Device error, e.g. paper out",
                "Value too large to be stored in data type",
                "Bad executable",
                "Bad CPU type in executable",
                "Shared library version mismatch",
                "Malformed Macho file"};

void *s21_memchr(const void *memptr, int val, s21_size_t num) {
    char *res = s21_NULL;
    char *memo = (char*)memptr;
    while ((char*)memptr < memo + num) {
        if (*(char*)memptr == val) {
            res = (char*)memptr;
            break;
        }
        memptr++;
    }
    memptr = memo;
    return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    unsigned char *ptr1 = (unsigned char *)str1;
    unsigned char *ptr2 = (unsigned char *)str2;
    int res = 0;
    for (s21_size_t i = 0; i < n; i++) {
        res = *ptr1 - *ptr2;
        if (*ptr1 != *ptr2) {
            break;
        }
        ptr1++;
        ptr2++;
    }
    return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    unsigned char *tmp_dest = (unsigned char*)dest;
    const unsigned char *tmp_src = (const unsigned char*)src;
    for (s21_size_t i = 0; i < n; ++i) {
        *tmp_dest++ = *tmp_src++;
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t len) {
    unsigned char *d = (unsigned char*)dest;
    unsigned char *s = (unsigned char*)src;
    char *temp = (char*) malloc(sizeof(char) * len);
    if (temp) {
        s21_memcpy(temp, s, len);
        s21_memcpy(d, temp, len);
        free(temp);
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    if (str) {
        char *tmp_mem = (char*)str;
        for (s21_size_t i = 0; i < n; i++) {
            *tmp_mem++ = c;
        }
    }
    return str;
}

char *s21_strcat(char *dest, const char *src) {
    s21_strcpy(dest + s21_strlen(dest), src);
    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    s21_memcpy(dest + s21_strlen(dest), src, n);
    return dest;
}

char *s21_strchr(const char *str, int c) {
    char *res = s21_NULL;
    for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
        if (str[i] == c) {
            res = ((char*)str) + i;
            break;
        }
    }
    return res;
}

int s21_strcmp(const char *str1, const char *str2) {
    for (; *str1 && *str2 && *str1 == *str2; str1++, str2++) {}
    return *str1-*str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int res = 0;
    if (str1 && str2 && n > 0) {
        for (s21_size_t i = 0; i < n; ++i) {
            if (str1[i] == '\0' || str1[i] != str2[i]) {
                res = str1[i] - str2[i];
                break;
            }
        }
    }
    return res;
}

char *s21_strcpy(char *dest, const char *src) {
    char *temp = dest;
    while (*src != '\0') {
        *dest++ = *(char*)src++;
    }
    *dest = '\0';
    return temp;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_memset(dest, '\0', n);
    for (s21_size_t i = 0; i < n && src[i]; i++) {
        dest[i] = src[i];
    }
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t l, k = 0, n = 0;
    while (str1[k] != '\0') {
        for (l = 0; l < s21_strlen(str2); l++) {
            if (str2[l] == str1[k]) {
                break;
            }
        }
        if (str2[l] == str1[k]) {
            break;
        }
        n++;
        k++;
    }
    return n;
}

char *s21_strerror(int errnum) {
    int flag;
    int num = errnum;
    #if defined(__linux__)
        if (errnum <= LINUX_ERR_CNT && errnum >= 0) {
            flag = 1;
        } else {
            flag = 1;
            errnum = -1;
            s21_err_itoa(num, LIN_ERR(0));
        }
    #elif defined(__APPLE__)
        if (errnum <= MAC_ERR_CNT && errnum >=0) {
            flag = 2;
        } else {
            flag = 2;
            errnum = -1;
            s21_err_itoa(num, MAC_ERR(0));
        }
    #else
        flag = 3;
    #endif
    return (flag == 3) ? s21_NULL : ((flag == 1) ? LIN_ERR(errnum + 1) : MAC_ERR(errnum + 1));
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t lenght = 0;
    while (*str != '\0') {
        str++;
        lenght++;
    }
    return lenght;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    s21_size_t l;
    char *res = s21_NULL;
    while (*str1 != '\0') {
        for (l = 0; l < s21_strlen(str2); l++) {
            if (str2[l] == *str1) {
                res = (char*)str1;
                break;
            }
        }
        if (str2[l] == *str1) {
            break;
        }
        str1++;
    }
    return res;
}

char *s21_strrchr(const char *str, int c) {
    char *res = s21_NULL;
    for (int i = s21_strlen(str); i >= 0; i--) {
        if (str[i] == c) {
            res = ((char*)str) + i;
            break;
        }
    }
    return res;
}

s21_size_t s21_strspn(const char *cs, const char *ct) {
    s21_size_t n;
    for (n = 0; *cs; cs++, n++) {
        const char *p;
        for (p = ct; *p && *p != *cs; p++) {}
        if (!*p) {
            break;
        }
    }
    return n;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *res = s21_NULL;
    s21_size_t i = 0, j = 0, k = 0;
    if (s21_strlen(haystack) >= s21_strlen(needle)) {
        for (i = 0; i <= s21_strlen(haystack) - s21_strlen(needle); i++) {
            int flag = 1;
            for (j = i, k = 0; needle[k] != '\0'; j++, k++) {
                if (haystack[j] != needle[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                res = (char*)haystack + i;
                break;
            }
        }
    }
    return res;
}

char *s21_strtok(char *str, const char *delim) {
    static char* buffer;
    char* token = s21_NULL;
    if (str) {
        buffer = str;
        while (*buffer && s21_strchr(delim, *buffer)) {
            *buffer++ = '\0';
        }
    }
    if (buffer && *buffer) {
        str = buffer;
        while (*buffer && !s21_strchr(delim, *buffer)) {
            ++buffer;
        }
        while (*buffer && s21_strchr(delim, *buffer)) {
            *buffer++ = '\0';
        }
        token = str;
    }
    return token;
}

void *s21_to_lower(const char *str) {
    char* s = NULL;
    if (str != s21_NULL) {
        s21_size_t len = s21_strlen(str);
        s = (char*)malloc(sizeof(char) * (len + 1));
        if (s != s21_NULL) {
            for (s21_size_t i = 0; i <= len; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    s[i] = (str[i] - 'A') + 'a';
                } else {
                    s[i] = str[i];
                }
            }
            s[len] = '\0';
        }
    }
    return s;
}

void *s21_to_upper(const char *str) {
    char* s = NULL;
    if (str != s21_NULL) {
        s21_size_t len = s21_strlen(str);
        s = (char*)malloc(sizeof(char) * (len + 1));
        if (s != s21_NULL) {
            for (s21_size_t i = 0; i <= len; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    s[i] = (str[i] - 'a') + 'A';
                } else {
                    s[i] = str[i];
                }
            }
            s[len] = '\0';
        }
    }
    return s;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char* ins = NULL;
    if (src && str) {
        ins = calloc(((s21_strlen(src) + s21_strlen(str)) + 1), sizeof(char));
        start_index--;
        s21_strncat(ins, src, start_index);
        s21_strcat(ins, str);
        s21_strcat(ins, &src[start_index]);
    }
    return ins;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char* temp = NULL;
    if (src) {
        if (trim_chars && *trim_chars) {
            long len = s21_strlen(src) - 1;
            long N = 0;
            temp = calloc(len + 1, sizeof(char));
            s21_memcpy(temp, src, len);
            int i = 0;
            int K = 0;
            for (; i < len; i++) {
                if (s21_is_in_char(src[i], trim_chars)) {
                    N++;
                } else {
                    break;
                }
            }
            temp += N;
            for (int i = len - N - 1; i > 0; i--) {
                if (s21_is_in_char(temp[i], trim_chars)) {
                    K++;
                } else {
                    break;
                }
            }
            temp[len - N - K] = '\0';
        } else {
            temp = s21_trim(src, " \t\n");
        }
    }
    return temp;
}

int s21_max(int a, int b) {
    return (a > b) ? a : b;
}

int s21_sprintf(char *str, const char *fmt, ...) {
    char* buf = str;
    s21_memset(buf, '\0', sizeof(buf));
    char* temp = s21_NULL;
    char* final_string = s21_NULL;
    long int d;
    long double f;
    wchar_t sym;
    char *string;
    uint64_t u;
    int format = 0;
    int left_padding = 0;
    int sign_display = 0;
    int space_instead_sign = 0;
    int width = -1;
    int floating = -1;
    int h_flag = 0;
    int l_flag = 0;
    int L_flag = 0;
    va_list param;
    va_start(param, fmt);
    for (const char *c = fmt; *c ; c++) {
        if ( *c == '\0' ) {
            break;
        }
        if ( format == 0 && *c != '%' ) {
            *buf++ = *c;
            *buf = 0;
            continue;
        }
        if ( format == 0 && *c == '%' ) {
            format = 1;
            continue;
        }
        if ( format ) {
            switch (*c) {
                case '%':
                    if (width != -1 && left_padding == 0) {
                        final_string = calloc(width + 2, sizeof(char));
                        for (int i = 0; i < width; i++) {
                            final_string[i] = ' ';
                            if (i == width - 1) {
                                final_string[i] = '%';
                            }
                        }
                    } else if (width != -1) {
                        final_string = calloc(width + 2, sizeof(char));
                        final_string[0] = '%';
                        for (int i = 1; i < width; i++) {
                            final_string[i] = ' ';
                        }
                    } else {
                        final_string = calloc(2, sizeof(char));
                        final_string[0] = '%';
                    }
                    for (s21_size_t size = 0; size < s21_strlen(final_string); size++) {
                        *buf++ = final_string[size];
                    }
                    free(final_string);
                    s21_release_flags(&format, &left_padding, &sign_display, &space_instead_sign,
                                      &width, &floating, &h_flag, &l_flag, &L_flag);
                    break;
                case '-':
                    left_padding = 1;
                    break;
                case '+':
                    sign_display = 1;
                    break;
                case ' ':
                    space_instead_sign = 1;
                    break;
                case '.':
                    floating = 0;
                    break;
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                    if ((int)floating == -1) {
                        width = s21_atoi((char*)c);
                        while (*(c + 1) > 47 && *(c + 1) < 58) {
                            c++;
                        }
                    } else if ((int)floating == 0) {
                        floating = s21_atoi((char*)c);
                        while (*(c + 1) > 47 && *(c + 1) < 58) {
                            c++;
                        }
                    }
                    break;
                case 'h':
                    h_flag = 1;
                    break;
                case 'l':
                    l_flag = 1;
                    break;
                case 'L':
                    L_flag = 1;
                    break;
                case 'i':
                case 'd':
                    if ( h_flag ) {
                        d = (short int)va_arg(param, int);
                    } else if ( l_flag ) {
                        d = va_arg(param, long int);
                    } else {
                        d = va_arg(param, int);
                    }
                    temp = s21_int_to_string(d, floating);
                    final_string = calloc(s21_strlen(temp) + 1, sizeof(char));
                    final_string = s21_add_sign(final_string, temp, sign_display,
                                                space_instead_sign, (long double)d);
                    final_string = s21_add_zero(final_string, temp, floating);
                    s21_strcat(final_string, temp);
                    free(temp);
                    final_string = s21_add_spaces(final_string, width, left_padding);
                    for (s21_size_t size = 0; size < s21_strlen(final_string); size++) {
                        *buf++ = final_string[size];
                    }
                    s21_release_flags(&format, &left_padding, &sign_display, &space_instead_sign,
                                      &width, &floating, &h_flag, &l_flag, &L_flag);
                    free(final_string);
                    break;
                case 'f':
                    if ( L_flag ) {
                        f = va_arg(param, long double);
                    } else {
                        f = va_arg(param, double);
                    }
                    temp = s21_float_to_string(f, floating);
                    final_string = calloc(s21_strlen(temp) + 1, sizeof(char));
                    final_string = s21_add_sign(final_string, temp,  sign_display,
                                                space_instead_sign, (long double)f);
                    s21_strcat(final_string, temp);
                    free(temp);
                    final_string = s21_add_spaces(final_string, width, left_padding);
                    for (s21_size_t size = 0; size < s21_strlen(final_string); size++) {
                        *buf++ = final_string[size];
                    }
                    s21_release_flags(&format, &left_padding, &sign_display,
                                      &space_instead_sign, &width, &floating,
                                      &h_flag, &l_flag, &L_flag);
                    free(final_string);
                    break;
                case 'c':
                    sym = (char)va_arg(param, int);
                    width = width == -1 ? 0 : width;
                    final_string = calloc(width + 2, sizeof(char));
                    char* fs = final_string;
                    if (width != 0 && left_padding == 0) {
                        for (int i = 1; i < width; i++) {
                            *fs++ = ' ';
                            if (i == width - 1) {
                                *fs++ = sym;
                            }
                        }
                        *fs = 0;
                    } else if (width != 0) {
                        *fs++ = sym;
                        for (int i = 1; i < width; i++) {
                            *fs++ = ' ';
                        }
                        *fs = 0;
                    } else {
                        *fs++ = sym;
                        *fs = 0;
                    }
                    s21_size_t len = fs - final_string;
                    for (s21_size_t size = 0; size < len ; size++) {
                        *buf++ = final_string[size];
                    }
                    s21_release_flags(&format, &left_padding, &sign_display, &space_instead_sign,
                                      &width, &floating, &h_flag, &l_flag, &L_flag);
                    free(final_string);
                    break;
                case 's':
                    string = va_arg(param, char*);
                    if (string == s21_NULL) string = "(null)";
                    int input_len = s21_strlen(string);
                    if (floating < input_len && floating >= 0) {
                        input_len = floating;
                    }
                    int output_len = s21_max(width, input_len);
                    int padding_len = s21_max(0, width - input_len);
                    final_string = calloc(output_len + 1, sizeof(char));
                    final_string[output_len] = '\0';
                    char* s_ptr;
                    char* p_ptr;
                    if (left_padding == 1) {
                        s_ptr = &final_string[0];
                        p_ptr = &final_string[input_len];
                    } else {
                        s_ptr = &final_string[padding_len];
                        p_ptr = &final_string[0];
                    }
                    s21_memset(p_ptr, ' ', padding_len);
                    s21_memcpy(s_ptr, string, input_len);
                    for (s21_size_t size = 0; size < s21_strlen(final_string); size++) {
                        *buf++ = final_string[size];
                    }
                    s21_release_flags(&format, &left_padding, &sign_display,
                                      &space_instead_sign, &width, &floating,
                                      &h_flag, &l_flag, &L_flag);
                    free(final_string);
                    break;
                case 'u':
                    u = va_arg(param, uint64_t);
                    if ( h_flag ) {
                        u = (uint16_t)u;
                    } else if ( l_flag ) {
                        u = (uint64_t)u;
                    } else {
                        u = (uint32_t)u;
                    }
                    temp = s21_uint_to_string(u, floating);
                    final_string = calloc(s21_strlen(temp) + 1, sizeof(char));
                    final_string = s21_add_zero(final_string, temp, floating);
                    s21_strcat(final_string, temp);
                    free(temp);
                    final_string = s21_add_spaces(final_string, width, left_padding);
                    for (s21_size_t size = 0; size < s21_strlen(final_string); size++) {
                        *buf++ = final_string[size];
                    }
                    s21_release_flags(&format, &left_padding, &sign_display,
                                      &space_instead_sign, &width, &floating,
                                      &h_flag, &l_flag, &L_flag);
                    free(final_string);
                    break;
            }
        }
    }
    va_end(param);
    *buf = 0;
    return buf - str;
}

void s21_release_flags(int *format, int *left_padding, int *sign_display,
                       int *space_instead_sign, int *width, int *floating,
                       int *h_flag, int *l_flag, int *L_flag) {
    *format = 0;
    *left_padding = 0;
    *sign_display = 0;
    *space_instead_sign = 0;
    *width = -1;
    *floating = -1;
    *h_flag = 0;
    *l_flag = 0;
    *L_flag = 0;
}

char *s21_add_zero(char* dest, char* src, int floating) {
    if ((int)floating > (int)s21_strlen(src)) {
        s21_size_t k = s21_strlen(dest);
        if (s21_strlen(dest)) floating++;
        dest = realloc(dest, (floating + 1) * sizeof(char));
        for (; k < (floating - s21_strlen(src)); k++) {
            s21_strcat(dest, "0");
        }
        dest[k] = '\0';
    }
    return dest;
}

char *s21_add_spaces(char* dest, int width, int left_padding) {
    int str_len = s21_strlen(dest);
    if (str_len < width) {
        char* temp = calloc(width + 1, sizeof(char));
        int padding_len = width - str_len;

        char *spc_ptr = calloc(padding_len + 1, sizeof(char));
        s21_memset(spc_ptr, ' ', padding_len);
        spc_ptr[padding_len] = 0;

        if (left_padding == 1) {
            s21_strcat(temp, dest);
            s21_strcat(temp, spc_ptr);
        } else {
            s21_strcat(temp, spc_ptr);
            s21_strcat(temp, dest);
        }
        free(spc_ptr);
        free(dest);
        dest = temp;
    }
    return dest;
}

char *s21_add_sign(char* dest, char* src, int sign_display,
               int space_instead_sign, long double number) {
    if ( number < 0.0 || (int)sign_display == 1 ) {
        dest = realloc(dest, s21_strlen(src) + 2);
        if ( number < 0 ) {
            dest[0] = '-';
        } else {
            dest[0] = '+';
        }
        dest[1] = '\0';
    } else if (space_instead_sign == 1) {
        dest = realloc(dest, s21_strlen(src) + 2);
        if ( number < 0.0 ) {
            dest[0] = '-';
        } else {
            dest[0] = ' ';
        }
        dest[1] = '\0';
    }
    return dest;
}

char *s21_int_to_string(long int num, long int floating) {
    int i = 1, j, k, c;
    char* str = calloc(i, sizeof(char));
    if (num != 0) {
        while ( num != 0 ) {
            str[i - 1] = (num < 0 ? (-1*(num % 10)) : (num % 10)) + '0';
            str = realloc(str, ++i * sizeof(char));
            if (!str) exit(0);
            num /= 10;
        }
    } else if (floating != 0) {
        str[i - 1] = '0';
        str = realloc(str, ++i * sizeof(char));
        if (!str) exit(0);
    }
    str[i - 1] = 0;
    for (j = 0, k = s21_strlen(str) - 1; j < k; j++, k--) {
        c = str[j];
        str[j] = str[k];
        str[k] = c;
    }
    return str;
}

int s21_atoi(char* str) {
    int res = 0;
    while (*str > 47 && *str < 58) {
        res = res *  10 + *str - '0';
        str++;
    }
    return res;
}

char *s21_err_itoa(int num, char* unk_err) {
    int dec = 1;
    int N = 0;
    int sgn = 0;
    while (num / dec != 0) {
        dec *= 10;
        N++;
    }
    if (num < 0) {
    #if defined(__linux__)
        unk_err[14] = '-';
    #elif defined(__APPLE__)
        unk_err[15] = '-';
    #endif
        sgn++;
        num = - num;
    }
    for (int i = 1; i < N + 1; i++) {
        dec /= 10;
    #if defined(__linux__)
        unk_err[13 + sgn + i] = num / dec + 48;
    #elif defined(__APPLE__)
        unk_err[14 + sgn + i] = num / dec + 48;
    #endif
        num -= num / dec * dec;
    }
#if defined(__linux__)
    unk_err[13 + sgn + N + 1] = 0;
#elif defined(__APPLE__)
    unk_err[14 + sgn + N + 1] = 0;
#endif
    return unk_err;
}

int s21_is_in_char(const char c, const char* str) {
    int is = 0;
    int i = 0;
    for (; str[i] != 0; i++) {
        if (str[i] == c) {
            break;
        }
    }
    if (str[i] != 0) {
        is = 1;
    }
    return is;
}

char *s21_uint_to_string(unsigned long long num, long int floating) {
    int i = 1, j, k, c;
    char* str = calloc(i, sizeof(char));
    if (num != 0) {
        while ( num > 0 ) {
            str[i - 1] = ( (num % 10) + '0');
            str = realloc(str, ++i * sizeof(char));
            if (!str) exit(0);
            num /= 10;
        }
    } else if (floating != 0) {
        str[i - 1] = '0';
        str = realloc(str, ++i * sizeof(char));
        if (!str) exit(0);
    }
    str[i - 1] = 0;
    for (j = 0, k = s21_strlen(str) - 1; j < k; j++, k--) {
        c = str[j];
        str[j] = str[k];
        str[k] = c;
    }
    return str;
}

unsigned int s21_float_normalize(long double *num) {
    unsigned int res = 1;
    while (*num >= 10 || *num <= -10) {
        res++;
        *num /= 10;
    }
    return res;
}

char *s21_float_to_string(long double num, int floating) {
    char *str = NULL;
    unsigned int exp = 1;
    long double num_cpy = num;
    exp = s21_float_normalize(&num_cpy);
    int i = 0;
    floating = (floating == -1) ? 6 : floating;
    if (num_cpy < 0) num_cpy *= -1;
    if (floating == 0) {
        str = s21_int_to_string((long int)roundl(num), 1);
    } else {
        str = calloc(exp + floating + 2, sizeof(char));
        while (exp > 0) {
            str[i++] = (((int)num_cpy % 10) + '0');
            num_cpy -= (int)num_cpy;
            num_cpy *= 10;
            exp--;
        }
        str[i++] = '.';
        while (floating > 0) {
            str[i++] = floating == 1 ? (((int)roundl(num_cpy) % 10) + '0') :(((int)num_cpy % 10) + '0');
            num_cpy -= (int)num_cpy;
            num_cpy *= 10;
            floating--;
        }
        str[i] = 0;
    }
    return str;
}

