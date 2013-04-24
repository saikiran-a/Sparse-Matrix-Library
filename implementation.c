#include"matrix.h"
#include<stdio.h>
#include<stdlib.h>

/*..................................Initialises the row headers and column headers and turning all of them to null....................................................*/

void init_sparse(sparse *s)
{
	int i,j;

	for( i = 0; i<(s->row_sz); i++)
	{
		s->row[i] = NULL;
	}
	for( j = 0; j<(s->col_sz); j++)
        {
                s->col[j] = NULL;
        }

}

/*..................................To add a node to the sparse matrix list by dynamically allocating the memory to each of the node recieved.........................*/  
void insert_node(int r,int c,double key,sparse *s1)
{
	node *temp;				//temporary pointer to the strucure of type node is created
	temp = (node*)malloc(sizeof(node));	//memory is allocated dynamically to that temp pointer with the size of structure "node"
	temp->key = key;
	temp->row = r;
	temp->col = c;
	temp->rlink =0;
	temp->clink = 0;
	node *rr = s1->row[r];
	node *cc = s1->col[c];

	if(rr == NULL)				//checks wether the pointed row list is empty 
	{
		s1->row[r] = temp;		//if the row list is empty ..... the temp is assigned as 1st node in that row list
	}

	else					//comes here if pointed row list is not empty
	{
		while(rr->rlink)		//to get link of the last in the pointed row list
		{
			rr = rr->rlink;
		}

		rr->rlink = temp;		//node is added then!!!!
		
	}
	
	if(cc == NULL)				//checks wether the pointed coloumn list is empty 
	{
        	s1->col[c] = temp;		//if the row list is empty ..... the temp is assigned as 1st node in that row list

        }

	else					//comes here if pointed row list is not empty

	{
		while(cc->clink)		//to get link of the last in the pointed row list

		{
			cc= cc->clink;
		}

		cc->clink = temp;		//node is added then!!!!

	}	
}
/*...........................................To display the elements present in the dynamically created sparse matrix list............................................*/
void display(sparse *s)

{
	int i,j,k,m,n;

	for(i = 0;i<(s->row_sz); ++i)						//To displaiy the elements of the matrix row wise

	{
		node * rr=s->row[i];
		node * p=s->row[i];

		if(rr == NULL)							//checks wether pointing row is null!!1
		{
			for(j = 0; j<(s->col_sz);++j)
			{
				printf("0.00\t");					//if pointin row list is null then prints the whole row elements as zero
				
			}
		}

		else								//comes here if row list is not empty
		{
			int prev = 0;
			int count = 0;

			while(rr != NULL)					//to print zero and non zero row elements in original form
			{
				if((rr->col == 0)||(rr->col-p->col == 1))	//for 1st or consecutive non zero elements 
				{
					printf("%.2f\t",rr->key);			//prints either 1st element or consecutive elements in the pointed row
				}
				
				else if(count != 0)				//for zero elements between the previous and current node and for key of current node
				{
					for(k = 1;k<((rr->col)-prev);++k)
					{
						printf("0.00\t");			//prints the zero elements between any 2 consecutive nodes "if present"
					}

					printf("%.2f\t",rr->key);			//prints the key of the current node 
				}

				 else 						//for the last element in the coloumn for the pointed row 
                                {
                                        for(n = 0;n< rr->col;++n)
                                        {
                                                printf("0.00\t");			//prints the zero elements 
                                        }
                                        printf("%.2f\t",rr->key);			//prints the key of last element
                                }

				count++;
				p = rr;
				prev = rr->col;
				rr = rr->rlink;
			}

			if(p->col < ((s->col_sz)-1))				//for zero elements after the last node in the pointed row list if present
				{
					for(m = p->col ; m < (s->col_sz)-1 ; ++m)
					{
						printf("0.00\t");			//prints zero elements
					}
				}
		}
		printf("\n");
		
	}

}


/*........................................................................................................................................................*/

void add(sparse *s1,sparse *s2,sparse *s3)
{

	int i,j;
	for(i=0;i<s1->row_sz;++i)
	{						// initialize the SUM matrix to first matrix
		node *temp1=s1->row[i];
		while(temp1)
		{
			insert_node(temp1->row,temp1->col,temp1->key,s3);
			temp1 = temp1->rlink;
		}
	}
	for(j=0;j<s2->row_sz;++j)
	{

		node *temp2 = s2->row[j];
		while(temp2)
		{
			node *pres;
			node *pres1;
			node *prev = NULL;
    			node *new = malloc(sizeof(node));
    			new->row = temp2->row;
    			new->col = temp2->col;
    			new->key = temp2->key;

    			if (s3->row[j] == NULL)
    			{
				
        			s3->row[j] = new;
        			new->rlink = NULL;
    			}
    			else
    			{	
        			pres = s3->row[j];
				pres1 = s3->row[j];
				int flag = 0;
				while(pres)
				{
					if(pres->col == new->col)
                                        {
                                              	pres->key = new->key + pres->key;
						flag = 1;
						break;
                                      	}
					pres = pres->rlink;

				}
						
				if(flag == 0)
				{
							
        				if(new->col < pres1->col)
        				{
							 
            					new->rlink = pres1;
            					s3->row[j] = new;
       					}
        				else if (new->col > pres1->col)
        				{	
							                                                      

            					while (pres1->rlink != NULL && (pres1->rlink)->col < new->col)
            					{
                					pres1 = pres1->rlink;
            					}	
            					new->rlink = pres1->rlink;
            					pres1->rlink = new;
        				}
				}
						
        					
    			}
        
						
					
			temp2 = temp2->rlink;
		}
	}
}

	 

/*.........................................................................................................................................................*/

void create_mat(sparse *s1)
{
	FILE *file1;
	char fname[20];

	int choice ;

	printf("Enter 1 if the file contains full Matrix...\n") ;
	printf("Enter 2 if the file contains Triplets...\n") ;

	scanf("%d" , &choice) ;

	if(choice == 1)
	{
		printf("\nenter the file name : ");
		scanf("%s",fname);
		file1 = fopen(fname,"r");                                       //opens the file present in read only mode
		if(file1==NULL)                                         //gives message if that file is not present
		{
			printf("file not found\n\n");
			exit(1);
		}
		printf("enter the row size and column size of the matrix : \n");
		printf("row size : ");
		scanf("%d",&s1->row_sz);
		printf("\ncol size : ");
		scanf("%d",&s1->col_sz);
		printf("\n");
		init_sparse(s1);
		int i,j;
		double ele ;

		for(i = 0; i<s1->row_sz; ++i)                      //to create sparse matrix
		{	
			for(j = 0; j<s1->col_sz; j++)
			{
				fscanf(file1,"%lf",&ele);         //reading elements present in matrix file one by one 
          			if(ele != 0)
               				insert_node(i,j,ele,s1);       	//adds a node to the sparse matrix list
			}
		}
	}

	else if(choice == 2)
	{
		printf("\nenter the file name : ");
		scanf("%s",fname);
                file1 = fopen(fname,"r");                                       //opens the file present in read only mode
                if(file1==NULL)                                         //gives message if that file is not present
                {
                        printf("file not found\n\n");
                        exit(1);
                }
                printf("enter the row size and column size of the matrix : \n");
                printf("row size : ");
                scanf("%d",&s1->row_sz);
                printf("\ncol size : ");
		               scanf("%d",&s1->col_sz);
                printf("\n");
                init_sparse(s1);
                int i,j ;
		double ele ;

		fscanf(file1 , "%d%d%lf" , &i , &j , &ele) ;
		while(!feof(file1))
		{
			insert_node(i,j,ele,s1) ;

			fscanf(file1 , "%d%d%lf" , &i , &j , &ele) ;

		 

		}


	}


}


/*......................................................................................................................................................*/
void mul(sparse *s1,sparse *s2,sparse *s3)
{
	if(s1->col_sz != s2->row_sz)
	{
		printf("matrices cannot be multiplied\n");
	}
	else
	{
		s3->row_sz = s1->row_sz;
		s3->col_sz = s2->col_sz;
		node *pres1;
		node *pres2;
		int i,j ;
		double key ;
		for(i=0 ; i<s3->row_sz ; ++i)
		{
		//	pres1 = s1->row[i];
			for(j=0 ; j<s3->col_sz ; ++j)
			{	
				key = 0;
				pres1 = s1->row[i] ;
				pres2 = s2->col[j];
				if(s1->row[i] == NULL | s2->col[j] == NULL)
				{
					key = 0.0;
				}
				
				else
				{
					while(pres1)
					{	
						pres2 = s2->col[j];
						while(pres2)
						{
							if(pres1->col == pres2->row)
							{
								key = key + (pres1->key)*(pres2->key);
								break ;
								
							}
							pres2 = pres2->clink;
						}
						pres1 = pres1->rlink;
					}
					insert_node(i,j,key,s3);
				}
			}
		}

	}
}
