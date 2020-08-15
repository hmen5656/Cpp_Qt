#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void add_graph(int graph_no,QColor my_color);
    ~MainWindow();

private slots:
    void on_start_btn_clicked();

    void on_stop_btn_clicked();

    void on_quit_btn_clicked();
    void realtimeplot();

private:
    Ui::MainWindow *ui;
    QTimer dataTimer;
    int square[2]={1,-1};
    QVector<double> y0;
    QColor new_color=QColor(40, 110, 255);
    int j=0;

};
#endif // MAINWINDOW_H
