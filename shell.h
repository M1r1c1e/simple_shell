#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


extern char **environ;
size_t mysh_strlen(const char *strW);
char *mysh_strcpy(char *receiver, const char *giver);
char *mira_strcat(char *dest_str, const char *input);
int mysh_strcmp(const char *sh_str1, const char *sh_str2);
char *mysh_strchr(const char *c_str, int charac);
char *mysh_strncpy(char *output, const char *origin, size_t num);
void program_envPTR(void);
void parent_childfork(char *buffhouse, char *const mira_argv[]);
char **obtain_tokens();
char *get_path(char *inputcom);
void proexit_fig(char **mira_argv);
int main(void);
int countPtr_args(char *const args[]);
void freePtr_args(char *args[]);


#endif
