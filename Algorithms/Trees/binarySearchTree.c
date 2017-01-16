/*Binary Search Trees 
 Function implemented:-
 * Insert
 * Delete
 * Find
 * Find Minimum and Find Maximum
 * Delete
 * PreOrderTraversal
 * InOrderTraversal
 * PostOrderTraversal
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

// Insert nodes in the Binary Search Tree.
treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
        /* Else the data is alreay present in the Tree. */
    
        return node;

}

// Function to find an element in a Binary Search Tree.
treeNode * Find(treeNode *node, int data)
{
	if (node==NULL) // Root Node is empty.
	return NULL;
	
	else if (data > node->data ) // Search in the right sub tree.
	return Find(node->right,data);
	
	else if (data < node->data) // Search in the left sub tree.
	return Find(node->left,data);
	
	else  // Data found.
	return node;
}

// Function to find the minimum value in a Binary Search Tree.
treeNode*findMin(treeNode*node)
      {
		  if (node==NULL)
		  return NULL;
		  
		  if(node->left)
		  return findMin(node->left);
		  else
		  return node;
	  }

// Function to find maximum value in a Binary Search Tree.
treeNode*findMax(treeNode*node)
{
	if (node==NULL)
	return NULL;
	
	if(node->right)
	return findMax(node->right);
	else
	return node;
}

// Function to delete a node from the Binary Search Tree.
treeNode*deleteNode(treeNode*node,int data)
{
	treeNode * temp;
	
	if (node==NULL)
	{ 
		printf("Element not in the Tree !!!");
		return NULL ;
	}
	
	else if (data < node->data)
	deleteNode(node->left,data);
	
	else if (data > node->data)
	deleteNode(node->right,data);
	
	else
	{              
		/*If the node to be deleted has a left node and right node then
		 select the minimum node from the right node and replace the node
		 to be deleted  with it.*/            
		if (node->right && node->left)
		{
			
			temp=findMin(node->right);
			node->data=temp->data;
			node->right=deleteNode(node->right,temp->data);
			
		}
		
		/* If the node to be deleted has no child node or just one child node,
		 irrespective of left child node or right child node, then we can remove 
		 it from the Tree and connect the parent node to child node.*/
		 
		else
		{
			temp = node;
			 
			if (node->right==NULL)
			node=node->left;
			
			else if(node->left==NULL)
			node=node->right;
			
			free (temp);
		}
	}
	
	return node;
}

/* PreOrder Traversal: In the preorder traversal, first the root
node is visited followed by the left subtree and then the right sub tree. */
void preOrderTraversal(treeNode* node)
{
		if (node==NULL)
			{
				return;
			}
		printf("%d ",node->data);
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
		
}

/* InOrder Traversal: In the preorder traversal, first the left subtree
  node is visited followed by the root and then the right sub tree. */
void inOrderTraversal(treeNode*node)
{
	if (node==NULL)
	{
		return;
		}
		
		inOrderTraversal(node->left);
		printf("%d ",node->data);
		inOrderTraversal(node->right);
	}

/* PostOrder Traversal: In the preorder traversal, first the left subtree
node is visited followed by the right sub tree and then the root. */
void postOrderTraversal(treeNode*node)
{
	if (node==NULL)
	{
		return;
		}
		
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		printf("%d ",node->data);	
	}
	
int main()
{
        treeNode *root=NULL;
        treeNode *findData;
        treeNode *foundMax,*foundMin;
        // Inserting elements and building the Binary Search Tree
        root = Insert(root, 5);     
        root = Insert(root, -1);
        root = Insert(root, 3);
        root = Insert(root, -14);
        root = Insert(root, 8);
        root = Insert(root, 10);
        root = Insert(root, 9);
        root = Insert(root, 6);

        /* Finding a particular element in the Tree
         when element is present in the Tree */  
        findData = Find(root,6);
        if (findData!=NULL)
        printf("Element 6 found");
        else
        printf("Element not found");
        
        printf("\n");
        
        /* Finding a particular element in the Tree
         when element is not present in the Tree.*/         
        findData = Find(root,2);
        if (findData!=NULL)
        printf("Element 2 found");
        else
        printf("Element 2 not found");
        
        printf("\n");
        
        // Finding the maximum element in the Tree.
        foundMax = findMax(root);
        printf("Maxium Element in the tree %d\n",foundMax->data);
         
        // Finding the minimum element in the Tree.
        foundMin = findMin(root);
        printf("Minimum Element in the tree %d\n",foundMin->data);
        
        // Delete a node in the Tree.
        root=deleteNode(root,10);
        
		// PreOrder Traversal in the BST.
		printf("PreOrder Traversal: ");
		preOrderTraversal(root);
		
		// InOrder Traversal in the BST.
		printf("\nInOrder Traversal: ");
		inOrderTraversal(root);
		
		// PostOrder Traversal in the BST
		printf("\nPostOrder Traversal: ");
		postOrderTraversal(root);
		

 
       return 0;                
}
