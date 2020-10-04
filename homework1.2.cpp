#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

int main()
{
    int length, m, n, t;
    int i = 0;
    cin >> length;
    Node *h = new Node;
    Node *p = new Node;
    h->next = p;
    while (i < length)
    {
        cin >> t;
        Node *q = new Node;
        q->data = t;
        q->next = p->next;
        p = q;
        i++;
    }
    /*for (int i = 0; i < length; i++)
    {
        cin >> a[i];
    }
    */
    for (int j = 0; j < length; j++)
    {
        Node *r = h->next;
        cout << r->data << ' ';
        r = r->next;
    }

    //cin >> m >> n;
    cout<<p->data;
    return 0;
}