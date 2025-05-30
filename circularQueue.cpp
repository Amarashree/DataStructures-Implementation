#include<iostream>

//Implemention circular queues

class cQueue{
    int size;
    int f;
    int r;
    int *arr;

    public:
    
    cQueue(const int& s){
        size = s;
        arr = new int[size];
        f = r = 0;
        std::cout<<"\ncQueue of size="<<size<<" is created";
    }

    void enqueue(const int& element){

        if(((r+1) % (size)) != f)
        {
            r = (r+1) % (size);
            
            arr[r] = element;
            std::cout<<"\n"<<element<<" is added successfully in position="<<r<<" anf forward = "<<f;
        }
        else    
             std::cout<<"\nCan't add the element, Queue is full";
    }

    void display(){
        std::cout<<"\nThe elements of the queue are\n";
        int itrF = f;
        int itrR = r;
        while(itrF != itrR){
            itrF = (itrF+1) % (size);
            std::cout<<arr[itrF]<<"\t";
        }
    }

    int dequeue(){
        if(f == r)
            std::cout<<"\nQueue is empty";
        else{
            f = (f+1)%(size);
            std::cout<<"\npoped out = "<<arr[f]<<" and position = "<<f;
        }
        return arr[f];
    }

};

int main(){

    int size = 5;
    cQueue cq(size);

    for(int i=0;i<size;i++)
        cq.enqueue(i);

    for(int i=0;i<size/2;i++)
        cq.dequeue();
    
    for(int i=0;i<size;i++)
        cq.enqueue(i);
    








    std::cout<<"\n\n\n";
    return 0;
}