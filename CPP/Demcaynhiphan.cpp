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

bool strcmp(string s1, string s2)
{
    int n = s1.size();
    if (n != s2.size())
        return false;
    for (int i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}

void Search(List &l, string s)
{
    Node *tam = new Node;
    tam->st = s;
    tam->count = 1;
    if (l == NULL)
    {
        tam->Next = NULL;
        tam->Prev = NULL;
        l = tam;
    }
    else
    {
        Node *taml = l, *tamr = l;
        while (!strcmp(taml->st,s) && taml->Prev != NULL && !strcmp(tamr->st,s) && tamr->Next != NULL)
        {
            taml = taml->Prev;
            tamr = tamr->Next;
        }
        if (taml->Prev != NULL)
        {
            if (strcmp(taml->st,s))
            {
                taml->count++;
                return;
            }
            while (taml->Prev != NULL && !strcmp(taml->st,s))
                taml = taml->Prev;
            if (strcmp(taml->st,s))
            {
                taml->count++;
                return;
            }
        }
        if (tamr->Next != NULL)
        {
            if (strcmp(tamr->st,s))
            {
                tamr->count++;
                return;
            }
            while (tamr->Next != NULL && !strcmp(tamr->st,s))
                tamr = tamr->Next;
            if (strcmp(tamr->st,s))
            {
                tamr->count++;
                return;
            }
        }
        if (taml->Prev == NULL)
        {
            tam->Next = taml;
            tam->Prev = NULL;
            taml->Prev = tam;
        }
        else if (tamr == NULL)
        {
            tam->Prev = tamr;
            tam->Next = NULL;
            tamr->Next = tam;
        }
    }
}

void ReadFile(List &l)
{
    ifstream f("D:/Code/IOFile/Caynhiphan.txt");
    while (!f.eof())
    {
        string s;
        f>>s;
        Search(l,s);
    }
}

void DuyetL(List l)
{
    if (l != NULL)
    {
        cout<<l->st<<" : "<<l->count<<endl;
        DuyetL(l->Next);
    }
}

void DuyetR(List l)
{
    if (l != NULL)
    {
        cout<<l->st<<" : "<<l->count<<endl;
        DuyetR(l->Prev);
    }
}

void Duyet(List l)
{
    if (l != NULL)
    {
        Duyet(l->Prev);
        cout<<l->st<<" : "<<l->count<<endl;
        Duyet(l->Next);
        //DuyetL(l->Next);
        //DuyetR(l->Prev);
    }
}

int main()
{
    List l = NULL;
    ReadFile(l);
    Duyet(l);
    cout<<"Hoan thanh!";
}
