// Queue Implemen with Interview Que.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Basic Implementation and Some problems are being commented in order to implement as many questions as possible in a  SINGLE FILE OF CPP


#include <iostream>
#include<queue> //Just to use the STL Library for Queue. We include this header file..
#include<stack>
#include<deque>
using namespace std;

/*

class Queue  //Basic Queue Operations..

{

    int* arr;
    int front;
    int back;
    int max_size;

public:
    Queue(int default_size = 10)
    {
        arr = new int[default_size];
        max_size = default_size;
        front = -1;
        back = -1;

    }
    bool empty() //to check if queue is empty or not..
    {
        return front == -1;
    }
    bool full() //to check if queue if full or not..
    {
        return back == max_size;
    }
    void enqueue(int d) //to enter the data in the front of queue..
    {
        if (full)
        {
            cout << "The queue is full:- QueueOverflow Condition." << endl;;
            return;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
                back = 0;
                arr[back] = d;
            }
            else
            {
                arr[back] = d;
            }
            back++;
        }
    }
    void dequeue() //to delete the data from the front of the queue..
    {
        if (empty())
        {
            cout << "Queue is Empty:- UnderFlow" << endl;
            return;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == back)
            {
                front = -1;
                back = -1;
            }
        }

    }
    int getFront() //returns the front value in queue...
    {
        if (empty()) {
            cout << "Queue is Empty:- UnderFlow" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }

    }
    int getBack() //returns the last value in queue...
    {
        if (empty()) {
            cout << "Queue is Empty:- UnderFlow" << endl;
            return -1;
        }
        else
        {
            return arr[back-1];
        }
    }

    void print() // to print the queue...
    {
        if (empty()) {
            cout << "Queue is Empty" << endl;
            return ;
        }
        int i = 0;
        while (i < max_size)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};


*/

/*
class CircularQueue  //circular queue implementation..

{
    int* arr;
    int size;
    int front;
    int rear;
    int max_size;
public:
    CircularQueue(int default_size = 10)
    {
        arr = new int[default_size];
        size = 0;
        front = -1;
        rear = -1;
        max_size = default_size;
        for (int i = 0; i < max_size; i++)
            arr[i] = -1;
    }

    void enqueue(int data)
    {
        if (full())
        {
            cout << "Queue OverFlow" << endl;
            return;
        }
        else
        {
            if (empty())
            {
                front = 0;
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                arr[rear] = data;
            }
            rear = (rear + 1) % max_size;
            size++;
        }

    }
    void dequeue()
    {
        if (empty())
        {
            cout << "Queue Underflow Condition" << endl;
            return;
        }
        else
        {
            arr[front] = -1;
            front = (front + 1) % max_size;
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            size--;
        }
    }
    bool empty()
    {
        return (front == -1 && rear == -1);
    }
    bool full()
    {
        return (rear!=-1 && rear == front);
    }
    int getFront()
    {
        if (empty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    int getRear()
    {
        if (empty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else
        {
            return arr[(rear - 1 + max_size) % max_size];
        }
    }

    int getSize()
    {
        return size;
    }
    int getMaxSize()
    {
        return max_size;
    }
    void print()
    {
        int i = 0;
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            while (i < max_size)
            {
                cout << arr[i] << " ";
                i++;
            }
            cout << endl;
        }
    }
};

*/

//GENERATE NUMBERS WITH GIVEN SET OF DIGITS....
/*
void generateNumbers()
{
    //Input section
    int d;
    cout << "Enter Value Less Than 15 for number of array element:-  " << endl;
    cin >> d;
    int digits[20];
    cout << "Please Enter Sorted Elements:- " << endl;
    for (int i = 0; i < d; i++)
        cin >> digits[i];
    cout << "Enter count till you want to generate number:- " << endl;
    int n;
    cin >> n;


    //implementation to Generate Numbers

    cout << "The Generated Element Queue is :- " << endl;

    if (n <= d)
    {
        for (int i = 0; i < n; i++)
        {
            cout << digits[i] << " ";
        }
    }
    else
    {
        queue<int> q;
        for (int i = 0; i < d; i++)
            q.push(digits[i]);



        int inserted = d, printed = 0;
        while (printed < n)
        {
            int t = q.front();
            q.pop();
            cout << t << " ";
            printed++;
            if(inserted < n)
            {
                for (int i = 0; i < d; i++)
                {
                    if (inserted < n)
                    {
                        q.push(t * 10 + digits[i]);
                        inserted++;
                    }
                }
            }
        }
    }
}

*/


//Implement Stack Using 2 Queues....  (Important Question)
/*
class Stack
{
    queue<int> * q1, * q2, * qtemp;
public:
    Stack()
    {
        q1 = new queue<int>;
        q2 = new queue<int>;
        qtemp = NULL;
    }
    void push(int data)
    {
        q2->push(data);
        while (!q1->empty())
        {
            q2->push(q1->front());
            q1->pop();
        }
        qtemp = q1;
        q1 = q2;
        q2 = qtemp;
    }
    void pop()
    {
        if (empty())
        {
            cout << "Stack Underflow-Cannot Pop" << endl;
            return;
        }
        else
            q1->pop();
    }
    int top()
    {
        if (empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
            return q1->front();
    }
    int size()
    {
        return q1->size() + q2->size();
    }
    bool empty()
    {
        return q1->empty() && q2->empty();
    }
};

*/


//Implementing a Queue using 2 Stacks.... (Important Question)..

/*
class Queue
{
    stack<int>* s1, * s2;
public:
    Queue(){
        s1 = new stack<int>;
        s2 = new stack<int>;
    }

    void push(int data)
    {
        s1->push(data);
    }
    void pop()
    {
        if (s2->empty())
        {
            //transfer elements from s1 to s2
            if (s1->empty())
            {
                cout << "Queue s1 Underflow" << endl;
            }
            else
            {
                while (!s1->empty())
                {
                    s2->push(s1->top());
                    s1->pop();
                }
                s2->pop();
            }
        }
        else
        {
            s2->pop();
        }
    }
    int front()
    {
        if (s2->empty())
        {
            //transfer logic
            if (s1->empty())
            {
                cout << "Stack S1 is Undeflow" << endl;
                return -1;
            }
            else
            {
                while (!s1->empty())
                {
                    s2->push(s1->top());
                    s1->pop();
                }
                return s2->top();
            }
        }
        else
        {
            return s2->top();
        }
    }
    int back()
    {
        if (s1->empty())
        {
            //transfer logic
            if (s2->empty())
            {
                cout << "Stack S1 is Undeflow" << endl;
                return -1;
            }
            else
            {
                while (!s2->empty())
                {
                    s1->push(s2->top());
                    s2->pop();
                }
                return s1->top();
            }
        }
        else
        {
            return s1->top();
        }
    }
    int size()
    {
        return s1->size() + s2->size();
    }
    bool empty()
    {
        return s1->empty() && s2->empty();
    }



};
*

*/


int main()
{

    /*
    *  CircularQueue cq = CircularQueue(5);
    cq.print();
    cq.enqueue(5);
    cq.enqueue(3);
    cq.enqueue(6);
    cq.print();
    cq.enqueue(66);
    cq.enqueue(77);
    cq.print();
    cq.dequeue();
    cq.print();
    cq.dequeue();
    cq.dequeue();
    cq.print();
    cq.getRear();
    */ 
    //generateNumbers();
    /*
     Stack st = Stack();
    st.push(10);
    st.push(20);
    st.push(30);
    st.size();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.top() << endl;
    */
   

    /*
    Queue q = Queue();
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    */


    //DEQUEUE DS-> (Doubly Ended Queue DS) Implementation...

    int n;
    cout << "Enter the length of Array less then 50" << endl;
    cin >> n;
    int arr[50];
    cout << "Enter the Array Elements:-  " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "The Entered Array is :-  ";
    for (int i = 0; i < n; i++)
        cout << arr[i]<<" ";
    cout << endl;
    cout << "Enter the Window Length for Deque" << endl;
    int k;
    cin >> k;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back(); 
        dq.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[dq.front()] << " ";
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[i] >=  arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    cout << arr[dq.front()] << endl;

    return 0;
}

 