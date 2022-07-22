    #include "servisdialog.h"
#include "ui_servisdialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include "notekledialog.h"
#include <QMenu>
#include "mainwindow.h"

ServisDialog::ServisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServisDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(" ");
}

ServisDialog::~ServisDialog()
{
    delete ui;
}
void ServisDialog::initialize(QSqlDatabase d,QString sNo) {
    ui->servisNo_->setText(sNo);
    database = d;
}
void ServisDialog::on_pushButton_clicked()
{

    if(database.open()) {

        servisNo = ui->servisNo_->text();
        gelisTarihi = ui->gelisTarihiYear_->text() + "-" + ui->gelisTarihiMonth_->text() + "-" + ui->gelisTarihiDay_->text();
        musteriAdi = ui->musteriAdi_->text();
        arizaTarifi = ui->arizaTanimi_->text();
        yapilanIslem = ui->yapilanIslem_->text();
        malzemeler = "";

        if(ui->donanim_1->isChecked()) {
            malzemeler += ui->donanim_1->text() + ", ";
        }if(ui->donanim_2->isChecked()) {
            malzemeler += ui->donanim_2->text() + ", ";
        }if(ui->donanim_3->isChecked()) {
            malzemeler += ui->donanim_3->text() + ", ";
        }if(ui->donanim_4->isChecked()) {
            malzemeler += ui->donanim_4->text() + ", ";
        }if(ui->donanim_5->isChecked()) {
            malzemeler += ui->donanim_5->text() + ", ";
        }if(ui->donanim_6->isChecked()) {
            malzemeler += ui->donanim_6->text() + ", ";
        }if(ui->donanim_7->isChecked()) {
            malzemeler += ui->donanim_7->text() + ", ";
        }if(ui->donanim_8->isChecked()) {
            malzemeler += ui->donanim_8->text() + ", ";
        }if(ui->donanim_9->isChecked()) {
            malzemeler += ui->donanim_9->text() + ", ";
        }if(ui->donanim_10->isChecked()) {
            malzemeler += ui->donanim_10->text() + ", ";
        }if(ui->donanim_11->isChecked()) {
            malzemeler += ui->donanim_11->text();
        }
        tamirBitisTarihi = ui->bitisTarihiDay_->text(); + "." + ui->bitisTarihiMonth_->text() + "." + ui->bitisTarihiYear_->text();
        testSuresi = ui->testSuresi_->text();
        sevkTarihi = ui->sevkTarihiDay_->text() + "." + ui->sevkTarihiMonth_->text() + "." + ui->sevkTarihiYear_->text();
        notlar = "";

        //QSqlQuery qry;
        /*
        qry.prepare("INSERT INTO teknikservis(`Servis No`,`UID No`,`Geliş Tarihi`,"
                    "`Müşteri Adı`,`Arıza Tarifi`,`Yapılan İşlem`,`Cihazla Gelen Malzemeler`,"
                    "`Tamir Bitiş Tarihi`,`Test Süresi`,`Sevk Tarihi`,`Notlar`)"
                    "VALUES(:servisNo,:uidNo,:gelisTarihi,"
                    ":musteriAdi,:arizaTarifi,:yapilanIslem,:malzemeler,"
                    ":tamirBitisTarih,:testSuresi,:sevkTarihi,:notlar)");
        qry.bindValue(":servisNo",servisNo);
        qry.bindValue(":uidNo",UIDno);
        qry.bindValue(":gelisTarihi",gelisTarihi);
        qry.bindValue(":musteriAdi",musteriAdi);
        qry.bindValue(":arizaTarifi",arizaTarifi);
        qry.bindValue(":yapilanIslem",yapilanIslem);
        qry.bindValue(":malzemeler",malzemeler);
        qry.bindValue(":tamirBitisTarih",tamirBitisTarihi);
        qry.bindValue(":testSuresi",testSuresi);
        qry.bindValue(":sevkTarihi",sevkTarihi);

        if(qry.exec()) {
            QMessageBox::information(this,"Inserted", "Data Inserted Succesfully");
        }else {
            QMessageBox::information(this,"Not Inserted",qry.lastError().text());
        }
*/


        NotEkleDialog *idNot = new NotEkleDialog();
        idNot->initialize(servisNo,database,malzemeler,UIDno,gelisTarihi,
                          musteriAdi,arizaTarifi,yapilanIslem,
                          tamirBitisTarihi,testSuresi,sevkTarihi);
        idNot->show();



        this->close();
    }else {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }



}

