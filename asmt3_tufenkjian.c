// ============================================================================
// Name: ASHOD CHRIS TUFENKJIAN
// Project#4: VIRTUAL MEMORY
// Due: November 8th, 2014
// COMP 222
// ============================================================================
#include <stdio.h>
#include <stdlib.h>

int mem_size,
    mem_address,
    page_size,
    number_of_rows,
    policy;

struct node
{
    int VP;
    int PF;
}*pt = NULL;
typedef struct node row;

void allocate_rows()
{
    pt = (row*) malloc (number_of_rows * sizeof(row));
    int i;
    for ( i=0; i < number_of_rows; i++ )
        pt[i].VP = -1;
    return;
}

void OPTION_1()
{
    printf("Entered selection 1: \n");

	printf("Enter main memory size (words): ");
	scanf("%d", &mem_size);

    printf("Enter page size (words/page): ");
	scanf("%d", &page_size);

    printf("Enter replacement policy (0 = LRU, 1 = FIFO): ");
	scanf("%d", &policy);

    number_of_rows = mem_size / page_size;

	allocate_rows();

	return;
}


void OPTION_2()
{
    int index = 0;
    int VP;
    int offset;

    printf("Enter virtual memory address to access: ");
	scanf("%d", &mem_address);

    VP = mem_address / page_size;

    offset = mem_address % page_size;

    while ( (index < number_of_rows) && (pt[index].VP != -1) && (pt[index].VP != VP) )
    {
        index++;
    }

    return;
}

void de_allocate()
{
    if (pt != NULL)
        free(pt);
    return;
}

int main ()
{
    int x = 1;
    while (x == 1)
    {
        int selection;

        printf("\nVirtual memory to Main memory mapping: \n");
        printf("--------------------------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Map virtual address\n");
        printf("3) Quit\n\n");
        printf("Enter Selection: \n");
        scanf("%d", &selection);

            if (selection == 1) OPTION_1();

            else if (selection == 2) OPTION_2();

            else if (selection == 3){
                de_allocate();
                x = 2;
            }
    }
    return 0;
}
