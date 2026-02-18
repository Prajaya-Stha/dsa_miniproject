#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    QWidget *w = new QWidget;
    QVBoxLayout *lay = new QVBoxLayout;

    input = new QLineEdit;
    input->setPlaceholderText("Enter place id");

    QPushButton *search = new QPushButton("Search");
    QPushButton *last = new QPushButton("Last Viewed");

    output = new QTextEdit;
    output->setReadOnly(true);

    lay->addWidget(input);
    lay->addWidget(search);
    lay->addWidget(last);
    lay->addWidget(output);

    w->setLayout(lay);
    setCentralWidget(w);

    head = NULL;

    insert(head,{"Pokhara",5});
    insert(head,{"Kathmandu",3});
    insert(head,{"Chitwan",4});

    connect(search,&QPushButton::clicked,this,&MainWindow::searchPlace);
    connect(last,&QPushButton::clicked,this,&MainWindow::lastViewed);
}

void MainWindow::searchPlace()
{
    int id = input->text().toInt();

    Place p = binarySearchLinkedList(head,id);

    history.push(p);

    output->append("Found: "+QString::fromStdString(p.name));
}

void MainWindow::lastViewed()
{
    if(!history.isEmpty()){
        Place p = history.pop();
        output->append("Last Viewed: "+QString::fromStdString(p.name));
    }
}
