#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct etudiant {
    char nom[10];
    int age;
    int moyenne;
    struct etudiant *suivant;
}Etudiant;
    Etudiant *cree_etud (char nom[] , int age , int moyenne){
        Etudiant *nouvu;
        nouvu=malloc(sizeof(Etudiant));
        strcpy(nouvu->nom,nom);
        nouvu->age=age;
        nouvu->moyenne=moyenne;
        nouvu->suivant=NULL;
        return nouvu;
    }
    void affichage (Etudiant *tete){
        Etudiant *courant=tete;
        while(courant!=NULL){
            printf(" %s -> %d -> %d \n ",courant->nom , courant->age , courant->moyenne);
            courant=courant->suivant;
        }

    }
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
    affichage(tete);
    int tail=taill(tete);
    printf("la taille de la listes est %d",tail);
    return 0;
}


