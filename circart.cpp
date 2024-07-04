#include "circart.h"
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

CircArt::CircArt(QWidget *parent)
    : AbstractArtWidget{parent}
{
    //builds layout with slider
    QGridLayout* layout = new QGridLayout();
    scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView();
    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(10, 1000);
    numCirc = 450;
    slider->setValue(numCirc);


    view->setScene(scene);
    layout->addWidget(view, 0, 0);
    layout->addWidget(slider, 1, 0);
    this->setLayout(layout);
    CircArt::createArt();
    //connects slidermoved event with onSlider method
    QObject::connect(slider, &QSlider::sliderMoved, this, &CircArt::onSlider);
}

CircArt::~CircArt(){

}

//changes numCirc to value of slider
void CircArt::onSlider(){
    numCirc = slider->value();
    scene->clear();
    createArt();
}

//checks second line of file and sets numCirc to file value
void CircArt::load(QString fileName){
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
                    numCirc = std::stoi(line);
                }
                catch(...){
                    throw std::string("Invalid Number");
                }
                if (numCirc < 20 || numCirc > 1000){
                    throw std::string("Number not in range");
                }

                slider->setValue(numCirc);
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

}

//opens new file and writes [CircArt] and current numRect
void CircArt::save(QString fileName){
    std::ofstream myfile (fileName.toStdString());
    if (myfile.is_open())
    {
        myfile << "[Circ Art]\n";
        myfile << numCirc << "\n";
        myfile.close();
    }
    else std::cout << "Unable to open file";

}

//draws numCirc amount of circles
//placement, size and color follow randomized sequence
void CircArt::createArt(){
    QRandomGenerator random;
    QColor color;
    color.setAlpha(70);
    int r;
    for(int i = 0; i < numCirc; i++){
        r = random.bounded(0, 3);
        color.setRed(palette[r][0]);
        color.setGreen(palette[r][1]);
        color.setBlue(palette[r][2]);
        scene->addEllipse(random.bounded(0, 400), random.bounded(0, 400), random.bounded(10, 100), random.bounded(10, 100), QPen(color), QBrush(color));
    }
}
