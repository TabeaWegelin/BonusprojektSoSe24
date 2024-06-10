#include "mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QWidget* widget = new QWidget();
    QPushButton* btnLoad = new QPushButton ("Load");
    QPushButton* btnSave = new QPushButton ("Save");
    QPushButton* btnRect = new QPushButton ("Rectangle");
    QPushButton* btnCirc = new QPushButton ("Circle");
    QGraphicsView* view = new QGraphicsView();
    this->scene = new QGraphicsScene();
    QGridLayout* layout = new QGridLayout();

    view->setScene(this->scene);
    layout->addWidget(btnLoad, 0, 0);
    layout->addWidget(btnSave, 0, 1);
    layout->addWidget(btnRect, 1, 0);
    layout->addWidget(btnCirc, 1, 1);
    layout->addWidget(view, 2, 0, 2, 2);

    widget->setLayout(layout);
    this->setCentralWidget(widget);

    QObject::connect(btnLoad, &QPushButton::clicked, this, &MainWindow::onLoadClicked);
    QObject::connect(btnSave, &QPushButton::clicked, this, &MainWindow::onSaveClicked);
    QObject::connect(btnRect, &QPushButton::clicked, this, &MainWindow::onRectClicked);
    QObject::connect(btnCirc, &QPushButton::clicked, this, &MainWindow::onCircClicked);

}

MainWindow::~MainWindow() {}

void MainWindow::onLoadClicked(){
    std::cout << "Load" << std::endl;
};

void MainWindow::onSaveClicked(){
    std::cout << "Save" << std::endl;
};

void MainWindow::onRectClicked(){
    std::cout << "Rectangle" << std::endl;
};

void MainWindow::onCircClicked(){
std::cout << "Circle" << std::endl;
};