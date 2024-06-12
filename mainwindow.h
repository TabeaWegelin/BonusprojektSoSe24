#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGridLayout>
#include "abstractartwidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void onLoadClicked();
    void onSaveClicked();
    void onRectClicked();
    void onCircClicked();
    QGraphicsScene* scene;
    AbstractArtWidget* artWidget;
    QGridLayout* layout;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
