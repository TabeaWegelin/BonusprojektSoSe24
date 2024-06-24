#ifndef ABSTRACTARTWIDGET_H
#define ABSTRACTARTWIDGET_H

#include <QWidget>

class AbstractArtWidget : public QWidget
{
    Q_OBJECT
public:
    AbstractArtWidget(QWidget *parent = nullptr);
    virtual ~AbstractArtWidget();
    virtual void load(QString fileName) = 0; //loads saved art parameters file
    virtual void save(QString fileName) = 0; // saves current art parameters in file
    virtual void createArt() = 0;
protected:
    static std::vector<std::vector<int>> palette; //only accessible to class and its children, static so it only exsists once



signals:
};

#endif // ABSTRACTARTWIDGET_H
