#include "fonctions.h"

main () {
	FILE*x=NULL;//intialisation d'un pointeur fichier
	Etudiant *p;
	Etudiant *Y;
	int *q,N,cne,a,b,i,j,f,cas,o;//tout les variable sont utilisées
	char line[25]="";//pour le remplissage du tab par notre fichier
	int k;
	green();//changer couleur d'écriture utilisée pls fois
	blue();
	blue();
	printf("\n\t\t\t");
	printf("________________________________________________");
	printf("\n\t\t");
	printf("________|   						|_______");
	printf("\n\t\t");
	printf("\\       |   	        MINI PROJET C		        |      /");
	printf("\n\t\t");
	printf(" \\      |   					        |     /");
	printf("\n\t\t");
	printf(" /      |_______________________________________________|     \\ ");
	printf("\n\t\t");
	printf("/__________)                                        (__________\\ ");
	
	
	printf("\n\n\n");
	printf("\n\t\t\t\t\tLOADING");
	for(i=0;i<10;i++){
			delay(100000000); // fonction de retard
			printf(".");
		}
		system("cls");
	white();
	purple();
	do{// menu intro
	printf("\n\n\n\n\n\n\n\t\t\t\t\t1) Charger l'ancienne liste\n");
	printf("\t\t\t\t\t2) Nouvelle liste d'etudiants\n");
	white();
	printf("\n\t\t\t\t\tEnter votre choix: ");
	scanf("%d",&cas);
	system("cls");
    }while(cas!=1 && cas!=2);
	switch(cas){//utilises l'ancienne liste ou creer une nouvelle
		case 1: 
				N=nbrligne(x);//prend le nombre d'etudiant dans le fichier
			    Y=(Etudiant*)malloc(sizeof(Etudiant)*N);//allocation dynamique 
			    x = fopen("Etudiant.txt","r");//ouverture en mode ecriture
			    if(x!=NULL){//si le fichier n'est pas vide
				for(k=0;k<=N;k++){//remplissage du tab depuis le fichier
					fscanf(x,"%s",line);
					strcpy(Y[k].N,line);
					fscanf(x,"%s",line);
					strcpy(Y[k].P,line);
					fscanf(x,"%s",line);
					Y[k].CNE=atoi(line);//atoi fct qui convetisse nombre char en nombre int definie dans stdio
					fscanf(x,"%s",line);
					strcpy(Y[k].naissance.dn,line);
					fscanf(x,"%s",line);
					Y[k].adresse.num=atoi(line);
					fscanf(x,"%s",line);
					strcpy(Y[k].adresse.V,line);
				}p=Y;//pointeur prend l'adresse du tab;
				fclose(x);}
				else {
					printf("Fichier vide \nNouvelle liste: \n");
					goto jump;//si le fichier est vide on commence le remplissage directement
					fclose(x);}
				break;
		case 2:	jump:
				printf("la taille de la liste des etudiants :");
				scanf("%d",&N);
				p=saisie(N);//pointeur prend l'adresse du tab
				x=fopen("Etudiant.txt","w");
				for(j=0;j<N;j++){//remplissage du fichier par la liste
				fprintf(x,"%s %s %d %s %d %s \n",p[j].N,p[j].P,p[j].CNE,p[j].naissance.dn,p[j].adresse.num,p[j].adresse.V);}
				fclose(x);
				break;
}
	q=&N;
	
	do{
		printf("\t\t\t\t********************************\n");
		printf("\t\t\t\t***     MENU DE GESTION      ***\n");
		printf("\t\t\t\t********************************\n");
	red();
	switch(menu()){//menu principale qui prend le choix retourner par la fct int menu et fait appel au fct
        case 1:	white();
				Afficher(p,N);
       			printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
        break;
        case 2:	white();
				printf("Entrer le CNE de l'etudiant a rechercher:");
        		scanf("%d",&cne);
				AfficheParCNE(p,cne,N);
				printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
        break;
        case 3: white();
				printf("Entrer le CNE de l'etudiant a supprimer:");
        		scanf("%d",&cne);
				SupprimerEtdParCNE(p,cne,q);
				printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
        break;
        case 4:	white();
				ChercherDich(p,N);
        		printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
        break;
        case 5:	white();
				printf("Entrer l'indice de l'etudiant a echanger :");
        		scanf("%d",&a);
        		printf("Entrer l'indice de l'etudiant a echanger :");
        		scanf("%d",&b);
				echange_Etd(N,a,b,p);
				printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
        break;
        case 6:	white();
		        tri(N,p);
        		printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
		break;
		case 7: white();
				Ajouter(p,q);
				printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
		break;
		case 8:	white();
				printf("Entrer l'indice de l'etudiant a changer :");
        		scanf("%d",&a);
				Miseajour(p,a,N);
				printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
		break;
		case 9:	copy_right();
				printf("Entrer 0 pour retourner au menu : ");
				scanf("%d",&f);
				system("cls");
        break;
		case 10:f=1;
		}}while(f==0);// le menu s'affiche tq l'utilisateur n'a pas entrer qlq chose que 0
        system("cls");
        white();
        printf("Entrer 0 si vous voulez mettre a jour la liste sauvgarder :");
        scanf("%d",&o);
        if(o==0) Miseajourdesdonnees(x,p,N);//sauvgarder les modifications ou non
        
}

