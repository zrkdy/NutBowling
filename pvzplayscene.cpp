#include "pvzplayscene.h"
#include "card.h"

using namespace std;

Card::bb *cardsets;

pvzPlayScene::pvzPlayScene(QWidget *parent) :
    QMainWindow(parent)
{
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));
    /*sound = new QSound("://Grazy Dave.wav",this);
    sound->play();
    sound->setLoops(QSound::Infinite);*/
    setFixedSize(900,600);
    timer = new QTimer;
    scene = new QGraphicsScene(this);

    scene->setSceneRect(150, 0, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    //小推车插入
    for (int i = 0; i < 5; i++)
    {
        Mower *mower = new Mower;
        mower->setPos(210, 130 + 98 * i);
        scene->addItem(mower);
    }

    //背景插入
    map_view = new QGraphicsView(scene, this);
    map_view->setRenderHint(QPainter::Antialiasing);
    map_view->resize(902,602);
    map_view->setBackgroundBrush(QPixmap("://pvz图片/Background.jpg"));
    map_view->setCacheMode(QGraphicsView::CacheBackground);
    map_view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    Shop * shop = new Shop;
    shop->setPos(520, 45);
    scene->addItem(shop);



    Map *map = new Map;
    map->setPos(618, 326);
    scene->addItem(map);


    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &pvzPlayScene::addZombie);
    connect(timer, &QTimer::timeout, this, &pvzPlayScene::addNutWall);
    connect(timer, &QTimer::timeout, this, &pvzPlayScene::check);
    connect(timer, &QTimer::timeout, this, &pvzPlayScene::move_card);
    timer->start(33);

    map_view->show();

}
pvzPlayScene::~pvzPlayScene()
{
    //delete sound;
    delete timer;
    delete scene;
    delete map_view;
}

void pvzPlayScene::addZombie()
{

    static int low = 4;
    static int high = 8;
    static int maxtime = 20 * 1000 / 33/3/2;
    static int time = maxtime / 2;
    static int counter = 0;
    if (++counter >= time)
    {
        if (++low > high)
        {
            maxtime /= 1.3;
            high *= 2;
        }
        counter = 0;
        time = qrand() % (2 * maxtime / 3) + maxtime / 2;
        int type = qrand() % 100;
        int i = qrand() % 5;
        Zombie *zombie;
        if (type < 40)
            zombie = new BasicZombie;
        else if (type < 70)
            zombie = new RoadBlockZombie;
        else if (type < 80)
            zombie = new MetalBucketZombie;
        else if (type < 90)
            zombie = new ScreenZombie;
        else
            zombie = new FootballZombie;
        zombie->setPos(1028, 130 + 98 * i);
        scene->addItem(zombie);
    }
}

void pvzPlayScene::addNutWall(){
    if(cardidx>=8){
        return;
    }
        static int low = 4;
        static int high = 8;
        static int maxtime = 20 * 1000 / 33/2/2;
        static int time = maxtime;
        static int counter = 0;
        if (++counter >= time)
        {
            if (++low > high)
            {
                maxtime /= 1.3;
                high *= 2;
            }
            counter = 0;
            time = qrand() % (2 * maxtime / 3) + maxtime / 3;
            int type = qrand() % 5;
            Card *card;
            if(type <3)
                card = new Card("NutWall");
            else if(type <4)
                card = new Card("redNutWall");
            else
                card = new Card("bigNutWall");
            card->setPos(750, 45);
            scene->addItem(card);
        }
}

void pvzPlayScene::move_card()
{
    Card *card1=new Card(1);
    auto cardsets=card1->re_sets();
    delete card1;
    if(cardidx==0)
        return;
    for(int i=0;i<cardidx;i++){
        if(cardsets[i].x==0){
           cardsets[i].card=nullptr;
            cardsets[i].x=1;
            for(int j=i;j<cardidx-1;j++){
                cardsets[j]=cardsets[j+1];
            }
            cardidx--;
        }
    }
    for(int i=0;i<cardidx;i++){
        cardsets[i].card->speed=3;
        if(cardsets[i].card->x()<230+60*(i+1)){
            cardsets[i].card->speed=0;
        }
        cardsets[i].card->setX(cardsets[i].card->x()-cardsets[i].card->speed);
    }

}

void pvzPlayScene::check()
{
    static int time = 1 * 1000 / 33;
    static int counter = 0;
    if (++counter >= time)
    {
        counter = 0;
        const QList<QGraphicsItem *> items = scene->items();
        foreach (QGraphicsItem *item, items)
            if (item->type() == Zombie::Type && item->x() < 200)
            {
                scene->addPixmap(QPixmap("://pvz图片/ZombiesWon.png"))->setPos(336, 92);
                scene->advance();
                timer->stop();
                return;
            }
    }
}
