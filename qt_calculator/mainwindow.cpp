#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Калькулятор");
    this->setMinimumWidth(400);
    this->setMinimumHeight(680);

    this->setStyleSheet(
        "background-image: url(:/fonts/background.jpg); "
        "background-position: center; " );

    QFontDatabase::addApplicationFont(":/fonts/Calculator.ttf");

    QWidget* cw = centralWidget();

    QPushButton *entry_button = new QPushButton("Log in", cw);
    entry_button->setMinimumWidth(200);
    entry_button->setMinimumHeight(200);
    entry_button->setFont(QFont("Calculator"));
    entry_button->setStyleSheet(
        "border-radius: 100%; "
        "background-image: url(:/fonts/mars.png); "
        "background-position: center; "
        "color: #000; "
        "padding: 3px; "
        "text-align: center; "
        "font-size: 60px; "
        "font-weight: 850; ");

    QVBoxLayout* main_layout = new QVBoxLayout(cw);
    main_layout->addWidget(entry_button, 0, Qt::AlignCenter);

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
