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

void preBT(tree* &root)
{
    if(root == nullptr)
        return ;
    cout<<root->value<<" ";
    preBT(root -> left);
    preBT(root -> right);
}

void inBT(tree* &root)
{
    if(root == nullptr)
        return ;
    inBT(root -> left);
    cout<<root->value<<" ";
    inBT(root -> right);
}

void postBT(tree* &root)
{
    if(root == nullptr)
        return ;
    postBT(root -> left);
    postBT(root -> right);
    cout<<root -> value<<" ";
}

int maxDepth(tree* &root)
{
    if(root == nullptr)
        return 0 ;
    int lh = maxDepth(root -> left);
    int rh = maxDepth(root -> right);
    return 1+max(lh, rh);
}

int calculateSumPath(tree* &root, int& maxi)
{
    if(root == nullptr)
        return 0 ;
    int leftSum = calculateSumPath(root -> left, maxi);
    int rightSum = calculateSumPath(root -> right, maxi);
    int currentSum = root -> value + max(0, max(leftSum, rightSum));
    maxi = max(maxi, max(currentSum, root -> value + leftSum + rightSum));
    return currentSum ;
}


int maxPathSum(tree* &root)
{
    int maxi = INT_MIN ;
    calculateSumPath(root, maxi);
    return maxi ;
}


int main()
{
    tree* root = new tree(20);
    root -> left = new tree(40);
    root -> right = new tree(60);
    root -> left -> right = new tree(80);
    root -> right -> right = new tree(100);
    cout<<"The pre-order traversal of the Binary tree is : "<<endl ;
    preBT(root);
    cout<<endl ;
    
    cout<<"The inorder traversal of the Binary tree is : "<<endl ;
    inBT(root);
    cout<<endl ;
    
    cout<<"The postorder traversal of the Binary tree is : "<<endl ;
    postBT(root);
    cout<<endl ;
    
    cout<<"The height of the Binary tree is : "<<maxDepth(root)<<endl ;
    
    cout<<"The maximum path sum of the binary tree is : "<<maxPathSum(root);
    return 0 ;
}
