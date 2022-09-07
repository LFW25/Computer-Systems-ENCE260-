# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>

# include "linkedlist.h"

void addElement(LinkedList_t* list, char data)
{
    LinkedListElement_t* newElement = calloc(1, sizeof(LinkedListElement_t));
    newElement->data = data;

    if (list->head == NULL) {
        list->head = newElement;
        list->tail = newElement;
    } else {
        LinkedListElement_t* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
        list->tail = newElement;
    }
}

LinkedListElement_t* findElement(LinkedList_t* list, char data)
{
    LinkedListElement_t* current = list->head;
    while (current->next != NULL) {
        if (current->data == data) {
            return current;
        } else {
            current = current->next;
        }
    }
    if (current->data == data) {
        return current;
    } else {
        return NULL;
    }    
}

void deleteElement(LinkedList_t* list, LinkedListElement_t* element)
{
    if ((element != NULL) && (findElement(list, element->data) != NULL)) {
        if (list->head == element) {
            if (list->tail == element) {
                LinkedListElement_t* oldHead = list->head;
                list->tail = NULL;
                list->head = NULL;
                free(oldHead);
            } else {
                LinkedListElement_t* oldHead = list->head;
                list->head = (list->head)->next;
                oldHead->next = NULL;
                free(oldHead);
            }
        } else {
            LinkedListElement_t* current = list->head;
            LinkedListElement_t* previous = list->head;
            while (current->next != NULL) {
                if (current == element) {
                    previous->next = current->next;
                    current->next = NULL;
                    free(current);
                    break;
                } else {
                    previous = current;
                    current = current->next;
                }
            }
            if (element == list->tail) {
                list->tail = previous;
                (list->tail)->next = NULL;
                free(current);
            }
        }
    } else if (element != NULL) {
        free(element);
    }
}


int main(void)
{
    
    LinkedList_t alist1 = {.head = NULL, .tail = NULL};
    LinkedListElement_t* element1;
    addElement(&alist1, 'a');
    addElement(&alist1, 'b');
    addElement(&alist1, 'c');
    element1 = findElement(&alist1, 'b');
    deleteElement(&alist1, element1);
    printf("Result: ");
    for (LinkedListElement_t* elem=alist1.head; elem != NULL; elem = elem->next) {
        printf("%c", elem->data);
    }
    //Clean up
    while (alist1.head != NULL) {
        deleteElement(&alist1, alist1.head);
    }
    printf(" Expected: ac\n");
    /* ac */

    LinkedList_t alist2 = {.head = NULL, .tail = NULL};
    LinkedListElement_t* element2;
    addElement(&alist2, 'a');
    element2 = findElement(&alist2, 'a');
    deleteElement(&alist2, element2);
    printf("Result: ");
    printf("%s", (alist2.head == NULL && alist2.tail == NULL) ? "Correct" : "Error");
    //Clean up
    while (alist2.head != NULL) {
        deleteElement(&alist2, alist2.head);
    }
    printf(" Expected: Correct\n");
    /* Correct */


    LinkedList_t alist3 = {.head = NULL, .tail = NULL};
    LinkedListElement_t* element3;
    addElement(&alist3, 'a');
    addElement(&alist3, 'b');
    element3 = findElement(&alist3, 'b');
    deleteElement(&alist3, element3);
    printf("Result: ");
    for (LinkedListElement_t* elem=alist3.head; elem != NULL; elem = elem->next) {
        printf("%c", elem->data);
    }
    //Clean up
    while (alist3.head != NULL) {
        deleteElement(&alist3, alist3.head);
    }
    printf(" Expected: a\n");
    /* a */


    LinkedList_t alist4 = {.head = NULL, .tail = NULL};
    LinkedListElement_t* element4;
    addElement(&alist4, 'a');
    addElement(&alist4, 'b');
    element4 = findElement(&alist4, 'a');
    deleteElement(&alist4, element4);
    printf("Result: ");
    for (LinkedListElement_t* elem=alist4.head; elem != NULL; elem = elem->next) {
        printf("%c", elem->data);
    }
    //Clean up
    while (alist4.head != NULL) {
        deleteElement(&alist4, alist4.head);
    }
    printf(" Expected: b\n");
    /* b */

    LinkedList_t alist5 = {.head = NULL, .tail = NULL};
    LinkedListElement_t* element5;
    addElement(&alist5, 'a');
    addElement(&alist5, 'b');
    addElement(&alist5, 'c');
    element5 = findElement(&alist5, 'g');
    deleteElement(&alist5, element5);
    printf("Result: ");
    for (LinkedListElement_t* elem=alist5.head; elem != NULL; elem = elem->next) {
        printf("%c", elem->data);
    }
    //Clean up
    while (alist5.head != NULL) {
        deleteElement(&alist5, alist5.head);
    }
    printf(" Expected: abc\n");
    /* abc */


    LinkedList_t alist6 = {.head = NULL, .tail = NULL};
    LinkedListElement_t* element6;
    addElement(&alist6, 'a');
    addElement(&alist6, 'b');
    addElement(&alist6, 'c');
    element6 = (LinkedListElement_t*)calloc(sizeof(LinkedListElement_t), 1);
    element6->data = 'g';
    deleteElement(&alist6, element6);
    printf("Result: ");
    for (LinkedListElement_t* elem=alist6.head; elem != NULL; elem = elem->next) {
        printf("%c", elem->data);
    }
    //Clean up
    while (alist6.head != NULL) {
        deleteElement(&alist6, alist6.head);
    }
    printf(" Expected: abc\n");
    /* abc */
}