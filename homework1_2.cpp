#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

void Insert(int num, Node *h)
{
    while (h->next != NULL)
        h = h->next;
    Node *p = new Node;
    p->data = num;
    p->next = NULL;
    h->next = p;
}

Node* Search(int num, Node *h)//注意加*
{
    for(int i=0;i<num;i++)
        h = h->next;
    return h;
}

int main()
{
    //建立链表
    int length, m, n, t;
    cin >> length;
    Node *h = new Node;
    h->next = NULL;
    for (int i = 0; i < length; i++)
    {
        cin >> t;
        Insert(t, h);
    }
    
    //进行交换
    cin >> m >> n;
    Node *a,*b,*c,*d,*e;
    a=Search(m,h);
    b=Search(m+1,h);
    c=Search(length-n,h);
    d=Search(length-n+1,h);
    e=Search(length,h);
    e->next=b;
    c->next=h->next;
    h->next=d;
    //print
    Node *r = h->next;
    for (int j = 0; j < length; j++)
    {
        cout << r->data <<endl;
        r = r->next;
    }
    return 0;
}