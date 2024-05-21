#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_rulesName.append("1");
    m_rulesName.append("2");
    m_rulesName.append("3");
    m_rulesName.append("4");
    m_rulesName.append("5");

    for(int i = 0; i < m_rulesName.count(); i++)
    {
        addRule(i);
    }

    connect(this, &MainWindow::itemStateChange, this, &MainWindow::ruleStateChange);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ruleStateChange(int checkState, int ruleIndex)
{
    // 根据ruleIndex找到对应的rule

    // 根据checkState执行添加或取消rule
    if(checkState == Qt::Checked)
    {

    }
    else
    {

    }
}

void MainWindow::addRule(int ruleIndex)
{
    QListWidgetItem* item = new QListWidgetItem(m_rulesName.at(ruleIndex), ui->listWidget);
    // Set the font color of the item
    QColor color_red(255, 0, 0);  // Red color
    QColor color_white(255, 255, 255);  // Red white
    item->setBackground(color_red);
    item->setForeground(color_white);
    item->setCheckState(Qt::Unchecked);
}

void MainWindow::on_btnSelectAll_clicked()
{
    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        item->setCheckState(Qt::Checked);
        emit itemStateChange(Qt::Checked, i);
    }
}


void MainWindow::on_btnDisselectAll_clicked()
{
    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        item->setCheckState(Qt::Unchecked);
        emit itemStateChange(Qt::Checked, i);
    }
}


void MainWindow::on_btnRun_clicked()
{

}


void MainWindow::on_btnReset_clicked()
{

}

