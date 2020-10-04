#include <iostream>
using namespace std;
struct coords
{
    int r;
    int c;
    int dir;
};

struct SeqStack
{
    coords base[200000];
    int top;
};

void push(SeqStack *stack, int r, int c, int dir)
{
    stack->top++;
    stack->base[stack->top - 1].r = r;
    stack->base[stack->top - 1].c = c;
    stack->base[stack->top - 1].dir = dir;
};

void pop(SeqStack *stack)
{
    if (stack->top <= 0)
        cout << "pop error";
    else
        stack->top--;
};

int main()
{
    int m, n;
    cin >> m >> n;
    int maze[m+2][n+2];
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
    SeqStack *stack = new SeqStack;
    stack->top = 0;
    push(stack, start.r, start.c, start.dir);
    coords move[4];
    move[0].r = 1, move[0].c = 0;
    move[1].r = 0, move[1].c = 1;
    move[2].r = -1, move[2].c = 0;
    move[3].r = 0, move[3].c = -1;
    while (stack->top != 0)
    {
        coords a = stack->base[stack->top - 1];
        while (a.dir < 4)
        {
            x = a.r + move[a.dir].r;
            y = a.c + move[a.dir].c;
            //int d = a.dir;
            //pop(stack);
            if (maze[x][y] == 0)
            {   
                //push(stack,a.r,a.c,d);
                push(stack, x, y, 0);
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
            pop(stack);
            if(stack->top==0)
            {
                cout<<"No";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}