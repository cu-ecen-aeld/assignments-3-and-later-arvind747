#include "systemcalls.h"

/**
 * @param cmd the command to execute with system()
 * @return true if the command in @param cmd was executed
 *   successfully using the system() call, false if an error occurred,
 *   either in invocation of the system() call, or if a non-zero return
 *   value was returned by the command issued in @param cmd.
*/
bool do_system(const char *cmd)
{

/*
 * TODO  add your code here
 *  Call the system() function with the command set in the cmd
 *   and return a boolean true if the system() call completed with success
 *   or false() if it returned a failure
*/
<<<<<<< HEAD
    int ret;

    ret = system(cmd);
    
    // checking if the command was executed successfully
    if (ret == 0) {
        printf("Command executed successfully. \n");

        if(WIFEXITED (ret))
        {
             printf ("Normal termination with exit status=%d\n", WEXITSTATUS (ret));
             return true; 
        }
        else
        {
            printf ("Normal termination with exit status=%d\n", WEXITSTATUS (ret));
            return false;
        }
    }
    else {
        printf("Command execution failed or returned \n");
        return false;
    }
=======

    return true;
>>>>>>> assignments-base/assignment5
}

/**
* @param count -The numbers of variables passed to the function. The variables are command to execute.
*   followed by arguments to pass to the command
*   Since exec() does not perform path expansion, the command to execute needs
*   to be an absolute path.
* @param ... - A list of 1 or more arguments after the @param count argument.
*   The first is always the full path to the command to execute with execv()
*   The remaining arguments are a list of arguments to pass to the command in execv()
* @return true if the command @param ... with arguments @param arguments were executed successfully
*   using the execv() call, false if an error occurred, either in invocation of the
*   fork, waitpid, or execv() command, or if a non-zero return value was returned
*   by the command issued in @param arguments with the specified arguments.
*/

bool do_exec(int count, ...)
{
    va_list args;
    va_start(args, count);
    char * command[count+1];
    int i;
<<<<<<< HEAD
    int status;
    pid_t pid;
=======
>>>>>>> assignments-base/assignment5
    for(i=0; i<count; i++)
    {
        command[i] = va_arg(args, char *);
    }
    command[count] = NULL;
    // this line is to avoid a compile warning before your implementation is complete
    // and may be removed
    command[count] = command[count];

/*
 * TODO:
 *   Execute a system command by calling fork, execv(),
 *   and wait instead of system (see LSP page 161).
 *   Use the command[0] as the full path to the command to execute
 *   (first argument to execv), and use the remaining arguments
 *   as second argument to the execv() command.
 *
*/
<<<<<<< HEAD
   //printf("command command[0] = %s *(command+1)= %s",command[0], *(command+1));
   va_end(args);

    pid = fork();
    if(pid == -1)
    {
        return -1;
    }
    else if(pid == 0)
    {
        execv(command[0], command);
        exit(EXIT_FAILURE);
    }
    else
    {
        pid = waitpid (-1, &status, 0);
        if (pid == -1)
        {
            perror ("waitpid");
        }
        else 
        {
            printf ("pid=%d\n", pid);
            
            if (WIFEXITED (status))
            {
            printf ("Normal termination with exit status=%d\n", WEXITSTATUS (status));
            }
            else if (WIFSIGNALED (status))
            {
            printf ("Killed by signal=%d%s\n", WTERMSIG (status), WCOREDUMP (status) ? " (dumped core)" : "");
            }
            else
            {
               /* do nothing */
            }
	    }
	
        return (status == EXIT_SUCCESS);
    }
=======

    va_end(args);

    return true;
>>>>>>> assignments-base/assignment5
}

/**
* @param outputfile - The full path to the file to write with command output.
*   This file will be closed at completion of the function call.
* All other parameters, see do_exec above
*/
bool do_exec_redirect(const char *outputfile, int count, ...)
{
    va_list args;
    va_start(args, count);
    char * command[count+1];
    int i;
<<<<<<< HEAD
    int kidpid;
    int status;

    int fd = open(outputfile, O_WRONLY|O_TRUNC|O_CREAT, 0644);

    if (fd < 0) 
    { 
        perror("open"); 
        abort(); 
    }

=======
>>>>>>> assignments-base/assignment5
    for(i=0; i<count; i++)
    {
        command[i] = va_arg(args, char *);
    }
    command[count] = NULL;
    // this line is to avoid a compile warning before your implementation is complete
    // and may be removed
    command[count] = command[count];


/*
 * TODO
 *   Call execv, but first using https://stackoverflow.com/a/13784315/1446624 as a refernce,
 *   redirect standard out to a file specified by outputfile.
 *   The rest of the behaviour is same as do_exec()
 *
*/
<<<<<<< HEAD
   switch (kidpid = fork()) 
   {
      case -1: perror("fork"); abort();
      case 0:
        if (dup2(fd, 1) < 0)
        { 
            perror("dup2"); 
            abort(); 
        }
        
        close(fd);
        execv(command[0], command);
        exit(EXIT_FAILURE);
      default:
      
        if (waitpid (-1, &status, 0) == -1)
        {
            return -1;
        }
        else if (WIFEXITED (status))
        {
            return WEXITSTATUS (status);
        }
        else
        {
            /* do nothing */
        }
        close(fd);
            return (status == EXIT_SUCCESS);;
        /* do whatever the parent wants to do. */
  }  

    va_end(args);


}

=======

    va_end(args);

    return true;
}
>>>>>>> assignments-base/assignment5
