#ifndef PVZPLAYSCENE_H
#define PVZPLAYSCENE_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTime>
#include <QMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QVector>
#include <QSound>

#include "mower.h"
#include "basiczombie.h"
#include "footballzombie.h"
#include "zombie.h"
#include "nutwall.h"
#include "shop.h"
#include "map.h"
#include "card.h"
#include "metalbucketzombie.h"
#include "roadblockzombie.h"
#include "screenzombie.h"

namespace Ui {
class MainGame;
}

class pvzPlayScene : public QMainWindow
{
    Q_OBJECT
public:
    QSound *sound;
    ~pvzPlayScene() override;
    explicit pvzPlayScene(QWidget *parent = nullptr);
    QGraphicsScene *scene;
    void addZombie();
    void check();
    void addNutWall();
    void move_card();
private:
    QTimer *timer;
    QGraphicsView *map_view;
    Ui::MainGame *ui;

signals:

public slots:
};

#endif // PVZPLAYSCENE_H
