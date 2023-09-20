#include "shell.h"

/**
 * _getpath - Obtient le chemin complet d'une commande.
 * @command: Nom de la commande à rechercher
 *
 * Return: Pointeur vers le chemin complet de la commande, ou NULL si non trouvé
 *
 * Cette fonction cherche le chemin complet de la commande spécifiée dans les
 * répertoires listés dans la variable d'environnement PATH.
 */

char *_getpath(char *command)
{
    char *path_env, *full_cmd, *dir;
    int i;
    struct stat sto;

    for (i=0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &sto) == 0)
                return (_strdup(command));
            return (NULL);
        }
    }

    path_env = _getenv("PATH");
    if (!path_env)
        return (NULL);

    dir = strtok(path_env, ":");
    while (dir)
    {
        full_cmd = malloc(_strlen(dir)+_strlen(command) + 2);
        if (full_cmd)
        {
            _strcpy(full_cmd, dir);
            _strcat(full_cmd, "/");
            _strcat(full_cmd, command);
            if (stat(full_cmd, &sto) == 0)
            {
                free(path_env);
                return (full_cmd);
            }
            free(full_cmd), full_cmd = NULL;

            dir = strtok(NULL, ":");
        }
    }
    free(path_env);
    return (NULL);
}
