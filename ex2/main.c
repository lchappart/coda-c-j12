#include "ex2.h"


void add_before(number **list) {
    int ajt;
    int nb2;
    printf("Quel nombre faut-il ajouter à la liste: ");
    scanf("%d", &ajt);
    printf("Avant quel nombre faut-il le mettre: ");
    scanf("%d", &nb2);

    number *tmp = *list;
    number *prev = NULL;
    number *item = (number *)malloc(sizeof(number));
    item->value = ajt;


    if (tmp == NULL || tmp->value == nb2) {
        item->next = *list;
        *list = item;
        return;
    }


    while (tmp != NULL && tmp->value != nb2) {
        prev = tmp;
        tmp = tmp->next;
    }


    if (tmp != NULL) {
        prev->next = item;
        item->next = tmp;
    } else {
        printf("Valeur %d non trouvée dans la liste.\n", nb2);
        free(item);
    }
}

void display_list(number *list) {
    number *tmp = list;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    number *list = NULL;
    int choix;

    while (1)
    {
        printf("(1) Pour ejouter un nombre à la liste \n (2) POur afficher la liste \n (3) Pour quitter le programme\n");

        scanf("%d", &choix);
        
        if (choix == 1)
        {
            add_before(&list);
        }
        else if (choix == 2)
        {
            display_list(list);
        }
        else if (choix == 3)
        {
            break;
        }
    }
    return 0;
}
    