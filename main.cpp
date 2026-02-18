#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QInputDialog>

#include "travel.h"
#include "stack.h"

using namespace std;

Node* head = NULL;
Stack history;

// Display all places
QString showPlaces() {
    QString out;
    Node* temp = head;
    while(temp) {
        out += QString::fromStdString(temp->data.name)
               + " | Budget: " + QString::number(temp->data.budget)
               + " | Rating: " + QString::number(temp->data.rating)
               + "\n";
        temp = temp->next;
    }
    return out;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Dataset
    // Dataset (Expanded)
    insert(head, {"Kathmandu",5000,4.2});
    insert(head, {"Pokhara",12000,4.8});
    insert(head, {"Chitwan",10000,4.5});
    insert(head, {"Lumbini",9000,4.3});
    insert(head, {"Nagarkot",7000,4.1});
    insert(head, {"Dhulikhel",6500,4.0});
    insert(head, {"Bandipur",8000,4.4});
    insert(head, {"Gosaikunda",15000,4.7});
    insert(head, {"Ilam",6000,4.1});
    insert(head, {"Mustang",20000,4.9});
    insert(head, {"Janakpur",5500,4.0});
    insert(head, {"Palpa",7500,4.2});
    insert(head, {"Rara Lake",22000,4.8});
    insert(head, {"Bardiya",11000,4.3});
    insert(head, {"Tansen",6800,4.1});
    insert(head, {"Kalinchowk",9000,4.4});


    QWidget window;
    window.setWindowTitle("Travel Recommendation System");

    QVBoxLayout *layout = new QVBoxLayout();

    QTextEdit *output = new QTextEdit();
    output->setReadOnly(true);

    QPushButton *viewBtn = new QPushButton("View Places");
    QPushButton *sortBtn = new QPushButton("Sort by Budget");
    QPushButton *searchBtn = new QPushButton("Search by Budget");
    QPushButton *stackBtn = new QPushButton("Last Viewed (Stack)");
    QPushButton *recBtn = new QPushButton("Recommend");
    QPushButton *exitBtn = new QPushButton("Exit");

    layout->addWidget(viewBtn);
    layout->addWidget(sortBtn);
    layout->addWidget(searchBtn);
    layout->addWidget(stackBtn);
    layout->addWidget(recBtn);
    layout->addWidget(exitBtn);
    layout->addWidget(output);

    // View places
    QObject::connect(viewBtn, &QPushButton::clicked, [&](){
        output->setText(showPlaces());
    });

    // Sort
    QObject::connect(sortBtn, &QPushButton::clicked, [&](){
        int n = countNodes(head);
        Place arr[20];
        toArray(head, arr);
        insertionSort(arr,n);

        QString res;
        for(int i=0;i<n;i++)
            res += QString::fromStdString(arr[i].name) +
                   " " + QString::number(arr[i].budget) + "\n";

        output->setText(res);
    });

    // Search + Stack push
    QObject::connect(searchBtn, &QPushButton::clicked, [&](){
        bool ok;
        int b = QInputDialog::getInt(&window,"Search","Enter Budget:",0,0,50000,1,&ok);
        if(!ok) return;

        int n = countNodes(head);
        Place arr[20];
        toArray(head, arr);
        insertionSort(arr,n);

        int pos = binarySearch(arr,n,b);

        if(pos!=-1){
            history.push(arr[pos]);
            output->setText("Found:\n"+QString::fromStdString(arr[pos].name));
        }
        else
            output->setText("Not Found");
    });

    // Stack pop
    QObject::connect(stackBtn,&QPushButton::clicked,[&](){
        if(!history.isEmpty()){
            Place p = history.pop();
            output->setText("Last Viewed:\n"+
                            QString::fromStdString(p.name)+
                            "\nBudget: "+QString::number(p.budget));
        } else {
            output->setText("Stack Empty");
        }
    });

    // Recommend
    QObject::connect(recBtn, &QPushButton::clicked, [&](){
        bool ok;
        int b = QInputDialog::getInt(&window,"Recommend","Max Budget:",0,0,50000,1,&ok);
        if(!ok) return;

        QString res;
        Node* temp = head;
        while(temp) {
            if(temp->data.budget<=b && temp->data.rating>=4.0)
                res += QString::fromStdString(temp->data.name) + "\n";
            temp=temp->next;
        }
        output->setText(res);
    });

    QObject::connect(exitBtn,&QPushButton::clicked,[&](){
        window.close();
    });

    window.setLayout(layout);
    window.resize(400,500);
    window.show();

    return app.exec();
}
