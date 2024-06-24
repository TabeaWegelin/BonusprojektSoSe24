#include "rectart.h"
#include <QGridLayout>
#include <QGraphicsScene>
#include <QSlider>
#include <QGraphicsView>
#include <QRect>
#include <QRandomGenerator>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <fstream>
#include <iostream>


RectArt::RectArt(QWidget *parent)
    : AbstractArtWidget(parent)
{
    //builds layout with slider
    QGridLayout* layout = new QGridLayout();
    scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView();
    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(10, 1000);
    numRect = 450;
    slider->setValue(numRect);

    view->setScene(scene);
    layout->addWidget(view, 0, 0);
    layout->addWidget(slider, 1, 0);
    this->setLayout(layout);
    RectArt::createArt();
    //connects slidermoved event with onSlider method
    QObject::connect(slider, &QSlider::sliderMoved, this, &RectArt::onSlider);
}

RectArt::~RectArt(){

};

//changes numRect to value of slider
void RectArt::onSlider(){
    numRect = slider->value();
    scene->clear();
    createArt();
};

//checks second line of file and sets numRect to file value
void RectArt::load(QString fileName){
    std::string line;
    std::ifstream myfile (fileName.toStdString());
    try{
        if (myfile.is_open())
        {
            if (getline (myfile,line))
            {
                std::cout << line << "\n";
            }
            if (getline (myfile,line))
            {
                std::cout << line << "\n";

                try{
                    numRect = std::stoi(line); //string to int
                }
                catch(...){
                    throw std::string("Invalid Number");
                }
                if (numRect < 20 || numRect > 1000){
                    throw std::string("Number not in range");
                }

                slider->setValue(numRect);
                createArt();
            }
            else
            {
                throw std::string("Number missing");
            }
            myfile.close();
        }
        else
        {
            std::cout << "Unable to open file";
            throw std::string("Unable to open file");
        }
    }
    catch(std::string const& ex){
        if(myfile.is_open()){
            myfile.close();
        }
        throw ex; //throws to catch block of OnLoadClicked in mainwindow.cpp
    }

};

//opens new file and writes [RectArt] and current numRect
void RectArt::save(QString fileName){
    std::ofstream myfile (fileName.toStdString());
    if (myfile.is_open())
    {
        myfile << "[Rect Art]\n";
        myfile << numRect << "\n";
        myfile.close();
    }
    else std::cout << "Unable to open file";

};

//draws numRect amount of rectangles
//placement, size and color follow randomized sequence
void RectArt::createArt(){
    QRandomGenerator random;
    QColor color;
    color.setAlpha(70);
    int r;
    for(int i = 0; i < numRect; i++){
        r = random.bounded(0, 3);
        color.setRed(palette[r][0]);
        color.setGreen(palette[r][1]);
        color.setBlue(palette[r][2]);
        scene->addRect(random.bounded(0, 400), random.bounded(0, 400), random.bounded(10, 100), random.bounded(10, 100), QPen(color), QBrush(color));
    }
};
