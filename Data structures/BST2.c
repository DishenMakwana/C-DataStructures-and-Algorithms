#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

}*root=NULL;

struct node* createnode(struct node* root,int data)
{
     root =(struct node*) malloc (sizeof(struct node));
     root->data = data;
     root->left = NULL;
     root->right = NULL;

     return root;
};
struct node* insert(struct node* root,int data)
{
    if(root==NULL)
        return createnode(root,data);

    else if(data < root->data)
        root->left = insert(root->left,data);

    else if(data > root->data)
        root->right = insert(root->right,data);

    return root;
}

struct node* minvalue(struct node* node)
{
    if(root->left == NULL)
    {
        return minvalue(root->left);
    }
    return root;
}

struct node* delete(struct node*root,int data)
{
    if(root==NULL)
        return root;

    else if(data < root->data)
        root->left = delete(root->left,data);

    else if(data > root->data)
        root->right = delete(root->right,data);

    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        if(root->left == NULL)
        {
            struct node*temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node*temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node* temp = minvalue(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%3d ->",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%3d ->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%3d ->",root->data);
    }
}

void main()
{
    int r,n,i,ch,e,b,x;
    root=NULL;

    printf("Enter root of tree: ");
    scanf("%d",&r);
    root=insert(root,r);

    printf("Enter no of element: ");
    scanf("%d",&n);

    printf("Enter tree elements: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&e);
        insert(root,e);
    }

     while(1)
    {
             printf("\n1]Insert \n2]Delete \n3]Preorder \n4]Inorder \n5]postorder \n6]Exit \nEnter your choice--> ");
             scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            {
                printf("Enter value to be inserted into Tree:");
                scanf("%d",&b);
                root=insert(root,b);
                break;
            }
        case 2:
            {
                printf("Enter deleted value into Tree :");
                scanf("%d",&x);
                delete(root,x);
                break;
            }
        case 3:
            {
                printf("Preorder :");
                preorder(root);
                break;
            }
        case 4:
            {
                printf("Inorder :");
                inorder(root);
                break;
            }
        case 5:
            {
                printf("Postorder :");
                postorder(root);
                break;
            }
        case 6:
            {
                exit(0);
                break;
            }
        }

    }
    getch();
}
