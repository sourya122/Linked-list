#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void beginsert();
void lastinsert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void reverse(); // NOT IN LAB CLASS ,ONLY IN THEORY CLASS.
int main()
{
    int choice = 0;
    while (choice != 10)
    {
        printf("\n ... Choose One option from the following list ...\n");
        printf("\n 1.Insert in beginig\n2.Insert at last\n3.Insert item at any location\n4.Delete from begining\n5.Delete from last\n6.Delete item from any location\n7.scarch\n8.display\n9.Reverse\n10.Exit\n");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            random_insert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            reverse(); // Calling the function to reverse the linked list
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid Choice..");
        }
    }
    return 0;
}

void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node ));
    if (ptr == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\n Enter value :");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Item Inserted");
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n Overflow");
    }
    else
    {
        printf("\nEnter value");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("Item Inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("Item Inserted");
        }
    }
}

void random_insert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter value");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the Location : ");
        scanf("%d", &loc);
        temp = head;
        for (int i = 1; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncant insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Item inserted");
    }
}

void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Item deleted from the begining.....\n");
    }
}

void last_delete()
{
    struct node *ptr, *ptrl;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted...\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptrl = ptr;
            ptr = ptr->next;
        }
        ptrl->next = NULL;
        free(ptr);
        printf("Item Deleted\n");
    }
}

void random_delete()
{
    struct node *ptr, *ptrl;
    int loc, i;
    printf("\n Enter the location");
    scanf("%d", &loc);
    ptr = head;
    for (int i = 0; i < loc; i++)
    {
        ptrl = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\ncant delete");
            return;
        }
    }
    ptrl->next = ptr->next;
    free(ptr);
    printf("Item delte at loc %d", loc);
}

void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\n Empty List\n");
    }
    else
    {
        printf("\nEnter scarching item : ");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("item found at location %d", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Item not found\n");
        }
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting value .......\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void reverse()
{
    struct node *prev, *current, *next;
    prev = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    printf("Reversed list:\n");
    display();
}
