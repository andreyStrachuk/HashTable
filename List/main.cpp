#include "list.h"

int main () {
    FILE *file = fopen ("ListDump.txt", "w");

    List lst = {};

    int resOfAct = 0;

    resOfAct = InitList (&lst);

    for (int i = 0; i < 10; ++i) {
        resOfAct = PushBack (&lst, i + 7);
    }

    if (resOfAct != OK) {
        printf ("Error!\n");
    }

    DumpList (&lst, file);

    free (lst.list);

    return 0;
}