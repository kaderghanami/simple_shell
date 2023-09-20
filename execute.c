#include "shell.h"

/**
 * _execute - Exécute une commande avec fork() et execve().
 * @command: Tableau de pointeurs vers les arguments de la commande
 * @argv: Tableau de pointeurs vers les arguments passés au programme principal
 * @idx: Numéro de la commande dans la séquence
 *
 * Return: Statut de sortie de la commande exécutée
 *
 * Cette fonction exécute une commande en créant un processus fils avec fork(),
 * puis en remplaçant l'image du processus fils avec la commande spécifiée par
 * execve(). Elle attend ensuite que le processus fils se termine et retourne
 * le statut de sortie.
 */

int _execute(char **command, char **argv, int idx)
{
    char *full_cmd;
    pid_t child;
    int status;

    full_cmd = _getpath(command[0]);
    if (!full_cmd)
    {
        printerror(argv[0], command[0], idx);
        freearray2D(command);
        return(127);
    }

    child = fork();
    if (child == 0)
    {
        if (execve(full_cmd, command, environ)== -1)
        {
            free(full_cmd), full_cmd = NULL;
            freearray2D(command);
        }
    }
    else
    {
        waitpid(child,&status, 0);
        freearray2D(command);
        free(full_cmd), full_cmd = NULL;
    }
    return(WEXITSTATUS(status));
}
