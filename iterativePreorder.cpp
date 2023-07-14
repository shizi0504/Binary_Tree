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

vector<int> preorderTraversal(tree* &root)
{
    vector<int> preorder ;
    if(root == nullptr)
        return preorder ;
    stack<tree*> st ;
    st.push(root);
    while(!st.empty())
    {
        tree* curr = st.top();
        st.pop();
        preorder.push_back(curr -> value);
        if(curr -> right != nullptr)
            st.push(curr -> right);
        if(curr -> left != nullptr)
            st.push(curr -> left);
    }
    return preorder ;
}

vector<vector<int>> levelOrder(tree* &root)
{
    vector<vector<int>> ans ;
    if(root == nullptr)
        return ans ;
    queue<tree* > q1 ;
    q1.push(root);
    while(!q1.empty())
    {
        int size = q1.size();
        vector<int> level ;
        for(int i=0;i<size;i++)
        {
            tree* node = q1.front();
            q1.pop();
            if(node -> left != nullptr)
                q1.push(node -> left);
            if(node -> right != nullptr)
                q1.push(node -> right);
            level.push_back(node -> value);
        }
        ans.push_back(level);
    }
    return ans ;
}

int main()
{
    tree* root = new tree(10);
    root -> left = new tree(20);
    root -> right = new tree(30);
    root -> left -> left = new tree(40);
    root -> right -> right = new tree(50);
    vector<int> ans = preorderTraversal(root);
    cout<<"The iterative preorder traversal is : "<<endl ;
    for(auto it : ans)
    {
        cout<<it<<" " ;
    }
    cout<<endl ;
    vector<vector<int>> LO_ans = levelOrder(root);
    cout<<"The level order traversal of the binary tree is: "<<endl ;
    for(auto it : LO_ans)
    {
        for(auto val : it)
        {
            cout<<val<<" ";
        }
        cout<<endl ;
    }
    return 0 ;
}
