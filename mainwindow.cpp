#include "mainwindow.h"
#include "calendrier.h"
#include "stat_combo.h"
#include "ui_mainwindow.h"
#include "event.h"
#include "QMessageBox"
#include "QApplication"
#include<QDateEdit>
#include<QDateTimeEdit>
#include<QIntValidator>
#include<QTableView>
#include <QTextDocument>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_CIN_EV_aj->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_NB_EV->setValidator(new QIntValidator(0, 99999, this));
    ui->lineEdit_NB_EV_mod->setValidator(new QIntValidator(0, 99999, this));
    ui->lineEdit_CIN_EV_mod->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_CIN_EV_supp->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_ID_EV->setValidator(new QIntValidator(0, 9999999, this));
    ui->lineEdit_ID_EV_MOD->setValidator(new QIntValidator(0, 9999999, this));








    ui->tableView_EV->setModel(Etmp.afficher_ev());
    ui->tableView_his->setModel(Etmp.afficher_his());
    ui->tableView_rech_tri->setModel(Etmp.afficher_ev());
    ui->lineEdit_rech->setPlaceholderText(QString("Chercher..."));
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
    //ui->stackedWidget->setCurrentIndex(5);
    Calendrier *cal = new Calendrier();
    cal->resize(600,600);
    cal->show();
}

void MainWindow::on_pushButton_STATISTIQUES_clicked()
{


        s = new stat_combo();

      s->setWindowTitle("statistique des types");
      s->choix_pie();
      s->show();


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


////////////////////////////////////////////////// recherche //////////////////////////////////////////////////////////////











/////////////////////////////////////////////// pdf /////////////////////////////////////////////////////////////////


void MainWindow::on_pushButton_PDF_clicked()
{


    QMessageBox::information(nullptr,QObject::tr("DONE"),
            QObject::tr("Fichier PDF generer\n""Click Cancel to exit."),QMessageBox::Cancel);


    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView_EV->model()->rowCount();
                const int columnCount =ui->tableView_EV->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                            "<h1>Liste des Evenements</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#f0f0f0>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView_EV->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView_EV->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";
                    // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tableView_EV->isColumnHidden(column)) {
                                   QString data = ui->tableView_EV->model()->data(ui->tableView_EV->model()->index(row, column)).toString().simplified();
                                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                               }
                           }
                           out << "</tr>\n";
                       }
                       out <<  "</table>\n"
                           "</body>\n"
                           "</html>\n";



        QTextDocument *document = new QTextDocument();
        document->setHtml(strStream);


        //QTextDocument document;
        //document.setHtml(html);
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("EVENTS.pdf");
        document->print(&printer);

}




void MainWindow::on_lineEdit_rech_textChanged()
{
    QString search=ui->lineEdit_rech->text();
    ui->tableView_rech_tri->setModel(Etmp.rechercher(search));
}

