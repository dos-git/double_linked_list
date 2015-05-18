#include "element.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#Show_All_Elements - display all elements form a list
*/
void Show_All_Elements(struct Element *p)
{
	if (p==NULL) {
		puts("List does not have elements.");
	} else {
		while (p) {
			printf("%s    id: %i\n", p->data->name, p->data->num);
			p = p->next;
		}
	}
}

/*
#Create_Item - creates a data for a new list node
*/
struct Data *Create_Item(int data_number, char *data_name)
{
    struct Data *data = (struct Data *)malloc(sizeof(struct Data));
    strcpy(data->name, data_name);
    data->num = data_number;
    return data;
}

/*
#Add_Element_at_Front - insert a new item at the front of list
*/
void Add_Element_at_Front(struct Element **hd, struct Element **tl,int new_number, char *new_name)
{
	struct Data *data = Create_Item(new_number, new_name);
	struct Element *e = (struct Element *)malloc(sizeof(struct Element));
	e->data = data;
	e->prev = NULL;
	e->next = (*hd);
	*hd = e;

	if(e->next) e->next->prev = e;      /* case if list is not empty    */
	else        *tl = e;                /* case if list is empty        */
}

/*
#Add_Element_at_End - insert a new item at the end of list
*/
void Add_Element_at_End(struct Element **hd, struct Element **tl, int new_number, char *new_name)
{
    struct Data *data = Create_Item(new_number, new_name);
	struct Element *e = (struct Element *)malloc(sizeof(struct Element));
	e->data = data;
	e->next = NULL;
	e->prev = (*tl);
	*tl = e;

//	if(e->prev) (*tl)->prev->next = e;  /* equivalent code    */
	if(e->prev) e->prev->next = e;  /* case if list is not empty    */
	else        *hd = e;            /* case if list is empty        */
}

/*
#Remove_Element - remove first or last element from a list by passing respectively
                  the head or tail pointer
*/
struct Element *Remove_Element(struct Element **hd, struct Element **tl, struct Element **e)
{
	struct Element *tmp = (*e);     /* temporary item for a processing          */
	struct Element *ret = NULL;     /* item that will be reurned by function    */

	if((*e)!=NULL){
        /*  reasigne pointers next/previous from a removed element  */
        /*  1. removing by using the head's pointer                    */
		if (tmp->next) {
            tmp->next->prev = tmp->prev;
        } else {
            (*tl) = tmp->prev;
            ret = (*tl);
		}
        /*  2/ removing by using the tail's pointer    */
		if (tmp->prev) {
            tmp->prev->next = tmp->next;
        } else {
            (*hd) = tmp->next;
            ret = (*hd);
        }
        /*  release allocated memory  */
        if (tmp) {
            free(tmp->data);
            free(tmp);
        }
        return ret;     /*  return a pointer that has been used: head/tail  */
	} else {
		return NULL;
	}
}

/*
#Remove_All - removes all elementd from a list
*/
void Remove_All(struct Element **hd, struct Element **tl, struct Element **hd_or_tl)
{
    while ( (*hd_or_tl) != NULL ) {
        (*hd_or_tl) = Remove_Element(&(*hd), &(*tl), &(*hd_or_tl));

        }
}

