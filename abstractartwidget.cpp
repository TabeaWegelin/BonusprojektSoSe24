#include "abstractartwidget.h"

AbstractArtWidget::AbstractArtWidget(QWidget *parent)
    : QWidget{parent}
{}

AbstractArtWidget::~AbstractArtWidget()
{}
//initializes color palette for all derived classes (CircArt and RectArt)
std::vector<std::vector<int>> AbstractArtWidget::palette = {{241,186,227},{234,136,209},{134,151,255},{185,195,255}};
