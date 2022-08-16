#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }

};
node *inter(node * root)
{

    int data;
    cout<<"Enter your data"<<endl;
    cin>>data;
    root=new node(data);
    if( data ==-1)
    {

        return NULL ;
    }

        cout<<"Enter the element to put in left"<<data;
        root->left=inter(root->left);
        cout<<"Enter the element to put in right"<<data;
        root->right=inter(root->right);
        return root;



}
void level(node *&root)
{

    queue<node*>q;
    int data;
    cout<<"Enter the root data"<<endl;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        cout<<"Enter the element in left "<<temp->data<<endl;
        int ldata;
        cin>>ldata;
        if(ldata != -1)
        {
            temp->left=new node(ldata);
            q.push(temp->left);
        }
        cout<<"Enter the element in right"<<temp->data<<endl;
        int rdata;
        cin>>rdata;
        if(rdata !=-1)
        {

            temp->right=new node(rdata);
            q.push(temp->right);
        }
    }

}
void levelorder(node * root)
{

    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {

            cout<<endl;
            if(!q.empty())
            {

                q.push(NULL);
            }
        }
        else
            {
              cout<<temp->data<<endl;
              if(temp->left)
                   q.push(temp->left);
              if(temp->right)
                  q.push(temp->right);
            }
    }
}
int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

void preorder(node *root)
{

    if(root==NULL)
    {

        return ;
    }
    preorder(root->left);
    cout<<root->data<<"   ";
    preorder(root->right);
}
int main()
{
       node *root=NULL;
       level(root);
       preorder(root);



}
