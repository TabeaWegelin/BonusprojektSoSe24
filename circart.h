#ifndef CIRCART_H
#define CIRCART_H

#include "abstractartwidget.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QSlider>

class CircArt : public AbstractArtWidget
{
    Q_OBJECT
private:
    int numCirc;
    QGraphicsScene* scene;
    QSlider* slider;
    void onSlider();

public:
    explicit CircArt(QWidget *parent = nullptr);
    virtual ~CircArt();
    virtual void load(QString fileName);
    virtual void save(QString fileName);
    virtual void createRandomArt();

signals:
};

#endif // CIRCART_H
