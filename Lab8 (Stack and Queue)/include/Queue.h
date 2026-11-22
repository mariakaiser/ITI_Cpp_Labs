class Queue
{
private:
    int size;
    int * d_array;
    int front;
    int back;
public:
    Queue(int size);
    void display();
    void enqueue(int data);
    void dequeue();
    
};

