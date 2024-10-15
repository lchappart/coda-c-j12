#include "ex3.h"
#include <stdio.h>
#include <stdlib.h>



number* sort(number *list) {
    if (list == NULL || list->next == NULL) {
        return list;
    }
    number *sorted = NULL;
    number *current = list;
    number *next;
    while (current != NULL) {
        next = current->next;
        if (sorted == NULL || sorted->value >= current->value) {
            current->next = sorted;
            sorted = current;
        } else {
            number *temp = sorted;
            while (temp->next != NULL && temp->next->value < current->value) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}
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

void add_to_end(number **list, int value) {
    number *tmp = *list;

    if (tmp == NULL) {
        tmp = (number *)malloc(sizeof(number));
        tmp->value = value;
        tmp->next = NULL;
        *list = tmp;
        return;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    number *item = (number *)malloc(sizeof(number));
    item->value = value;
    item->next = NULL;
    tmp->next = item;
}

void display_list(number *list) {
    if (list == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    number *tmp = list;
    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int main(int argc, char const *argv[]) {
    int nb;
    int choix;
    number *list = NULL;

    printf("Veuillez saisir le premier nombre :\n");
    scanf("%d", &nb);
    add_to_end(&list, nb);

    while (1) {
        printf("Que faire maintenant ?\n (1) Pour ajouter un nombre à la fin de la liste\n (2) Pour afficher la liste\n (3) Pour effacer l'écran\n (4) Pour sortir du programme\n (5) Pour rentrer une valeur supplémentaire dans la liste\n (6) Pour trier la liste\n");
        scanf("%d", &choix);

        if (choix == 1) {
            printf("Veuillez saisir le nombre à ajouter :\n");
            scanf("%d", &nb);
            add_to_end(&list, nb);
        } else if (choix == 2) {
            display_list(list);
        } else if (choix == 3) {
            system("clear");
        } else if (choix == 4) {
            break;
        } else if (choix == 5) {
            add_before(&list);
        } else if (choix == 6) {
            list = sort(list);
        } else {
            printf("Cette instruction n'est pas valide.\n");
        }
    }

    return 0;
}
