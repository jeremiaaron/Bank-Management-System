#include "TransacHistory.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Queue is full when size
// becomes equal to the capacity
bool Queue::isFull(Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
bool Queue::isEmpty(Queue* queue)
{
	return (queue->size == 0);
}

// Function to add the deposit transaction to the queue.
// It changes rear and size
void Queue::enqueueDeposit(Queue* queue, int num, int dep)
{
	string log;
	
	if(queue->size == 0) { // If queue is empty, reset the front and rear to -1 again
		queue->front = -1;
		queue->rear = -1;
	}
	
	log = "Bank Account No. " + to_string(num) + " has deposited " + "Rp " + to_string(dep) + ",00"; // Concatenate the string expression
	
	if(isFull(queue))
		return;

	else if(queue->front == -1) { // If front is -1 add +1 so that front is pointing to the beginning of the array
		queue->front += 1;
	}
	
	queue->rear = (queue->rear + 1) % queue->capacity; // Modulo here is used to limit the shifting of rear from one element to another in the array
	queue->array[queue->rear] = log; // Store the string expression into the array
	queue->accNum[queue->rear] = num; // Store the account number
	queue->size = queue->size + 1; // Increase the size as the expression is added
}

// Function to add the withdrawal transaction to the queue.
// It changes rear and size
void Queue::enqueueWithdrawal(Queue* queue, int num, int wit)
{
	string log;
	
	if(queue->size == 0) { // If queue is empty, reset the front and rear to -1 again
		queue->front = -1;
		queue->rear = -1;
	}
	
	log = "Bank Account No. " + to_string(num) + " has withdraw " + "Rp " + to_string(wit) + ",00"; // Concatenate the string expression
	
	if(isFull(queue))
		return;

	else if(queue->front == -1) { // If front is -1 add +1 so that front is pointing to the beginning of the array
		queue->front += 1;
	}
	
	queue->rear = (queue->rear + 1) % queue->capacity; // Modulo here is used to limit the shifting of rear from one element to another in the array
	queue->array[queue->rear] = log; // Store the string expression into the array
	queue->accNum[queue->rear] = num; // Store the account number
	queue->size = queue->size + 1; // Increase the size as the expression is added
}

// Show a user's account bank transaction
void Queue::showUserHistory(Queue* queue, int num) {
	
	cout << "|-------------------TRANSACTION HISTORY-------------------|\n" << endl;
	
	// Check if the array is empty
	if(isEmpty(queue)) {
		cout << "\t\t\tEmpty History\t\n" << endl;
	}else {
		int j = 0;
		for(int i = 0; i < queue->size; i++) {
			if(queue->accNum[i] == num)
			{
				j += 1;
				cout << j << ". " << queue->array[i] << "\n" << endl;
			}
			else continue;
		}
	}
	cout << "|---------------------------END---------------------------|\n" << endl;
	return;
}

// Show all transaction history each bank accounts
void Queue::showAllHistory(Queue* queue) {
	
	cout << "|-------------------TRANSACTION HISTORY-------------------|\n" << endl;
	
	// Check if the array is empty
	if(isEmpty(queue)) {
		cout << "\t\t\tEmpty History\t\n" << endl;
	}else {
		for(int i = 0; i <= (queue->size-1); i++) {
			cout << i + 1 << ". " << queue->array[i] << "\n" << endl;		
		}
	}
	cout << "|---------------------------END---------------------------|\n" << endl;
	return;
}
