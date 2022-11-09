#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "QMessageBox"
#include "QApplication"
#include<QDateEdit>
#include<QDateTimeEdit>
#include<QIntValidator>
#include<QTableView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_CIN_EV_aj->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_ID_EV->setValidator(new QIntValidator(0, 9999999, this));
    ui->tableView_EV->setModel(Etmp.afficher_ev());
    ui->tableView_his->setModel(Etmp.afficher_his());
    //ui->tableView_rech_tri->setModel(Etmp.rechercher_ev());
    //ui->tableView_rech_tri->setModel(Etmp.afficher_ev());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_close_clicked()
{

}

void MainWindow::on_pushButton_gestion_event_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_HISTORIQUES_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);


}

void MainWindow::on_pushButton_RECH_TRI_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_Calendrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_STATISTIQUES_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}




void MainWindow::on_pushButton_retour_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_retour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_retour_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_retour_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(2);
}

//Boutons pour acceder aux operations ********************

void MainWindow::on_pushButton_ajouter_ev_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_pushButton_Eliminer_ev_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
     ui->stackedWidget_2->setCurrentIndex(3);
}


void MainWindow::on_pushButton_liste_ev_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
     ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_modifier_vrai_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ajouter_vrai_clicked()
{
   // Recuperer les informations saisie dans les 6 champs
   int CIN_EV=ui->lineEdit_CIN_EV_aj->text().toInt();
   int NB_INV_EV=ui->lineEdit_NB_EV->text().toInt();
   int ID_EV=ui->lineEdit_ID_EV->text().toInt();
   QString NOM_EV=ui->lineEdit_NOM_EV->text();
   QString TYPE_EV=ui->lineEdit_TYPE_EV->text();
   QDateTime DATE_EV=ui->dateEdit_DATE_EV->dateTime();
   Event e(CIN_EV,ID_EV,NB_INV_EV,NOM_EV,TYPE_EV,DATE_EV);
   bool test=e.ajouter_ev();

if(test)
{
    //Refresh
    ui->tableView_EV->setModel(Etmp.afficher_ev());
    ui->tableView_his->setModel(Etmp.afficher_his());

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("Ajout effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
}
    else
{
    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
            QObject::tr("Ajout non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
}


ui->lineEdit_CIN_EV_aj->setText("");
ui->lineEdit_NB_EV->setText("");
ui->lineEdit_ID_EV->setText("");
ui->lineEdit_NOM_EV->setText("");
ui->lineEdit_TYPE_EV->setText("");
//ui->dateTimeEdit_DATE_EV_rech->setDateTime();

}


void MainWindow::on_pushButton_supprimer_vrai_clicked()
{
    int ID_EV=ui->lineEdit_CIN_EV_supp->text().toInt();

    bool test=Etmp.supprimer_ev(ID_EV);

    if(test)
    {
        //Refresh
        ui->tableView_EV->setModel(Etmp.afficher_ev());
        ui->tableView_his->setModel(Etmp.afficher_his());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("suppression effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("suppression non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
}



void MainWindow::on_pushButton_modifier_vrai_2_clicked()
{
    int CIN_EV = ui->lineEdit_CIN_EV_mod->text().toInt();
    int NB_INV_EV=ui->lineEdit_NB_EV_mod->text().toInt();
    int ID_EV = ui->lineEdit_ID_EV_MOD->text().toInt();
    QString NOM_EV=ui->lineEdit_NOM_EV_mod->text();
    QString TYPE_EV=ui->lineEdit_TYPE_EV_mod->text();
    QDateTime DATE_EV=ui->dateEdit_DATE_EV_mod->dateTime();

    Event e(CIN_EV,ID_EV,NB_INV_EV,NOM_EV,TYPE_EV,DATE_EV);
    bool test=e.modifier_ev(ID_EV,CIN_EV,NB_INV_EV);

            if(test)
            {
                //refresh
                ui->tableView_EV->setModel(e.afficher_ev());
                ui->tableView_his->setModel(Etmp.afficher_his());


                       QMessageBox::information(nullptr, QObject::tr("effectué"),
                            QObject::tr(" Modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                       ui->lineEdit_ID_EV_MOD->clear();
                       ui->lineEdit_CIN_EV_mod->clear();
                       ui->lineEdit_NOM_EV_mod->clear();
                       ui->lineEdit_TYPE_EV_mod->clear();
                       ui->dateEdit_DATE_EV_mod->clear();
                       ui->lineEdit_NB_EV_mod->clear();
           }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("non effectué"),
                            QObject::tr("non modifié !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->lineEdit_ID_EV_MOD->clear();
                ui->lineEdit_CIN_EV_mod->clear();
                ui->lineEdit_NOM_EV_mod->clear();
                ui->lineEdit_TYPE_EV_mod->clear();
                ui->dateEdit_DATE_EV_mod->clear();
                ui->lineEdit_NB_EV_mod->clear();


            }

}




void MainWindow::on_pushButton_trier_vrai_clicked()

{
    if(ui->radioButton_date->isChecked())
    {
     bool test=Etmp.afficher_tri_date();


     if(test)
     {
                  //Refresh
                  ui->tableView_EV->setModel(Etmp.afficher_tri_date());

         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("TRI par date effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                 QObject::tr("TRI par date non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}

    else if(ui->radioButton_nom->isChecked())
    {
     bool test=Etmp.afficher_tri_nom();


     if(test)
     {
                  //Refresh
                  ui->tableView_EV->setModel(Etmp.afficher_tri_nom());

         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("TRI par nom effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                 QObject::tr("TRI par nom non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}



    else if(ui->radioButton_nb_inv->isChecked())
    {
     bool test=Etmp.afficher_tri_nb_inv();


     if(test)
     {
                  //Refresh
                  ui->tableView_EV->setModel(Etmp.afficher_tri_nb_inv());

         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("TRI par nom effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                 QObject::tr("TRI par nom non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void MainWindow::on_pushButton_chercher_vrai_clicked()
{


    int CIN_EV = ui->lineEdit_CIN_EV_rech->text().toInt();
    int NB_INV_EV=ui->lineEdit_NB_EV_rech->text().toInt();
    int ID_EV = ui->lineEdit_ID_EV_rech->text().toInt();




    ui->tableView_rech_tri->setModel(Etmp.rechercher_ev(QString));


}

*/
/*

void MainWindow::on_pushButton_chercher_vrai_clicked()
{

    //     QString id=ui-> lineEdit_14->text();

   // ui->tableView_colloborateur->setModel( tempcolloborateur.rechercher(id));



    int ID_EV=ui->lineEdit_CIN_EV_rech->text().toInt();

    bool test=Etmp.rechercher_ev(ID_EV);

    if(test)
    {
        //Refresh

        ui->tableView_rech_tri->setModel(Etmp.rechercher_ev(ID_EV));
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("rech effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("rech non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
}

*/
