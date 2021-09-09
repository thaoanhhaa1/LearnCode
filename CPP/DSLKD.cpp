#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};
typedef Node* List;

void AddList(List &l, int a){
    Node *tam = new Node();
    tam->data = a;
    tam->next = NULL;
    if (l == NULL)
        l = tam;
    else{
        Node *p = l;
        while (p->next != NULL)
            p = p->next;
        p->next = tam;
    }
}

int SumMax(List l){
    if (l == NULL)
        return 0;
    int dem = 0, Max = 0;
    Node *p = l;
    while (true){
        if (Max == p->data)
            dem++;
        else if (Max < p->data){
            Max = p->data;
            dem = 1;
        }
        if (p->next == NULL)
            break;
        p = p->next;
    }
    return Max*dem;
}

int main(){
    List l = NULL;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        int a;
        cin>>a;
        AddList(l,a);
    }
    cout<<SumMax(l);
}