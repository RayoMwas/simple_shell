#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
int prompt(void);
extern char *command;
int printEnvironment(void);
int execute_command(char *command);
#endif
