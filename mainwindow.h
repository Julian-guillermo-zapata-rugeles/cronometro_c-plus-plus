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
    ~MainWindow();

private slots:
    void on_btn_iniciar_clicked();

    void on_btn_pausa_clicked();

    void on_btn_stop_clicked();

    void procesar();

private:
    Ui::MainWindow *ui;
    short int minutos;
    short int segundos;
    bool pausado;
    QTimer reloj;
};
#endif // MAINWINDOW_H
