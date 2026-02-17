#include <iostream>
#include "travel.h"

using namespace std;

int main() {

    Node* head = NULL;

    
    insert(head, {"Kathmandu",5000,4.2});
    insert(head, {"Pokhara",12000,4.8});
    insert(head, {"Chitwan",10000,4.5});
    insert(head, {"Lumbini",9000,4.3});
    insert(head, {"Nagarkot",7000,4.1});
    insert(head, {"Dhulikhel",6500,4.0});

    int choice;

    do {
        cout << "\n--- Travel Recommendation System ---\n";
        cout << "1. View Places\n";
        cout << "2. Sort by Budget\n";
        cout << "3. Binary Search by Budget\n";
        cout << "4. Get Recommendation\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int n = countNodes(head);
        Place arr[20];
        toArray(head, arr);

        switch(choice) {

        case 1:
            display(head);
            break;

        case 2:
            insertionSort(arr, n);
            cout << "Sorted Places:\n";
            for(int i=0;i<n;i++)
                cout << arr[i].name << " " << arr[i].budget << endl;
            break;

        case 3: {
            insertionSort(arr,n);
            int b;
            cout << "Enter budget to search: ";
            cin >> b;
            int pos = binarySearch(arr,n,b);
            if(pos!=-1)
                cout << "Found: " << arr[pos].name << endl;
            else
                cout << "Not Found\n";
            break;
        }

        case 4: {
            int ub;
            cout << "Enter your max budget: ";
            cin >> ub;
            recommend(head,ub);
            break;
        }

        }

    } while(choice != 5);

    return 0;
}
