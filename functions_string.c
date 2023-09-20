#include "shell.h"
/**
 * _strcpy - Copie la chaîne source dans la chaîne de destination.
 * @dest: Pointeur vers la chaîne de destination
 * @src: Pointeur vers la chaîne source
 *
 * Return: Pointeur vers la chaîne de destination
 */

char *_strcpy(char *dest, char *src)
{
    int i =0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i]= '\0';
    return (dest);
}

/**
 * _strdup - Duplique une chaîne de caractères.
 * @str: Chaîne à dupliquer
 *
 * Return: Pointeur vers la nouvelle chaîne de caractères
 */

char *_strdup(const char *str)
{
    char *ptr;
    int i, len = 0;

    if (str== NULL)
        return (NULL);
    while (str[len])
        len++;

    ptr = malloc(sizeof(char) * (len +1));
    if(ptr == NULL)
        return (NULL);
    for (i=0 ; i <=len; i++)
        ptr[i] = str[i];
    return (ptr);
}

/**
 * _strcmp - Compare deux chaînes de caractères.
 * @s1: Première chaîne à comparer
 * @s2: Seconde chaîne à comparer
 *
 * Return: Différence entre les caractères
 */

int _strcmp(char *s1, char *s2)
{
    int cmp;

    cmp = (int)*s1-(int)*s2;
    while (*s1)
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
        cmp = (int)*s1 - (int)*s2;
    }
    return(cmp);
}

/**
 * _strlen - Calcule la longueur d'une chaîne de caractères.
 * @s: Chaîne de caractères
 *
 * Return: Longueur de la chaîne
 */


int _strlen(char *s)
{
    int len =0;

    while (s[len])
        len++;
    return (len);
}

/**
 * _strcat - Concatène la chaîne source à la fin de la chaîne destination.
 * @dest: Chaîne de destination
 * @src: Chaîne source
 *
 * Return: Pointeur vers la chaîne de destination
 */

char *_strcat(char *dest, char *src)
{
    char *p= dest;

    while (*p)
        p++;

    while (*src)
    {
        *p = *src;
        p++;
        src++;
    }
    *p = '\0';
    return (dest);
}
