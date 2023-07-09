#include <bits/stdc++.h>
using namespace std ;
class tree
{
    public : 
        int value ;
        tree* left ;
        tree* right ;
        
        tree(int x)
        {
            value = x ;
            left = nullptr ;
            right = nullptr ;
        }
};

/*
void printBT(tree* root)
{
    if(root == nullptr)
    {
        return ;
    }
        cout<<root -> value<<" ";
        printBT(root -> left);
        printBT(root -> right);
    
}
*/

void printPreorderBT(tree* root)
{
    if(root == nullptr)
    {
        return ;
    }
    cout<<root -> value<<" ";
    printPreorderBT(root -> left);
    printPreorderBT(root -> right);
}

void printPostBT(tree* root)
{
    if(root == nullptr)
    {
        return ;
    }
    printPostBT(root -> left);
    printPostBT(root -> right);
    cout<<root -> value<<" ";
}

void printInorderBT(tree* root)
{
    if(root == nullptr)
    {
        return ;
    }
    printInorderBT(root -> left);
    cout<<root -> value<<" " ;
    printInorderBT(root -> right);
}

int main()
{
    tree* root = new tree(10);
    root -> left = new tree(20);
    root -> right = new tree(30);
    root -> left -> right = new tree(40);
    root -> left -> left = new tree(50);
    root -> right -> left = new tree(60);
    root -> right -> right = new tree(70);
    
    //printBT(root);
    cout<<"The Binary tree in pre-order is : "<<endl ;
    printPreorderBT(root);
    cout<<endl ;
    
    //print Postorder traversal BT
    cout<<"The binary tree in post-order is: "<<endl ;
    printPostBT(root);
    cout<<endl ;
    
    //print Inorder traversal BT
    cout<<"The binary tree in inorder traversal is: "<<endl ;
    printInorderBT(root);
    cout<<endl ;
    return 0 ;
}
