#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Designed by Huseyin MEN");
    ui->label->setStyleSheet("QLabel { background-color : white; color : black; border:1px solid gray}");
    ui->zero->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->one->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->two->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->three->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->four->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->five->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->six->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->seven->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->eight->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");
    ui->nine->setStyleSheet("QPushButton {border:1px solid gray;background-color:rgb(192,175,212)}");

    ui->clear->setStyleSheet("QPushButton {border:1px solid gray;background-color:\"gray\"}");
    ui->add->setStyleSheet("QPushButton {border:1px solid gray;background-color:\"orange\"}");
    ui->minus->setStyleSheet("QPushButton {border:1px solid gray;background-color:\"orange\"}");
    ui->mult->setStyleSheet("QPushButton {border:1px solid gray;background-color:\"orange\"}");
    ui->divide->setStyleSheet("QPushButton {border:1px solid gray;background-color:\"orange\"}");
    ui->equ->setStyleSheet("QPushButton {border:1px solid gray;background-color:\"orange\"}");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zero_clicked()
{
        if(my_num!=0){
            my_num*=10;
        }
        else{
            my_num=0;
        }
        ui->label->setNum(my_num);
}

void MainWindow::on_one_clicked()
{
    if(my_operator=="minus"){
            if(my_num==0){
                my_num=-1;
            }
            else{
                my_num*=10;
                my_num-=1;}
        }
        else{
        if(my_num==0){
            my_num=1;
        }
        else{
            my_num*=10;
            my_num+=1;

        }
    }
    ui->label->setNum(my_num);

}

void MainWindow::on_two_clicked()
{
    if(my_operator=="minus"){
            if(my_num==0){
                my_num=-2;
            }
            else{
                my_num*=10;
                my_num-=2;}
        }
        else{
    if(my_num==0){
        my_num=2;
    }
    else{
        my_num*=10;
        my_num+=2;
    }
    }
    ui->label->setNum(my_num);

}

void MainWindow::on_three_clicked()
{
    if(my_operator=="minus"){
        if(my_num==0){
            my_num=-3;
        }
        else{
            my_num*=10;
            my_num-=3;}
    }
    else{
    if(my_num==0){
        my_num=3;
    }
    else{
        my_num*=10;
        my_num+=3;
    }
    }
    ui->label->setNum(my_num);

}

void MainWindow::on_four_clicked()
{
    if(my_operator=="minus"){
            if(my_num==0){
                my_num=-4;
            }
            else{
                my_num*=10;
                my_num-=4;}
        }
        else{
    if(my_num==0){
        my_num=4;
    }
    else{
        my_num*=10;
        my_num+=4;
    }}
    ui->label->setNum(my_num);
}

void MainWindow::on_five_clicked()
{
    if(my_operator=="minus"){
            if(my_num==0){
                my_num=-5;
            }
            else{
                my_num*=10;
                my_num-=5;}
        }
        else{
    if(my_num==0){
        my_num=5;
    }
    else{
        my_num*=10;
        my_num+=5;
    }}
    ui->label->setNum(my_num);
}

void MainWindow::on_six_clicked()
{
    if(my_operator=="minus"){
            if(my_num==0){
                my_num=-6;
            }
            else{
                my_num*=10;
                my_num-=6;}
        }
        else{
    if(my_num==0){
        my_num=6;
    }
    else{
        my_num*=10;
        my_num+=6;
    }}
    ui->label->setNum(my_num);
}

void MainWindow::on_seven_clicked()
{
    if(my_operator=="minus"){
            if(my_num==0){
                my_num=-7;
            }
            else{
                my_num*=10;
                my_num-=7;}
        }
        else{

    if(my_num==0){
        my_num=7;
    }
    else{
        my_num*=10;
        my_num+=7;
    }}
    ui->label->setNum(my_num);
}

void MainWindow::on_eight_clicked()
{
    if(my_operator=="minus"){
            if(my_num==0){
                my_num=-8;
            }
            else{
                my_num*=10;
                my_num-=8;}
        }
        else{
    if(my_num==0){
        my_num=8;
    }
    else{
        my_num*=10;
        my_num+=8;
    }}
    ui->label->setNum(my_num);
}

void MainWindow::on_nine_clicked()
{
    if(my_operator=="minus"){
            if(my_num==0){
                my_num=-9;
            }
            else{
                my_num*=10;
                my_num-=9;}
        }
        else{
    if(my_num==0){
        my_num=9;
    }
    else{
        my_num*=10;
        my_num+=9;
    }}
    ui->label->setNum(my_num);
}
void MainWindow::on_equ_clicked()
{
    if(div=="nothing"){
        total+=my_num;
        total_txt=QString::number(total,'g',4);
        ui->label->setText(total_txt);
        my_num=0;
    }
    else if(div=="division")
    {
        total/=my_num;
        total_txt=QString::number(total,'g',4);
        ui->label->setText(total_txt);
        my_num=0;
    }
    else if(div=="mult"){
        total*=my_num;
        total_txt=QString::number(total,'g',4);
        ui->label->setText(total_txt);
        my_num=0;
    }
    div="nothing";

}

void MainWindow::on_clear_clicked()
{
    total=0;
    my_num=0;
    ui->label->setNum(my_num);
    my_operator="positive";
}

void MainWindow::on_add_clicked()
{
    total+=my_num;
    my_num=0;
    ui->label->setNum(my_num);
    my_operator="positive";
}

void MainWindow::on_minus_clicked()
{
    total+=my_num;
    my_num=0;
    ui->label->setNum(my_num);
    my_operator="minus";

}

void MainWindow::on_divide_clicked()
{
    total+=my_num;
    my_num=0;

    ui->label->setNum(my_num);
    div="division";
}

void MainWindow::on_mult_clicked()
{
    total+=my_num;
    my_num=0;
    ui->label->setNum(my_num);
    div="mult";
}
