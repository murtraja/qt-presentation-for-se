#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "topics.cpp"

void MainWindow::setTopic(int index)
{
    ui->te_topics->setPlainText(QString::fromStdString(topics[index]));
}

void MainWindow::setTopic()
{
    ui->te_topics->setPlainText(QString::fromStdString(topics[this->currentTopic]));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    username = "mmr";
    password = "idk";
    currentTopic = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_le_password_returnPressed()
{
    QString username = ui->le_username->text();
    QString password = ui->le_password->text();
    if(this->username == username && this->password==password)
    {
        QMessageBox::information(this, "Authentication", "Welcome "+this->username.toUpper()+"!", QMessageBox::Ok);
        //start populating topics from the text file
        Topics tp;
        this->topics = tp.getTopics();
        setTopic(currentTopic);
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        //display proper message here!
        QMessageBox::warning(this, "Authentication", "Wrong Credentials!", QMessageBox::Ok);
    }
    ui->pb_login->click();
    ui->le_username->setFocus();
}

/*
 * The Login button does (almost) nothing when clicked
 */
void MainWindow::on_pb_login_clicked()
{
    ui->le_password->clear();
    ui->le_username->clear();
}

void MainWindow::on_pb_goback_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Go back to authentication screen");
    msgBox.setInformativeText("Are you sure?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    switch(ret)
    {
        case QMessageBox::Yes:
        ui->stackedWidget->setCurrentIndex(0);
        break;

    case QMessageBox::No:
    case QMessageBox::Cancel:
        break;
    }
}

void MainWindow::on_pb_first_clicked()
{
    this->currentTopic=0;
    this->setTopic();
}

void MainWindow::on_pb_prev_clicked()
{
    if(currentTopic==0)
    {
        //cannot go back, this is the first topic
    }
    else
    {
        this->currentTopic-=1;
        setTopic();
    }
}

void MainWindow::on_pb_next_clicked()
{
    if(currentTopic == topics.size()-1)
    {
        //cannot go forward, this is the last topic
        QMessageBox::information(this, "Presentation", "Ho gaya bhai!", QMessageBox::Ok);

    }
    else
    {
        this->currentTopic+=1;
        setTopic();
    }
}

void MainWindow::on_pb_last_clicked()
{
    this->currentTopic=this->topics.size()-1;
    setTopic();
}
