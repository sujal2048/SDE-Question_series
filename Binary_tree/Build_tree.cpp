#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
    
};

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}
Node* buildtree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }

    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);
    if(start==end){
        return node;
    }
    int pos=search(inorder,start,end,curr);
    node->left=buildtree(preorder,inorder,start,pos-1);
    node->right=buildtree(preorder,inorder,pos+1,end);

    return node;
}
void inorderprint(Node* root){
    if(root==NULL){
        return ;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
void postorderprint(Node* root){
    if(root==NULL){
        return ;
    }
    inorderprint(root->left);
    inorderprint(root->right);
    cout<<root->data<<" ";
}
void printlevelorder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node =q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left)
             q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())
         q.push(NULL);
    }
}
int calcheight(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(calcheight(root->left),calcheight(root->right))+1;

}
int calcdiameter(Node* root){     //time=o(n*n)
    if(root==NULL){
        return 0;
    }
    int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);
    int currdiameter=lheight+rheight+1;

    int ldiameter=calcdiameter(root->left);
    int rdiameter=calcdiameter(root->right);

    return max(currdiameter,max(ldiameter,rdiameter));

}
int caldiameter(Node* root,int* height){   //time=o(n)
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ldiameter = caldiameter(root->left,&lh);
    int rdiameter = caldiameter(root->right,&rh);
    
    int currdiameter=lh+rh+1;
    *height = max(lh,rh)+1;

    return max(currdiameter,max(ldiameter,rdiameter));
}
int sumnode(Node* root){
    if(root==NULL){
        return 0;
    }
    root->data+=sumnode(root->left)+sumnode(root->right);
    return root->data;
}
bool isbalanced(Node* root,int* height){
    if(root==NULL){
        *height=0;
        return true;
    }
    int h=0;
    int z=0;
    if(isbalanced(root->left,&h) && isbalanced(root->right,&z)){
        *height=max(h,z)+1;
        if(abs(h-z)<=1){
            return true;
        }
    }
    return false;
}
int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    //build tree;
    Node* root= buildtree(preorder,inorder,0,4);
    //    1
    //   / \
    //  2   3
    // /   /
    //4   5

    //tree checking
    inorderprint(root);cout<<endl;;
    postorderprint(root);
    cout<<endl;

    //level wise tree printing
   // printlevelorder(root);
    cout<<endl;

    //diameter of tree  time=o(n*n)
  //  cout<<calcdiameter(root)<<endl;
    
    //diameter of tree  time=o(n)
    int height=0;
    //cout<<caldiameter(root,&height)<<"\n";

    //making sum node
    cout<<sumnode(root)<<endl;
    inorderprint(root);
    cout<<endl;

    Node* root2=new Node(5);
    root2->left=new Node(6);
    root2->left->left=new Node(7);
    //balanced binary tree
    int heig=0;
    cout<< isbalanced(root,&heig)<<endl;

    return 0;
}
//ece302.nitdgp@gmail.com