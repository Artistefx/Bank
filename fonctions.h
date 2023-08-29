#include "Fonction.h"

Etudiant* saisie(int taille);
void Afficher(Etudiant * LEtd,int taille);
void AfficheParCNE(Etudiant *LEtd, int cne, int taille);
void SupprimerEtdParCNE(Etudiant *LEtd, int cne, int *taille);
void Ajouter(Etudiant *LEtd,int *taille);
void Miseajour(Etudiant *LEtd,int j,int taille);
void tri(int taille ,Etudiant *LEtd );
void echange_Etd(int taille,int i, int j, Etudiant* LEtd);
void Tri (Etudiant *LEtd, int nbPers);
Etudiant * ChercherDich(Etudiant *LEtd, int nbPers);
int nbrligne(FILE *fichier);
int menu(void);
void delay(int j);
void Miseajourdesdonnees(FILE*fich,Etudiant *p,int taille);
void copy_right(void);
