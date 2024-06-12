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

CircArt::CircArt(QWidget *parent)
    : AbstractArtWidget{parent}
{
    QGridLayout* layout = new QGridLayout();
    scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView();
    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(10, 1000);
    numCirc = 20;

    view->setScene(scene);
    layout->addWidget(view, 0, 0);
    layout->addWidget(slider, 1, 0);
    this->setLayout(layout);
    this->createRandomArt();
    QObject::connect(slider, &QSlider::sliderMoved, this, &CircArt::onSlider);
}

CircArt::~CircArt(){

}

void CircArt::onSlider(){
    numCirc = slider->value();
    scene->clear();
    createRandomArt();
}

void CircArt::load(QString fileName){

}

void CircArt::save(QString fileName){

}

void CircArt::createRandomArt(){
    int arr[4][3] = {{241,186,227},{234,136,209},{134,151,255},{185,195,255}};
    QRandomGenerator random;
    QColor color;
    color.setAlpha(70);
    int r;
    for(int i = 0; i < numCirc; i++){
        r = random.bounded(0, 3);
        color.setRed(arr[r][0]);
        color.setGreen(arr[r][1]);
        color.setBlue(arr[r][2]);
        scene->addEllipse(random.bounded(0, 400), random.bounded(0, 400), random.bounded(10, 100), random.bounded(10, 100), QPen(color), QBrush(color));
    }
}
