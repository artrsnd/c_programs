//  THIS EXAMPLE WORKS WITH ALL LISTS, WITH STACK AND QUEUE.

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "circular-linked-list.c"

int main(void) {
  clist_t *list = NULL, *p;
  data_t d;
  char opc = '1';

  while (opc != '0') {
    printf("[1] INSERT\n"
        "[2] DELETE\n"
        "[3] LIST\n"
        "[0] EXIT\n\n"
        ">> ");

    __fpurge(stdin);
    opc = getchar();

    switch (opc) {
      case '1':
        printf("\n[INSERT] ID: ");
        scanf("%d", &d.id);

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
        printf("\n[circular-linked-list]\n\n");
        p = list;

        if (p != NULL) {
          printf("[HEAD] -> [%d]", list->data.id);
          p = p->next;
          while (p != list) {
            printf(" -> [%d]", p->data.id);
            p = p->next;
          }
          printf("\n");
        } else {
          printf("The list is empty\n\n");
        }
        break;
      case '0':
        listclr(&list);
        break;
    }
  }

  return 0;
}
