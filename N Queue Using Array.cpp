#include <bits/stdc++.h> 
class NQueue{
public:
    // Initialize your data structure.
    int N, S, freespot;
    int *arr;
    int *front;
    int *rear;
    int *next;

    NQueue(int n, int s){
        // Write your code here.
        N = n;
        S = s;
        freespot = 0;

        arr = new int[S];
        front = new int[N];
        rear = new int[N];
        next = new int[S];

        for(int i=0; i<N; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        for(int i=0; i<S-1; i++){
            next[i] = i+1;
        }
        next[S-1] = -1;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        // Write your code here.
        // Overflow
        if(freespot == -1) return false;

        // Step 1: find first free index.
        int index = freespot;
        arr[index] = x;
        // Step 2: update freespot.
        freespot = next[index];
        // Step 3: check whether first element.
        if(front[m-1] == -1){
            front[m-1] = index;
        } 
        else{//link new element to the prev element
            next[rear[m-1]] = index;
        }
        // Step 4: Update the next
        next[index] = -1;
        // Step 5: update rear
        rear[m-1] = index;

        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        // Write your code here.
        // Check Underflow conditions.
        if(front[m-1] == -1) return -1;
        // Step 1: find index to pop.
        int index = front[m-1];
        // Step 2: front ko aage badhao.
        front[m-1] = next[index];
        // Step 3: Check if the queue become empty.
        if(front[m-1] == -1){
            rear[m-1] = -1;
        }
        // Step 4: freeSlots ko manage karo.
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};
