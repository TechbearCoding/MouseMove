#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

#define mouseMoveOffset 5

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initLabels();
    current = lbl[0]->pos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLabels()
{
    lbl[0] = ui->FrontLabel;
    lbl[1] = ui->DownLabel;
    lbl[2] = ui->LeftLabel;
    lbl[3] = ui->rightLabel;

    for(int i = 0; i<4; i++){
        lbl[i]->setStyleSheet("QLabel { background-color : red;}");
        lbl[i]->installEventFilter(this);
    }
}

bool MainWindow::eventFilter(QObject *target, QEvent *event)
{
    QObject *obj = target;

    for(int i = 0; i<4; i++){
        if(obj == lbl[i] && event->type()==QEvent::MouseButtonPress){
            turnLabelColor(i);
        }
    }
    return QWidget::eventFilter(target, event);
}

void MainWindow::turnLabelColor(int labelNo)
{
    for(int i = 0; i<4; i++){
        lbl[i]->setStyleSheet("QLabel { background-color : red;}");
    }

    lbl[labelNo]->setStyleSheet("QLabel { background-color : green;}");
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = event->pos();

    double changeX = fabs(point.rx() - current.rx());
    double changeY = fabs(point.ry() - current.ry());

    if(changeX>changeY){
        if(current.rx()<point.rx()){
            turnLabelColor(3);
        }else if(current.rx()>point.rx()){
            turnLabelColor(2);
        }
    }else{
        if(current.ry()>point.ry()){
            turnLabelColor(0);
        }else if(current.ry()<point.ry()){
            turnLabelColor(1);
        }
    }

    current=point;
}
