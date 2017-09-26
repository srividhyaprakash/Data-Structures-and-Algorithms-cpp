#include <stdio.h>

struct Node 
{
    int data;
    struct Node* next;
};

void reverse(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next;
     
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *head_ref)
{
    struct Node* temp = head_ref;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void insertAfter(struct Node *prev_ref, int data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}
void append(struct Node **head_ref, int new_data)
{
    struct Node* temp = *head_ref;
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    if(temp->next == NULL)
    {
        new_node->next = NULL;
        *head_ref = new_node;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    
}
void delete(struct Node **head_ref, int data)
{

    struct Node* temp = *head_ref, *prev;
    
    if(temp != NULL && temp->data == data)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
    
}

void rotate(struct Node **head_ref, int k)
{
    struct Node* temp = *head_ref;
    struct Node* last = *head_ref;
    int i = 1;
    
    while(last->next != NULL)
    {
        last = last->next;
        
        if(i < k)
        {
            i = i + 1;
            temp = temp->next;
        }
    }
    last->next = *head_ref;
    *head_ref = (temp->next);
    temp->next = NULL;
}
int main() {
	
	//code
	struct Node* second;
	struct Node* third;
	struct Node* head;
	
	head = (struct Node*) malloc(sizeof(struct Node));
	second = (struct Node*) malloc(sizeof(struct Node));
	third = (struct Node*) malloc(sizeof(struct Node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	//printList(head);
	append(&head, 4);
	append(&head, 5);
	append(&head, 6);
	append(&head, 7);
	reverse(&head);
	delete(&head, 3);
	printList(head);
	rotate(&head, 4);
	printList(head);
	return 0;
}