#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QScreen>
#include <QPushButton>
#include <QFontDatabase>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget {
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
    QLineEdit *display;
    QPushButton *btn_divide;
    QPushButton *btn_multiply;
    QPushButton *btn_procent;
    QPushButton *btn_minus;
    QPushButton *btn0;
    QPushButton *btn_dot;
    QPushButton *btn_equal;
    QPushButton *btn_plus;
    QPushButton *btn_clear;
    QPushButton *btn_delete;
    QPushButton *digit_buttons[];

private slots:
    void digit_clicked();


public slots:
    void button_slot();
};

#endif // CALCULATOR_H
