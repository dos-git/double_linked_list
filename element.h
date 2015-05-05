#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED


#define MAX_BUF_SIZE 256
#define NULL ((void *)0)

struct Data{
	int num;
	char name[MAX_BUF_SIZE];
};

struct Element{
	unsigned int counter;
	struct Element *next, *prev;
	struct Data *data;
};

/*
1 - globals head and tail
void Show_All_Elements(struct Element *);
void Remove_All();
void Remove_Element(struct Element *);
void Add_Element_at_Front(int, char *);
void Add_Element_at_End(int, char *);
*/


void Show_All_Elements(struct Element *);
void Remove_All(struct Element *, struct Element *);
struct Element *Remove_Element(struct Element *, struct Element *, struct Element *);
void Add_Element_at_Front(struct Element *, struct Element *,int, char *);
void Add_Element_at_End(struct Element *, struct Element *,int, char *);

/*
void Show_All_Elements(struct Element *);
//struct Element *Remove_All(struct Element *);
//void Remove_All(struct Element *);
void Remove_All(struct Element *, struct Element *,struct Element *);
struct Element * Remove_Element(struct Element *,struct Element *,struct Element *);
//void Remove_Element(struct Element *);
void Add_Element_at_Front(struct Element *, struct Element *, int, char *);
void Add_Element_at_End(struct Element *, struct Element *, int, char *);
*/

#endif // ELEMENT_H_INCLUDED
