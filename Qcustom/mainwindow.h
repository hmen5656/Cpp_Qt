#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_stop_plot_clicked();
    void realtimeplot();
    void on_start_plot_clicked();

    void on_Quit_btn_clicked();

private:
    Ui::MainWindow *ui;
    QTimer dataTimer;
    QString mySignal;
    bool mystate=false;
    QTime time;
    double lastPointKey;


};
#endif // MAINWINDOW_H
