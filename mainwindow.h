#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"event.h"
#include"fourniseur.h"
#include <QMainWindow>
#include <QFileDialog>
//zaykaaa
//test conection github.

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_fournisseur_clicked();

    void on_pushButton_ajouter_Frs_clicked();

    void on_pushButton_liste_Frs_clicked();

    void on_pushButton_ajouter_f_clicked();

    void on_pushButton_Eliminer_ev_2_clicked();

    void on_pushButton_Eliminer_ev_3_clicked();

    void on_pushButton_chercher_vrai_8_clicked();

    void on_pushButton_Eliminer_F_clicked();

    void on_pushButton_chercher_vrai_7_clicked();

    void on_pushButton_chercher_vrai_6_clicked();

    void on_pushButton_modifier_f_clicked();

    void on_pushButton_MENU_clicked();

    void on_pushButton_MENU_2_clicked();

    void on_pushButton_MENU_3_clicked();

    void on_pushButton_MENU_4_clicked();

    void on_pushButton_RECH_TRI_2_clicked();

    void on_pushButton_MENU___clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_chercher_clicked();

    void on_pushButton_stat_clicked();

    void on_btn_img_clicked();

    void on_radioButton_gat_clicked();

    void on_pushButton_STATISTIQUES_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_exPDF_clicked();

    void on_pushButton_MENU_6_clicked();

    void on_pushButton_RECH_TRI_3_clicked();

    void on_pb_affiche_C_clicked();

    void on_pushButton_Calendrier_3_clicked();

    void on_pushButton_MENU__1_clicked();

    void on_pushButton_monatnt_fact_clicked();

    void on_pushButton_monatnt_fact_2_clicked();

    void on_pushButton_FACTURE_clicked();

private:
    Ui::MainWindow * ui;
    Fourniseur Etmp1;
};
#endif // MAINWINDOW_H
