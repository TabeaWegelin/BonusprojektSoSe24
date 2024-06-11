#include "mainwindow.h"
#include "rectart.h"
#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(400, 400);
    QWidget* widget = new QWidget();
    QPushButton* btnLoad = new QPushButton ("Load");
    QPushButton* btnSave = new QPushButton ("Save");
    QPushButton* btnRect = new QPushButton ("Rectangle");
    QPushButton* btnCirc = new QPushButton ("Circle");
    artWidget = new RectArt();
    layout = new QGridLayout();


    layout->addWidget(btnLoad, 0, 0);
    layout->addWidget(btnSave, 0, 1);
    layout->addWidget(btnRect, 1, 0);
    layout->addWidget(btnCirc, 1, 1);
    layout->addWidget(artWidget, 2, 0, 2, 2);

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
    //std::cout << "Rectangle" << std::endl;
    layout->removeWidget(artWidget);
    delete artWidget;
    artWidget = new RectArt();

    layout->addWidget(artWidget, 2, 0, 2, 2);
};

void MainWindow::onCircClicked(){
std::cout << "Circle" << std::endl;
};
