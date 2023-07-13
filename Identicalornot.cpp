#include <bits/stdc++.h>
using namespace std ;
class tree
{
    public :
        int value ;
        tree* left = nullptr ;
        tree* right = nullptr ;
        
    tree(int x)
    {
        value = x ;
        left = nullptr ;
        right = nullptr ;
    }
};

bool isIdentical(tree* &p, tree* &q)
{
    if(p == nullptr || q == nullptr)
        return (p == q);
    return ((p -> value == q -> value) && isIdentical(p -> left , q -> left) && isIdentical(p -> right, q -> right));
}

int main()
{
    tree* root1 = new tree(10);
    root1 -> left = new tree(20);
    root1 -> right = new tree(30);
    root1 -> right -> left = new tree(40);
    root1 -> right -> right = new tree(50);
    
    tree* root2 = new tree(10);
    root2 -> left = new tree(20);
    root2 -> right = new tree(30);
    root2 -> right -> left = new tree(40);
    root2 -> right -> right = new tree(50);
    cout<<endl ;
    if(isIdentical(root1, root2))
    {
        cout<<"Identical binary trees." ;
    }
    else
        cout<<"Non-identical binary trees.";
    return 0 ;
}
