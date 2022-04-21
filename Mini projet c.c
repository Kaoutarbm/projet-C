#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include<windows.h>
#include <conio.h>


                        /* ************************************************************************************
                         *                                                                                   *                                                                                *
                        *                            PROJECT BY: KAOUTAR EL BAAMRANI
                                                          GROUPE TP: SMI4 G2B
                                                        CNE:  20-D136794925                                 *                         *
                       *                                                                                   *
                      *                                                                                   *
                     *                                                                                   *
                    *                                                                                   *
                   ************************************************************************************/





typedef struct date
{
int j;
int m;
int a;
}date;

typedef struct Voiture
{
int idVoiture;
char marque[15];
char nomVoiture[15];
char couleur[7];
int nbplaces;
int prixJour;
char EnLocation[4];
}voiture;

typedef struct contratLocation
{
int numContrat;
int idVoiture;
int idClient;
date debut;
date fin;
int count;
}contrat;

typedef struct Client
{
int idClient;
char nom[20];
char prenom[20];
int cin;
char adresse[15];
int telephone;
}client;


//declaration de type struct
voiture V;
contrat CO;
client C;
FILE *F,*L,*G,*G1,*K,*K1,*F1;

//MENU
void MenuPrincipal();
void MenuGestionVoiture();
void MenuGestionClient();
void MenuLocation();
char Retourn();
//fonctions client
 void listeclient();
 void ajouteclient();
 void supprimeclient();
 void modifierclient();
 int rechC();

//fonctions voiture
 void  listevoiture();
 void  ajoutevoiture();
 void SupprimerVoiture();
 void modifiervoiture();
int rechV();


//fonctions contrat
void Visualisercontrat();
void louervoiture();
void ajoutecontrat();
void Retournervoiure();
void Modifiercontrat();
void SupprimerContrat();
void modifierLoation();
int rechCo();

void MenuPrincipal()
{  system("cls");
	int choix;
     char c;

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Menu Principale \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Location..............................1   \xba");
	printf("\n               \xba    Gestion voitures......................2   \xba");
	printf("\n               \xba    Gestion clients.......................3   \xba");
	printf("\n               \xba    Quitter...............................4   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	scanf("%d",&choix);

 switch(choix)
{
     case 1:
         MenuLocation();
          c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else

     MenuLocation();


             break;
     case 2:
          MenuGestionVoiture();

          c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else

       MenuGestionVoiture();

             break;
     case 3:
         MenuGestionClient();

          c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else

         MenuGestionClient();

             break;
     case 4:{
	 system("cls");
             exit(0);}
     default:{
     	puts("**************************************************************************************************");
          printf("\n  entrez le choix correcte");
        puts("**************************************************************************************************");
             if(getch())
                    MenuPrincipal();
             }
}
 }


//Retourn

char Retourn()
{   char c;
	printf("  \n\n************revenir au menu principal oui(o)/non(n) *******************\n\n");
    scanf("%c",&c);
    return c;

        }



        void MenuGestionVoiture()
{
	int choix;
	char c;
    system("cls");

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion voiture \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    liste de voiture......................1   \xba");
	printf("\n               \xba    Ajouter voiture.......................2   \xba");
	printf("\n               \xba    Modifier voiture......................3   \xba");
	printf("\n               \xba    Supprimer voiture.....................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
    scanf("%d",&choix);

	 switch(choix)
{
     case 1:
          listevoiture();
           c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else


		   listevoiture();

             break;
     case 2:
          ajoutevoiture();
            c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else
			ajoutevoiture();
             break;
     case 3:
          modifiervoiture();
           c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else
			  modifiervoiture();
			   c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else


		  modifiervoiture();
             break;
     case 4:
         SupprimerVoiture();
          c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else
			  SupprimerVoiture();
             break;
     case 5:

            MenuPrincipal();


            break;
     default:{

      printf("\n entrez le choix correct' \n");

             if(getch())
                    MenuGestionVoiture();
             }	}

}





int rechV(int idV)
{
rewind(F);
while(fread(&V,sizeof(V),1,F)==1)
if(V.idVoiture==idV)
return 0;
return 1;
}



void listevoiture(){
       system("cls");

      printf("\n\n********************************* Liste de voitures*****************************\n\n");
	  F=fopen("voiture.dat","rb");
       while(fread(&V,sizeof(V),1,F)==1)
		{
			printf("\n id de voiture .................. :   %d\n",V.idVoiture);

			printf("   marque de voiture............... :   %s\n",V.marque);

			printf("   le nom de voiture............... :   %s\n",V.nomVoiture);

			printf("   le prix de joure de voiture..... :   %d\n",V.prixJour);

			printf("   le couleur de voiture........... :   %s\n",V.couleur);

			printf("   le nembre deplace de voiture.... :   %d\n",V.nbplaces);

			printf("   en location  : oui (1)/non(0)... :   %s \n",V.EnLocation);

			printf("****************************************************************************************");

            }  sleep(10);
             system("cls");
			  fclose(F);
        //	MenuGestionVoiture();
}




void  ajoutevoiture(){
system("cls");

 int id;
   printf("\n\n\n*************Entrez id de voiture qui vous voulez ajouter******************************\n\n\n");
   scanf("%d",&id);
    F=fopen("voiture.dat","ab+");

	if(rechV(id) == 1)


{                system("cls");
		          puts("/n**************************************************************************************************/n");
	            	 printf("\n ->Entrez votre nom de voiture \n");
		             scanf("%s",V.nomVoiture);
		             fflush(stdin);
		             printf("  ->Entrez votre Id de voiture \n");
                     scanf("%d",&V.idVoiture);
                     fflush(stdin);
                     printf("  ->Entrez votre de mark de voiture  \n");
                     scanf("%s",V.marque);
                     fflush(stdin);
                     printf("  ->Entrez votre couleur de voiture  \n");
                     scanf("%s",V.couleur);
                     fflush(stdin);
                     printf("  ->Entrez votre nbplace de voiture  \n");
                     scanf("%d",&V.nbplaces);
                     fflush(stdin);
                     printf("  ->Entrez votre prix de jour   \n");
                     scanf("%d",&V.prixJour);
                     fflush(stdin);
                     printf("  ->Entrez votre enlocation oui (0)/non (1)\n ");
                     scanf("%s",V.EnLocation);
                     fflush(stdin);
                     printf("\n**************************************************************************************************/n");
	                 fwrite(&V,sizeof(V),1,F);
	                 fseek(F,0,SEEK_END);
                     fclose(F);
                    printf("\n****************L'enregistrement est enregistrer*******************");


	}
	else
         printf("\n *********id du voiture existe deja*********** ");
	}



void modifiervoiture(void)
	{
		system("cls");
		int id;

		printf("\n ***************Modifier les information sur une voiture ***************\n");
         system("cls");

			printf(" ->Entrez le id  de voiture qui vous modifier:");
			scanf("%d",&id);
			F=fopen("voiture.dat","rb+");
	while  (fread(&V,sizeof(V),1,F)  )
        {

		  if((rechV(id)==0))
{


                    printf("\n*********** la voiture est disponible      : **********\n");
					printf("\n ********** Entrez nouveau  id de voiture  : **********\n");
					scanf("%d",&V.idVoiture);
					fflush(stdin);

					printf("\n ->Entrez nouveau nom de voiture :\n");
					scanf("%s",V.nomVoiture);
					fflush(stdin);

					printf("\n ->Entrez nouveau  marque de voiture: \n");
					scanf("%s",V.marque);
					fflush(stdin);

					printf("\n ->Entrez nouveau  couleur de voiture: \n");
					scanf("%s",V.couleur);
					fflush(stdin);


					printf("\n  ->Entrez nouveau n de placces de voiture:\n");
					scanf("%d",&V.nbplaces);
					fflush(stdin);


					printf("\n  ->Enterz  nouveau prix de voiture :\n");
					scanf("%d",&V.prixJour);
					fflush(stdin);

					printf("\n  ->Enter  nouveau location de voiture oui ou non :\n");
					scanf("%s",V.EnLocation);
					fflush(stdin);

					printf("\n*****************L'enregistrement est reussi ****************************\n");
					fseek(F,ftell(F)-sizeof(V),0);
					fwrite(&V,sizeof(V),1,F);
					fclose(F);



        }
        else
        	printf(" \n************ id n'existe pas*************\n");

        }






        }



void SupprimerVoiture()
{
	  char choix;
	int id;
	printf("**************************************************************************************");
	 printf(" \n Entrez id de voiture qui vous voulez supprimer  \n\n          ");
	  scanf("%d",&id);
	   fflush(stdin);
	        F=fopen("voiture.dat","rb+");

             while(fread(&V,sizeof(V),1,F)==1)
                {
	 	        if(rechV(id)==0)
            {

	 		     printf("\n........la voiture est disponible :)...........\n");

                              F1=fopen("tmpvoiture.dat","wb+");

                                  while(fread(&V,sizeof(V),1,F)==1){
                                         if(id!=V.idVoiture){
                                        fseek(F1,0,SEEK_CUR);
                                         fwrite(&V,sizeof(V),1,F1);
                                     }                            }
                                          fclose(F1);
                                          fclose(F);
                                           remove("voiture.dat");
                               rename("tmpvoiture.dat","voiture.dat");

	 		printf("\n.........la suppression est reussi : .............\n");
	 		 }
	 		 else{
	           	printf("  \n............. id de votr voiture n'existe pas dans la liste :) ...................\n");
			  }

}}



void MenuGestionClient(void)
{    char c;
	int choix;
	system("cls");

	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Gestion client  \xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    liset client..........................1   \xba");
	printf("\n               \xba    ajoute client.........................2   \xba");
	printf("\n               \xba    Modifier client ......................3   \xba");
	printf("\n               \xba    Supprimer client  ....................4   \xba");
	printf("\n               \xba    Retour................................5   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
    scanf("%d",&choix);
  switch(choix)
{
     case 1:
         listeclient();
         c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else


		   listeclient();
             break;
     case 2:
          ajouteclient();
          c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else


		  ajouteclient();
             break;
     case 3:
         modifierclient();
          c=Retourn();
          if(c=='o'| c=='O')
		 {
            MenuPrincipal();
			}
			else
           modifierclient();

             break;
     case 4:
          supprimeclient();
             break;
     case 5:
        MenuPrincipal();
             break;
     default:{
     	puts("**************************************************************************************************");
          printf("\a.............entrez le choix correcte :) .....................");
        puts("**************************************************************************************************");
             if(getch())
                    MenuGestionClient();
             }
}
}



        int rechC( int idC)
{
rewind(G);
while(fread(&C,sizeof(C),1,G)==1)
if(C.idClient==idC)
return 0;
return 1;
}


void listeclient()
{
    system("cls");

      printf("\n\n********************************* Liste de clients*****************************\n\n");
	  G=fopen("client.dat","rb");
       while(fread(&C,sizeof(C),1,G)==1)
		{
			printf("\n  id de client.....................:   %d",C.idClient);

			printf("\n  le nom  de client................:   %s",C.nom);

			printf("\n  le prenom de client..............:   %s",C.prenom);

			printf("\n  le cin  de client................:   %d",C.cin);

		    printf("\n  l'adresse de client..............:   %s",C.adresse);

			printf("\n  le numero de telephone de client.:    %d\n",C.telephone);

			printf("****************************************************************************************");

            }  sleep(10);
             system("cls");
			  fclose(G);

}



void  ajouteclient(void){
system("cls");

 int id;
      printf("\n\n\n********************** Ajouter un client ******************************\n\n\n");

   printf("\n***Entrez le id de client*** \n\n");
   scanf("%d",&id);
    fflush(stdin);
    G=fopen("client.dat","ab+");

	if(rechC(id) == 1)

       {

           system("cls");
		          printf("/n**************************************************************************************************/n");
	            	 printf("\n ->Entrez le id de client \n");
		             scanf("%d",&C.idClient);
		              fflush(stdin);

		             printf("  ->Entrez le nom de client \n");
                     scanf("%s",C.nom);
                      fflush(stdin);

                     printf("  ->Entrez le prenom de client \n");
                     scanf("%s",C.prenom);
                      fflush(stdin);

                     printf("  ->Entrez  le cin de client \n");
                     scanf("%d",&C.cin);
                      fflush(stdin);

                     printf("  ->Entez l'adresse de client \n");
                     scanf("%s",C.adresse);
                      fflush(stdin);

                     printf("  ->Entrez le numero de telephone de client\n ");
                     scanf("%d",&C.telephone);
                     fflush(stdin);
                printf("\n**************************************************************************************************/n");
                fwrite(&C,sizeof(C),1,G);
	            fseek(G,0,SEEK_END);
              fclose(G);
                printf("\n************L'enregistrement est enregistrer**************");



	}
	else  printf("*********id de client deja existe**************");
	}

void modifierclient()
	{
		system("cls");

		int id;

		printf("\n ***************Modifier les information sur le client ***************\n");
             system("cls");

			printf(" ->Entrez le id  de client qui vous modifier:");
			scanf("%d",&id);
			 fflush(stdin);
			G=fopen("client.dat","rb+");
	while  (fread(&C,sizeof(C),1,G)  )
        {

		  if((rechC(id)==0))
{
                     printf("\n********** le client est disponible : **********\n");

					 printf("\n ->Entrez le id de client \n");
		             scanf("%d",&C.idClient);
		             fflush(stdin);

		             printf("   ->Entrez le nom de client \n");
                     scanf("%s",C.nom);
                      fflush(stdin);

                     printf("   ->Entrez le prenom de client \n");
                     scanf("%s",C.prenom);
                      fflush(stdin);

                     printf("   ->Entrez  le cin de client \n");
                     scanf("%d",&C.cin);
                      fflush(stdin);

                     printf("   ->Entez l'adresse de client \n");
                     scanf("%s",C.adresse);
                      fflush(stdin);

                    printf("\n ->Entez numero de telephone de client \n");
                    scanf("%d",&C.telephone);
                     fflush(stdin);

                    printf("\n*****************L'enregistrement est reussi ****************************\n");
					fseek(G,ftell(G)-sizeof(C),0);
					fwrite(&C,sizeof(C),1,G);
                    }
                     else
                   printf(" \n ***********id n'existe pas************\n");
                   fclose(G);
        }
                     }





void supprimeclient()
{
	  char choix;
	int id;
	printf("**************************************************************************************");
	 printf("           \n\n taper id de voiture qui vous voulez supprimer  \n\n          ");
	  scanf("%d",&id);
	   fflush(stdin);
	        G =fopen("client.dat","rb+");

             while(fread(&C,sizeof(C),1,G)==1)
                {
	 	        if(rechC(id)==0)
            {

	 		     printf("\n\\t\t.........le client est disponible :)...........\t\t");

                              G1=fopen("tmpclient.dat","wb+");

                                  while(fread(&C,sizeof(C),1,G)==1){
                                         if(id!=C.idClient){
                                        fseek(G1,0,SEEK_CUR);
                                         fwrite(&C,sizeof(C),1,G1);
                                     }                            }
                                          fclose(G1);
                                          fclose(G);
                                           remove("client.dat");
                               rename("tmpclient.dat","client.dat");

	 		printf("\n\t\t.........La suppression est reussi:.............\t\t\t");
	 		 }
	 		 else{
	           	printf("  \n............. id de votr voiture n'existe pas dans la liste :) ...................\a\n");
			  }

}}




void MenuLocation()
{
	int choix;
	system("cls");


	printf("\n                               \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                               \xb3 Location voiture\xb3");
	printf("\n                               \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

	printf("\n\n");

	printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                              \xba");
	printf("\n               \xba    Visualiser contrat....................1   \xba");
	printf("\n               \xba    louer voiture.........................2   \xba");
	printf("\n               \xba    Retourner voiture.....................3   \xba");
	printf("\n               \xba    Modifier contrat......................4   \xba");
	printf("\n               \xba    Supprimer contrat.....................5   \xba");
	printf("\n               \xba    Retour................................6   \xba");
	printf("\n               \xba                                              \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");

switch(getch())
{
     case '1':
         Visualisercontrat();
             break;
     case '2':
          louervoiture();
             break;
     case '3':
         Retournervoiture();
             break;
     case '4':
          Modifiercontrat();
             break;
     case '5':
        SupprimerContrat();
             break;
     case '6':
         MenuPrincipal();
             break;
     default:{
     	puts("**************************************************************************************************");
          printf("\n saisir le choix correcte");
        puts("**************************************************************************************************");
             if(getch())
                    MenuLocation();
             }
}
}

int rechCo(int num)
{
rewind(K);
while(fread(&CO,sizeof(CO),1,K)==1)
if(CO.numContrat==num)
return 0;
return 1;
}


void Visualisercontrat(){

    int num;
      printf("\n\n********************************* Liste de contrat*****************************\n\n");

	  K=fopen("contrat.dat","rb");

       while(fread(&CO,sizeof(CO),1,K)==1)
       {


            printf("****************************************************************************************");
            printf(" \n ->numero de contrat      :   %d\n",CO.numContrat);

			printf("    ->id de voiture          :   %d\n",CO.idVoiture);

			printf("    ->id de client           :   %d\n",CO.idClient);

			printf("    -> le debut de la date   :   %d/%d/%d \n",CO.debut.j,CO.debut.m,CO.debut.a );

			printf("    ->la fin de la date      :   %d/%d/%d \n",CO.fin.j,CO.fin.m,CO.fin.a);

			printf("    ->le prix                :    %d dh         \n",CO.count);

			printf("****************************************************************************************");

            }  sleep(5);
             system("cls");
			  fclose(F);
        	MenuGestionVoiture();
}






void Retournervoiture(){
    system("cls");

	 	int idV, idC, num;
	 	int a=0; 

	 	G=fopen("client.dat","rb+");
		F=fopen("voiture.dat","rb+");
	 	K=fopen("contrat.dat","rb+");
	 	printf("	** Retour de voiture **");
	 	printf("\n	=> Entrer l'id de voiture a retourner : ");
	 	scanf("%d",&idV);

	 	if( rechV(idV)==0 ){

	 		printf("\n	=> Entrer votre id de client  : ");
	 		scanf("%d",&idC);
	 	
			 
	 		if( rechC(idC)==0){

	 			printf("\n	=> Entrer le numero de votre contrat : ");
	 			scanf("%d",&num);
	 		
	 			if( rechCo(num ) ==0){

	 					modifierLoation();
	 					//SupprimerContrat();
	 				a=1;
	 			}
	 		
	 		}
			 		 
}

if(a=1) SupprimerContrat();
 fclose(K);
		 fclose(G);
		 fclose(F);
		//if(a=1) SupprimerContrat();
		
}
void louervoiture(){



int idv;
char nom[10],prenom[10];
int det=0,d;
char vr[200];
F=fopen("voiture.dat","rb+");
G=fopen("client.dat","rb+");
K=fopen("contrat.dat","ab+");

if(F!=0){
 printf("\nsaisir votre nom: ");
 scanf("%s",&nom);
 printf("\nsaisir votre prenom: ");
 scanf("%s",&prenom);

while(fread(&C,sizeof(struct Client),1,G)==1){//read client

    if(strcmp(C.prenom,prenom)==0 &&strcmp(C.nom,nom)==0 ){
        det=1;
    }
}
if(det==1){
    printf("\nvotre nom est  dans le systeme.\n");


printf("\nsaisir id de voiture que vous voullez louer : ");
scanf("%d",&idv);

while(fread(&V,sizeof(struct Voiture),1,F)==1){
    if(V.idVoiture==idv){
        printf("\nce voiture est existe.\n");


    if(strcmp(V.EnLocation,"oui")==0){
        printf("\ncette voiture est louer maintenat !!!\n");
        sleep(5);

    }else{
        printf("\nce voiture n'est pas louer.");
        printf("\nvous voullez le louer (1 si oui / 0 sinon) ? ");
        scanf("%d",&d);
        break;
    }

    }

}

if(d==1){
    int pv=0;

       modifierLoation();
       fclose(F);

  ajoutecontrat();
  printf("\t les informations enregistrer \n");

fwrite(&CO,sizeof(struct contratLocation),1,K);
fclose(K);

}

fclose(G);

}else{
    printf("\nVous n'avez pas dans notre systeme!!\n");
    sleep(5);
}
}

}




void modifierLoation(void)
	{
		system("cls");
		int id;

		printf("\n ***************Modifier les information sur une voiture ***************\n");
         system("cls");

			printf(" ->Entrez le id  de voiture qui vous modifier:");
			scanf("%d",&id);
			F=fopen("voiture.dat","rb+");
	while  (fread(&V,sizeof(V),1,F)  )
        {

		  if((rechV(id)==0))
{


                    printf("\n*********** la voiture est disponible      : **********\n");




					printf("\n  ->changer location de voiture   :\n");
					scanf("%s",V.EnLocation);
					fflush(stdin);

					printf("\n*****************L'enregistrement est reussi ****************************\n");
					fseek(F,ftell(F)-sizeof(V),0);
					fwrite(&V,sizeof(V),1,F);
					fclose(F);



        }
        else
        printf(" \n************ id n'existe pas*************\n");

        }



					


        }

void ajoutecontrat(){
system("cls");

 int num;
   printf("\n\n\n*********************entrez le numero de contrat  que vous voulez ajouter******************************\n\n\n");
   scanf("%d",&num);

K=fopen("contrat.dat","ab+");

	if(rechCo(num) == 1)


{                system("cls");
		          puts("/n**************************************************************************************************/n");
	            	printf("\n entrez numero de contrat \n");
                    scanf("%d",&CO.numContrat);
                    fflush(stdin);

		            printf("\n  entrez le id de voiture \n");
                    scanf("%d",&CO.idVoiture);
                    fflush(stdin);

                    printf("\n entrez le id de client  \n");
                    scanf("%d",&CO.idClient);
                    fflush(stdin);

                    printf("\n entrez le dubet de date jour/mois/annee \n");
                    scanf("%d%d%d",&CO.debut.j,&CO.debut.m,&CO.debut.a);
                    fflush(stdin);

                    printf("\n entrez fin de date jour/mois/annee \n");
                    scanf("%d%d%d",&CO.fin.j,&CO.fin.m,&CO.fin.a);
                    fflush(stdin);

                    CO.count=V.prixJour*((CO.fin.j+30*CO.fin.m+365*CO.fin.a)-(CO.debut.j+30*CO.debut.m+365*CO.debut.a));
                    printf("le prix est %d",&CO.count);

                printf("\n**************************************************************************************************/n");
	        fwrite(&CO,sizeof(CO),1,K);
	        fseek(K,0,SEEK_END);
              fclose(K);
                  printf("\n  les informations est enregistrer");


	}
	else
         printf("\n numero du  contrat existe deja ");
}





void Modifiercontrat(void)
	{
		system("cls");

		int num;

		printf("\n ***************Modifier les information DE CONTRAT ***************\n");


			system("cls");

			printf(" entrez le numero de contrat qui vous modifier:");
			scanf("%d",&num);
			fflush(stdin);
			K=fopen("contrat.dat","rb+");
	while  (fread(&CO,sizeof(CO),1,K)  )
        {

		  if(rechCo(num)==0)
{


                    printf("\n********** le contrat est disponible : **********\n");
                    printf("\n Entrez id de client");
                    scanf("%d",&CO.idClient);
                    fflush(stdin);

                    printf("\n Entrez id de voiture\n");
                    scanf("%d",&CO.idVoiture);
                    fflush(stdin);


                     printf("\n entrez la dubet de date jour/mois/annee \n");
                     scanf("%d%d%d",&CO.debut.j,&CO.debut.m,&CO.debut.a);
                     fflush(stdin);

                     printf("\n entrez fin de date jour/mois/annee \n");
                     scanf("%d%d%d",&CO.fin.j,&CO.fin.m,&CO.fin.a);
                     fflush(stdin);


					printf("\n*****************L'enregistrement est reussi ****************************\n");
					fseek(K,ftell(K)-sizeof(CO),0);
					fwrite(&CO,sizeof(CO),1,K);
					fclose(K);



        }
        else printf(" \n id n'existe pas\n");

        }






        }




void SupprimerContrat()
{
	  char choix;
	int num;
	printf("**************************************************************************************");
	 printf("           \n Entrez numero de contrat qui vous voulez supprimer  \n\n          ");
	  scanf("%d",&num);
	   fflush(stdin);
	        K=fopen("contrat.dat","rb+");

             while(fread(&CO,sizeof(CO),1,K)==1)
                {
	 	        if(rechCo(num)==0)
            {

	 		     printf("\n........le contrat est disponible :)...........\n");

                              K1=fopen("tmpcontrat.dat","wb+");

                                  while(fread(&CO,sizeof(CO),1,K)==1){
                                         if(num!=CO.numContrat){
                                        fseek(K1,0,SEEK_CUR);
                                         fwrite(&CO,sizeof(CO),1,K1);
                                     }                            }
                                          fclose(K1);
                                          fclose(K);
                                           remove("contrat.dat");
                               rename("tmpcontrat.dat","contrat.dat");
              printf("\n*************************************************************************************\n");
	 		  printf("\n.........la suppression est reussi : .............\n");
              printf("\n*************************************************************************************\n");
	 		 }
	 		 else{
                printf("\n*************************************************************************************\n");
	           	printf("\n............. ID de votr voiture n'existe pas dans la liste :) ...................\n");
                printf("\n*************************************************************************************\n");
			  }

}}


	int main()
	{
	    MenuPrincipal();
	    return 0;
	}
