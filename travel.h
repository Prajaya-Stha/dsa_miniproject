#ifndef TRAVEL_H
#define TRAVEL_H

#include <string>
using namespace std;

struct Place {
    string name;
    int budget;
    float rating;

    Place() {
        name="";
        budget=0;
        rating=0;
    }

    Place(string n,int b,float r){
        name=n;
        budget=b;
        rating=r;
    }
};

struct Node {
    Place data;
    Node* next;
};

void insert(Node* &head, Place p);
int countNodes(Node* head);
void toArray(Node* head, Place arr[]);
void insertionSort(Place arr[], int n);
int binarySearch(Place arr[], int n, int key);

#endif
