#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int pres_pro(void);
int full_path(void);
int exec_prog(void);
int system_call(void);
int words_array(char *input);
int line_vibe(void);
int print_all(int ac, char **av);


#endif /* _SHELL_H_ */
