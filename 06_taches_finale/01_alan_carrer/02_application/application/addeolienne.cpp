#include "addeolienne.h"
#include "ui_addeolienne.h"

addEolienne::addEolienne(QSqlDatabase *db, QWidget *parent) : QWidget(parent), ui(new Ui::addEolienne)
{
    ui->setupUi(this);
    this->setWindowTitle("Banc de test eolienne | Ajouter eolienne");

    this->db = db;
    this->file_name = "";
}

addEolienne::~addEolienne()
{
    delete ui;
}

void addEolienne::on_pushButton_clicked()
{
    if(ui->txt_fab->text() != NULL || ui->txt_model->text() !=NULL || ui->txt_type->text() != NULL){
        eolienne = new Ceolienne(ui->txt_model->text(), ui->txt_type->text(),ui->txt_fab->text(),this->file_name);
        if(eolienne->insertDB(*db)){
            ui->txt_fab->clear();
            ui->txt_model->clear();
            ui->txt_type->clear();
            this->file_name = "";
            QMessageBox::information(this, tr("Ajout éolienne"),
                                           tr("L'éolienne a bien été ajouté."),
                                           QMessageBox::Ok);
        }
        else{
            QMessageBox::critical(this, tr("Ajout éolienne"),
                                        tr("Une erreur a été rencontrée lors de la connexion avec la base de données."
                                           "Veuillez contacter votre administrateur réseau pour plus d'informations"),
                                           QMessageBox::Ok);
        }
    }
    else{
        QMessageBox::critical(this, tr("Ajout éolienne"),
                                    tr("L'un des champs demandé n'a pas été complété."),
                                    QMessageBox::Ok);
    }
}

void addEolienne::on_toolButton_clicked()
{
    this->file_name = QFileDialog::getOpenFileName(this,"Sélectionner la documentation", "C://");
}
