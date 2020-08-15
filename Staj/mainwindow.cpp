#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    add_graph(0,new_color);
    connect(ui->quit_btn,SIGNAL(clicked()),this,SLOT(close()));
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeplot()));
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));

    ui->stop_btn->setVisible(false);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_graph(int graph_no, QColor my_color){
    ui->customPlot->clearItems();
    ui->customPlot->clearGraphs();
    ui->customPlot->replot();
    ui->customPlot->addGraph();
    ui->customPlot->graph(graph_no)->setPen(QPen(my_color));
    ui->customPlot->graph(graph_no)->setBrush(QBrush(my_color));
    ui->customPlot->yAxis->setRange(-4, 4);
}
void MainWindow::on_start_btn_clicked()
{
    ui->stop_btn->setVisible(true);
    ui->start_btn->setVisible(false);
    if(ui->comboBox->currentText()=="Sin"){
        for (double i=0; i<359; i+=(359/99.5))
        {
            y0.append(qSin(qDegreesToRadians(i)));
        }
    }
    else if(ui->comboBox->currentText()=="Cos"){
        for (double i=0; i<359; i+=(359/99.5))
        {
            y0.append(qCos(qDegreesToRadians(i)));
        }
    }
    else if(ui->comboBox->currentText()=="Square"){
        for (double i=0; i<359; i+=(359/99.5))
        {
            if(i<180)
                y0.append(square[0]);
            else
                y0.append(square[1]);
        }
    }
    dataTimer.start(5);
}
void MainWindow::on_stop_btn_clicked()
{
    dataTimer.stop();
    ui->start_btn->setVisible(true);
    ui->stop_btn->setVisible(false);
    //add_graph(0,new_color);
}
void MainWindow::realtimeplot()
{
    static double i=0;
    if(j==100)
        j=0;
    ui->customPlot->graph(0)->addData(qDegreesToRadians(i),y0[j++]);
    ui->customPlot->xAxis->setRange(qDegreesToRadians(i)/4, 12, Qt::AlignRight);
    ui->customPlot->replot();
    ui->customPlot->graph(0)->rescaleAxes();
    i+=(359/99.5);
}

void MainWindow::on_quit_btn_clicked()
{

}
