#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#include "mylib.h"

#include <stdio.h>
#include <stdlib.h>

int run (char *command, int *result){

    int pid, status, i;
    char *args[MAX_ARGS];

    i = 0;
    args[i] = strtok(command, DELIMITER);
    while(  (args[++i] == strtok(NULL, DELIMITER))  );

        /* Fork */
        pid = fork();

    //Se o fork falhar, retorna 0 e nao seta resultado
    if (pid < 0){
        return 0;
    }

    if(pid > 0){    //Caller
        wait (&status); //Espera o subprocesso parar
        if(WIFEXITED(status))
            *result= WEXITSTATUS(status);
        else
            *result = -1;
            return -1;
    }else{              //Subprocess
        execvp(args[0], args);
    }
    
   printf("progama nao existe");
   *result = 0;
   return -1;



    return pid;
}











