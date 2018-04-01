#include"../include/apue.h"
#include<errno.h>
#include<stdarg.h>

static void err_doit(int, int, const char*, va_list);

//Nonfatal error related to a system call. Print and return.
void err_ret(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1,errno, fmt, ap);
    va_end(ap);
}

//Fatal error related to a system call. Print and terminate.
void err_sys(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}

//Nonfatal error unrelated to a system call. Print and return.
void err_cont(int error, const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, error, fmt, ap);
    va_end(ap);
}

//Fatal error unrelated to a system all. Print and terminate.
void err_exit(int error, const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, error, fmt, ap);
    va_end(ap);
    exit(1);
}

//Fatal error related to a system call. Print, dump core and terminate.
void err_dump(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    abort();
    exit(1);
}

//Nonfatal error unrelated to a system call. Print and return.
void err_msg(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
}

//Fatal error unrelated to a system call. Print and terminate.
void err_quit(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
    exit(1);
}

static void err_doit(int errno_flag, int error, const char* fmt, va_list ap)
{
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE-1, fmt, ap);
    if(errno_flag)
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1, ": %s", strerror(error));
    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}
