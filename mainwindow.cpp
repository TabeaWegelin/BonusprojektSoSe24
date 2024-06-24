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
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //build grid layout and buttons
    this->resize(700, 700);
    QWidget* widget = new QWidget();
    QPushButton* btnLoad = new QPushButton ("Load");
    QPushButton* btnSave = new QPushButton ("Save");
    QPushButton* btnRect = new QPushButton ("Rectangle");
    QPushButton* btnCirc = new QPushButton ("Circle");
    artWidget = new RectArt();
    layout = new QGridLayout();

    //add buttons and art widget to layout
    layout->addWidget(btnLoad, 0, 0);
    layout->addWidget(btnRect, 1, 0);
    layout->addWidget(btnSave, 0, 1);
    layout->addWidget(btnCirc, 1, 1);
    layout->addWidget(artWidget, 2, 0, 1, 2);

    //pass layout to main widget and add it to the main window
    widget->setLayout(layout);
    this->setCentralWidget(widget);

    //connect button events to their event handlers
    QObject::connect(btnLoad, &QPushButton::clicked, this, &MainWindow::onLoadClicked);
    QObject::connect(btnSave, &QPushButton::clicked, this, &MainWindow::onSaveClicked);
    QObject::connect(btnRect, &QPushButton::clicked, this, &MainWindow::onRectClicked);
    QObject::connect(btnCirc, &QPushButton::clicked, this, &MainWindow::onCircClicked);

}

MainWindow::~MainWindow() {}


void MainWindow::onLoadClicked(){

    AbstractArtWidget* loadedArtWidget = NULL;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load Art Parameters"),
                                                    "",
                                                    tr("Art Parameters (*.ap)"));
    std::string line;
    std::ifstream myfile (fileName.toStdString());
    try{
        //if file is open, read contents, writes first line into string named line, close file
        if (myfile.is_open())
        {
            if (getline (myfile,line)) //can be read as "if not NULL"
            {
                std::cout << line << "\n";
            }
            myfile.close();
        }
        //if file is not open throw error
        else
        {
            std::cout << "Unable to open file";
            throw std::string("Unable to open file");
        }
        //depending on first line of file, either build RectArt, CircArt or throw error
        if (line == "[Rect Art]")
        {
            loadedArtWidget = new RectArt();
        }
        else if (line == "[Circ Art]")
        {
            loadedArtWidget = new CircArt();
        }
        else
        {
            throw std::string("Invalid file content");
        }
        //load method may throw an error
        loadedArtWidget->load(fileName);

        //swap loadedArtWidget with artWidget
        layout->removeWidget(artWidget);
        delete artWidget;
        artWidget = loadedArtWidget;
        layout->addWidget(artWidget, 2, 0, 1, 2);
    }

    //catches thrown strings, prints to console and opens error message box
    catch(std::string const& ex){
        std::cout << ex << std::endl;
        QMessageBox messageBox;
        messageBox.critical(0, "Error", ex.c_str());
        //makes sure loadedArtWidget is destroyed
        if (loadedArtWidget != NULL)
        {
            delete loadedArtWidget;
        }
    }
};

//opens dialog to save parameters in .ap file
void MainWindow::onSaveClicked(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Art Parameters"),
                                                    "",
                                                    tr("Art Parameters (*.ap)"));
    artWidget->save(fileName);
};

//removes current artWidget and builds a RectArt for it instead
void MainWindow::onRectClicked(){
    layout->removeWidget(artWidget);
    delete artWidget;
    artWidget = new RectArt();

    layout->addWidget(artWidget, 2, 0, 1, 2);
};

//removes current artWidget and builds a CircArt for it instead
void MainWindow::onCircClicked(){
    layout->removeWidget(artWidget);
    delete artWidget;
    artWidget = new CircArt();

    layout->addWidget(artWidget, 2, 0, 1, 2);
};
