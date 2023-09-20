#include "shell.h"

/**
 * main - Fonction principale du programme.
 * @ac: Nombre d'arguments en ligne de commande
 * @argv: Tableau de pointeurs vers les arguments
 *
 * Return: Statut de sortie du programme
 *
 * Cette fonction est la fonction principale du programme. Elle lit une ligne
 * de l'entrée standard, la découpe en commandes, et les exécute.
 */
int main(int ac, char **argv)
{
    char *line = NULL, **command = NULL;
    int idx = 0, status = 0;
    (void) ac;

    while (1)
    {
        line = read_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (status);
        }

        idx++;

        command = tokenizer(line);
        if (!command)
            continue;

        status = _execute(command, argv, idx);
    }

}
