#include "element.h"
#include <stddef.h>

#define TRUE 1
#define FALSE 0


int main()
{
    struct Element *head = NULL, *tail = NULL;
    printf("\nStart HEAD address [%p] value [%p]\n", (void *)&head, head );
    printf("\nStart TAIL address [%p] value [%p]\n", (void *)&head, head );

    Add_Element_at_End(&head, &tail, 9999, "9999999999999");
    Add_Element_at_End(&head, &tail, 9999, "8888888888");

    Show_All_Elements(head);

    Remove_All(&head, &tail, &head);

    free(head);
    free(tail);
    return 0;
}

