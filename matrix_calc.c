#include<stdio.h>
int main()
{	


	int n;
        printf("enter the size of sqaure matrix=");
        scanf("%d",&n);
	int i,j,k,l,sum,pro,diff,a[n][n],b[n][n];

	for(i=0;i<n;i++)
	  {
               for(j=0;j<n;j++)

	       {     
		       printf("enter element no %d,%d\n",i,j);
		       scanf("%d",&a[i][j]);
	       }
	  }
	

	 for(i=0;i<n;i++)
	 {
		 for(j=0;j<n;j++)
					                         
		 {     
			 printf("enter element no %d,%d\n",i,j);
		      	 scanf("%d",&b[i][j]);
	          }       
	 }
   printf("sum= ");
	 for(i=0;i<n;i++)
	 {
		 for(j=0;j<n;j++)
		 {
			 sum= a[i][j]+b[i][j];
			 printf("\t%d",sum);


		 }
		 printf("\n");
	 }

	 printf("diff=");

         for(i=0;i<n;i++)
	 {
	         for(j=0;j<n;j++)
	          {
	                 diff= a[i][j]-b[i][j];
			 printf("\t%d",diff);
                   }
		 printf("\n");
          }     



			printf("pro=");
	 for(i=0;i<n;i++)
	 {	
		 for(j=0;j<n;j++)
		 {    
			 l=0;
			 for(k=0;k<n;k++)
			 {
				 
				 pro=a[i][k]*b[k][j];
				 l+=pro;
			 }
				 printf("\t%d",l);
		 }

		 printf("\n");
	 }
	 return 0;
}
