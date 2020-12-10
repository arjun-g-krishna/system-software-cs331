#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char n;
	char n1,c1,i;
	char fn[10][10],ilab[20],iopd[20],m[20][3],oper[20];
	FILE *fp1,*fp2,*p[5];
	n=0;
	fp1 = fopen("macin.txt","r");
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s",ilab,iopd,oper);
		if(strcmp(iopd,"macro")==0)
			n++;
	}
	printf("Number of macros = %d",n);
	n1 = n;
	printf("\nEnter the filename(s): ");
	for(i=0;i<n;i++)
	{
		scanf("%s",fn[i]);
		p[i]= fopen(fn[i],"w");
	} 
	n = 0;
	rewind(fp1);
	while(!feof(fp1)){
		fscanf(fp1,"%s%s%s",ilab,iopd,oper);
		if(strcmp(iopd,"macro")==0)
		{
			strcpy(m[n],oper);
			fscanf(fp1,"%s%s%s",ilab,iopd,oper);
			while(strcmp(iopd,"mend")!=0)
			{
				fprintf(p[n],"%s%s%s\n",ilab,iopd,oper);
				fscanf(fp1,"%s%s%s",ilab,iopd,oper);
			}
			fclose(p[n]);
			n++;
		}	
	}
	for(i=0;i<n1;i++)
		p[i]=fopen(fn[i],"r");
	fp2 =  fopen("outmac.txt","w");
	rewind(fp1);
	fscanf(fp1,"%s%s%s",ilab,iopd,oper);
	while(!feof(fp1))
	{
		if(strcmp(iopd,"call")==0)
		{
			for(i=0;i<n1;i++)
			{
				if(strcmp(m[i],oper)==0)
				{
					rewind(p[i]);
					fscanf(fp2,"%s%s%s",ilab,iopd,oper);
					while(!feof(p[i]))
					{
						fprintf(fp2,"%s%s%s\n",ilab,iopd,oper);
						c1=1;
						fscanf(p[i],"%s%s%s",ilab,iopd,oper);
					}
					break;
				}
			}
		}
		if(c1!=1)
			fprintf(fp2,"%s%s%s\n",ilab,iopd,oper);
		c1 = 0;
		fscanf(fp1,"%s%s%s",ilab,iopd,oper);	
	}
	fprintf(fp2,"%s%s%s\n",ilab,iopd,oper);
	return 0;	
	
}
