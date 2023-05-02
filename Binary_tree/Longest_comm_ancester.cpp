#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int MOD =1000000007;

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
int search(vector<ll> inorder,ll start,ll end,ll curr){
    for(int i=start;i<=end;i++){
        if(curr==inorder[i]){
            return i;
            break;
        }
    }
    return -1;
}
Node* buildtree(vector<ll> preorder,vector<ll> inorder,ll start,ll end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    Node* node=new Node(curr);
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
int least_comm_ances(Node* root,ll x,ll y){
    if(root==NULL){
        return -1;
    }
    if(x==root->data || y== root->data){
        return root->data;
    }
    int lft=least_comm_ances(root->left,x,y);
    int rght=least_comm_ances(root->right,x,y);
    if(lft==-1 && rght==-1){
        return -1;
    }
    if(lft!=-1 && rght!=-1){
        return root->data;
    }
    if(lft==-1){
        return rght;
    }
    else{
        return lft;
    }
}
int main(){
    vector<ll> preorder={1,2,4,5,6,7,3};
    vector<ll> inorder={5,4,7,6,2,1,3};
    Node* root=buildtree(preorder,inorder,0,6);
    inorderprint(root);
    cout<<endl;
    cout<<least_comm_ances(root,7,8);
    return 0;
}