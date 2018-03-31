#ifndef _APUE_H_
#define _APUE_H_

#define _POSIX_C_SOURCE 200809L

#include<sys/types.h>
#include<sys/stat.h>
#include<sys/termios.h>

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

#define MAXLINE 4096

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

#define DIR_MODE (FILE_MODE|S_IXUSR|S_IXGRP|S_IXOTH)

typedef void Sigfunc(init);

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

char*       path_alloc(size_t*);
long        open_max(void);

int         set_cloexec(int);
int         clr_fl(int, int);
int         set_fl(int, int);

void        pr_exit(int);

void        pr_mask(const char*);
Sigfunc*    signal_intr(int, Sigfunc*);

void        daemonize(const char*);

void        sleep_us(unsighed int);
void        readn(int, void*, size_t);
