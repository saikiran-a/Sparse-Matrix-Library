/* Sparse matrix */

#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

int main()
{
	int loop = 1 ;
	while(loop)
	{
		int ch ;
		printf("1. ADD 2 MATRICES\n2. MULTIPLY 2 MATRICES\n3. EXIT\n") ;
		scanf("%d" , &ch) ;
		sparse s1,s2,s3 ;
	
		switch(ch)
		{
			case 1:
				
				printf("Enter the details of 1st matrix..\n") ;
				create_mat(&s1) ;
				printf("entered matrix is : \n") ;
				display(&s1) ;

				printf("Enter the details of 2nd matrix..\n") ;

				create_mat(&s2) ;
				printf("entered matrix is : \n") ;
                                display(&s2) ;
				if(s1.row_sz == s2.row_sz && s1.col_sz == s2.col_sz) 
				{
					s3.row_sz = s2.row_sz ;
                                	s3.col_sz = s2.col_sz ;
					init_sparse(&s3) ;

					add(&s1,&s2,&s3) ;

					printf("\nSUM of MATRICES PRESENT IS : \n") ;
					display(&s3) ;   
				}
				else
					printf("can't be added..\n") ;
				break ;

			case 2:
				printf("Enter the details of 1st matrix..\n") ;

				create_mat(&s1) ;
                                printf("entered matrix is : \n") ;
                                display(&s1) ;
				
				printf("Enter the details of 2nd matrix..\n") ;

                                create_mat(&s2) ;
                                printf("entered matrix is : \n") ;
                                display(&s2) ;

				if(s1.col_sz == s2.row_sz)
				{
                                	s3.row_sz = s1.row_sz ;
                                	s3.col_sz = s2.col_sz ;

                                	init_sparse(&s3) ;

                                	mul(&s1,&s2,&s3) ;

                                	printf("\nProduct of MATRICES PRESENT IS : \n") ;
                               		display(&s3) ;
				}
				else
					printf("cant be multiplied..\n") ;
				break ;

			case 3:
				loop = 0 ;
				break ;
	

			default:
				printf("enter a valid choice\n") ;


		}
	
	
	


	}
#if 0
	sparse s1,s2,s3;
	create_mat(&s1);
	create_mat(&s2);
	s3.row_sz = s2.row_sz;
	s3.col_sz = s2.col_sz;
	
	init_sparse(&s3);
 	add(&s1,&s2,&s3);	

	printf("\nMATRIX PRESENT IS : \n");
	display(&s3);		
#endif		
//displays the elements of the matrix in original form
	return 0;
}
