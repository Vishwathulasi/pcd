#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct op
{
	char l;
	char r[20];
}op[20],pr[20];
int main()
{
	int n,i=0,j=0,z=0;
	char temp;
	printf("Enter the number of values : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("\nLeft : ");
		scanf(" %c",&op[i].l);
		printf("Right : ");
		scanf("%s",op[i].r);
	}
	printf("\nIntermediate Code : ");
	for(i=0;i<n;i++)
	{
		printf("\n%c = %s",op[i].l,op[i].r);
	}
	
	for(i=0;i<n;i++)
	{
		temp=op[i].l;
		for(j=0;j<n;j++)
		{
			if(strchr(op[j].r,temp))
			{
				pr[z++]=op[i];
				break;
			}
		}
	}
	
	printf("\n\nAfter dead code elimination : ");
	for(i=0;i<z;i++)
	{
		printf("\n%c = %s",pr[i].l,pr[i].r);
	}
	
	for(i=0;i<z;i++)
	{
		for(j=i+1;j<z;j++)
		{
			if(strstr(pr[i].r,pr[j].r))
			{
				pr[j].l=pr[i].l;
			}
		}
	}
	
	printf("\n\nEliminate common expression : ");
	for(i=0;i<z;i++)
	{
		printf("\n%c = %s",pr[i].l,pr[i].r);
	}
	
	printf("\n\nOptimized code : ");
	for(i=0;i<z;i++)
	{
		if(pr[i].l!='\0')
		{
			for(j=i+1;j<z;j++)
			{
				if(pr[i].l==pr[j].l && strcmp(pr[i].r,pr[j].r)==0)
				{
					pr[j].l='\0';
				}
			}
			printf("\n%c = %s",pr[i].l,pr[i].r);
		}
	}
}
/*Enter the number of values : 5

Left : a
Right : 10

Left : b
Right : 20

Left : c
Right : a+b

Left : e
Right : c+d

Left : d
Right : a+b*/
