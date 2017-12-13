/*
  This example explains how you can use any lists in ../Data Structure dir.
  I have decided to use the circular linked list as example, but the bhavior of the others
  lists are very similar, like the stack and queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "../circular-linked-list.c"

int main(void) {
  /* First, create a variable with the list type you want ant assign the NULL value.
    (To find out the correct type, check the source file you want to use.)*/
  clist_t *list = NULL;
  clist_t *p;
  /* Create a data_t variable. You can modify the structure in the source file. */
  data_t d;
  char opc = '1';

  while (opc != '0') {
    printf("\n[Circular Linked List]\n\n"
        "[1] INSERT\n"
        "[2] DELETE\n"
        "[3] SHOW\n"
        "[0] EXIT\n\n"
        ">> ");

    __fpurge(stdin);
    opc = getchar();

    switch (opc) {
      case '1':
        printf("\n[INSERT] ID: ");
        scanf("%d", &d.id); // Assign the values to data_t type variable

        // if you want unique values, call the search function before the insert function
        if (insert(&list, d))
          printf("%d successfully inserted.\n\n", d.id);
        else
          printf("Failed to insert the %d valur in the list\n\n", d.id);

        break;
      case '2':
        printf("\n[DELETE] ID: ");
        scanf("%d", &d.id);

        if (remove_by_key(&list, d.id))
          printf("%d successfully deleted.\n\n", d.id);
        else
          printf("The value don't belongs to the list\n\n");
        break;
      case '3':
        printf("\n== Showing the list ==\n\n");
        p = list;

        if (p != NULL) {
          printf("[HEAD] -> [%d]", list->data.id);
          p = p->next;
          while (p != list) {
            printf(" -> [%d]", p->data.id);
            p = p->next;
          }
          printf(" -> [HEAD]\n");
        } else {
          printf("The list is empty\n\n");
        }
        break;
      case '0':
        // Always call the function listclr(clist_t*) before terminate
        listclr(&list);
        break;
    }
  }

  return 0;
}
