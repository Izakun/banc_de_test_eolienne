#include "createscenario.h"
#include "ui_createscenario.h"

createScenario::createScenario(QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createScenario)
{
    ui->setupUi(this);
    this->db = db;
    Actu();
}

createScenario::~createScenario()
{
    delete ui;
}

void createScenario::on_btn_create_clicked()
{
    if(ui->txt_scenario->text() != NULL || ui->txt_scenario->text() != NULL){
        scenario = new CScenario(ui->txt_scenario->text());
        if(scenario->insertDB(*db)){
            Actu();
            ui->txt_scenario->clear();
            QMessageBox::information(this, tr("Création scénario"),
                                           tr("Le scénario a bien été créé."),
                                           QMessageBox::Ok);
        }
        else{
            QMessageBox::critical(this, tr("Création scénario"),
                                        tr("Une erreur a été rencontrée lors de la connexion avec la base de données."
                                           "Veuillez contacter votre administrateur réseau pour plus d'informations"),
                                           QMessageBox::Ok);
        }
    }
    else{
        QMessageBox::critical(this, tr("Création scénario"),
                                    tr("Vous n'avez pas rentré de nom pour le scénario."),
                                    QMessageBox::Ok);
    }
}

void createScenario::on_btn_add_clicked()
{
    if(ui->combo_scenario->currentData() != NULL || ui->txt_phase->text() != NULL || ui->nb_power->value() != NULL || ui->nb_time->value() !=NULL){
        phase = new Cphase(ui->combo_scenario->currentData().toInt() ,ui->nb_time->value(),ui->nb_power->value());
        if(phase->insertDB(*db)){
            ui->txt_scenario->clear();
            ui->tab_db->clear();
            QMessageBox::information(this, tr("Ajouter phase"),
                                           tr("La phase a bien été ajouté."),
                                           QMessageBox::Ok);
            Actu();
        }
        else{
            QMessageBox::critical(this, tr("Ajouter phase"),
                                        tr("Une erreur a été rencontrée lors de la connexion avec la base de données."
                                           "Veuillez contacter votre administrateur réseau pour plus d'informations"),
                                           QMessageBox::Ok);
        }
    }
    else{
        QMessageBox::critical(this, tr("Ajouter phase"),
                                    tr("Vous n'avez pas complété touts les champs demandé."),
                                    QMessageBox::Ok);
    }

}

void createScenario::Actu()
{
    ui->combo_scenario->clear();
    this->db = db;
    query.prepare("SELECT * FROM scenario");
    query.exec();
    if(query.size()>0) while(query.next()) ui->combo_scenario->addItem(query.value("nom").toString().toUtf8().constData(), query.value("id")); //currentData to select id

    query.prepare("SELECT temps, puissance FROM phase WHERE fk_scenario=?");
    query.addBindValue(ui->combo_scenario->currentData().toInt());
    query.exec();
    ui->tab_db->setColumnCount(2);
    QStringList TabHeader;
    TabHeader<<"Temps"<<"Puissance";
    ui->tab_db->setHorizontalHeaderLabels(TabHeader);
    while(query.next()){
        ui->tab_db->insertRow( ui->tab_db->rowCount() );
        ui->tab_db->setItem(ui->tab_db->rowCount()-1,0, new QTableWidgetItem("essai") ) ; //new QTableWidgetItem(query.value("temps").toInt()));
        ui->tab_db->setItem(ui->tab_db->rowCount()-1,1, new QTableWidgetItem(query.value("puissance").toString()));
    }
}
