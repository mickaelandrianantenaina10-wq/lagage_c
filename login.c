#include<stdio.h>
#include<stdlib.h>
void safidy(int *choix);
void operation(int nombre);
void creat(int nombre);
void login(int nombre);
int main()
{
	int choix;
	safidy(&choix);
	printf("votre choix est :%d\n",choix);
	operation(choix);
	return 0;
}
void safidy(int *choix)
{
	printf("Bonjour\tvoulez vouz faire quoi?\n");
	printf("1:Creer un utilisteur\n2:se connecter\n");
	while(1)
	{
		scanf("%d",choix);
		if (*choix==1)
		{
			break;
		}
		else if(*choix==2)
		{
			break;
		}
		else
		{
			printf("Veuiller choisir entre 1 et 2\n");
		}
	}
}
void operation(int nombre)
{
	FILE* pfile;
	FILE* pmdp;
	char mot[50],mdp[8];
	if (nombre==1)
	{
		int i=0;
		pfile=fopen("utilisateur.txt","a");
		pmdp=fopen("mdp.txt","a");
		if(pfile!=NULL && pmdp!=NULL)
		{
		printf("Entrer le nom de l'utilisateur:");
		scanf(" %[^\n]",mot);
		fprintf(pfile,"%s\n",mot);
		printf("Entrer le mot de passe de l'utilisateur (en 4 caractere)");
		while (1)
		{
			i=0;
			scanf(" %[^\n]",mdp);
			while(mdp[i]!='\0')
			{
				i++;
			}
			if (i==4)
			{
				printf("Mot de passe confirmer avec succer");
				fprintf(pmdp,"%s\n",mdp);
				break;
			}
		}
		printf("User creer avec succes\n");
		}
		fclose(pfile);
		fclose(pmdp);
	}
	else if(nombre==2)
	{
		int j=0;int k=0;
		int l=0,m=0,n=0,n1=0,m1=0,l1,verificateur=0,verificateur1=0;
		pfile=fopen("utilisateur.txt","r");
		pmdp=fopen("mdp.txt","r");
		char consnom[5][50];
		char consmdp[5][5];
		//recuperation des information dans les fichier
		while (!feof(pfile))
		{
			fscanf(pfile," %[^\n]",consnom[k]);
			k++;
		}
		while (!feof(pmdp))
		{
			fscanf(pmdp," %[^\n]",consmdp[j]);
			j++;
		}
		char nom[50],mdps[4];
		if(pfile!=NULL && pmdp!=NULL)
		{
			printf("Entrer votre nom:");
			scanf(" %[^\n]",nom);
			printf("Entrer votre mot de passe:");
			scanf(" %[^\n]",mdps);
			while(n<k-1)
			{
				verificateur=0;
				for(l=0;consnom[n][l]!='\0';l++)
				{
					if(nom[m]!=consnom[n][l])
					{
						verificateur++;
					}
					m++;
				}
				if (verificateur==0)
				{
					break;
				}
				m=0;
				n++;
			}
			while(n1<j-1)
			{
				verificateur1=0;
				for(l1=0;l1<5;l1++)
				{
					if(mdps[m1] != consmdp[n1][l1])
					{
						verificateur1++;
					}
					m1++;
				}
				if (verificateur1==0)
				{
					break;
				}
				m1=0;
				n1++;
			}
			if(verificateur1==0 && verificateur==0)
			{
				printf("Salut cher membre du groupe\n");
			}
			else
			{
				printf("Desoler mais vois n'etes pas de notre\n");
			}
			fclose(pfile);
			fclose(pmdp);
		}
		else
		{
			printf("Les fichier des information sont disparu\n");
		}
	}
}

