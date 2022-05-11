#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>

#define INITCAPACITY 120

#define ASSERT_OK(smth, do)         if (smth) { do }

#define STR_EQ(str1, str2, length)          (strncmp (str1, str2, length + 1) == 0)

enum ERRORS {
    RECREATING_LIST,
    NULLPTR,
    OK,
    WRONGINDEX,
    NOTHINGTOREMOVE,
    WRONGSIZE,
    WRONGTAIL,
    WRONGHEAD,
    WRONGFREEHEAD,
    LISTISDAMAGED,
    ALLOC_FAILED,
    UNABLETOOPENFILE,
    NOARGUMENTS
};

struct Line {
    char *string;
    int length;
};

typedef char* DATA;

struct ListElement {
    DATA value;
    int length;

    int next;
    int prev;
};

struct List {
    ListElement *list;

    int size;
    int capacity;
    int tail;
    int head;
    int ifSorted;

    int freeHead;
};

int InitList (List *lst);

int PushBack (List *lst, const DATA value, const int length);

int Insert (List *lst, const int index, const DATA value);

int Remove (List *lst, const int index);

int ListSearch (List *lst, char *str, const int length);

int ListSearchOpt (List *lst, const DATA str, const int length);

void PrintList (const List *lst);

int PopFront (List *lst);

int PopBack (List *lst);

List  *LinearList (List *lst);

void DumpList (List *lst, FILE *listDump);

int VerifyList (List *lst);

void PrintErrors (const int err);

int ListDestruct (List *lst);

#endif