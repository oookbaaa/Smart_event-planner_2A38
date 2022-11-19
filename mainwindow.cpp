#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fourniseur.h"
#include "QMessageBox"
#include "QApplication"
#include<QDateEdit>
#include "stat.h"
#include <QDebug>
#include <QBuffer>
#include <QResource>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_f->setModel(Etmp1.afficher());
    ui->tableView_2_pdf->setModel(Etmp1.afficher());
    ui->lineEdit_6->setValidator(new QIntValidator(1,9999, this));
    ui->lineEdit_7->setValidator(new QIntValidator(11111111, 99999999, this));
    ui->lineEdit_prix_f->setValidator(new QIntValidator(1, 999999999, this));
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    ui->lineEdit_4->setValidator(validator_String);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_fournisseur_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajouter_Frs_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_liste_Frs_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_ajouter_f_clicked()
{
    int id=ui->lineEdit_6->text().toUInt();
    int num_t=ui->lineEdit_7->text().toUInt();
    double prix=ui->lineEdit_prix_f->text().toUShort();
    QString produit=ui->lineEdit_5->text();
    QString nom_f=ui->lineEdit_4->text();
    QString img=ui->lin_path->text();
    Fourniseur f(nom_f,produit,img,prix,id,num_t);
    bool test=f.ajouter();

    if(test)
    {
        //Refresh

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("Ajout effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
        ui->tableView_f->setModel(Etmp1.afficher());
    }
        else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("Ajout non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
    }



}
void MainWindow::on_pushButton_Eliminer_F_clicked()
{
   ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_chercher_vrai_7_clicked()
{
    int id=ui->lineEdit_TYPE_Frs_13->text().toInt();
    bool test=Etmp1.supprimer(id);

    if(test)
    {
        //Refresh
        ui->tableView_f->setModel(Etmp1.afficher());

    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("suppression non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercher_vrai_6_clicked()
{
    {
               int id = ui->lineEdit_TYPE_Frs_10->text().toInt();
                QString nom_f= ui->lineEdit_NOM_Frs_14->text();
                 QString produit= ui->lineEdit_NOM_EV_15->text();
                 QString img= ui->lineEdit_NOM_EV_15->text();
                 double prix = ui->lineEdit_NOM_Frs_15->text().toUShort();
                 int num_t = ui->lineEdit_TYPE_Frs_11->text().toInt();


                Fourniseur f(nom_f,produit,img,prix,id,num_t);
                bool test=f.modifier_f(id);
                if(test)
                {

                    ui->tableView_f->setModel(f.afficher());//refresh


                           ui->lineEdit_TYPE_Frs_10->clear();
                           ui->lineEdit_NOM_Frs_14->clear();
                           ui->lineEdit_NOM_EV_15->clear();
                           ui->lineEdit_NOM_Frs_15->clear();
                           ui->lineEdit_TYPE_Frs_11->clear();
               }
                else
                {

                    ui->lineEdit_TYPE_Frs_10->clear();
                    ui->lineEdit_NOM_Frs_14->clear();
                    ui->lineEdit_NOM_EV_15->clear();
                    ui->lineEdit_NOM_Frs_15->clear();
                    ui->lineEdit_TYPE_Frs_11->clear();



                }

    }
}

void MainWindow::on_pushButton_modifier_f_clicked()
{
   ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_MENU_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_pushButton_MENU_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_MENU_3_clicked()
{
      ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_MENU_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_RECH_TRI_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_MENU___clicked()
{
   ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_trier_clicked()
{
    if(ui->radioButton->isChecked())
    {
     bool test=Etmp1.afficher_tri_prix();


     if(test)
     {
                  //Refresh
                  ui->tableView_tri->setModel(Etmp1.afficher_tri_prix());

         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("TRI par prix effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                 QObject::tr("TRI par prix non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}

    else if(ui->radioButton_2->isChecked())
    {
     bool test=Etmp1.afficher_tri_produit();


     if(test)
     {
                  //Refresh
                  ui->tableView_tri->setModel(Etmp1.afficher_tri_produit());

         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("TRI par produit effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                 QObject::tr("TRI par produit non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}



    else if(ui->radioButton_3->isChecked())
    {
     bool test=Etmp1.afficher_tri_nom_f();


     if(test)
     {
                  //Refresh
                  ui->tableView_tri->setModel(Etmp1.afficher_tri_nom_f());

         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("TRI par nom effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
     else
     {
         QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                 QObject::tr("TRI par nom non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}

}

void MainWindow::on_pushButton_chercher_clicked()
{

   QString str= ui->lineEdit_Chercher->text();
   bool test=Etmp1.rechercher(str);

    if(test)
    {
                 //Refresh
                 ui->tableView_tri->setModel(Etmp1.rechercher(str));

        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("rechercher a effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                QObject::tr("recherche non effectuer\n""Click Cancel to exit."),QMessageBox::Cancel);}

}
void MainWindow::on_btn_img_clicked()
{
    const QString folderPath = QFileDialog::getExistingDirectory(this, tr("Image folder"));
    if(!folderPath.isEmpty())
    {
        QDir dir(folderPath);
        QStringList filter;
        filter << QLatin1String("*.png");
        filter << QLatin1String("*.jpeg");
        filter << QLatin1String("*.jpg");
        dir.setNameFilters(filter);
        QFileInfoList filelistinfo = dir.entryInfoList();
        QStringList fileList;
        foreach (const QFileInfo &fileinfo, filelistinfo)
        {
            QString imageFile = fileinfo.absoluteFilePath();
            //imageFile is the image path, just put your load image code here


           ui->lbl_img->setPixmap(imageFile);
           ui->lin_path->setText(imageFile);

}
}
}

//       }
//       else {
//           // error
//       }
//   }
//}





void MainWindow::on_pushButton_stat_clicked()
{

        int res;
                statistiques w(this);
                w.setWindowTitle("Statistiques des prix");

                res = w.exec();
                qDebug() << res;
                if (res == QDialog::Rejected)
                  return;

}


void MainWindow::on_pushButton_STATISTIQUES_clicked()
{
   ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_pdf_clicked()
{

        QMessageBox::information(nullptr,QObject::tr("DONE"),
                    QObject::tr("Fichier PDF generer\n""Click Cancel to exit."),QMessageBox::Cancel);


            QString strStream;
                        QTextStream out(&strStream);
                        const int rowCount = ui->tableView_2_pdf->model()->rowCount();
                        const int columnCount =ui->tableView_2_pdf->model()->columnCount();


                        out <<  "<html>\n"
                                "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                <<  QString("<title>%1</title>\n").arg("eleve")
                                <<  "</head>\n"
                                "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                    "<h1>Liste des Fournisseurs</h1>"

                                    "<table border=1 cellspacing=0 cellpadding=2>\n";


                        // headers
                            out << "<thead><tr bgcolor=#f0f0f0>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tableView_2_pdf->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tableView_2_pdf->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";
                            // data table
                               for (int row = 0; row < rowCount; row++) {
                                   out << "<tr>";
                                   for (int column = 0; column < columnCount; column++) {
                                       if (!ui->tableView_2_pdf->isColumnHidden(column)) {
                                           QString data = ui->tableView_2_pdf->model()->data(ui->tableView_2_pdf->model()->index(row, column)).toString().simplified();
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
                printer.setOutputFileName("FOURNISSEURS.pdf");
                document->print(&printer);


}

void MainWindow::on_pushButton_exPDF_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_MENU_6_clicked()
{
 ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_RECH_TRI_3_clicked()
{
      ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pb_affiche_C_clicked()
{
    QString produit ;
    produit = ui->lineEdit_Chercher_5->text();

    QSqlQuery query(" SELECT* FROM FOURNISSEUR where produit like '"+produit+"%'");
       query.bindValue(0, produit);
       while (query.next()) {
               QString path = query.value(5).toString();
               QString prix = query.value(2).toString();
               QString nom = query.value(0).toString();
               QString nume = query.value(3).toString();
               QString id = query.value(4).toString();

               ui->label_img_C->setPixmap(path);
               ui->lineEdit_Chercher_4->setText(prix);
                ui->lineEdit_nom_CA->setText(nom);
                ui->lineEdit_num_ca->setText(nume);
                ui->lineEdit_id_ca->setText(id);
               qDebug() << path ;

                //ui->label_img_C2->setPixmap(path);
           }
}

void MainWindow::on_pushButton_Calendrier_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_MENU__1_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_monatnt_fact_clicked()
{
    double montant ;
    int   quntite;

    QString id ;
    id = ui->lineEdit_id_fact->text();
    quntite = ui->lineEdit_nb_inv->text().toInt();

    QSqlQuery query(" SELECT* FROM FOURNISSEUR where id like '"+id+"%'");
       query.bindValue(0, id);
       while (query.next()) {
            int prix = query.value(2).toString().toUInt();
            QString produit = query.value(1).toString();
            if(produit=="sale")
            {
                quntite =quntite/20 ;
            }
           else if(produit=="jus")  {
               quntite =quntite/4;

            }else{
                quntite= quntite;
            }
            montant=quntite*prix;
            qDebug() << montant ;
             QString montant_string= QString::number(montant);
            ui->lineEdit_montant_fact->setText(montant_string);


       }

}

void MainWindow::on_pushButton_monatnt_fact_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_FACTURE_clicked()
{
 ui->stackedWidget->setCurrentIndex(2);
}
