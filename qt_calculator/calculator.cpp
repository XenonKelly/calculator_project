#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator) {
    ui->setupUi(this);
    this->setWindowTitle("Калькулятор");
    this->setMinimumWidth(400);
    this->setMinimumHeight(680);

    this->setMaximumWidth(550);
    this->setMaximumHeight(830);
    this->setStyleSheet("background: rgb(9, 30, 54); ");

    QFontDatabase::addApplicationFont(":/fonts/Calculator.ttf");

    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());

    display = new QLineEdit("0", this);
    display->setStyleSheet(
        "border-radius: 45%; "
        "padding: 5px; "
        "width: 100px; "
        "height: 80px; "
        "color: #fff; "
        "font-size: 70px; "
        "font-weight: 650; ");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFont(QFont("Calculator"));

    QPushButton *btn7 = new QPushButton("7", this);
    QPushButton *btn8 = new QPushButton("8", this);
    QPushButton *btn9 = new QPushButton("9", this);
    QPushButton *btn_divide = new QPushButton("/", this);
    QPushButton *btn4 = new QPushButton("4", this);
    QPushButton *btn5 = new QPushButton("5", this);
    QPushButton *btn6 = new QPushButton("6", this);
    QPushButton *btn_multiply = new QPushButton("*", this);
    QPushButton *btn1 = new QPushButton("1", this);
    QPushButton *btn2 = new QPushButton("2", this);
    QPushButton *btn3 = new QPushButton("3", this);
    QPushButton *btn_procent = new QPushButton("%", this);
    QPushButton *btn_minus = new QPushButton("-", this);
    QPushButton *btn0 = new QPushButton("0", this);
    QPushButton *btn_dot = new QPushButton(".", this);
    QPushButton *btn_equal = new QPushButton("=", this);
    QPushButton *btn_plus = new QPushButton("+", this);
    QPushButton *btn_clear = new QPushButton("C", this);
    QPushButton *btn_delete = new QPushButton("D", this);

    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(display, 0, 0, 1, 4);

    gridLayout->addWidget(btn_clear, 1, 0);
    gridLayout->addWidget(btn_procent, 1, 2);
    gridLayout->addWidget(btn_delete, 1, 1);
    gridLayout->addWidget(btn_divide, 1, 3);

    gridLayout->addWidget(btn7, 2, 0);
    gridLayout->addWidget(btn8, 2, 1);
    gridLayout->addWidget(btn9, 2, 2);
    gridLayout->addWidget(btn_multiply, 2, 3);

    gridLayout->addWidget(btn4, 3, 0);
    gridLayout->addWidget(btn5, 3, 1);
    gridLayout->addWidget(btn6, 3, 2);
    gridLayout->addWidget(btn_minus, 3, 3);

    gridLayout->addWidget(btn1, 4, 0);
    gridLayout->addWidget(btn2, 4, 1);
    gridLayout->addWidget(btn3, 4, 2);
    gridLayout->addWidget(btn_plus, 4, 3);

    gridLayout->addWidget(btn0, 5, 0, 1, 2);
    gridLayout->addWidget(btn_dot, 5, 2);
    gridLayout->addWidget(btn_equal, 5, 3);

    setLayout(gridLayout);

    btn7->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn8->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn9->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn6->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn5->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn4->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn3->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn2->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn1->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");
    btn_minus->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(231,187,103); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 30px; "
        "font-weight: 700; ");
    btn_plus->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(231,187,103); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 30px; "
        "font-weight: 700; ");
    btn_multiply->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(231,187,103); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 30px; "
        "font-weight: 700; ");
    btn_divide->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(231,187,103); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 30px; "
        "font-weight: 700; ");
    btn_procent->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(231,187,103); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 30px; "
        "font-weight: 700; ");
    btn_clear->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(255, 198, 67); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 25px; "
        "font-weight: 620; ");
    btn_delete->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(255, 198, 67); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 25px; "
        "font-weight: 620; ");
    btn_equal->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(231,187,103); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 30px; "
        "font-weight: 700; ");
    btn_dot->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 84px; "
        "height: 84px; "
        "font-size: 30px; "
        "font-weight: 700; ");
    btn0->setStyleSheet(
        "border-radius: 43%; "
        "background: rgb(87, 92, 130); "
        "color: #fff; "
        "padding: 1px; "
        "text-align: center; "
        "width: 100px; "
        "height: 84px; "
        "font-size: 20px; "
        "font-weight: 700; ");

    connect(btn9, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn8, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn7, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn6, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn5, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn4, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn3, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn2, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn1, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn0, &QPushButton::clicked, this, &Calculator::digit_clicked);
    connect(btn_dot, &QPushButton::clicked, this, &Calculator::digit_clicked);
}

Calculator::~Calculator() {
    delete ui;
}

void Calculator::button_slot() {
    this->show();
}

void Calculator::digit_clicked() {
    QPushButton *btn = (QPushButton*)(sender());
    int digit = btn->text().toInt();
    if (display->text() == "0") {
        display->clear();
    }
    display->setText(display->text() + QString::number(digit));
}
