#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<queue> 
using namespace std;
const int maxn=1010;
typedef struct Node{
	char val;
	struct Node* left;
	struct Node* right;
}TreeNode;
TreeNode *create(){
	queue<TreeNode*>q;
	char ch;
	cin>>ch;
	if(ch=='#')return NULL;
	TreeNode *root=new TreeNode();
	TreeNode *T=root;
	root->val=ch;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		cin>>ch;
		if(ch=='#')
			root->left=NULL;
		else{
			root->left=new TreeNode();
			root->left->val=ch;
			q.push(root->left);
		}
		cin>>ch;
		if(ch=='#')
			root->right=NULL;
		else{
			root->right=new TreeNode();
			root->right->val=ch;
			q.push(root->right); 
		}
	}
	return T;
}
void LevelOrder(TreeNode *root){
	
	queue<TreeNode *>q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		cout<<root->val<<" ";
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	} 
}
void Delete(TreeNode *&T){
	if(T){
		Delete(T->left);
		Delete(T->right);
		free(T);
	}
} 
TreeNode *Delete1(TreeNode *&root){
	if(root==NULL)return NULL;
//	if(root->left==NULL&&root->right==NULL)return NULL;
	Delete1(root->left);	
	Delete1(root->right);
	
	free(root);

}
int main()
{	
	TreeNode* T,*T1;
	T=create();
	LevelOrder(T);
	cout<<endl;

	Delete1(T->left->left);
	LevelOrder(T);

	
	
	return 0;
 } 
 /*≤‚ ‘
12345######
 */ 
