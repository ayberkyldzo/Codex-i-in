#include "CalculatorWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QInputDialog>
#include <QMessageBox>

CalculatorWindow::CalculatorWindow(QWidget *parent) : QMainWindow(parent) {
    createMenus();
    setWindowTitle("Calculator");
    resize(400, 300);
}

void CalculatorWindow::createMenus() {
    QMenu *operationMenu = menuBar()->addMenu("Operations");
    QAction *addAction = operationMenu->addAction("Add");
    connect(addAction, &QAction::triggered, this, &CalculatorWindow::onAdd);

    QAction *subtractAction = operationMenu->addAction("Subtract");
    connect(subtractAction, &QAction::triggered, this, &CalculatorWindow::onSubtract);

    QAction *multiplyAction = operationMenu->addAction("Multiply");
    connect(multiplyAction, &QAction::triggered, this, &CalculatorWindow::onMultiply);

    QAction *divideAction = operationMenu->addAction("Divide");
    connect(divideAction, &QAction::triggered, this, &CalculatorWindow::onDivide);

    operationMenu->addSeparator();
    QAction *quitAction = operationMenu->addAction("Quit");
    connect(quitAction, &QAction::triggered, this, &CalculatorWindow::close);
}

static bool getTwoNumbers(double &a, double &b, QWidget *parent) {
    bool ok1, ok2;
    a = QInputDialog::getDouble(parent, "Input", "First number:", 0, -1e9, 1e9, 2, &ok1);
    if (!ok1) return false;
    b = QInputDialog::getDouble(parent, "Input", "Second number:", 0, -1e9, 1e9, 2, &ok2);
    if (!ok2) return false;
    return true;
}

void CalculatorWindow::onAdd() {
    double a, b;
    if (!getTwoNumbers(a, b, this)) return;
    double result = a + b;
    QMessageBox::information(this, "Result", QString("%1 + %2 = %3").arg(a).arg(b).arg(result));
}

void CalculatorWindow::onSubtract() {
    double a, b;
    if (!getTwoNumbers(a, b, this)) return;
    double result = a - b;
    QMessageBox::information(this, "Result", QString("%1 - %2 = %3").arg(a).arg(b).arg(result));
}

void CalculatorWindow::onMultiply() {
    double a, b;
    if (!getTwoNumbers(a, b, this)) return;
    double result = a * b;
    QMessageBox::information(this, "Result", QString("%1 * %2 = %3").arg(a).arg(b).arg(result));
}

void CalculatorWindow::onDivide() {
    double a, b;
    if (!getTwoNumbers(a, b, this)) return;
    if (b == 0) {
        QMessageBox::warning(this, "Error", "Cannot divide by zero.");
        return;
    }
    double result = a / b;
    QMessageBox::information(this, "Result", QString("%1 / %2 = %3").arg(a).arg(b).arg(result));
}

