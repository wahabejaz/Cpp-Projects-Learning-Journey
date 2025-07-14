#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick();
    void resetGame();

private:
    Ui::MainWindow *ui;           // Pointer to auto-generated UI
    QPushButton* buttons[9];      // Array of 9 buttons
    char board[3][3];             // 3x3 board array
    char currentPlayer;           // 'X' or 'O'

    bool checkWin();              // Win condition
    bool checkDraw();             // Draw condition
    void disableAllButtons();     // Disable all after game ends
};

#endif // MAINWINDOW_H
