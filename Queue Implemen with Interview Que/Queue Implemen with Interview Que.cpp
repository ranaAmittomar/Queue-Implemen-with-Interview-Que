// Queue Implemen with Interview Que.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
using namespace std;


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

int main()
{
    std::cout << "Hello World!\n";
    return 0;
}

 