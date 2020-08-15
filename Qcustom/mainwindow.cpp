#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stop_plot->setVisible(false);
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
    ui->comboBox->addItem("Sin");
    ui->comboBox->addItem("Cos");
    ui->comboBox->addItem("Square");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_stop_plot_clicked()
{
    dataTimer.stop();

    ui->start_plot->setVisible(true);
    ui->stop_plot->setVisible(false);
    qDebug()<<"STOP";
    mystate=true;
}

void MainWindow::on_start_plot_clicked()
{
    if(ui->comboBox->currentText()=="Sin"){
        mySignal="Sin";}
    else if(ui->comboBox->currentText()=="Cos"){
        mySignal="Cos";}
    else{
        mySignal="Squ wave";
    }
    ui->customPlot->clearItems();
    ui->customPlot->clearGraphs();
    ui->customPlot->replot();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
    ui->customPlot->addGraph(); // red line
    ui->customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));
    ui->customPlot->addGraph(); // red line
    ui->customPlot->graph(2)->setPen(QPen(QColor(130, 220, 40)));
    ui->customPlot->graph(2)->setBrush(QBrush(QColor(30,0,190,20)));
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    //ui->customPlot->xAxis->setTicker(timeTicker);
    //ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->yAxis->setRange(-1.5,1.5);

    if(mystate==false){
        ui->start_plot->setVisible(false);
        ui->stop_plot->setVisible(true);
        // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
        connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeplot()));
        lastPointKey=0;
        time=QTime(QTime::currentTime());
    }
    else{
        mystate=false;
        ui->start_plot->setVisible(false);
        ui->stop_plot->setVisible(true);
        lastPointKey=0;
        time=QTime(QTime::currentTime());
    }
    dataTimer.start(10);
}
void MainWindow::realtimeplot(){
    double key = time.elapsed()/100.0; // time elapsed since start of demo, in seconds
    int square[2]={1,-1};
    //qDebug()<<key;
    if (key-lastPointKey > 0.01) // at most add point every 100us
    {
        if(mySignal=="Sin"){
            ui->customPlot->graph(0)->addData(key/4, qSin(key));}
        else if(mySignal=="Cos"){
            ui->customPlot->graph(1)->addData(key/4, qCos(key));
        }
        else if(mySignal=="Squ wave"){
            if(int(key/4)%2 == 0)
                ui->customPlot->graph(2)->addData(key/4,square[0]);
            else
                ui->customPlot->graph(2)->addData(key/4,square[1]);
        }

        lastPointKey = key;
    }

    ui->customPlot->xAxis->setRange(key/4, 8, Qt::AlignRight);
    ui->customPlot->replot();
}

void MainWindow::on_Quit_btn_clicked()
{
    this->close();
}
