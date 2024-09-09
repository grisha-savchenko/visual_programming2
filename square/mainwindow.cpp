#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areacalculator.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    idx = 0;
    ui->setupUi(this);
    connect(ui->actionAuthors, &QAction::triggered, this, &MainWindow::showAuthors);
    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::clearFields);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::close);
    on_figureComboBox_currentIndexChanged(idx);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    clearFields();
    on_figureComboBox_currentIndexChanged(this->idx);
}

void MainWindow::on_pushButton_clicked()
{
    AreaCalculator calculator;
    double result = 0;

    if (ui->figureComboBox->currentText() == "квадрат") {
        double side = ui->lineEdit->text().toDouble();
        result = calculator.CalculateSquare(side);
    } else if (ui->figureComboBox->currentText() == "прямоугольник") {
        double length = ui->lineEdit->text().toDouble();
        double width = ui->lineEdit_2->text().toDouble();
        result = calculator.CalculateRectangle(length, width);
    } else if (ui->figureComboBox->currentText() == "параллелограмм") {
        double length = ui->lineEdit->text().toDouble();
        double heigth = ui->lineEdit_2->text().toDouble();
        result = calculator.CalculateParallelogram(length, heigth);
    } else if (ui->figureComboBox->currentText() == "ромб") {
        double length = ui->lineEdit->text().toDouble();
        double heigth = ui->lineEdit_2->text().toDouble();
        result = calculator.CalculateRhombus(length, heigth);
    } else if (ui->figureComboBox->currentText() == "треугольник") {
        double length = ui->lineEdit->text().toDouble();
        double heigth = ui->lineEdit_2->text().toDouble();
        result = calculator.CalculateTriangle(length, heigth);
    } else if (ui->figureComboBox->currentText() == "трапеция") {
        double length = ui->lineEdit->text().toDouble();
        double length2 = ui->lineEdit_2->text().toDouble();
        double heigth = ui->lineEdit_3->text().toDouble();
        result = calculator.CalculateTrapezoid(length, length2, heigth);
    } else if (ui->figureComboBox->currentText() == "круг") {
        double radius = ui->lineEdit->text().toDouble();
        result = calculator.CalculateCircle(radius);
    } else if (ui->figureComboBox->currentText() == "сектор") {
        double radius = ui->lineEdit->text().toDouble();
        double angle = ui->lineEdit_2->text().toDouble();
        result = calculator.CalculateSector(radius, angle);
    }

    ui->resultLabel->setText("= " + QString::number(result));
}

void MainWindow::on_figureComboBox_currentIndexChanged(int index)
{
    idx = index;
    clearFields();
    // Скрываем все поля ввода
    ui->lineEdit->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    // Добавьте скрытие других полей ввода для других фигур

    // Показываем поля ввода для выбранной фигуры
    if (index == 0) { // Квадрат
        ui->imageLabel->setPixmap(QPixmap("../square/images/square.png"));
        ui->formulaLable->setText("Формула: S = a * a");
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setPlaceholderText("длина");
    } else if (index == 1) { // Прямоугольник
        ui->imageLabel->setPixmap(QPixmap("../square/images/rectangle.png").scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        ui->formulaLable->setText("Формула: S = a * b");
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setPlaceholderText("длина");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_2->setPlaceholderText("ширина");
    } else if (index == 2) {
        ui->imageLabel->setPixmap(QPixmap("../square/images/parallelogramm.png").scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        ui->formulaLable->setText("Формула: S = a * h");
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setPlaceholderText("длина");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_2->setPlaceholderText("высота");
    } else if (index == 3) {
        ui->imageLabel->setPixmap(QPixmap("../square/images/rhombus.png").scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        ui->formulaLable->setText("Формула: S = a * h");
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setPlaceholderText("длина");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_2->setPlaceholderText("высота");
    } else if (index == 4) {
        ui->imageLabel->setPixmap(QPixmap("../square/images/triangle.png").scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        ui->formulaLable->setText("Формула: S = a * h");
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setPlaceholderText("длина");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_2->setPlaceholderText("высота");
    } else if (index == 5) {
        ui->imageLabel->setPixmap(QPixmap("../square/images/trapezoid.png").scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        ui->formulaLable->setText("Формула: S = h * (a + b) / 2");
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setPlaceholderText("длина");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_2->setPlaceholderText("вторая длина");
        ui->lineEdit_3->setVisible(true);
        ui->lineEdit_3->setPlaceholderText("высота");
    } else if (index == 6) {
        ui->imageLabel->setPixmap(QPixmap("../square/images/circle.png").scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        ui->lineEdit->setVisible(true);
        ui->formulaLable->setText("Формула: S = pi * r * r");
        ui->lineEdit->setPlaceholderText("радиус");
    } else if (index == 7) {
        ui->imageLabel->setPixmap(QPixmap("../square/images/sector.png").scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        ui->formulaLable->setText("Формула: S = a * pi * r * r / 360");
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setPlaceholderText("радиус");
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_2->setPlaceholderText("угол");
    }

}

void MainWindow::showAuthors()
{
    QMessageBox::information(this, "Авторы", "Имя автора: Grisha");
}

void MainWindow::clearFields()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->resultLabel->clear();
}
