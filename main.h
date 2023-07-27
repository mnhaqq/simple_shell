#ifndef _MAIN_H_
#define _MAIN_H_

/* libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>
#include <ctype.h>

/* function prototypes */
int _putchar(char c);
void _puts(char *str);
char **args_to_array(char *args);
char **read_textfile(const char *filename, size_t letters);
int interactive_mode(void);
int non_interactive_mode(void);
int execute_command(char *line);
int _strlen(char *s);
void free_word_array(char **word_array);
void print_environment(void);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
void remove_extra_whitespace(char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
void exit_builtin(char **args);
char **sep_commands(char *args);
void clear_whitespace(char* str);

/* global varaibles */
extern char **environ;

#endif
