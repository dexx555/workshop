#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*////listes doublement chainee circulaire////*/
/*creation de la liste*/
typedef struct etudiant {
    char nom[10];
    struct etudiant *suivant;
    struct etudiant *prec;
}Etudiant;
/*allocation dynamiqeu de le neau*/
    Etudiant *cree_etud(char nom[]){
        Etudiant *etud=malloc(sizeof(Etudiant));
        strcpy(etud->nom,nom);
        etud->suivant=etud;
        etud->prec=etud;
    return etud;
}
    /*ajout ou debut*/
    /*nouvu->suivant=premier;*/
    Etudiant *ajout_debut(Etudiant *tete , char nom[]){
        Etudiant *nouvu=cree_etud(nom);
        if(tete==NULL){
            tete=nouvu;
            return tete;
        }
        Etudiant *dernier=tete->prec;
        nouvu->suivant=tete;
        nouvu->prec=dernier;
        dernier->suivant=nouvu;
        tete->prec=nouvu;
        tete=nouvu;
        return tete;
    }
    Etudiant *ajout_fin(Etudiant *tete , char nom[]){
        Etudiant *nouvu=cree_etud(nom);
        if(tete==NULL){
            tete=nouvu;
            return tete;
        }
        Etudiant *dernier=tete->prec;
        nouvu->suivant=tete;
        nouvu->prec=dernier;
        dernier->suivant=nouvu;
        tete->prec=nouvu;
        return tete;
    }
    Etudiant *suppdebut(Etudiant *tete){
        if(tete==NULL){
            printf("la list est vide");
        return NULL;
        }
        if(tete->suivant ==tete){
            free(tete);
            return NULL;
        }
        Etudiant *dernier=tete->prec;
        Etudiant *nouvtete=tete->suivant;
        dernier->suivant=nouvtete;
        nouvtete->prec=dernier;
        free(tete);
        return nouvtete;
    }
    Etudiant *suppfin(Etudiant *tete){
        if(tete==NULL){
            printf("la list est vide");
        return NULL;
        }
        if(tete->suivant ==tete){
            free(tete);
            return NULL;
        }
        Etudiant *dernier=tete->prec;
        Etudiant *avantdernier=dernier->prec;
        avantdernier->suivant=tete;
        tete->prec=avantdernier;
        free(dernier);
        return tete;
    }
    Etudiant *supp_node_donne(Etudiant *tete ,char nom[] ){
        if(tete==NULL){
            printf("la list est vide");
        return NULL;
        }
        Etudiant *courant=tete;
        do{
            if(strcmp(courant->nom,nom)==0){
                if(courant->suivant==courant){
                    free(courant);
                    return NULL;
                }
            if(courant==tete)
                    tete=tete->suivant;
            Etudiant *avant=courant->prec;
            Etudiant *apres=courant->suivant;
            avant->suivant=apres;
            apres->prec=avant;
            free(courant);
            return tete;      
            }
            courant=courant->suivant;
        }while(courant!=tete);
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
         printf("3: suppression au debut \n");
         printf("4: suppression a la fin \n");
         printf("5: aficher la list \n");
         printf("6: quite \n");
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
             tete=suppdebut(tete);
            break;
     case 4:
             tete=suppfin(tete);
            break;
     case 5:
             affichage(tete);
            break;
     case 6:
             printf("====arrivederci====");
            break;

     default:
             printf("le choix est incorrect");
         }
    }while(c!=6);


    return 0;
}
