#include <iostream>
using namespace std;
struct Node
{
    int num;
    int data;
    Node *next;
};

void Insert(int i, int num, Node *h)
{
    while (h->next != NULL)
    {
        h = h->next;
    }
    Node *p = new Node;
    p->next = h->next;
    h->next = p;
    p->data = i;
    p->num = num;
};

void Delete(Node *h)//删掉的是h的下一个
{
    Node *p = h->next;
    h->next = p->next;
    h = p->next;
    free(p);
};

int main()
{
    int m, n, temp, flag;
    int flag2=0;
    cin >> m >> n;
    Node *h = new Node;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        Insert(temp, i + 1, h);
    }
    Node *tail = h;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = h->next; //循环链表
    h = tail->next;
    h->num = 1;
    for (int j = 0; j < n; j++)
    {
        if(flag2!=0)
            flag = 0;
        else
        {
            flag = 1;
        }//???????????????????????
        
        while (flag < m-1)
        {
            h = h->next;
            flag++;
        }
        cout << h->next->num << endl;
        m = h->next->data;
        Delete(h);
        flag2++;//???????????????????
    }
    /*Delete(h->next);
    for (int j=0;j<15;j++)
    {
        cout<<h->num<<h->data<<endl;
        h=h->next;
    }*/
    return 0;
}