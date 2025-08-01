#ifndef CALCULATORWINDOW_H
#define CALCULATORWINDOW_H

#include <QMainWindow>

class CalculatorWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit CalculatorWindow(QWidget *parent = nullptr);

private slots:
    void onAdd();
    void onSubtract();
    void onMultiply();
    void onDivide();

private:
    void createMenus();
};

#endif // CALCULATORWINDOW_H
