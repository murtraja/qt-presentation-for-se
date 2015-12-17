#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include "topics.h"
#include <vector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    vector<string> topics;
    int currentTopic;
    void setTopic(int index);
    void setTopic();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_le_password_returnPressed();

    void on_pb_login_clicked();

    void on_pb_goback_clicked();

    void on_pb_first_clicked();

    void on_pb_prev_clicked();

    void on_pb_next_clicked();

    void on_pb_last_clicked();

private:
    Ui::MainWindow *ui;
    QString username, password;
};

#endif // MAINWINDOW_H
