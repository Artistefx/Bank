#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

typedef struct {//structure date 
		char dn[10];//contenant le date de naissance
	}Date;
typedef struct  {
		int num;//contient le num de l'étudiant
		char V[20];//contient la ville de l'étudiant
	}Adresse;
typedef struct {
		char N[25],P[25];//contient la nom(N) et le prenom(P) de l'étudiant
		int CNE;//contient le cne de l'étudiant
		Date naissance;//variable de type date
		Adresse adresse;//variable de type adresse
	}Etudiant;

    Etudiant* saisie(int taille){//fonction de saisie
	Etudiant *T;//pointeur de type étudiant
	T=(Etudiant*)malloc(sizeof(Etudiant)*taille);//allocation dynamique avec la taille récupérer dans main
	int i;
	for(i=0;i<taille;i++){//boucle pour le remplissage du tableau
		printf("Entrer le nom :");
		scanf("%s",T[i].N);
		printf("Entrer le prenom :");
		scanf("%s",T[i].P);
		printf("Entrer le CNE :");
		scanf("%d",&T[i].CNE);
		printf("Entrer le date de naissance (j/m/a) :");
		scanf("%s",T[i].naissance.dn);
		printf("Entrer le num :");
		scanf("%d",&T[i].adresse.num);
		printf("Entrer la ville :");
		scanf("%s",T[i].adresse.V);

		system("cls");//supprimer se qui est afficher utilisés pls fois dans ce programme
}
return T;//retourne l'adresse du tab
}
void Afficher(Etudiant * LEtd,int taille){//fonction d'affichage de la list des étudiants
	int i;
	for(i=0;i<taille;i++){//boucle d'affichage
	printf("le nom de l'etudiant est : %s \n",LEtd[i].N);
	printf("le prenom de l'etudiant est : %s \n",LEtd[i].P);
	printf("le CNE de l'etudiant est : %d \n",LEtd[i].CNE);
	printf("la date de naissance de l'etudiant est :%s \n",LEtd[i].naissance.dn);
	printf("le numero: %d la ville :%s \n\n",LEtd[i].adresse.num,LEtd[i].adresse.V);
	}
}
void AfficheParCNE(Etudiant *LEtd, int cne, int taille){//affichage en recherchant le cne de l'étudiant
	int i,c=0;
	for(i=0;i<taille;i++){//boucle de rechereche
		if(LEtd[i].CNE==cne){//si la cond est vérifiée on a trouver l'étudiant
			c=1;
		Afficher(LEtd+i,1);//fct affichage pour afficher l'étudiant en qst
		break;}
	}
	if(c==0)
	printf("Etudiant rechercher introuvable\n");//si c ne prend pas 1 donc la cond n'est pas vérifiée
}
void SupprimerEtdParCNE(Etudiant *LEtd, int cne, int *taille){//supprime l'étudiant en recherchant le cne
	int i,j,flag,t;
	for(i=0;i<*taille;i++){//boucle de recherche
		if(LEtd[i].CNE==cne ){//condition de recherche
			if(i!=*taille-1){//i ne doit pas prendre la dernière case pour tasser le tab correctement
		        for(j=i;j<*taille-1;j++){//boucle de tasseage
		            LEtd[j]=LEtd[j+1];//tasser les cases depuis l'étudiant a supprimer 
		 }}
	    --*taille;//supprimer la dernière case
		flag=1;
		break;}

}
if(flag==0)
		printf("Pas d'etudiant avec ce CNE!! ");}//si flag n'a pas pris 1 donc la cond n'est pas vérifiée d'ou étudiant introuvable 

void Ajouter(Etudiant *LEtd,int *taille){//ajouter étudiant au tableau
	++*taille;//augmenter la taille par 1
		printf("Entrer le nom :");
		scanf("%s",LEtd[*taille-1].N);
		printf("Entrer le prenom :");
		scanf("%s",LEtd[*taille-1].P);
		printf("Entrer le CNE :");
		scanf("%d",&LEtd[*taille-1].CNE);
		printf("Entrer le date de naissance (j/m/a) :");
		scanf("%s",LEtd[*taille-1].naissance.dn);
		printf("Entrer le num :");
		scanf("%d",&LEtd[*taille-1].adresse.num);
		printf("Entrer la ville :");
		scanf("%s",LEtd[*taille-1].adresse.V);//remplissage de la case ajouter
}
void Miseajour(Etudiant *LEtd,int j,int taille){//mettre a jour les informations d'un étudiant
	int i=j-1,flag;
	 if(i!=taille){//i ne doit pas arriver a la taille car le dernier étudiant est taille-1
	 	flag=1;
		printf("Entrer le nom :");
		scanf("%s",LEtd[i].N);
		printf("Entrer le prenom :");
		scanf("%s",LEtd[i].P);
		printf("Entrer le CNE :");
		scanf("%d",&LEtd[i].CNE);
		printf("Entrer le date de naissance (j/m/a) :");
		scanf("%s",LEtd[i].naissance.dn);
		printf("Entrer le num :");
		scanf("%d",&LEtd[i].adresse.num);
		printf("Entrer la ville :");
		scanf("%s",LEtd[i].adresse.V);//changement des info de l'étudiant
		}
	if(flag==0){
		printf("Erreur indice plus grand que le nombre d'etudiant \n");//si flag n'a pas pris 1 donc la cond n'est pas vérifiée d'ou indice faux 
	}	
	
}
void tri(int taille ,Etudiant *LEtd ){//tri par selection du tab en se basant sur le cne
	int m,i,b,j;
	Etudiant temp;//variable pour l'echange des case

	for(i=0;i<taille-1;i++){//principe fondamentale du tri par selection
		m=i;
	       for(j=i+1;j<taille;j++){
	       	if(LEtd[j].CNE<LEtd[m].CNE){
	       		m=j;
			   }
		   }
		   temp = LEtd[m];
		   LEtd[m]=LEtd[i];
		   LEtd[i]=temp;
		}Afficher(LEtd,taille);//utilise la fct afficher pour afficher le tab apres tri
		}
void echange_Etd(int taille,int i, int j, Etudiant* LEtd){//prend 2 indice de 2 étudiant et fait un échenge d'info
    Etudiant temp;
    if(i<=taille && j<=taille){//i et j ne doivent pas dépassser le dernière case qui est taille-1
		temp=LEtd[i-1];	LEtd[i-1]=LEtd[j-1];	LEtd[j-1]=temp;}
	else{
		printf("Erreur indice plus grand que le nombre d'etudiant \n");}
}

void Tri (Etudiant *LEtd, int nbPers) {//tri par selection du nom pour pouvoir faire recherche dichotomique
	int i, j, indexduPetitElm ; // pour le tri par sélection 

	for (i = 0 ; i < nbPers-1 ; i++) {
		indexduPetitElm = i ;
		for ( j = i+1 ; j < nbPers ; j++ ){
			if ( strcmp(LEtd[j].N , LEtd[indexduPetitElm].N) < 0 )//strcmp compare deux chaînes caractère par caractère. Si les chaînes sont égales, la fonction renvoie 0
			indexduPetitElm = j ;
		}
		if (indexduPetitElm != i)  {  //faire des échanges
			echange_Etd(nbPers,i,indexduPetitElm,LEtd);
		} //fin de if
	} // fin de for
}

/* Recherche dichotomique dans un tableau trié  */
Etudiant * ChercherDich(Etudiant *LEtd, int nbPers) {
	Tri (LEtd,nbPers);
	char aChercher[21] ;
	int  mini, maxi, milieu, trouve ;
	int  compare, longueur ;

	printf("\n\n\t\t\t\t>>>>>>>     RECHERCHE DICHOTOMIQUE     <<<<<<<<<\n");
	printf("Entrez le nom de l'etudiant rechercher :");
	scanf("%s",&aChercher); /* get string = lire une chaîne */

	longueur = strlen(aChercher);//prend la longueur de la chaine

	mini = 0;
	maxi = nbPers - 1 ;
	trouve = 0 ; // on ne trouve pas encore 
	while (!trouve && mini <= maxi) {
		milieu = (mini + maxi) / 2 ;
		compare = strnicmp(aChercher, LEtd[milieu].N, longueur);
		if ( compare < 0 )
			maxi = milieu - 1 ;
		else  if (compare > 0)
			mini = milieu + 1 ;
		else trouve = 1 ;
	}
	if (!trouve)
		printf("Désolé, on ne trouve pas %s \n", aChercher);

	else {
		Afficher(LEtd+milieu,1);
	}
}
int nbrligne(FILE *fichier){//fct pour trouver le nombre d'etudiant dans un fichier
	
	int c, NbLigne;
	char line[20];
	NbLigne = 0;
	while((c=fgetc(fichier)) != EOF)
	{
		if(c=='\n')
		NbLigne++;
			
	}
	NbLigne+=2;
	return NbLigne;//return le nombre des lignes
	
}
	
int menu(){//menu avec printf et switch
	int choix,choix2;
	printf("\t\t\t\t1) Affichage de le liste des etudiants\n");
	printf("\t\t\t\t2) Rechercher etudiant par CNE\n");
	printf("\t\t\t\t3) Supprimer etudiant par CNE\n");
	printf("\t\t\t\t4) Chercher par dichotomie (Nom)\n");
	printf("\t\t\t\t5) Echanger 2 etudiants par indice\n");
	printf("\t\t\t\t6) Trier tableau par CNE\n");
	printf("\t\t\t\t7) Ajouter un etudiant\n");
	printf("\t\t\t\t8) Mise a jour d'un etudiant\n");
	printf("\t\t\t\t9) Createurs\n");
	printf("\t\t\t\t10)Quitter\n");
	printf("\n\t\t\t\t\tEnter votre choix: ");
	scanf("%d",&choix);

	system("cls");
	switch(choix){
        case 1:choix2=1;
        break;
        case 2:choix2=2;
        break;
        case 3:choix2=3;
        break;
        case 4:choix2=4;
        break;
        case 5:choix2=5;
        break;
        case 6:choix2=6;
        break;
        case 7:choix2=7;
        break;
        case 8:choix2=8;
        break;
        case 9:choix2=9;
        break;
        case 10:choix2=10;
        break;
        default:menu();	
}
return choix2;}//return le choix de utlisateur
void delay(int j)//fct de délai pour creer l'animation loading 
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void Miseajourdesdonnees(FILE*fich,Etudiant *p,int taille){//mettre a jour les donnees du fichier
	int j;
	fich=fopen("Etudiant.txt","w");//ouverture en mode ecriture en effecant le contenu
	for(j=0;j<taille;j++){//boucle de remplissage du fichier
	fprintf(fich,"%s %s %d %s %d %s \n",p[j].N,p[j].P,p[j].CNE,p[j].naissance.dn,p[j].adresse.num,p[j].adresse.V);
	}fclose(fich);
}
void copy_right(){//fct base avec printf des noms des createurs

	yellow();
	printf("\n\n\n\t\t\t\t==========>HAMZA KERBOUB GRP 4\n\n");
	purple();

	printf("\t\t\t\t==========>HASSAN BENHAMOU GRP 1\n\n");
	red();

	printf("\t\t\t\t==========>YOUSSEF KHALID GRP 4\n\n\n\n");
	
	cyan();
	printf("7NA GA TALABA W LPROJET NADI MAFIHA BAS LA TLA9TI IDK A OSTAD FDIK LA NOTE\nLPROJET 5DMNA 3LIH MN A TAL Z CHI SOUTENANCE MER7BA 7ADRIN NADRIN\n");

	white();
}
