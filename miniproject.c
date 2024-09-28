#include <stdio.h>
#include <string.h>

#define T_MAX 100
#define MAX_C 20


void Ajouter_livre(char titres[][MAX_C], char auteur[][MAX_C], float prix[], int quantitie[],int *n);
void Afficher_livres(char titres[][MAX_C], char auteur[][MAX_C], float prix[], int quantitie[],int n);
void Rechercher_livre(char titres[][MAX_C], char auteur[][MAX_C], float prix[], int quantitie[],int *n);
void Afficher_nombre_livres(char titres[][MAX_C], char auteur[][MAX_C], float prix[], int quantitie[],int *n);
void Modifier_q_livre(int quantitie[],int *n);
int main(){
    
    char tab_titre[T_MAX][MAX_C];
    char tab_auteur[T_MAX][MAX_C];
    float tab_prix[T_MAX];
    int tab_quantitie[T_MAX];
    int nb = 0;
    int choi;

    printf(" Systeme de Gestion de Stock dans une Librairie : \n\n");
    
    //display options

    do {
        
        printf("Choisie une option :\n");
        printf("1.Ajouter un Livre au Stock\n");
        printf("2.Afficher Tous les Livres Disponibles\n");
        printf("3.Rechercher Livre\n");
        printf("4.Afficher le Nombre Total de Livres en Stock\n");
        printf("5.Mettre a Jour la Quantite d'un Livre\n");
        printf("6.Supprimer un Livre du Stock\n");
        printf("7.Quiter le programme\n");
        scanf("%d",&choi);

        //switching the menu items
        switch (choi){

           case 1 : 
           Ajouter_livre(tab_titre,tab_auteur,tab_prix,tab_quantitie,&nb);
           break;
           case 2:
           Afficher_livres(tab_titre,tab_auteur,tab_prix,tab_quantitie,nb);
           break;
           case 3:
           Rechercher_livre(tab_titre,tab_auteur,tab_prix,tab_quantitie,&nb);
           break;
           case 4:
           Afficher_nombre_livres(tab_titre,tab_auteur,tab_prix,tab_quantitie,&nb);
           break;
           case 5:
           Modifier_q_livre(tab_quantitie,&nb);
           break;
           //
           case 7 : printf("Bye\n");
           break;
           default: printf("invalide input");
           break;
      }

    } while(choi != 7);
   
 return 0;

}


void Ajouter_livre(char titres[][MAX_C], char auteur[][MAX_C], float prix[], int quantitie[],int *n){
            
            if (*n >= T_MAX)
            {
                printf("le tableau est plein");
                return;
            }
            
            printf("titre du livre : ");
            getchar();
            fgets(titres[*n],MAX_C,stdin);
            titres[*n][strcspn(titres[*n],"\n")] = '\0';

            printf("auteur du livre : ");
            fgets(auteur[*n],MAX_C,stdin);
            auteur[*n][strcspn(auteur[*n],"\n")] = '\0';

            printf("Prix du livre : ");
            scanf("%f",&prix[*n]);

            printf("quantitie du livre : ");
            scanf("%d",&quantitie[*n]);
            (*n)++;
    
}

void Afficher_livres(char titres[][MAX_C], char auteur[][MAX_C], float prix[], int quantitie[],int n){
        
        if (n == 0)
        {
            printf("auncun livre disponible\n\n");
            return;
        }
         
        printf("\nListe des livres disponible :\n");

        for (int i = 0; i < n; i++) {
                printf("Livre %d",i + 1);
                printf("\t Titre : %s",titres[i]);
                printf("\t Auteur : %s",auteur[i]);
                printf("\t Prix : %.2f",prix[i]);
                printf("\t Quantitie : %d \n\n",quantitie[i]);
        
        }
        
    
    
}

void Rechercher_livre(char titres[][MAX_C], char auteur[][MAX_C], float prix[], int quantitie[],int *n){
   char title[MAX_C];
   printf("entrer le nom de livre que vous avez chercher : \n");
   scanf("%s",title);
   char *t = title;
   
   for (int i = 0; i < *n; i++)
   {
    
       if (strcmp(t,titres[i]) == 0)
       {
        printf("Livre %d",i + 1);
                printf("\t Titre : %s",titres[i]);
                printf("\t Auteur : %s",auteur[i]);
                printf("\t Prix : %.2f",prix[i]);
                printf("\t Quantitie : %d \n\n",quantitie[i]);
       }
       //else printf("le nom du livre que vous rechercher n'est disponible\n");
       
   }
   
}

void Afficher_nombre_livres(char titres[][MAX_C], char auteur[][MAX_C], float prix[], int quantitie[],int *n){
    int count = 0;
    for (int i = 0; i < *n; i++)
    {
        count += quantitie[i];
    }
    printf("le nombre de livres disponible est %d\n",count);
    
}

void Modifier_q_livre(int quantitie[],int *n){
    int numero, nv_quantitie;
 printf("entrer le numero du livre que vous voulez modifier : \n");
 scanf("%d",&numero);
 for (int i = 0; i < *n; i++)
 {
    if (numero == i+1)
    {
        printf("nouveau quntitie : ");
        scanf("%d",&nv_quantitie);
        quantitie[i] = nv_quantitie;
    }
    else printf("aucun livre disponible avec ce numero\n");
    
 }
 
}