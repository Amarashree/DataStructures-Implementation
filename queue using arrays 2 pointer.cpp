#include<iostream>
// implemention queue using array and 2 poinetrs

class queueImp{

    int size; //fixed size of queue
    int front;
    int rear;
    int *Q;

    public:

    queueImp(){
        front = -1;
        rear = -1;
        size = 10;
        Q = new int[size];
    }
    queueImp(int s){
        front = -1;
        rear = -1;
        size = s;
        Q = new int[size];

        std::cout<<"\nQueue of size = "<<this->size<<" is created.";
    }

    void enqueue(int a){
        if(rear == size - 1)
            std::cout<<"\nCan't insert, queue is full";
        else{
            rear++;
            Q[rear] = a;
            std::cout<<"\n"<<a<<" is inserted successfully";
        }
    }

    int dequeue(){
        if(front == rear){
            std::cout<<"\nQueue is empty, can't dequeue";
        }
        else{
            front++;
            return Q[front];
        }
    }

    bool isEmpty(){
        if(rear == front){
            std::cout<<"\nYes! Queue is empty";
            return true;
        }
        else{
            std::cout<<"No! Queue is not empty";
            return false;
        }
    }

    void display(){
        std::cout<<"\nQueue elements are\n";
        for(int i = front+1; i<= rear; i++)
            std::cout<<Q[i]<<"\t";
    }


};

int main(){

    queueImp q(15);
    q.enqueue(24);
    q.dequeue();
    q.dequeue();

    bool flag = q.isEmpty();

    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(23);
    q.enqueue(43);

    q.display();
    










    std::cout<<"\n\n\n\n";
    return 0;
}