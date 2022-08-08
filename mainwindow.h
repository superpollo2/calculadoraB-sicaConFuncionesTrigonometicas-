#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//funciones
    void digit_pressed();
    void on_pushButton_decimal_released();
    void binary_operation_pressed();
    void on_pushButton_igual_released();
    void on_pushButton_borrar_released();
    void handleButton();
    void on_pushButton_potenciax_clicked(bool checked);

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_decimal_pressed();

    void on_pushButton_enviar_pressed();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
