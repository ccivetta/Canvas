#include "mainwindow.h"
#include "ScribbleArea.h"
#include <QSignalMapper>
#include <QApplication>
#include <QColorDialog>
#include <QFileDialog>
#include <QImageWriter>
#include <QInputDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QCloseEvent>
#include <./ui_mainwindow.h>
#include <QBoxLayout>
#include <QVBoxLayout>
#include <iostream>
using namespace std;

list<string> drawings;
list<string>::iterator i;
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)//, scribbleArea(new ScribbleArea(this))
{
    ui->setupUi(this);
    drawings = {"Banana", "Penguin", "Cat", "Fish", "Shoe"};

    i = drawings.begin();
    connect(ui->clearBtn, SIGNAL(released()), this, SLOT(on_clearBtn_clicked()));
    connect(ui->colorBtn, SIGNAL(released()), this, SLOT(on_colorBtn_clicked()));
    connect(ui->widthBtn, SIGNAL(released()), this, SLOT(on_widthBtn_clicked()));
    //connect(ui->submitBtn, SIGNAL(clicked()), this, SLOT(on_submitBtn_clicked()));
    //connect(signalMapper, SIGNAL(mapped()), this, SLOT(on_submitBtn_clicked()));
    createActions();
    createMenus();

    setWindowTitle(tr("Scribble"));
    //resize(500, 300);


}
//void MainWindow::closeEvent(QCloseEvent *event)
//
//{
//    if (maybeSave())
//        event->accept();
//    else
//        event->ignore();
//}

//void MainWindow::open()
//
//{
//    if (maybeSave()) {
//        QString fileName = QFileDialog::getOpenFileName(this,
//                                                        tr("Open File"), QDir::currentPath());
//        if (!fileName.isEmpty())
//            scribbleArea->openImage(fileName);
//    }
//}

//void MainWindow::save()
//
//{
//    QAction *action = qobject_cast<QAction *>(sender());
//    QByteArray fileFormat = action->data().toByteArray();
//    saveFile(fileFormat);
//}

void MainWindow::penColor()

{
    QColor newColor = QColorDialog::getColor(ui->MainScribbleArea->penColor());
    if (newColor.isValid())
        ui->MainScribbleArea->setPenColor(newColor);
}

void MainWindow::penWidth()

{
    bool ok;
    int newWidth = QInputDialog::getInt(this, tr("Scribble"),
                                        tr("Select pen width:"),
                                        ui->MainScribbleArea->penWidth(),
                                        1, 50, 1, &ok);
    if (ok)
        ui->MainScribbleArea->setPenWidth(newWidth);
}

//void MainWindow::about()
//
//{
//    QMessageBox::about(this, tr("About Scribble"),
//                       tr("<p>The <b>Scribble</b> example shows how to use QMainWindow as the "
//                          "base widget for an application, and how to reimplement some of "
//                          "QWidget's event handlers to receive the events generated for "
//                          "the application's widgets:</p><p> We reimplement the mouse event "
//                          "handlers to facilitate drawing, the paint event handler to "
//                          "update the application and the resize event handler to optimize "
//                          "the application's appearance. In addition we reimplement the "
//                          "close event handler to intercept the close events before "
//                          "terminating the application.</p><p> The example also demonstrates "
//                          "how to use QPainter to draw an image in real time, as well as "
//                          "to repaint widgets.</p>"));
//}

void MainWindow::createActions()

{
    //openAct = new QAction(tr("&Open..."), this);
    //openAct->setShortcuts(QKeySequence::Open);
    //connect(openAct, &QAction::triggered, this, &MainWindow::open);

//    const QList<QByteArray> imageFormats = QImageWriter::supportedImageFormats();
//    for (const QByteArray &format : imageFormats) {
//        QString text = tr("%1...").arg(QString::fromLatin1(format).toUpper());

//        QAction *action = new QAction(text, this);
//        action->setData(format);
//        connect(action, &QAction::triggered, this, &MainWindow::save);
//        saveAsActs.append(action);

//    printAct = new QAction(tr("&Print..."), this);
//    connect(printAct, &QAction::triggered, scribbleArea, &ScribbleArea::print);
//
//    exitAct = new QAction(tr("E&xit"), this);
//    exitAct->setShortcuts(QKeySequence::Quit);
//    connect(exitAct, &QAction::triggered, this, &MainWindow::close);
//
//    penColorAct = new QAction(tr("&Pen Color..."), this);
//    connect(penColorAct, &QAction::triggered, this, &MainWindow::penColor);
//
//    penWidthAct = new QAction(tr("Pen &Width..."), this);
//    connect(penWidthAct, &QAction::triggered, this, &MainWindow::penWidth);
//
   clearScreenAct = new QAction(tr("&Clear Screen"), this);
   clearScreenAct->setShortcut(tr("Ctrl+L"));
   //connect(ui->colorBtn, SIGNAL(released()), ui->MainScribbleArea, &ScribbleArea::clearImage);
   connect(clearScreenAct, &QAction::triggered,

            ui->MainScribbleArea, &ScribbleArea::clearImage);





//    aboutAct = new QAction(tr("&About"), this);
//    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

//    aboutQtAct = new QAction(tr("About &Qt"), this);
//    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::createMenus()

{
//    saveAsMenu = new QMenu(tr("&Save As"), this);
//    for (QAction *action : qAsConst(saveAsActs))
//        saveAsMenu->addAction(action);
//
//    fileMenu = new QMenu(tr("&File"), this);
//    fileMenu->addAction(openAct);
//    fileMenu->addMenu(saveAsMenu);
//    fileMenu->addAction(printAct);
//    fileMenu->addSeparator();
//    fileMenu->addAction(exitAct);
//
    optionMenu = new QMenu(tr("&Options"), this);
//    optionMenu->addAction(penColorAct);
//    optionMenu->addAction(penWidthAct);
//    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);
//
//    helpMenu = new QMenu(tr("&Help"), this);
//    helpMenu->addAction(aboutAct);
//    helpMenu->addAction(aboutQtAct);
//
//    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
//    menuBar()->addMenu(helpMenu);
}

//bool MainWindow::maybeSave()
//
//{
//    if (scribbleArea->isModified()) {
//        QMessageBox::StandardButton ret;
//        ret = QMessageBox::warning(this, tr("Scribble"),
//                                   tr("The image has been modified.\n"
//                                      "Do you want to save your changes?"),
//                                   QMessageBox::Save | QMessageBox::Discard
//                                   | QMessageBox::Cancel);
//        if (ret == QMessageBox::Save)
//            return saveFile("png");
//        else if (ret == QMessageBox::Cancel)
//            return false;
//    }
//    return true;
//}
//bool MainWindow::saveFile(const QByteArray &fileFormat)
//{
//    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;
//
//    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
//                                                    initialPath,
//                                                    tr("%1 Files (*.%2);;All Files (*)")
//                                                            .arg(QString::fromLatin1(fileFormat.toUpper()))
//                                                            .arg(QString::fromLatin1(fileFormat)));
//    if (fileName.isEmpty())
//        return false;
//    return scribbleArea->saveImage(fileName, fileFormat.constData());
//}


void MainWindow::on_clearBtn_clicked()
{
    ui->MainScribbleArea->clearImage();
}

void MainWindow::on_colorBtn_clicked()
{
    penColor();
}

void MainWindow::on_widthBtn_clicked() {
    penWidth();
}

void MainWindow::on_submitBtn_clicked() {
    cout << *i  << endl;
    //list<string> listRef = drawings;
    //i = listRef.begin();
    ui->assignmentLbl->setText(QString::fromStdString(*i));
    //cout << *i << endl;
    i++;
    //cout << *i << endl;
}
