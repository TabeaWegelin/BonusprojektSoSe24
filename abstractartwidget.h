#ifndef ABSTRACTARTWIDGET_H
#define ABSTRACTARTWIDGET_H

#include <QWidget>
#include <QRandomGenerator>

class AbstractArtWidget : public QWidget
{
    Q_OBJECT
public:
    AbstractArtWidget(QWidget *parent = nullptr);
    virtual ~AbstractArtWidget();
    virtual void load(QString fileName) = 0;
    virtual void save(QString fileName) = 0;
    virtual void createArt() = 0; //when starting the programm
protected:
    static std::vector<std::vector<int>> palette;
    static QRandomGenerator random;



signals:
};

#endif // ABSTRACTARTWIDGET_H
