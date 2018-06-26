#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct node
{
    char name[16];
    int num;
    char desc[41];
    float time;
    struct node *next;
}node_t;

node_t *head = NULL;
node_t *tail = NULL;
node_t *curr = NULL;
node_t *first = NULL;

int init();
void enque();
void deque();
void display();

int main()
{
    int i = 0;

    init();

    while(i != 4)
    {
        printf("\n\n1. Enter ticket\n");
        printf("2. De-queue ticket\n");
        printf("3. Display tickets\n");
        printf("4. End\n\n");

        scanf("%d", &i);
        fflush(stdin);

        if(i == 1)
        {
            curr = tail;

            if(curr->num != NULL)
            {
                printf("\nList is full.\n2");
            }
            else
            {
                enque();
            }
        }
        else if(i == 2)
        {
            curr = head;

            if(curr->num == NULL)
            {
                printf("\nList is empty\n");
            }
            else
            {
                deque();
            }
        }
        else if(i == 3)
        {
            curr = head;

            for(i=0; i<5; i++)
            {
                if(curr->num == NULL)
                {

                }
                else
                {
                    printf("\n\tTicket %d\n", i+1);

                    display();
                    curr = curr->next;
                }
            }
        }
        else
        {
            printf("\nINVALID OPTION\n");
        }
    }


    return(0);
}

int init()
{
    int i;

    first = (struct node*)malloc(sizeof(node_t));//first node created

    if(first == NULL)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }

    head = first;//sets head and tail to the start
    tail = first;

    for(i=0; i<4; i++)
    {
        tail->next = (struct node*)malloc(sizeof(node_t));//creates next 4 nodes
        if(tail->next == NULL)
        {
            printf("\n Node creation failed \n");
            return NULL;
        }

        tail->num = NULL;//each num variable set to NULL using it as identifier

        tail->next->next = NULL;//last node = NULL
        if(i != 4)
        {
            tail = tail -> next;//tail moved forward
        }
    }

    tail->next = first;//points last node to first creating a loop

    tail = first;//set to top of the queue

    strcpy(tail->name, "Jane");   //sets the example tickets
    tail->num = 4558;
    strcpy(tail->desc, "Monitor broken");
    tail->time = 12.05;

    tail = tail->next;

    strcpy(tail->name, "Sean");
    tail->num = 5656;
    strcpy(tail->desc, "Desktop won't flickering");
    tail->time = 12.06;

    tail = tail->next;

    strcpy(tail->name, "Mark");
    tail->num = 1212;
    strcpy(tail->desc, "Router lights amber");
    tail->time = 12.10;

    tail = tail->next;
}

void enque()
{
    printf("\nEnter Name: ");
    scanf("%10s", tail->name);
    fflush(stdin);
    printf("\nEnter Contact Number: ");
    scanf("%d",&tail->num);
    fflush(stdin);
    printf("\nEnter Description(max 40 charcters): ");
    gets(tail->desc);
    printf("\nEnter time: (hh.mm) ");
    scanf("%f",&tail->time);

    while(tail->time > 24 || tail->time < 1)//limits time entered
    {
        printf("\nEnter a valid time (eg. 13.45)\n");
        scanf("%f",&tail->time);
    }
    printf("\n\tNEW TICKET\n");

    curr = tail;
    display();

    tail = tail->next;
}

void deque()
{
    curr = head;//reset back to start of queue

    display();//display node del

    printf("\tITEM DE-QUEUED\n");
    head->num = NULL;
    head = head->next;
}

void display()//curr n
{
    printf("Name: %s\n",curr->name);
    printf("Contact Number: %d\n",curr->num);
    printf("Description: %s\n",curr->desc);
    printf("Time: %.2f\n",curr->time);
}
