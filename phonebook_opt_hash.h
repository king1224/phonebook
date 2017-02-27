#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 42737

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define HASH 1
typedef struct __DETAL_DATA {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detal;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    detal *data;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

unsigned int DJB2HASH(char *str);
entry *findName(char lastName[], entry *p[]);
void append(char lastName[], entry *e[]);


#endif
