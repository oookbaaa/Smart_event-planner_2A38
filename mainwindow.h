#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"event.h"
#include <QMainWindow>

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
    void on_close_clicked();

    void on_pushButton_gestion_event_clicked();

    void on_pushButton_HISTORIQUES_clicked();

    void on_pushButton_RECH_TRI_clicked();

    void on_pushButton_STATISTIQUES_clicked();

    void on_pushButton_Calendrier_clicked();

    void on_pushButton_retour_clicked();

    void on_pushButton_retour_1_clicked();

    void on_pushButton_retour_2_clicked();

    void on_pushButton_retour_3_clicked();

    void on_pushButton_retour_4_clicked();

    void on_pushButton_retour_5_clicked();

//Boutons pour acceder aux operations ********************
    void on_pushButton_ajouter_ev_clicked();

    void on_pushButton_Eliminer_ev_clicked();

    void on_pushButton_liste_ev_clicked();


//Boutons des operations ********************
    void on_pushButton_ajouter_vrai_clicked();

    void on_pushButton_supprimer_vrai_clicked();




    void on_pushButton_modifier_vrai_clicked();

    void on_pushButton_modifier_vrai_2_clicked();

    void on_pushButton_retour_6_clicked();

private:
    Ui::MainWindow *ui;
    Event Etmp;
};
#endif // MAINWINDOW_H
