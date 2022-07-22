#ifndef INFORMATIONDIALOG_H
#define INFORMATIONDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "secdialog.h"


namespace Ui {
class InformationDialog;
}

class InformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InformationDialog(QWidget *parent = nullptr);  
    void onMessageSent(const QString &);
    ~InformationDialog();
public slots:
    void initialize(QString s, QSqlDatabase d);
private slots:
    //void onMessageSent(const QString &);
    void on_pushButton_clicked();

private:
    Ui::InformationDialog *ui;
    QString values;
    QString seriNo;
    QMainWindow* _mainWindow;

    QSqlDatabase database;
};

#endif // INFORMATIONDIALOG_H
