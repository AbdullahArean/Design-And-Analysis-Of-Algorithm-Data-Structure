#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
class Queuey
{
private:
    int arr[MAX];
    int size;
    int front = -1, rear = -1;

public:
	Queuey(int arraysize)
	{size=arraysize;

	}
    bool IsFull() {
           return (rear+1)%size == front;
       }
	bool IsEmpty()
	{
        return rear == -1 && front == -1;
	}
	void Enqueue(int data)
	{
         if(IsFull()) {
               printf("Overflow");
               return;
           }
           //if it's the 1st element
           if(front == -1) {
               front = 0;
           }
 
           rear = (rear + 1)%size;
           arr[rear] = data;
	
	}
	int Dequeue()
	{
		   if(IsEmpty()) {
               printf("empty queue");
               return -1;
           }
           int res = arr[front];
 
           //if only 1 element is present
           if(front == rear) {
               front = rear = -1;
           } else {
               front = (front+1)%size;
           }
 
           return res;
	}
	int Front()
	{
        if(IsEmpty()) printf("The Queue is empty");
        else return arr[front];
		
	}
    
	void Print()
	{
        int i=front;
        while(i!=rear){
            printf("%d =>",arr[i]);
            i=(i+1)%size;
        }
        printf("%d =>",arr[rear]);
    }
};
int main(){
    Queuey q1= Queuey(10);
    q1.Enqueue(12);
    q1.Enqueue(142);
    q1.Enqueue(122);
    q1.Enqueue(12524);
    q1.Enqueue(125245);
    q1.Enqueue(12667);
    q1.Enqueue(1285);
    q1.Enqueue(1256785);
    q1.Enqueue(1285);
    q1.Enqueue(1258764);
    //q1.Enqueue(1285);
    //q1.Enqueue(1256785);
    // q1.Enqueue(1285);
    // q1.Enqueue(1258764);
//q1.Dequeue();
    q1.Print();
}
 
       
