#include "mainscene.h"
#include "ui_mainscene.h"
MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    setFixedSize(900,600);
    QPalette pa(this->palette());
    QImage img =QImage("://pvz图片/startBackgound.png");
    img = img.scaled(this->size());
    QBrush *pic=new QBrush(img);
    pa.setBrush(QPalette::Window,*pic);
    this->setPalette(pa);
    pvzStartButton=new pvzMyPushButton("://pvz图片/startButton.png");
    pvzStartButton->setParent(this);
    pvzStartButton->setGeometry(300,490,100,40);

    connect(pvzStartButton,&pvzMyPushButton::clicked,[=](){
            pvzStartButton->pop1();
            pvzStartButton->pop2();
            QTimer::singleShot(500,this,[=]{
                this->hide();
                pvzPlayScene1=new pvzPlayScene;
                pvzPlayScene1->show();
            });
        });
}

MainScene::~MainScene()
{
    delete ui;

}
