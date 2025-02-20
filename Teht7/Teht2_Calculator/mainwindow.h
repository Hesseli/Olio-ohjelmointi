#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void numbers();
    void operators();
    void clearEnter();

private:
    Ui::MainWindow *ui;

    QString currentOperator;
    int currentBox;
};
#endif // MAINWINDOW_H
