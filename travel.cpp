#include <iostream>
#include "travel.h"

using namespace std;

void insert(Node* &head, Place p) {
    Node* temp = new Node();
    temp->data = p;
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
        return;
    }

    Node* curr = head;
    while(curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
}


void display(Node* head) {
    while(head != NULL) {
        cout << "Name: " << head->data.name
             << " Budget: " << head->data.budget
             << " Rating: " << head->data.rating << endl;
        head = head->next;
    }
}


int countNodes(Node* head) {
    int c = 0;
    while(head) {
        c++;
        head = head->next;
    }
    return c;
}

// Convert linked list to array
void toArray(Node* head, Place arr[]) {
    int i = 0;
    while(head) {
        arr[i++] = head->data;
        head = head->next;
    }
}


void insertionSort(Place arr[], int n) {
    for(int i=1;i<n;i++) {
        Place key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j].budget > key.budget) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int binarySearch(Place arr[], int n, int key) {
    int low=0, high=n-1;

    while(low<=high) {
        int mid=(low+high)/2;

        if(arr[mid].budget==key)
            return mid;
        else if(arr[mid].budget<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}


void recommend(Node* head, int userBudget) {
    cout << "\nRecommended Places:\n";
    while(head) {
        if(head->data.budget<=userBudget && head->data.rating>=4.0)
            cout << head->data.name << endl;
        head=head->next;
    }
}
