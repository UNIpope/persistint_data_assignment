#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct  item{
    int quantity;
    char model[50];
    float cost;
};

void case1(void);
void case2(void);
void case3(void);
void case4(void);
void case5(void);
void display(void);


struct item item[100];
int n;

int main()
{


    int option = 0;
    int i,c;

    while(1 == 1)
    {
        //menu
        printf("\nSelect an option from the following menu: \n1:Add an item \n2:delete an item \n3:Edit item \n4:Find item \n5:Record inventory \n");

        //option in menu
        option=getchar();
        fflush(stdin);

        switch(option)
        {
            case '1':
            {

                case1();
                display();

                break;

            }//end case 1
            case '2':
            {

                case2();
                display();
                break;

            }//end case 2
            case '3':
            {
                case3();
                display();

                break;

            }//end case 3
            case '4':
            {
                case4();

                break;
            }
            case '5':
            {
                case5();

                break;
            }
            default:
            {

                //error check menu
                printf("\nEnter a number between 1-5.\n");

                break;

            }//end default

        }//end switch

    }// end while

    return(0);
}

case1(void)
{
    int i = 0;

    printf("Enter number of items:");
    scanf("%d", &n);
    fflush(stdin);

    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\nItem quantity: \n");
        scanf("%d", &item[i].quantity);
        fflush(stdin);

        printf("Item code: \n");
        scanf("%s", &item[i].model);
        fflush(stdin);

        printf("Item cost: \n");
        scanf("%f", &item[i].cost);
        fflush(stdin);


    }

}

case2(void)
{
    int d;
    int i;

    printf("Enter number of the item to delete:");
    scanf("%d", &d);
    fflush(stdin);

    if ( d >= n+1 )
    {
        printf("error\n");
    }
    //delete an element
    else
    {
        for ( i = d - 1 ; i < n- 1 ; i++ )
        {
            item[i] = item[i+1];
        }

        printf("Result array is:\n");

        /* for( i = 0 ; i < n - 1 ; i++ )
        {
            printf("%f\n", item[i].cost);
        }
    */
    }//end else



}

case3(void)
{
    int c;
    int option;

    printf("Enter item to edit: \t");
    scanf("%d", &c);
    fflush(stdin);

    c = (c - 1);

    printf("Enter part of item to edit: \t");
    option = getchar();
    fflush(stdin);

    switch(option)
    {
        case '1':
        {

            printf("\nItem quantity: \n");
            scanf("%d", &item[c].quantity);
            fflush(stdin);

            break;
        }
        case '2':
        {

            printf("Item code: \n");
            scanf("%s", &item[c].model);
            fflush(stdin);

            break;
        }
        case '3':
        {

            printf("Item cost: \n");
            scanf("%f", &item[c].cost);
            fflush(stdin);

            break;
        }
        default:
        {

            //error check menu
            printf("\nEnter a number between 1-3.\n");

            break;

        }//end default


    }//end switch
}

case4(void)
{
    int i;
    char name[20] = "";

    printf("\nEnter the model number of the item: \t");
    gets(name);
    fflush(stdin);


    for(i = 0; i < n ;i ++ )
    {
        if(strcmp(item[i].model, name) == 0)
        {

            printf("Quantity Model\tCost\n\n");

            printf("%d  \t", item[i].quantity);
            printf(" %s \t", item[i].model);
            printf("%f \n", item[i].cost);
        }

    }



}

case5(void)
{
    int i,j;
    char t[20];
    int  te;
    float tem;

    FILE *rec;
    rec = fopen("ITinventory.txt", "w");

    if(rec == NULL)
    {
        printf("error");

        fclose(rec);
    }
    else
    {


        for (i = 1; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                if (strcmp(item[j -1].model, item[j].model) > 0)
                {
                    strcpy(t, item[j - 1].model);
                    strcpy(item[j - 1].model, item[j].model);
                    strcpy(item[j].model, t);

                    te = item[j - 1].quantity;
                    item[j - 1].quantity = item[j].quantity;
                    item[j].quantity = te;

                    tem = item[j - 1].cost;
                    item[j - 1].cost = item[j].cost;
                    item[j].cost = tem;


                }
            }
        }


        fprintf(rec,"Quantity\t Model\t\tCost\n\n");

        for(i = 0; i < n ; i++)
        {

            fprintf(rec,"%d  \t", item[i].quantity);
            fprintf(rec," %s \t\t", item[i].model);
            fprintf(rec,"%f \n", item[i].cost);

        }

        fclose(rec);

    }



}

display(void)
{
    int i;

    printf("Quantity Model\tCost\n\n");
    for(i = 0 ; i <  n; i++)
    {

        printf("%d  \t", item[i].quantity);
        printf(" %s \t", item[i].model);
        printf("%f \n", item[i].cost);

    }


}//end disp
