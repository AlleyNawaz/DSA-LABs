#include <iostream>
using namespace std;

const int MAX = 100;

int adj[MAX][MAX];
bool visited[MAX];

int q[MAX];
int front = -1, rear = -1;

void enqueue(int x){
    if(rear == MAX-1){
        cout << "Queue Overflow\n";
        return;
    }
    if(front == -1) front = 0;
    q[++rear] = x;
}

int dequeue(){
    if(front == -1 || front > rear){
        return -1;
    }
    return q[front++];
}

bool isEmpty(){
    return (front == -1 || front > rear);
}

void insertEdge(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void deleteEdge(int u, int v){
    adj[u][v] = 0;
    adj[v][u] = 0;
}

void displayMatrix(int V){
    cout << "\nAdjacency Matrix:\n";
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(int start, int V){

    for(int i=0; i<V; i++)
        visited[i] = false;

    // reset queue
    front = rear = -1;

    visited[start] = true;
    enqueue(start);

    cout << "\nBFS Traversal: ";

    while(!isEmpty()){
        int curr = dequeue();

        cout << curr << " ";

        for(int i=0; i<V; i++){
            if(adj[curr][i] == 1 && !visited[i]){
                visited[i] = true;
                enqueue(i);
            }
        }
    }
}

int main(){
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    // initialize matrix
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            adj[i][j] = 0;

    int choice, u, v;

    do{
        cout << "\n1. Insert Edge";
        cout << "\n2. Delete Edge";
        cout << "\n3. Display Matrix";
        cout << "\n4. BFS Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice){

        case 1:
            cout << "Enter edge (u v): ";
            cin >> u >> v;
            insertEdge(u,v);
            break;

        case 2:
            cout << "Enter edge to delete (u v): ";
            cin >> u >> v;
            deleteEdge(u,v);
            break;

        case 3:
            displayMatrix(V);
            break;

        case 4:
            cout << "Enter starting node: ";
            cin >> u;
            BFS(u,V);
            cout << endl;
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    }while(choice != 5);

    return 0;
}