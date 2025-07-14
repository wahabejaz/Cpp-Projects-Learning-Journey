#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect buttons to handleButtonClick()
    buttons[0] = ui->btn1;
    buttons[1] = ui->btn2;
    buttons[2] = ui->btn3;
    buttons[3] = ui->btn4;
    buttons[4] = ui->btn5;
    buttons[5] = ui->btn6;
    buttons[6] = ui->btn7;
    buttons[7] = ui->btn8;
    buttons[8] = ui->btn9;

    for (int i = 0; i < 9; i++) {
        connect(buttons[i], &QPushButton::clicked, this, &MainWindow::handleButtonClick);
    }

    connect(ui->btnReset, &QPushButton::clicked, this, &MainWindow::resetGame);

    // Initialize board and player
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';

    currentPlayer = 'X';
    ui->labelStatus->setText("Player X's turn");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButtonClick()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    // Find index of clicked button
    int index = -1;
    for (int i = 0; i < 9; i++) {
        if (buttons[i] == clickedButton) {
            index = i;
            break;
        }
    }

    if (index == -1) return;

    int row = index / 3;
    int col = index % 3;

    // Ignore if already marked
    if (board[row][col] != ' ') return;

    // Update board + button
    board[row][col] = currentPlayer;
    clickedButton->setText(QString(currentPlayer));
    clickedButton->setEnabled(false);

    if (checkWin()) {
        ui->labelStatus->setText(QString("🎉 Player %1 wins!").arg(currentPlayer));
        disableAllButtons();
    }
    else if (checkDraw()) {
        ui->labelStatus->setText("🤝 It's a draw!");
    }
    else {
        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        ui->labelStatus->setText(QString("Player %1's turn").arg(currentPlayer));
    }
}

void MainWindow::resetGame()
{
    for (int i = 0; i < 9; i++) {
        buttons[i]->setText("");
        buttons[i]->setEnabled(true);
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';

    currentPlayer = 'X';
    ui->labelStatus->setText("Player X's turn");
}

bool MainWindow::checkWin()
{
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

bool MainWindow::checkDraw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void MainWindow::disableAllButtons()
{
    for (int i = 0; i < 9; i++) {
        buttons[i]->setEnabled(false);
    }
}
