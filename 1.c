#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
	
};

//struct node *root = NULL;
int n =100;
 struct node  *que[100];
 int front = -1;
 int rear = -1;

 int findMaxOfNumber(int a,int b)
 {
 	if (a>b)
 	{
 		return a;
 	}
 	else
 		return b;
 }

	 
int findHeight(struct node *root)
{
	int leftHeight;
	int rightHeight;
	if (root == NULL)
	{
		return 0;
	}
	 leftHeight = findHeight(root->left);
	 rightHeight = findHeight(root->right);
	return (findMaxOfNumber(leftHeight,rightHeight)+1);


}

 struct node *findMin(struct node * root)
 {
 	while(root->left != NULL)
 		root = root->left;
 	return root;
 }

 void nq(struct node *item)
 {
 	if ( rear == n-1)
 	{
 		printf("dont fuck with my code\n");
 		return;
 	}
 	else if (front == -1 )
 	{
 		front = 0 ;
 		rear = 0;
 	}

 	
 	else{
 		rear +=1;
 	}
 	que[rear] = item;


 }


 void dq()
 {
 	if (front == -1)
 	{
 		printf("empty hai \n");
 		return;
 	}
 	//printf("dequed item is %d\n",que[front] );
 	if (front == rear)
 	{
 		front = -1;
 		rear = -1;
 		return;
 		
 		/* code */
 	}
 	front +=1;
 



 }

 struct node* peak()
 {
 	if (front == -1)
 	{
 		printf("queue is empty\n");
 		return;
 	}

 	return que[front];



 }
 void preorder(struct node *root)
{
	if (root == NULL)
	{
		return;

	}
	printf("%d\n",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node *root)
{
	if (root == NULL)
	{
		return;

	}
	
	inorder(root->left);
	printf("%d\n",root->data);
	inorder(root->right);
}
struct node *createNode(int item)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new -> data = item;
	new -> left = NULL;
	new -> right = NULL;
	return new;
}

struct node *insertNode(struct node *root,int item)
{
	if (root == NULL)
	{
		struct node *new = createNode(item);
		root = new;
		return new;

		
	}
	else if (item <= root->data)
	{
		root->left = insertNode(root->left,item);
	}
	else
	{
		root->right = insertNode(root->right,item);
	}
	return root;
}

bool search(struct node *root,int data)
{
	if (root == NULL)
	{
		return false;

	}
	else if (data == root->data )
	{
		return true;
	}
	else if (data <= root->data)
	{
		return search(root->left,data);
	}
	else
		return search(root->right,data);
}
struct node* delete(struct node *root,int data)
{
	if (root == NULL)
	{
		return;
	}
	else if (root->data < data)
	{
		delete(root->right,data);
	}
	else if (root->data > data)
	{
		delete(root->left,data);
	}

	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			root = root->right;
		}
		else if (root->right == NULL)
		{
			root = root->left;
		}
		else
		{
			struct node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = delete(root->right,temp->data);
		}
	}
	return root;
}
bool que_notEmpty()
{
	if (front == -1 && rear == -1)
	{
		return true;
	}

	return false;
}

void levelOrder(struct node *root)
{
	if(root == NULL) return;
	nq(root);

	while(!que_notEmpty())
	{
		struct node *current = peak();
		struct node *current_left = current->left;
		struct node *current_right = current->right;
		dq();

		if(current_left != NULL) 
			nq(current_left);
		if(current_right != NULL) nq(current_right);
		printf("%d\n",current->data);


	}



}
struct node *find_node(struct node *root,int data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		return root;
	}

	if (data > root->data )
	{
		return find_node(root->right,data);
	}
	if (data < root->data)
	{
		return find_node(root->left,data);
	}
}

struct node *getsuccessor(struct node *root,int data)
{
	struct node *current_node = find_node(root,data);
	if(current_node == NULL)
		 return NULL;

	else if(current_node->right!=NULL)
	{
		return findMin(current_node->right);
	}

	else
	{
		struct node *prev = root;
		struct node *successor = NULL;
		while(successor!=prev)
		{
			if(current_node->data < prev->data)
			{
				successor = prev;
				prev = prev->left;
			}
			else
				prev = prev ->right;
		}
	return successor;
	}
}



int  main()
{
	struct node *root = NULL;
	root = insertNode(root,10);
	root = insertNode(root,20);
	root = insertNode(root,3);
	root = insertNode(root,0);
	root = insertNode(root,14);
	root = insertNode(root,24);

	printf("enter value to be search\n");
	int i;
	scanf("%d",&i);
	if (search(root,i))
	{
		printf("found\n");

	}
	else
		printf("not found\n");
	//root = delete(root,10);

	

	//levelOrder(root);
	printf("inorder is\n");
	//inorder(root);
	int k = findHeight(root);
	printf("%d\n",k);
	printf("successor is\n");
	if (getsuccessor(root,20)!=NULL)
	{
		/* code */
		printf("%d\n",getsuccessor(root,20)->data );
	}
	

	return 0;



}