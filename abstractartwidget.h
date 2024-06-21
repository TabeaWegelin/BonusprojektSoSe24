#ifndef ABSTRACTARTWIDGET_H
#define ABSTRACTARTWIDGET_H

#include <QWidget>

class AbstractArtWidget : public QWidget
{
    Q_OBJECT
public:
    AbstractArtWidget(QWidget *parent = nullptr);
    virtual ~AbstractArtWidget();
    virtual void load(QString fileName) = 0;
    virtual void save(QString fileName) = 0;
    virtual void createArt() = 0; //when starting the programm


signals:
};

#endif // ABSTRACTARTWIDGET_H
