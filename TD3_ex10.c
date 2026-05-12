#include<stdio.h>
int main()
{
	char lettre[500],conservateur[500];
	int i,compteur=0;
	int a;
	printf("Entrer une lettre :");
	scanf("%[^\n]",lettre);
	while (lettre[compteur] != '\0')
	{
		 	compteur++;
	}
	a=0;
	for (i=0;i<compteur;i++)
	{
		
		if (((lettre [i]!='a' && lettre[i] !='e' && lettre[i]!='i' && lettre[i]!='o' && lettre[i]!='u' && lettre[i] !='y')&&(lettre [i+1]=='a' || lettre[i+1] =='e'||lettre[i+1]=='i' || lettre[i+1]=='o'||lettre[i+1]=='u' || lettre[i+1] =='y')))
		{
			conservateur[a]=lettre[i];
			conservateur[a+1]='I';
			conservateur[a+2]='T';
			conservateur[a+3]=lettre[i+1];
			a=a+4;
			i++;
		}
		else
		{
			conservateur[a]=lettre[i];
			a++;
		}
	}
	conservateur[a]='\0';
	printf("%s\n",conservateur);
	return 0;
}

