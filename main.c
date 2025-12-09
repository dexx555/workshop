#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tache {
    int id;
    char description[50];
    int priorite;
    struct Tache *suiv;
} Tache;

// Crée une nouvelle tâche
Tache* creerTache(int id, char desc[], int priorite) {
    Tache *nouv = (Tache*)malloc(sizeof(Tache));
    if (!nouv) {
        printf("Erreur d'allocation mémoire.\n");
        exit(1);
    }
    nouv->id = id;
    strcpy(nouv->description, desc);
    nouv->priorite = priorite;
    nouv->suiv = NULL;
    return nouv;
}

// 1. Insertion au début
Tache* insererDebut(Tache *tete, int id, char desc[], int priorite) {
    Tache *nouv = creerTache(id, desc, priorite);
    nouv->suiv = tete;
    tete = nouv;
    return tete;
}

// 2. Insertion à la fin
Tache* insererFin(Tache *tete, int id, char desc[], int priorite) {
    Tache *nouv = creerTache(id, desc, priorite);
    
    // Liste vide
    if (tete == NULL) {
        tete = nouv;
        return tete;
    }

    // Liste non vide
    Tache *tmp = tete;
    while (tmp->suiv != NULL)
        tmp = tmp->suiv;
    tmp->suiv = nouv;
    return tete;
}

// 3. Insertion avant une tâche donnée
Tache* insererAvant(Tache *tete, int id_ref, int id, char desc[], int priorite) {
    if (tete == NULL) {
        printf("Liste vide.\n");
        return tete;
    }
    Tache *nouv = creerTache(id, desc, priorite);
    if (tete->id == id_ref) {
        nouv->suiv = tete;
        return nouv;
    }
    Tache *prec = tete, *curr = tete->suiv;
    while (curr && curr->id != id_ref) {
        prec = curr;
        curr = curr->suiv;
    }
    if (!curr) {
        printf("Tâche non trouvée.\n");
        free(nouv);
    } else {
        prec->suiv = nouv;
        nouv->suiv = curr;
    }
    return tete;
}

// 4. Insertion après une tâche donnée
Tache* insererApres(Tache *tete, int id_ref, int id, char desc[], int priorite) {
    Tache *tmp = tete;
    
    while (tmp!=NULL && tmp->id != id_ref)
        tmp = tmp->suiv;
    
    if (tmp==NULL) {
        printf("Tâche non trouvée.\n");   
    }
    else{
        Tache *nouv = creerTache(id, desc, priorite);
        nouv->suiv = tmp->suiv;
        tmp->suiv = nouv;
    }
    
    return tete;
}

// 5. Suppression d'une tâche donnée
Tache* supprimerTache(Tache *tete, int id) {
    if (tete == NULL) {
        printf("Liste vide.\n");
        return NULL;
    }
    if (tete->id == id) {
        Tache *tmp = tete->suiv;
        free(tete);
        return tmp;
    }
    Tache *prec = tete, *curr = tete->suiv;
    while (curr && curr->id != id) {
        prec = curr;
        curr = curr->suiv;
    }
    if (!curr) {
        printf("Tâche non trouvée.\n");
    } else {
        prec->suiv = curr->suiv;
        free(curr);
    }
    return tete;
}

// 6. Suppression avant une tâche donnée (recherche par id)
// * Principe : Pour supprimer le nœud précédant celui dont l'id est recherché, 
//              il faut gérer plusieurs cas :
//      1.  Liste vide
//      2.  La tâche recherchée est en tête, Il n’existe rien avant, 
//          rien à supprimer
//      3. Le nœud à supprimer est la tête → on doit mettre à jour tete
//      4. Recherche dans le reste de la liste
//
// Il faut au moins trois pointeurs (pprec, prec, curr) pour détecter 
// le nœud avant celui recherché.

Tache* supprimerAvant(Tache *tete, int id) {
    if (!tete || !tete->suiv) {  
        printf("Suppression impossible (liste vide ou un seul élément).\n");
        return tete;
    }

    // Si la tête est la tâche recherchée → rien avant à supprimer
    if (tete->id == id) {
        printf("Aucune tâche avant celle d'id %d.\n", id);
        return tete;
    }

    Tache *pprec = NULL;    // pointeur du nœud avant prec
    Tache *prec = tete;     // précède curr
    Tache *curr = tete->suiv;

    while (curr && curr->id != id) {
        pprec = prec;
        prec = curr;
        curr = curr->suiv;
    }

    if (!curr) {
        printf("Tâche cible non trouvée.\n");
        return tete;
    }

    // Ici : curr est la tâche dont l'id == id
    // prec est la tâche juste avant curr --> à supprimer

    if (!pprec) {
        // Cela signifie que prec == tete
        tete = tete->suiv;
    } else {
        pprec->suiv = prec->suiv;
    }

    free(prec);
    printf("Suppression effectuée : tâche avant l'id %d supprimée.\n", id);

    return tete;
}

// 7. Suppression après une tâche donnée (recherche par id)
// * Principe :
//  - Chercher le nœud dont l'id correspond
//  - Vérifier qu'il a bien un suivant
//  - Supprimer ce suivant
//
// * Cas particuliers :
//  - Liste vide
//  - Tâche recherchée introuvable
//  - Tâche trouvée mais aucune tâche après elle
Tache* supprimerApres(Tache *tete, int id) {

    if (!tete) {
        printf("Liste vide.\n");
        return tete;
    }

    Tache *curr = tete;

    // Recherche de l'id
    while (curr && curr->id != id) {
        curr = curr->suiv;
    }

    if (!curr) {
        printf("Tâche %d non trouvée.\n", id);
        return tete;
    }

    if (!curr->suiv) {
        printf("Aucune tâche après la tâche %d.\n", id);
        return tete;
    }

    // Suppression de la tâche après curr
    Tache *tmp = curr->suiv;
    curr->suiv = tmp->suiv;
    free(tmp);

    printf("Suppression effectuée : tâche après l'id %d supprimée.\n", id);

    return tete;
}

// 8. Affichage
void afficherListe(Tache *tete) {
    if (!tete) {
        printf("Liste vide.\n");
        return;
    }
    while (tete) {
        printf("[ID:%d] \"%s\" - Priorité:%d\n", tete->id, tete->description, tete->priorite);
        tete = tete->suiv;
    }
}

// 9. Comptage
int compterTaches(Tache *tete) {
    int n = 0;
    while (tete) {
        n++;
        tete = tete->suiv;
    }
    return n;
}

int main() {
    Tache *liste = NULL;
    int choix, id, id_ref, priorite;
    char desc[50];

    do {
        printf("\n===== MENU GESTION TACHES =====\n");
        printf("1. Ajouter au début\n");
        printf("2. Ajouter à la fin\n");
        printf("3. Ajouter avant une autre\n");
        printf("4. Ajouter après une autre\n");
        printf("5. Supprimer une tâche\n");
        printf("6. Supprimer avant une tâche\n");
        printf("7. Supprimer après une tâche\n");
        printf("8. Afficher toutes les tâches\n");
        printf("9. Compter le nombre de tâches\n");
        printf("10. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
        case 1:
            printf("ID : "); scanf("%d", &id); getchar();
            printf("Description : "); fgets(desc, 50, stdin); desc[strcspn(desc, "\n")] = 0;
            printf("Priorité : "); scanf("%d", &priorite);
            liste = insererDebut(liste, id, desc, priorite);
            break;
        case 2:
            printf("ID : "); scanf("%d", &id); getchar();
            printf("Description : "); fgets(desc, 50, stdin); desc[strcspn(desc, "\n")] = 0;
            printf("Priorité : "); scanf("%d", &priorite);
            liste = insererFin(liste, id, desc, priorite);
            break;
        case 3:
            printf("ID référence : "); scanf("%d", &id_ref);
            printf("ID : "); scanf("%d", &id); getchar();
            printf("Description : "); fgets(desc, 50, stdin); desc[strcspn(desc, "\n")] = 0;
            printf("Priorité : "); scanf("%d", &priorite);
            liste = insererAvant(liste, id_ref, id, desc, priorite);
            break;
        case 4:
            printf("ID référence : "); scanf("%d", &id_ref);
            printf("ID : "); scanf("%d", &id); getchar();
            printf("Description : "); fgets(desc, 50, stdin); desc[strcspn(desc, "\n")] = 0;
            printf("Priorité : "); scanf("%d", &priorite);
            liste = insererApres(liste, id_ref, id, desc, priorite);
            break;
        case 5:
            printf("ID à supprimer : "); scanf("%d", &id);
            liste = supprimerTache(liste, id);
            break;
        case 6:
            printf("ID à supprimer avant : "); scanf("%d", &id);
            liste = supprimerAvant(liste, id);
            break;
        case 7:
            printf("ID à supprimer apres : "); scanf("%d", &id);
            liste = supprimerApres(liste, id);
            break;
        case 8:
            afficherListe(liste);
            break;
        case 9:
            printf("Nombre total : %d\n", compterTaches(liste));
            break;
        case 10:
            printf("Fin du programme.\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choix != 10);

    return 0;
}