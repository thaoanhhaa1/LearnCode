#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    string st;
    int count;
    Node *Next;
    Node *Prev;
};
typedef Node *List;

Node* CreatNode(string s)
{
    Node * a = new Node();
    a->st = s;
    a->count = 1;
    a->Prev = NULL;
    a->Next = NULL;
    return a;
}

void AddNode(List &l, Node *p)
{
    if (l == NULL)
        l = p;
    else if (l->st.compare(p->st) == 0)
        l->count++;
    else if (l->st.compare(p->st) > 0)
        AddNode(l->Prev, p);
    else
        AddNode(l->Next, p);
}

void ReadFile(List &l)
{
    ifstream f("D:/Code/IOFile/Caynhiphan.txt");
    while (!f.eof())
    {
        string s;
        f>>s;
        Node *p = CreatNode(s);
        AddNode(l,p);
    }
}

void ShowNode(List l)
{
    if (l != NULL)
    {
        ShowNode(l->Prev);
        cout<<l->st<<" : "<<l->count<<endl;
        ShowNode(l->Next);
    }
}

int main()
{
    List l = NULL;
    ReadFile(l);
    ShowNode(l);
}