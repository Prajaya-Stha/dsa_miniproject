#include "travel.h"

void insert(Node* &head, Place p){
    Node* n=new Node;
    n->data=p;
    n->next=head;
    head=n;
}

int countNodes(Node* head){
    int c=0;
    while(head){
        c++;
        head=head->next;
    }
    return c;
}

void toArray(Node* head, Place arr[]){
    int i=0;
    while(head){
        arr[i++]=head->data;
        head=head->next;
    }
}

void insertionSort(Place arr[],int n){
    for(int i=1;i<n;i++){
        Place key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j].budget>key.budget){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int binarySearch(Place arr[],int n,int key){
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m].budget==key) return m;
        else if(arr[m].budget<key) l=m+1;
        else r=m-1;
    }
    return -1;
}
