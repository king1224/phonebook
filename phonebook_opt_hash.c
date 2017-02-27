#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
unsigned int DJB2HASH(char *str)
{
    long long int hash=0;
    do {
        hash = (hash << 5) + (*str++);
    } while(*str);
    return hash % TABLE_SIZE;
}

entry *findName(char lastName[], entry *p[])
{
    /* TODO: implement */
    unsigned int pos = DJB2HASH(lastName);
    entry *tmp = p[pos];
    if(tmp == NULL)
        return NULL;
    do {
        if(strcasecmp(lastName, tmp->lastName) == 0)
            return tmp;
        tmp = tmp->pNext;
    } while(tmp != NULL);

}

void append(char lastName[], entry *e[])
{
    unsigned int pos = DJB2HASH(lastName);

    if(!e[pos]) {
        e[pos] = (entry *) malloc(sizeof(entry));
        strcpy(e[pos]->lastName, lastName);
        e[pos]->pNext = NULL;
    } else {
        entry *new = (entry *) malloc(sizeof(entry));
        strcpy(new->lastName, lastName);
        new->pNext = e[pos];
        e[pos] = new;
    }
}
