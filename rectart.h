#ifndef RECTART_H
#define RECTART_H

#include "abstractartwidget.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QSlider>

class RectArt : public AbstractArtWidget
{
    Q_OBJECT
private:
    int numRect;
    QGraphicsScene* scene;
    QSlider* slider;
    void onSlider();

public:
    RectArt(QWidget *parent = nullptr);
    virtual ~RectArt();
    virtual void load(QString fileName);
    virtual void save(QString fileName);
    virtual void createArt();

signals:
};

#endif // RECTART_H
