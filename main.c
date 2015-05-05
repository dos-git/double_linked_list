
#define TRUE 1
#define FALSE 0

#include "element.h"

extern struct Element *head, *tail;

int main()
{
    Add_Element_at_Front(head, tail, 7, "domino");
    Add_Element_at_Front(head, tail, 9, "stefano");
    Add_Element_at_Front(head, tail, 11, "lobek");
    Add_Element_at_End(head, tail, 6666, "norek");
    Show_All_Elements(head);
    Remove_All(head, tail);

    return 0;
}
