#include <stdio.h>
#include <stdlib.h>

struct Element {
    int value;
    struct Element *next;
};

typedef struct {
    struct Element *root;
} List;

struct Element * createElement(int value){
    struct Element *newElement = (struct Element*) malloc(sizeof (struct Element));
    if (newElement == NULL){
        return NULL;
    }
    newElement->next = (struct Element*) malloc(sizeof (struct Element));
    if(newElement->next == NULL){
        free(newElement);
        printf("Couldn't allocate Memory for Number %d", value);
        return NULL;
    }
    newElement->value = value;
    return newElement;
}

void insert(List *list, int value){
    struct Element *newElement = createElement(value);
    if (newElement == NULL){
        return;
    }
    if (list->root == NULL){
        list->root = newElement;
    } else {
        newElement->next = list->root;
        list->root = newElement;
    }
}

void add(List *list, int value){
    struct Element *newElement = createElement(value);
    if (newElement == NULL){
        return;
    }
    if (list->root == NULL){
        list->root = newElement;
        return;
    }
    struct Element *current = list->root;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = newElement;
}

int listSize(const List *list){
    int counter = 0;
    struct Element *current = list->root;
    while (current->next != NULL){
        counter ++;
        current = current->next;
    }
    return counter;
}

int contains(const List *list, int value){
    struct Element *current = list->root;
    while (current != NULL){
        if (current->value != NULL && current->value == value){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void freeMem(List *list){
    struct Element *next = NULL;
    struct Element *current = list->root;
    while (current != NULL) {
        next = current->next;
        printf("Memory for %d was released!\n", current->value);
        free(current);
        current = next;
    }
}

int main(){

    List list;
    List *pList = &list;
    int userInput;
    int* pUserInput = &userInput;
    while (1) {
        printf("Enter a number:");
        scanf("%d", pUserInput);
        if (*pUserInput == -1){
            break;
        }
        insert(pList, *pUserInput);
        if (contains(pList, *pUserInput) == 1){
            printf("Successfully inserted value %d\n", *pUserInput);
        } else {
            printf("Couldn't insert value %d\n", *pUserInput);
        }
        //printf("List contains now %d Elements.\n", listSize(pList));
    }

    printf("list contains 1: %d\n", (contains(pList, 1)));
    printf("list contains 3: %d\n", (contains(pList, 3)));
    printf("list contains 5: %d\n", (contains(pList, 5)));
    printf("list contains 7: %d\n", (contains(pList, 7)));
    printf("list contains 9: %d\n", (contains(pList, 9)));

    freeMem(pList);
    return 0;
}