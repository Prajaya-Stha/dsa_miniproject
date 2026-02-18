#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

#include "travel.h"
#include "stack.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void searchPlace();
    void lastViewed();

private:
    QLineEdit *input;
    QTextEdit *output;

    Node *head;    // YOUR linked list
    Stack history; // new stack
};

#endif
