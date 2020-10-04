#include <iostream>
using namespace std;
struct coords
{
    int r;
    int c;
    int dir;
};
 
struct Node
{
    coords data;
    Node *next;
};
 
void push(Node *top, int r, int c, int dir)
{
    Node *p = new Node;
    p->next=top->next;
    top->next=p;
    p->data.r = r;
    p->data.c = c;
    p->data.dir = dir;
};
 
void pop(Node *top)
{
    Node *p=top->next;
    top->next=p->next;
    free(p);
};
 
int main()
{
    int m, n;
    cin >> m >> n;
    int maze[m][n];
    int x, y;
    coords start, end;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    cin >> start.r >> start.c >> end.r >> end.c;
    start.dir = 0;
    Node *top=new Node;
    
    push(top, start.r, start.c, start.dir);
    coords move[4];
    move[0].r = 1, move[0].c = 0;
    move[1].r = 0, move[1].c = 1;
    move[2].r = -1, move[2].c = 0;
    move[3].r = 0, move[3].c = -1;
    while (top->next!=NULL)
    {
        coords a = top->next->data;
        while (a.dir < 4)
        {
            x = a.r + move[a.dir].r;
            y = a.c + move[a.dir].c;
            //int d = a.dir;
            //pop(stack);
            if (maze[x][y] == 0)
            {   
                //push(stack,a.r,a.c,d);
                push(top, x, y, 0);
                //cout<<x<<y<<endl;
                maze[x][y] = -1;
                if (x == end.r && y == end.c)
                {
                    cout << "Yes";
                    return 0;
                }
                break;
            }
            else
            {
                a.dir++;
            }
        }
        if (a.dir >= 4)
        {
            pop(top);
            /*if(top->next!=NULL)
            {
                cout<<"No";
                return 0;
            }*/
        }
    }
    cout << "No";
    return 0;
}