/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <int> adj[],int v,int u )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printBFSfunction(vector <int> adj[],int v)
{
    bool a[v];int i,s;
    for(i=0;i<v;i++)
    {
        a[i]=false;
    }
    s=0;
    a[0]=true;
    queue <int> q;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        cout<<s<<" ";
        for(int x:adj[s])
        {
            if(a[x]==false)
            {
                q.push(x);
                a[x]=true;
            }
        }
    }
}
bool DFS[100];
void printDFSfunction(vector <int> adj[],int v)
{
    cout<<v<<" ";
    DFS[v]=true;
    for(int x:adj[v])
    {
        if(DFS[x]==false)
        {
             printDFSfunction(adj,x);
        }
    }
}



int main()
{
    //printf("Hello World");
    int v=6;
    int i;
    for(i=0;i<v;i++)
    {
        DFS[i]=false;
    }
    vector <int> adj[6];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,3,2);
    addEdge(adj,3,5);
    addEdge(adj,5,4);
    cout<<"BFS : "<<endl;
    printBFSfunction(adj,v);
    cout<<endl<<"DFS : "<<endl;
    printDFSfunction(adj,2);
    
    return 0;
}
