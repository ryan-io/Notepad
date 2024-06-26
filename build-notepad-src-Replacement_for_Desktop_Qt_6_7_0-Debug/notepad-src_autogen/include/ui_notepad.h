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
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionFont;
    QAction *actionFont_Size;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEditor;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *file;
    QMenu *menuSet_Font;

    void setupUi(QMainWindow *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName("Notepad");
        Notepad->resize(800, 600);
        Notepad->setTabShape(QTabWidget::Rounded);
        actionNew = new QAction(Notepad);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(Notepad);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(Notepad);
        actionSave->setObjectName("actionSave");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(Notepad);
        actionSave_As->setObjectName("actionSave_As");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/save_as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_As->setIcon(icon3);
        actionFont = new QAction(Notepad);
        actionFont->setObjectName("actionFont");
        actionFont_Size = new QAction(Notepad);
        actionFont_Size->setObjectName("actionFont_Size");
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
        statusbar = new QStatusBar(Notepad);
        statusbar->setObjectName("statusbar");
        Notepad->setStatusBar(statusbar);
        menubar = new QMenuBar(Notepad);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        file = new QMenu(menubar);
        file->setObjectName("file");
        menuSet_Font = new QMenu(menubar);
        menuSet_Font->setObjectName("menuSet_Font");
        Notepad->setMenuBar(menubar);

        menubar->addAction(file->menuAction());
        menubar->addAction(menuSet_Font->menuAction());
        file->addSeparator();
        file->addSeparator();
        file->addSeparator();
        file->addAction(actionNew);
        file->addAction(actionOpen);
        file->addAction(actionSave);
        file->addAction(actionSave_As);
        menuSet_Font->addAction(actionFont);
        menuSet_Font->addSeparator();
        menuSet_Font->addAction(actionFont_Size);

        retranslateUi(Notepad);

        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QMainWindow *Notepad)
    {
        Notepad->setWindowTitle(QCoreApplication::translate("Notepad", "Notepad Application", nullptr));
        actionNew->setText(QCoreApplication::translate("Notepad", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("Notepad", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("Notepad", "Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("Notepad", "Save", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave_As->setText(QCoreApplication::translate("Notepad", "Save As", nullptr));
        actionFont->setText(QCoreApplication::translate("Notepad", "Font", nullptr));
        actionFont_Size->setText(QCoreApplication::translate("Notepad", "Font Size", nullptr));
        file->setTitle(QCoreApplication::translate("Notepad", "File", nullptr));
        menuSet_Font->setTitle(QCoreApplication::translate("Notepad", "Set", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
