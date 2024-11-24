#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
<<<<<<< HEAD
#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/fs.h>
#include <sys/wait.h>
=======
>>>>>>> assignments-base/assignment5

bool do_system(const char *command);

bool do_exec(int count, ...);

bool do_exec_redirect(const char *outputfile, int count, ...);
