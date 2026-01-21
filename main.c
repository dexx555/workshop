#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*////listes doublement chainee////*/

/*creation de la liste*/
typedef struct etudiant {
    char nom[10];
    int age;
    int moyenne;
    struct etudiant *suivant;
    struct etudiant *prec;
}Etudiant;
/*allocation dynamiqeu de le neau*/
    Etudiant *cree_etud (char nom[] , int age , int moyenne){
        Etudiant *nouvu=malloc(sizeof(Etudiant));
        strcpy(nouvu->nom,nom);
        nouvu->age=age;
        nouvu->moyenne=moyenne;
        nouvu->suivant=NULL;
        nouvu->prec=NULL;
        return nouvu;
    }
        /*ajout ou debut*/
    /*nouvnoeud->suivant=premier;*/
    Etudiant *ajout_debut(Etudiant *tete , char nom[] , int age , int moyenne){
        Etudiant *Nouvnoeud=cree_etud(nom,age ,moyenne);
            Nouvnoeud->suivant=tete;
        if(tete!=NULL)
            tete->prec=Nouvnoeud;
            tete=Nouvnoeud;
        return tete;
    }
    /*insertion a la fin */
    Etudiant *ajout_fin(Etudiant *tete , char nom[] , int age , int moyenne){
        Etudiant *Nouvnoeud=cree_etud(nom,age , moyenne);
        if (tete==NULL){
            return Nouvnoeud;
        }
    Etudiant *courant=tete;
    while(courant->suivant!=NULL){
        courant=courant->suivant;
    }
        courant->suivant=Nouvnoeud;
        Nouvnoeud->prec=courant;
    return tete;
    }
    Etudiant *ajout_avant_node(Etudiant *tete , char nom[] , int age , int moyenne){
        if (tete==NULL){
            printf("acun element avant a lajute");
            return tete;
        }
        Etudiant *Nouvnoeud=cree_etud(nom,age , moyenne);
         Etudiant *courant=tete->suivant;
        if(strcmp(courant->nom,nom)==0){
            Nouvnoeud->suivant=tete;
            tete->prec=Nouvnoeud;
            Nouvnoeud->prec=NULL;
            tete=Nouvnoeud;
            return tete;
        }
        courant=tete->suivant;
        while(courant && strcmp(courant->nom,nom)!=0){
            courant=courant->suivant;
        }
        if(!courant){
            printf("le noeud est untrovable \n");
            return tete;
        }
        else{
            Nouvnoeud->suivant=courant;
            Nouvnoeud->prec=courant->prec;
            courant->prec->suivant=Nouvnoeud;
            courant->prec=Nouvnoeud;

        }
        return tete;
    }
    Etudiant *ajout_apre_node(Etudiant *tete , char nom[] , int age , int moyenne){
        Etudiant *Nouvnoeud=cree_etud(nom,age , moyenne);
         if(tete==NULL){
        printf("aucun apres a ajute");
        return tete;
        }
        Etudiant *courant=tete;
        while(courant && strcmp(courant->nom,nom)!=0){
            courant=courant->suivant;
        }
        if(!courant){
            printf("le noeud est untrovable \n");
            return tete;
        }
        else{
             Nouvnoeud->suivant=courant->suivant;
             Nouvnoeud->prec=courant;
             courant->suivant=Nouvnoeud;
             if(courant->suivant!=NULL)
                courant->suivant->prec=Nouvnoeud;
        }
        return tete;
    }
    Etudiant *suppfin(Etudiant *tete){
        if(tete==NULL){
        printf("la list est vide");
        return NULL;
        }
        Etudiant *courant=tete;
        if(courant->suivant==NULL){
            free(courant);
            return NULL;
        }
        courant=tete->suivant;
        while(courant->suivant!=NULL){
        courant=courant->suivant;
        }
        courant->prec->suivant=NULL;
        free(courant);
        return tete;
    }
    Etudiant *suppdebut(Etudiant *tete){
        if(tete==NULL){
        printf("la list est vide");
        return NULL;
        }
        Etudiant *tmp=tete;
        tete=tete->suivant;
        if(tete!=NULL)
        tete->prec=NULL;
        free(tmp);
        return tete;
    }
    Etudiant *supp_avant_noeud(Etudiant *tete , char nom[]){
        if(tete==NULL || tete->suivant==NULL){
        printf("la list est vide ou aucun a supprimer");
        return NULL;
        }
        Etudiant *courant=tete;
        if(strcmp(tete->nom,nom)==0){
            printf("aucun avant a supprimer");
            return tete;
        }
        courant=tete->suivant;
        while(courant && strcmp(courant->nom,nom)!=0){
            courant=courant->suivant;
        }
        if(!courant){
            printf("le noeud a suprimer untrovable \n");
            return tete;
        }
        Etudiant *a_suppri=courant->prec;
        if(a_suppri==tete){
            tete=tete->suivant;
            tete->prec=NULL;
            return tete;
        }
        else{
            a_suppri->prec->suivant=courant;
            courant->prec=a_suppri->prec;
        }
        printf("le noeud avant le noeud donnes %s est supprimer", courant->nom);
        free(a_suppri);
        return tete;
    }
    Etudiant *supp_apres_noeud(Etudiant *tete , char nom[]){
        if(tete==NULL){
        printf("la list est vide");
        return NULL;
        }
        Etudiant *courant=tete;
        while(courant && strcmp(courant->nom,nom)!=0){
            courant=courant->suivant;
        }
        if(!courant){
            printf("le noeud a suprimer untrovable \n");
            return tete;
        }
        Etudiant *a_suppri=courant->suivant;
        if(!courant->suivant){
            printf("aucun apres a supprimer");
            return tete;
        }
            courant->suivant=a_suppri->suivant;
            if(a_suppri->suivant==NULL){
                a_suppri->suivant->prec=courant;
            }
        printf("le noeud avant le noeud donnes %s est supprimer", courant->nom);
        free(a_suppri);
        return tete;
    }
    Etudiant *supp_un_noeud(Etudiant *tete , char nom[]){
        if(tete==NULL){
        printf("la list est vide");
        return NULL;
        }
        Etudiant *courant=tete;
        if(strcmp(courant->nom,nom)==0){
            tete=tete->suivant;
            if(tete!=NULL)
                tete->prec=NULL;
            free(courant);
            return tete;
        }
        courant=tete->suivant;
        while(courant && strcmp(courant->nom,nom)!=0){
            courant=courant->suivant;
        }
        if(courant==NULL){
                printf("le noeud est introuvable \n");
            return tete;
        }
        else{
            courant->prec->suivant=courant->suivant;
            if(courant->suivant!=NULL)
                courant->suivant->prec=courant->prec;
            free(courant);
        }

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
         printf("3: ajoute ce qui precede ce noeud \n");
         printf("4: ajoute ce qui suit ce noeud \n");
         printf("5: recherche dun element \n");
         printf("6: supprime le dernier element de la list \n");
         printf("7: supprime l premier element de la list \n");
         printf("8: supprime un noeud donne de la list \n");
         printf("9: supprime ce qui precede ce noeud \n");
         printf("10: supprime ce qui suit ce noeud \n");
         printf("11: afichage de tout les etudiant \n");
         printf("12: la taill de la laist  \n");
         printf("13: exit \n");
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
             printf("entre le nom de etudiant: ");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             tete=ajout_avant_node(tete ,nom_ , age , moyenne);
             printf("entre le nom de etudiant: ");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             printf("entre age de etudiant: ");
             scanf("%d",&age);
             printf("entre moyenn de etudiant: ");
             scanf("%d",&moyenne);
            break;
     case 4:
             printf("entre le nom de etudiant: ");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             printf("entre age de etudiant: ");
             scanf("%d",&age);
             printf("entre moyenn de etudiant: ");
             scanf("%d",&moyenne);
             tete=ajout_fin(tete ,nom_ , age , moyenne);
            break;
     case 5:
             printf("entre le nom de etudient a rechercher :");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             Etudiant *result=recherche(tete,nom_);
                if (result!=NULL)
                    printf("le nom de etudiant est exist %s et son age est %d et la moyenne est %d \n ",nom_,result->age,result->moyenne);
                else
                    printf("le nom de etudiant est untrovable \n ");
            break;
     case 6:
             tete=suppfin(tete);
            break;
     case 7:
             tete=suppdebut(tete);
            break;
     case 8:
             printf("entre le nom de etudient a supprimer :");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             tete=supp_un_noeud(tete , nom_);
            break;
     case 9:
             printf("entre le nom de etudient avant a supprimer :");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             tete=supp_avant_noeud(tete , nom_);
            break;
     case 10:
             printf("entre le nom de etudient avant a supprimer :");
             fgets(nom_,50,stdin);
             nom_[strcspn(nom_,"\n")]=0;
             tete=supp_apres_noeud(tete , nom_);
            break;
     case 11:
             affichage(tete);
            break;
     case 12:
                int tail=taill(tete);
             printf("la taille de la list est %d\n ",tail);
            break;
     case 13:
             printf("====arrivederci55====");
            break;
     default:
             printf("le choix est incorrect");
         }
    }while(c!=13);

    return 0;
}