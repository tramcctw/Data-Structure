#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
	int hight;
}Tree;

Tree tree;

int kmax(int x,int y){
	if(x >= y){
		return x;
	}else{
		return y;
	}
}

int gethight(Tree *head){
	if(!head){
		return 0;
	}else{
		return head->hight;
	}
}


void Creat(Tree ** head){
	int k;
    //printf("请输入数据:");
    scanf("%d",&k);
    if(k == -1){
    	*head = NULL;        
    }else{
        (*head) = (Tree *)malloc(sizeof(tree));
        (*head)->hight = 1;
        if(!(*head))
        	exit(1);
         (*head)->data = k;
         Creat(&((*head)->left));
         Creat(&((*head)->right));
	}
}


Tree * singLeftRotation(Tree * A){
     Tree * B;
     B = A->left;
     A->left = B->right;
     B->right = A; 
     A->hight = kmax(gethight(A->left),gethight(A->right))+1;
     B->hight = kmax(gethight(B->left),gethight(B->right))+1;
     return B;
}
   
   
Tree * singRightRotation(Tree * A){
     Tree * B;
     B = A->right;
     A->right = B->left;
     B->left = A; 
     A->hight = kmax(gethight(A->left),gethight(A->right))+1;
     B->hight = kmax(gethight(B->left),gethight(B->right))+1;
     return B;
}
   
  
  
  
  
   Tree * DoubleLetfRightRotation(Tree * A){
        A->left = singRightRotation(A->left); 
      return  singLeftRotation(A);      
   
   }
   
    
   Tree * DoubleRightLeftRotation(Tree * A){
        A->right = singLeftRotation(A->right);   
        return  singRightRotation(A);
   
   }

Tree * Avl_insert(int x,Tree*head){
	if(!head){
		head = (Tree*)malloc(sizeof(tree));
		head->data = x;
		head->hight = 0;
		head->left = NULL;
		head->right = NULL;
	}else if(x < head->data){
		  	head->left = Avl_insert(x,head->left);
		  	if(gethight(head->left)-gethight(head->right) == 2){
               if(x < head->left->data){    
                 head = singLeftRotation(head); 
               }else{
                 head = DoubleLetfRightRotation(head);                 
               } 
            }
	}else
		 if(x > head->data){
             head->right = Avl_insert(x,head->right);             
           if(gethight(head->left)-gethight(head->right) == -2){
               if(x > head->right->data){
               		head = singRightRotation(head);
               }else{               
                  	head = DoubleRightLeftRotation(head);                
               }                      
            }
        }  
      
   head->hight = kmax(gethight(head->left),gethight(head->right))+1;       
   return head;  
}

void ergodic(Tree * head){
         
    if(head){
	    printf("%d ",head->data);      
	    ergodic(head->left);     
	    ergodic(head->right);     
    }
}
   
   
 
void main()
{
  int k;    
  Tree * head;                                                                                                                                                                                                        
  Creat(&head);
  printf("请输入需要插入的元素:");
  scanf("%d",&k);
  head = Avl_insert(k,head);
  printf("已插入!");
  printf("\n");
  //printf("%d\n",head->data);
  ergodic(head);
 
}//AvL树的创建与插入。