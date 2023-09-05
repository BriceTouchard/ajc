#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <list>
#include <tab.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabsClosable(true);
//    connect(ui->pushButtonOpen, SIGNAL(clicked( bool)), this, SLOT(Open(bool))); // ancienne syntaxe
    connect(ui->pushButtonOpen,   &QPushButton::clicked,          this, &MainWindow::OpenFile);
    connect(ui->pushButtonSave,   &QPushButton::clicked,          this, &MainWindow::SaveFile);
    connect(ui->pushButtonNewTab, &QPushButton::clicked,          this, &MainWindow::deleteStar);
    connect(ui->tabWidget,        &QTabWidget::tabCloseRequested, this, &MainWindow::CloseTab);
    connect(ui->tabWidget->currentWidget()->findChild<QTextEdit *>(), &QTextEdit::textChanged, this, &MainWindow::addStar);

//    QTextEdit* currentTextEdit = ui->tabWidget->currentWidget()->findChild<QTextEdit *>();
//    connect(currentTextEdit, &QTextEdit::textChanged, this, &MainWindow::addStar);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::Open a text file
 */
void MainWindow::OpenFile( bool){

    int index = ui->tabWidget->currentIndex(); // index de l'onglet
    QWidget* currentWidget = ui->tabWidget->currentWidget();  // Widget dans l'onglet courant
    QTextEdit* currentTextEdit = currentWidget->findChild<QTextEdit *>();   // TextEdit de l'onglet courant
    QString currentTabText = ui->tabWidget->tabText(index); // titre de l'onglet

    /// Ouvre un boite de dialogue et stocke le nom du fichier choisi dans "fileName"
    QString fileAdress = QFileDialog::getOpenFileName(this,
        tr("Ouvrir fichier texte"), "/home/brice/Qt", tr("Text files (*.txt);;XML files (*.xml)"));
    QString fileName = fileAdress.split(u'/').last();

    if(ui->tabWidget->count() != 0){
        if(currentTextEdit->toPlainText() != ""){ // Ouvre un nouvel onglet
            QWidget *newTab = new Tab(ui->tabWidget);
            ui->tabWidget->addTab(newTab, fileName);
            ui->tabWidget->setCurrentIndex(index+1);
        }else { // Si n a un onglet sans texte (au démarrage) change le titre (tabtext) de l'onglet courant
            ui->tabWidget->setTabText(index,fileName);
        }
    }else { // S'il n'y a pas d'onglet on en ajoute un
        QWidget *newTab = new Tab(ui->tabWidget);
        ui->tabWidget->addTab(newTab, fileName);
    }

    /// Lis les lignes du fichier sélectionné et les met dans le textEdit
    QFile file(fileAdress);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
           return;
       }
    QByteArray text;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        text.append(line);
    }
    currentTextEdit = ui->tabWidget->currentWidget()->findChild<QTextEdit *>();
    currentTextEdit->setText(text);
}

/**
 * @brief MainWindow::Save a text file
 */
void MainWindow::SaveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save File"),"/home/brice/Qt", tr("Text files (*.txt)"));

    QFile file( fileName );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        QTextEdit* currentTextEdit = ui->tabWidget->currentWidget()->findChild<QTextEdit *>();
        QString text = currentTextEdit->toPlainText();

        stream << text << Qt::endl;
    }
}

void MainWindow::CloseTab(int i)
{
    int index = ui->tabWidget->currentIndex();
    QString fileName = ui->tabWidget->tabText(index);
    if(fileName.contains("*")){
        QMessageBox msgBox;
        msgBox.setText("Le document a été modifié.");
        msgBox.setInformativeText("Voulez-vous sauvegarder les modifications ?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
          case QMessageBox::Save:
                qDebug() << "Save was clicked";
                SaveFile();
              break;
          case QMessageBox::Discard:
              ui->tabWidget->removeTab(i);
              break;
          case QMessageBox::Cancel:
              qDebug() << "Cancel was clicked";
              break;
          default:
              // should never be reached
              break;
        }


    }else{
        ui->tabWidget->removeTab(i);
    }
}

void MainWindow::addStar()
{
    int index = ui->tabWidget->currentIndex();
    QString fileName = ui->tabWidget->tabText(index);
    if(fileName.contains("*")){

    }else{
        fileName.append("*");
        ui->tabWidget->setTabText(index,fileName);
    }
}

void MainWindow::deleteStar()
{
    int index = ui->tabWidget->currentIndex();
    QString fileName = ui->tabWidget->tabText(index);
    if(fileName.contains("*")){
        fileName.chop(1);
        ui->tabWidget->setTabText(index,fileName);
    }else{

    }
}



