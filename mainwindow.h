#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>

QT_BEGIN_NAMESPACE

class QStringListModel;
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

signals:
    void itemStateChange(int checkState, int ruleIndex);

private slots:
    void ruleStateChange(int checkState, int ruleIndex);

    void on_btnSelectAll_clicked();

    void on_btnDisselectAll_clicked();

    void on_btnRun_clicked();

    void on_btnReset_clicked();

private:
    Ui::MainWindow *ui;

    QStringList m_rulesName;

    void addRule(int ruleIndex);

};
#endif // MAINWINDOW_H
