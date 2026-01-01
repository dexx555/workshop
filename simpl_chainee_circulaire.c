#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*////listes simplement chainee circulaire////*/

/*creation de la liste*/
typedef struct etudiant {
    char nom[10];
    struct etudiant *suivant;
    /*allocation dynamiqeu de le neau*/
}Etudiant;
    Etudiant *cree_etud(char nom[]){
        Etudiant *etud=malloc(sizeof(Etudiant));
        strcpy(etud->nom,nom);
        etud->suivant=NULL;
    return etud;
}
    /*ajout ou debut*/
    /*nouvu->suivant=premier;*/
    Etudiant *ajout_debut(Etudiant *tete , char nom[]){
        Etudiant *nouvu=cree_etud(nom);
        if(tete==NULL){
            nouvu->suivant=nouvu;
            return nouvu;
        }
        Etudiant *courant=tete;
        while(courant->suivant!=tete)
            courant=courant->suivant;
        nouvu->suivant=tete;
        courant->suivant=nouvu;
        return nouvu;
    }
    Etudiant *ajout_fin(Etudiant *tete , char nom[]){
        Etudiant *nouvu=cree_etud(nom);
        if(tete==NULL){
            nouvu->suivant=nouvu;
            return nouvu;
        }
        Etudiant *courant=tete;
        while(courant->suivant!=tete)
            courant=courant->suivant;
        courant->suivant=nouvu;
        nouvu->suivant=tete;
        return tete;
    }
    void affichage (Etudiant *tete){
        Etudiant *courant=tete;
        do{
            printf(" %s \n ",courant->nom);
            courant=courant->suivant;

        }while(courant!=tete);
    }

int main(){
    Etudiant *tete=NULL;
    int age , moyenne ,c;
    char nom_[50];
    do{
         printf("\n ====MENU==== \n");
         printf("1: ajout au debut \n");
         printf("2: ajout a la fin \n");
         printf("3: aficher la list \n");
         printf("4: quite \n");
         printf("choix: ");
         scanf("%d",&c);
         getchar();
         switch(c){
     case 1:
             printf("entre le nom de etudiant: ");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             tete=ajout_debut(tete , nom_);
            break;
     case 2:
             printf("entre le nom de etudiant: ");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             tete=ajout_fin(tete ,nom_);
            break;
     case 3:
             affichage(tete);
            break;
     case 4:
             printf("====arrivederci====");
            break;

     default:
             printf("le choix est incorrect");
         }
    }while(c!=4);


    return 0;
}
