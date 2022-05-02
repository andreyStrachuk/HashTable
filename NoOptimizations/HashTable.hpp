#ifndef HASHTABLE
#define HASHTABLE

#include "../List/list.h"
#include <string.h>
#include <ctype.h>

#define HASHTABLESIZE 9973

struct HashTable {

    List *listArr;

    int size;

};


int HashTableInit (HashTable *table, const int size);

int HashTableDestruct (HashTable *table);

int FillHashTable (HashTable *table, const char *fileName, int (* HashFunction)(void *, int));

int HashTableInsert (HashTable *table, char *str, int length, int (* HashFunction)(void *, int));

int HashASCII (void *str, const int length);

int HashFirstLetter (void *str, const int length);

int HashROL (void *str, const int length);

int HashCRC32 (void *str, const int length);

int GetFileSize (FILE *input);

char *GetBuffer (const char *fileName);

int FillBuffer (HashTable *table, char *buffer, const int length, int (* HashFunction)(void *, int));

int ModifyBuffer (char *str);

char *FindFirstLetter (char *str);

char *FindLastLetter (char *str);


#endif
