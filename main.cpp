#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QInputDialog>

#include "travel.h"
using namespace std;

Node* head = NULL;

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
    insert(head, {"Kathmandu",5000,4.2});
    insert(head, {"Pokhara",12000,4.8});
    insert(head, {"Chitwan",10000,4.5});
    insert(head, {"Lumbini",9000,4.3});
    insert(head, {"Nagarkot",7000,4.1});
    insert(head, {"Dhulikhel",6500,4.0});

    QWidget window;
    window.setWindowTitle("Travel Recommendation System");

    QVBoxLayout *layout = new QVBoxLayout();

    QTextEdit *output = new QTextEdit();
    output->setReadOnly(true);

    QPushButton *viewBtn = new QPushButton("View Places");
    QPushButton *sortBtn = new QPushButton("Sort by Budget");
    QPushButton *searchBtn = new QPushButton("Search by Budget");
    QPushButton *recBtn = new QPushButton("Recommend");
    QPushButton *exitBtn = new QPushButton("Exit");

    layout->addWidget(viewBtn);
    layout->addWidget(sortBtn);
    layout->addWidget(searchBtn);
    layout->addWidget(recBtn);
    layout->addWidget(exitBtn);
    layout->addWidget(output);

    QObject::connect(viewBtn, &QPushButton::clicked, [&](){
        output->setText(showPlaces());
    });

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

    QObject::connect(searchBtn, &QPushButton::clicked, [&](){
        bool ok;
        int b = QInputDialog::getInt(&window,"Search","Enter Budget:",0,0,50000,1,&ok);
        if(!ok) return;

        int n = countNodes(head);
        Place arr[20];
        toArray(head, arr);
        insertionSort(arr,n);

        int pos = binarySearch(arr,n,b);
        if(pos!=-1)
            output->setText("Found: " + QString::fromStdString(arr[pos].name));
        else
            output->setText("Not Found");
    });

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
