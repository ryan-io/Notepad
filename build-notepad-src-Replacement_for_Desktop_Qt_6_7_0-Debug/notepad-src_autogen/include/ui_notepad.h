/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notepad
{
public:
    QAction *newDocument;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionPrint;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditor;
    QMenuBar *menubar;
    QMenu *file;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName("Notepad");
        Notepad->resize(800, 600);
        Notepad->setTabShape(QTabWidget::Rounded);
        newDocument = new QAction(Notepad);
        newDocument->setObjectName("newDocument");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newDocument->setIcon(icon);
        actionOpen = new QAction(Notepad);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(Notepad);
        actionSave->setObjectName("actionSave");
        actionSaveAs = new QAction(Notepad);
        actionSaveAs->setObjectName("actionSaveAs");
        actionPrint = new QAction(Notepad);
        actionPrint->setObjectName("actionPrint");
        actionExit = new QAction(Notepad);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(Notepad);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textEditor = new QTextEdit(centralwidget);
        textEditor->setObjectName("textEditor");
        textEditor->setStyleSheet(QString::fromUtf8("border-color: rgb(28, 113, 216);"));
        textEditor->setTabChangesFocus(true);

        verticalLayout->addWidget(textEditor);


        verticalLayout_2->addLayout(verticalLayout);

        Notepad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Notepad);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        file = new QMenu(menubar);
        file->setObjectName("file");
        Notepad->setMenuBar(menubar);
        statusbar = new QStatusBar(Notepad);
        statusbar->setObjectName("statusbar");
        Notepad->setStatusBar(statusbar);

        menubar->addAction(file->menuAction());
        file->addSeparator();
        file->addAction(newDocument);
        file->addAction(actionOpen);
        file->addAction(actionSave);
        file->addAction(actionSaveAs);
        file->addAction(actionPrint);
        file->addAction(actionExit);

        retranslateUi(Notepad);

        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QMainWindow *Notepad)
    {
        Notepad->setWindowTitle(QCoreApplication::translate("Notepad", "Notepad Application", nullptr));
        newDocument->setText(QCoreApplication::translate("Notepad", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("Notepad", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("Notepad", "Save", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("Notepad", "SaveAs", nullptr));
        actionPrint->setText(QCoreApplication::translate("Notepad", "Print", nullptr));
        actionExit->setText(QCoreApplication::translate("Notepad", "Exit", nullptr));
        file->setTitle(QCoreApplication::translate("Notepad", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
