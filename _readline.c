#include "shell.h"
/**
 * read_line - Lit une ligne de l'entrée standard.
 *
 * Return: Pointeur vers la chaîne de caractères contenant la ligne lue.
 *
 * Cette fonction lit une ligne de l'entrée standard et la retourne sous
 * forme d'une chaîne de caractères. Elle gère dynamiquement la mémoire
 * nécessaire à la ligne lue.
 */

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ",2);
    n = getline(&line, &len, stdin);
    if (n == -1)
    {
        free(line);
        return(NULL);
    }

    return (line);
}
