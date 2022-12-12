#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <pvzmypushbutton.h>
#include <qtimer.h>

#include "pvzplayscene.h"
namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();


private:
    Ui::MainScene *ui;
    pvzMyPushButton * pvzStartButton;
    pvzPlayScene *pvzPlayScene1;
};

#endif // MAINSCENE_H
