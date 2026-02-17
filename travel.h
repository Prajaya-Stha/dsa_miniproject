#ifndef TRAVEL_H
#define TRAVEL_H

#include <string>
using namespace std;


struct Place
{
    string name;
    int budget;
    float rating;
};


struct Node
{
    Place data;
    Node *next;
};

void insert(Node *&head, Place p);
void display(Node *head);
int countNodes(Node *head);
void toArray(Node *head, Place arr[]);
void insertionSort(Place arr[], int n);
int binarySearch(Place arr[], int n, int key);
void recommend(Node *head, int userBudget);

#endif
