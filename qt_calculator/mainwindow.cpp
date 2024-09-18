#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Калькулятор");
    this->setMinimumWidth(400);
    this->setMinimumHeight(680);

    this->setMaximumWidth(550);
    this->setMaximumHeight(830);
    this->setStyleSheet(
        "background-image:url(:/fonts/background.jpg); background-position: center;" );

    QFontDatabase::addApplicationFont(":/fonts/Calculator.ttf");
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());

    QPushButton *entry_button = new QPushButton("Log in", this);
    entry_button->setGeometry((this->width() - 200) / 2, (this->height() - 200) / 2 , 200, 200);
    entry_button->setFont(QFont("Calculator"));
    entry_button->setStyleSheet(" border-radius: 100%; background-image:url(:/fonts/mars.png); background-position: center; color: #000; padding: 3px; text-align: center; width: 200px; height: 200px; font-size: 60px; font-weight: 850");

    calculator_window = new Calculator;
    connect(entry_button, &QPushButton::clicked, this, &MainWindow::entry_btn_clicked);
    connect(this, &MainWindow::signal, calculator_window, &Calculator::button_slot);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::entry_btn_clicked() {
    emit signal();
    this->hide();
    this->~MainWindow();
}
