#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*////listes simplement chainee////*/

/*creation de la liste*/
typedef struct taxi {
    char modele[10];
    int numero_de_plaque;
    int etat;
    struct taxi *suivant;
    /*allocation dynamiqeu de le neau*/
}Taxi;
    Etudiant *cree_taxi (char modele[] , int numero_de_plaque , int etat){
        Taxi *nouv=malloc(sizeof(Taxi));
        strcpy(nouvu->modele,modele);
        nouvu->numero_de_plaque=numero_de_plaque;
        nouvu->etat=etat;
        nouvu->suivant=NULL;
        return nouvu;
    }
    /*affichage de la liste chainee*/
    void affichage (Taxi *tete){
        Taxi *courant=tete;
        while(courant!=NULL){
            printf(" %s -> %d -> %d \n ",courant->modele , courant->numero_de_plaque , courant->etat);
            courant=courant->suivant;
        }

    }
    /*la taill de la liste chainee*/
    int taill (Taxi *tete){
        int cmp=0;
        Taxi *couran=tete;
        while(couran!=NULL){
            couran=couran->suivant;
            cmp++;
        }
        return cmp;
    }
    /*recherche dans de la liste chainee*/
    Etudiant *recherche(Taxi *tete ,int numero_de_plaque){
        Taxi *courant=tete;
        while(courant!=NULL){
            if (courant->numero_de_plaque==numero_de_plaque)
            return courant;
            courant=courant->suivant;
    }
    return NULL;
    }
    /*ajout ou debut*/
    /*nouvnoeud->suivant=premier;*/
    Etudiant *ajout(Etudiant *tete , char nom[] , int age , int moyenne){
        Etudiant *Nouvnoeud;
        Nouvnoeud=malloc(sizeof(Etudiant));
         strcpy(Nouvnoeud->nom,nom);
        Nouvnoeud->age=age;
        Nouvnoeud->moyenne=moyenne;
        Nouvnoeud->suivant=NULL;
        if (tete!=NULL)
            Nouvnoeud->suivant=tete;
            tete=Nouvnoeud;

        return tete;
    }
int main(){
    Etudiant *premiere=cree_etud("ahmed",17,15);
    Etudiant *deuxieme=cree_etud("smail",24,18);
    Etudiant *troisieme=cree_etud("said",20,18);
    Etudiant *quatre=cree_etud("karim",20,14);
    Etudiant *queue=cree_etud("houcine",21,18);
    Etudiant *tete=premiere;
    premiere->suivant=deuxieme;
    deuxieme->suivant=troisieme;
    troisieme->suivant=quatre;
    quatre->suivant=queue;
    queue->suivant=NULL;
    tete=ajout(tete,"kamal",19,11);
    affichage(tete);
    int tail=taill(tete);
    printf("la taille de la listes est %d\n ",tail);
    char nom[50];
    printf("entre le nom de etudient a rechercher :");
    gets(nom);
    Etudiant *result=recherche(tete,nom);
    if (result!=NULL)
        printf("le nom de etudiant est exist %s et son age est %d et la moyenne est %d ",nom,result->age,result->moyenne);
    else
        printf("le nom de etudiant est untrovable ");
    return 0;
}
