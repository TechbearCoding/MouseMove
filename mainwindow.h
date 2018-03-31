#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel* lbl[4];
    QPoint current;

    void initLabels();
    bool eventFilter(QObject *target, QEvent *event);
    void turnLabelColor(int labelNo);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
