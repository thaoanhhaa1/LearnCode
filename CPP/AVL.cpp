#include <iostream>

using namespace std;

struct node{
    int data;
    node *pre;
    node *next;
};
typedef node *List;

void AddNode(List &l, int x){
    if (l == NULL){
        node *temp = new node();
        temp->data = x;
        temp->pre = NULL;
        temp->next = NULL;
        l = temp;
    }
    else
        if (x < l->data)
            AddNode(l->pre,x);
        else
            AddNode(l->next,x);
}

int LevelTree(List l){
    if (l == NULL)
        return -1;
    return 1 + max(LevelTree(l->pre),LevelTree(l->next));
}

void XoayPhai(List &l){
    node *temp = l;
    l = l->pre;
    temp->pre = l->next;
    l->next = temp;
}

void XoayTrai(List &l){
    node *temp = l;
    l = l->next;
    temp->next = l->pre;
    l->pre = temp;
}

void PrintNode(List l){
    if (l != NULL){
        PrintNode(l->pre);
        cout<<l->data<<" ";
        PrintNode(l->next);
    }
}

bool CheckAVL(List l){
    if (l == NULL)
        return true;
    if (abs(LevelTree(l->pre)-LevelTree(l->next)) > 1)
        return false;
    return CheckAVL(l->pre) && CheckAVL(l->next);
}

void UpdateAVL(List &l){
    if (!CheckAVL(l)){
        if (LevelTree(l->pre) > LevelTree(l->next))
            XoayPhai(l);
        else
            XoayTrai(l);
    }
    if (l->pre != NULL) UpdateAVL(l->pre);
    if (l->next != NULL) UpdateAVL(l->next);
}

int CountX(List l, int x){
    if (l == NULL) return 0;
    if (l->data == x)
        return 1 + CountX(l->pre,x) + CountX(l->next,x);
    else if (l->data > x)
        return CountX(l->pre,x);
    return CountX(l->next,x);
}

int main(){
    List l = NULL;
    int n, temp;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>temp;
        AddNode(l,temp);
    }
    while (!CheckAVL(l))
        UpdateAVL(l);
    int x;
    cin>>x;
    cout<<CountX(l,x);
}