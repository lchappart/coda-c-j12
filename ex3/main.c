#include "ex3.h"

void add_before(number **list) 
{
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
}

void add_to_end(number **list, int value)
{
    number *tmp = *list;

	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	number *item = malloc(sizeof(*item));
	item->value = value;
	item->next = NULL;

	tmp->next = item;
}

void display_list(number **list)
{
	number *tmp = *list;

	while(tmp != NULL)
	{
		printf("%d\n", tmp->value);
        tmp = tmp->next;
	}
}

int main(int argc, char const *argv[])
{
    int nb;
    int choix;
    printf("Veuillez saisir le premier nombre :\n");
    scanf("%d", &nb);
    number *premier = (number *)malloc(sizeof(number));
    premier->value = nb;
    premier->next = NULL;
    number *list = NULL;

    while (1)
    {
        printf("Que faire maintenant ? \n (1) Pour ajouter un nombre à la liste \n (2) Pour afficher la liste \n (3) Pour effacer l'écran \n (4) Pour sortir du programme \n (5) Pour rentrer une valeur supplémentaire dans la liste ");
        scanf("%d", &choix);
        if (choix == 1)
        {
            printf("Veuillez saisir le nombre à ajouter :\n");
            scanf("%d",&nb);
            add_to_end(&premier, nb);
        }
        else if (choix == 2)
        {
            display_list(&premier);
        }
        else if (choix == 3)
        {
            system("clear");
        }
        else if (choix == 4)
        {
            break;
        }
        else if (choix == 5)
        {
            add_before(&list);
        }
        else
        {
            printf("Cette instruction n'est pas valide");
        }
    }
    
    return 0;
}
