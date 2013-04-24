#ifndef MATRIX_H
#define MATRIX_H
struct Node
{
	int row,col;
	double key ;
	struct Node *rlink;
	struct Node *clink;
};
typedef struct Node node;

struct Sparse
{
	node *row[500];
	node *col[500];
	int row_sz;
	int col_sz;
		
};
typedef struct Sparse sparse;

void insert_node(int ,int ,double ,sparse *);
void init_sparse(sparse *);
void display(sparse*);
void create_mat(sparse *);
void add(sparse *,sparse *,sparse *);
void mul(sparse *,sparse *,sparse *);
#endif
