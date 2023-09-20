#include "shell.h"

/**
 * freearray2D - Libère la mémoire allouée pour un tableau 2D de chaînes de caractères.
 * @arr: Pointeur vers le tableau 2D
 *
 * Cette fonction libère la mémoire allouée pour un tableau 2D de chaînes de caractères.
 */

void freearray2D(char **arr)
{
    int i;

    if (!arr)
        return;

    for (i=0; arr[i]; i++)
    {
        free(arr[i]);
        arr[i]= NULL;

    }

    free(arr), arr = NULL;
}

/**
 * printerror - Affiche un message d'erreur avec le nom, la commande et l'indice donnés.
 * @name: Nom du programme
 * @cmd: Commande qui a causé l'erreur
 * @indx: Indice associé à l'erreur
 *
 * Cette fonction affiche un message d'erreur sur la sortie d'erreur standard (stderr).
 */
void printerror(char *name, char *cmd, int indx)
{
    char *index, mssg[]= ": not found\n";

    index = _itoa(indx);

    write(STDERR_FILENO, name,_strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index,_strlen(index));
    write(STDERR_FILENO, ": ",2);
    write(STDERR_FILENO, cmd,_strlen(cmd));
    write(STDERR_FILENO, mssg,_strlen(mssg));

    free(index);
}


/**
 * reverse_string - Inverse une chaîne de caractères.
 * @str: Chaîne de caractères à inverser
 * @len: Longueur de la chaîne
 *
 * Cette fonction inverse une chaîne de caractères donnée.
 */
void reverse_string(char *str, int len)
{
    char tmp;
    int start = 0;
    int end = len -1;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}

/**
 * _itoa - Convertit un entier en une chaîne de caractères.
 * @n: Entier à convertir
 *
 * Return: Pointeur vers la chaîne de caractères résultante
 *
 * Cette fonction convertit un entier en une chaîne de caractères.
 */

char *_itoa(int n)
{
    char buffer[20];
    int i=0;

    if (n==0)
        buffer [i++] = '0';
    else
    {
        while (n>0)
        {
            buffer[i++] = (n%10)+ '0';
            n/=10;
        }
    }

    buffer[i] ='\0';
    reverse_string(buffer, i);

    return (_strdup(buffer));
}
