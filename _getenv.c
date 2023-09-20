#include "shell.h"

/**
 * _getenv - Récupère la valeur d'une variable d'environnement.
 * @variable: Nom de la variable d'environnement à chercher
 *
 * Return: Pointeur vers la valeur de la variable d'environnement, ou NULL si non trouvée
 *
 * Cette fonction recherche la variable d'environnement spécifiée par le paramètre
 * 'variable' et retourne sa valeur.
 */

char *_getenv(char *variable)
{
    char *tmp, *key, *value, *env;
    int i;

    for (i=0; environ[i];i++)
    {
        tmp = _strdup(environ[i]);
        key = strtok(tmp,"=");
        if (_strcmp(key, variable)== 0)
        {
            value = strtok(NULL, "\n");
            env = _strdup(value);
            free(tmp);
            return (env);
        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}
