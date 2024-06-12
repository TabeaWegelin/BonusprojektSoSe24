#include "mainwindow.h"
#include "rectart.h"
#include "circart.h"
#include <QPushButton>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <string.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(700, 700);
    QWidget* widget = new QWidget();
    QPushButton* btnLoad = new QPushButton ("Load");
    QPushButton* btnSave = new QPushButton ("Save");
    QPushButton* btnRect = new QPushButton ("Rectangle");
    QPushButton* btnCirc = new QPushButton ("Circle");
    artWidget = new RectArt();
    layout = new QGridLayout();


    layout->addWidget(btnLoad, 0, 0);
    layout->addWidget(btnRect, 1, 0);
    layout->addWidget(btnSave, 0, 1);
    layout->addWidget(btnCirc, 1, 1);
    layout->addWidget(artWidget, 2, 0, 1, 2);

    widget->setLayout(layout);
    this->setCentralWidget(widget);

    QObject::connect(btnLoad, &QPushButton::clicked, this, &MainWindow::onLoadClicked);
    QObject::connect(btnSave, &QPushButton::clicked, this, &MainWindow::onSaveClicked);
    QObject::connect(btnRect, &QPushButton::clicked, this, &MainWindow::onRectClicked);
    QObject::connect(btnCirc, &QPushButton::clicked, this, &MainWindow::onCircClicked);

}

MainWindow::~MainWindow() {}

void MainWindow::onLoadClicked(){
    //std::cout << "Load" << std::endl;
    AbstractArtWidget* loadedArtWidget = NULL;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Art Parameters"),
                                                    "",
                                                    tr("Art Parameters (*.ap)"));
    std::string line;
    std::ifstream myfile (fileName.toStdString());
    if (myfile.is_open())
    {
        if (getline (myfile,line))
        {
            std::cout << line << "\n";
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file";
    }
    if (line == "[Rect Art]")
    {
        loadedArtWidget = new RectArt();
    }
    else if (line == "[Circ Art]")
    {
        loadedArtWidget = new CircArt();
    }
    loadedArtWidget->load(fileName);

    layout->removeWidget(artWidget);
    delete artWidget;
    artWidget = loadedArtWidget;
    layout->addWidget(artWidget, 2, 0, 1, 2);

    std::cout << fileName.toStdString() << std::endl;
};

void MainWindow::onSaveClicked(){
    //std::cout << "Save" << std::endl;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Art Parameters"),
                                                    "",
                                                    tr("Art Parameters (*.ap)"));
    artWidget->save(fileName);
    std::cout << fileName.toStdString() << std::endl;
};

void MainWindow::onRectClicked(){
    //std::cout << "Rectangle" << std::endl;
    layout->removeWidget(artWidget);
    delete artWidget;
    artWidget = new RectArt();

    layout->addWidget(artWidget, 2, 0, 1, 2);
};

void MainWindow::onCircClicked(){
    //std::cout << "Circle" << std::endl;
    layout->removeWidget(artWidget);
    delete artWidget;
    artWidget = new CircArt();

    layout->addWidget(artWidget, 2, 0, 1, 2);
};
