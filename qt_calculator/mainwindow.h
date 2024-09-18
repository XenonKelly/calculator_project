#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculator.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLayout>
#include <QScreen>
#include <QFontDatabase>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPushButton *entry_button;
    Calculator *calculator_window;

public slots:
    void entry_btn_clicked();

signals:
    void signal();
};
#endif // MAINWINDOW_H
