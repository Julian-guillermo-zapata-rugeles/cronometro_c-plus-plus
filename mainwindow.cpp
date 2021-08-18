#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    segundos = 0;
    minutos = 0;
    pausado = false;
    connect(&reloj,SIGNAL(timeout()),this,SLOT(procesar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_iniciar_clicked()
{
    reloj.start(1000);
}


void MainWindow::on_btn_pausa_clicked()
{
    if (pausado==false) {
        reloj.stop();
        pausado=true;
        ui->btn_pausa->setText("reanudar");
    }
    else{
        pausado=false;
        reloj.start(1000);
        ui->btn_pausa->setText("pausar");
    }
}


void MainWindow::on_btn_stop_clicked()
{
    minutos=0;
    segundos=0;
    pausado=false;
    ui->minutos->display(minutos);
    ui->segundos->display(segundos);
    reloj.stop();
}

void MainWindow::procesar()
{
    segundos=segundos+1; // segundos++;
    if (segundos==60) {
        segundos=0;
        minutos=minutos+1;
    }
    else{
        ui->segundos->display(segundos);
        ui->minutos->display(minutos);
    }
}

