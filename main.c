#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*////listes simplement chainee////*/

/*creation de la liste*/
typedef struct etudiant {
    char nom[10];
    int age;
    int moyenne;
    struct etudiant *suivant;
    /*allocation dynamiqeu de le neau*/
}Etudiant;
    Etudiant *cree_etud (char nom[] , int age , int moyenne){
        Etudiant *nouvu=malloc(sizeof(Etudiant));
        strcpy(nouvu->nom,nom);
        nouvu->age=age;
        nouvu->moyenne=moyenne;
        nouvu->suivant=NULL;
        return nouvu;
    }
        /*ajout ou debut*/
    /*nouvnoeud->suivant=premier;*/
    Etudiant *ajout_debut(Etudiant *tete , char nom[] , int age , int moyenne){
        Etudiant *Nouvnoeud=cree_etud(nom,age ,moyenne);
            Nouvnoeud->suivant=tete;
            tete=Nouvnoeud;

        return tete;
    }
    /*insertion a la fin */
    Etudiant *ajout_fin(Etudiant *tete , char nom[] , int age , int moyenne){
        Etudiant *Nouvnoeud=cree_etud(nom,age , moyenne);
        if (tete==NULL)
    return Nouvnoeud;
    Etudiant *courant=tete;
    while(courant->suivant!=NULL)
    courant=courant->suivant;
    courant->suivant=Nouvnoeud;
    return tete;
    }
    /*recherche dans de la liste chainee*/
    Etudiant *recherche(Etudiant *tete ,char nom[]){
        Etudiant *courant=tete;
        while(courant!=NULL){
            if (strcmp(courant->nom,nom)==0)
            return courant;
            courant=courant->suivant;
    }
    return NULL;
    }

    /*affichage de la liste chainee*/
    void affichage (Etudiant *tete){
        Etudiant *courant=tete;
        while(courant!=NULL){
            printf(" %s -> %d -> %d \n ",courant->nom , courant->age , courant->moyenne);
            courant=courant->suivant;
        }
    }
    /*la taill de la liste chainee*/
    int taill (Etudiant *tete){
        int cmp=0;
        Etudiant *couran=tete;
        while(couran!=NULL){
            couran=couran->suivant;
            cmp++;
        }
        return cmp;
    }

int main(){
        Etudiant *tete=NULL;
    int age , moyenne ,c;
    char nom_[50];
    do{
         printf("\n ====MENU==== \n");
         printf("1: ajout au debut \n");
         printf("2: ajout a la fin \n");
         printf("3: recherche dun element \n");
         printf("4: afichage de tout les etudiant \n");
         printf("5: la taill de la laist  \n");
         printf("6: exit \n");
         printf("choix: ");
         scanf("%d",&c);
         getchar();
         switch(c){
     case 1:
             printf("entre le nom de etudiant: ");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             printf("entre age de etudiant: ");
             scanf("%d",&age);
             printf("entre moyenn de etudiant: ");
             scanf("%d",&moyenne);
             tete=ajout_debut(tete , nom_ , age , moyenne);
            break;
     case 2:
             printf("entre le nom de etudiant: ");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             printf("entre age de etudiant: ");
             scanf("%d",&age);
             printf("entre moyenn de etudiant: ");
             scanf("%d",&moyenne);
             tete=ajout_fin(tete ,nom_ , age , moyenne);
            break;
     case 3:
             printf("entre le nom de etudient a rechercher :");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             Etudiant *result=recherche(tete,nom_);
                if (result!=NULL)
                    printf("le nom de etudiant est exist %s et son age est %d et la moyenne est %d \n ",nom_,result->age,result->moyenne);
                else
                    printf("le nom de etudiant est untrovable \n ");
            break;
     case 4:
             affichage(tete);
            break;
     case 5:
                int tail=taill(tete);
             printf("la taille de la list est %d\n ",tail);
            break;
     case 6:
             printf("====arrivederci55====");
            break;
     default:
             printf("le choix est incorrect");
         }
    }while(c!=6);

    return 0;
}