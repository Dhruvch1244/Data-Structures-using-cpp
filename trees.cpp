#include <iostream>
using namespace std;
struct tree{
    int val;
    tree* left;
    tree* right;
};
void push(tree** root,int data){
    tree* c = *root;
    if(c->val>= data && c->left != NULL){
        push(&c->left,data);
    }
    else if(c->val< data && c->right != NULL){
        push(&c->right,data);
    }
    else{
        tree* d = new tree();
        if(c->val>=data){
            c->left = d;
        }
        else{
            c->right = d;
        }
        d->val = data;
        d->left = NULL;
        d->right = NULL;
    }
}
int main(){
    tree* root = new tree();
    root->val = 5;
    root->left = NULL;
    root->right = NULL;
    tree* c = root;
    push(&c,6);
    push(&c,5);
    push(&c,1);
    push(&c,10);
    push(&c,-4);
    push(&c,30);
    push(&c,3);
    while(c!=NULL){
        cout<<"->"<<c->val;
        c = c->left;
    }
    cout<<"\n";
    c = root;
    while(c!=NULL){
        cout<<"->"<<c->val;
        c = c->right;
    }
    return 0;
}
