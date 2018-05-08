/********************************************************************************
** Form generated from reading UI file 'guiBladeDesigner.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIBLADEDESIGNER_H
#define UI_GUIBLADEDESIGNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_guiBladeDesignerClass
{
public:
    QAction *actionRead;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionConfig;
    QAction *actionExport_to_AutoCad;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *plotLayout;
    QFrame *line_2;
    QCustomPlot *globalPlot;
    QFrame *line;
    QCustomPlot *additionalPlot;
    QFrame *line_3;
    QVBoxLayout *toolsLayout;
    QTabWidget *tab_panel;
    QWidget *tab_parametrs;
    QHBoxLayout *horizontalLayout_9;
    QTableWidget *parametrsTable;
    QWidget *tab_cascade;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *computeCamberButton;
    QPushButton *computeSuctionSideButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *guiBladeDesignerClass)
    {
        if (guiBladeDesignerClass->objectName().isEmpty())
            guiBladeDesignerClass->setObjectName(QStringLiteral("guiBladeDesignerClass"));
        guiBladeDesignerClass->resize(1214, 794);
        actionRead = new QAction(guiBladeDesignerClass);
        actionRead->setObjectName(QStringLiteral("actionRead"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/guiBladeDesigner/Resources/Icons/if_ic_find_in_page_48px_352363.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRead->setIcon(icon);
        actionSave = new QAction(guiBladeDesignerClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/guiBladeDesigner/Resources/Icons/if_ic_save_48px_352084.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionExit = new QAction(guiBladeDesignerClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionConfig = new QAction(guiBladeDesignerClass);
        actionConfig->setObjectName(QStringLiteral("actionConfig"));
        actionConfig->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/guiBladeDesigner/Resources/Icons/if_ic_settings_48px_352095.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfig->setIcon(icon2);
        actionExport_to_AutoCad = new QAction(guiBladeDesignerClass);
        actionExport_to_AutoCad->setObjectName(QStringLiteral("actionExport_to_AutoCad"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/guiBladeDesigner/Resources/Icons/if_export-outline_216189.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_to_AutoCad->setIcon(icon3);
        centralWidget = new QWidget(guiBladeDesignerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        plotLayout = new QVBoxLayout();
        plotLayout->setSpacing(10);
        plotLayout->setObjectName(QStringLiteral("plotLayout"));
        plotLayout->setContentsMargins(5, 5, 5, -1);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy1);
        line_2->setMinimumSize(QSize(0, 2));
        line_2->setMaximumSize(QSize(16777215, 5));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        plotLayout->addWidget(line_2);

        globalPlot = new QCustomPlot(centralWidget);
        globalPlot->setObjectName(QStringLiteral("globalPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(15);
        sizePolicy2.setHeightForWidth(globalPlot->sizePolicy().hasHeightForWidth());
        globalPlot->setSizePolicy(sizePolicy2);
        globalPlot->setBaseSize(QSize(0, 0));

        plotLayout->addWidget(globalPlot);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setMinimumSize(QSize(0, 2));
        line->setMaximumSize(QSize(16777215, 5));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        plotLayout->addWidget(line);

        additionalPlot = new QCustomPlot(centralWidget);
        additionalPlot->setObjectName(QStringLiteral("additionalPlot"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(6);
        sizePolicy3.setHeightForWidth(additionalPlot->sizePolicy().hasHeightForWidth());
        additionalPlot->setSizePolicy(sizePolicy3);

        plotLayout->addWidget(additionalPlot);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        sizePolicy1.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy1);
        line_3->setMinimumSize(QSize(0, 2));
        line_3->setMaximumSize(QSize(16777215, 5));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        plotLayout->addWidget(line_3);


        horizontalLayout->addLayout(plotLayout);

        toolsLayout = new QVBoxLayout();
        toolsLayout->setSpacing(10);
        toolsLayout->setObjectName(QStringLiteral("toolsLayout"));
        toolsLayout->setContentsMargins(20, 5, 20, 50);
        tab_panel = new QTabWidget(centralWidget);
        tab_panel->setObjectName(QStringLiteral("tab_panel"));
        sizePolicy1.setHeightForWidth(tab_panel->sizePolicy().hasHeightForWidth());
        tab_panel->setSizePolicy(sizePolicy1);
        tab_panel->setMinimumSize(QSize(0, 480));
        tab_panel->setMaximumSize(QSize(16777215, 480));
        tab_parametrs = new QWidget();
        tab_parametrs->setObjectName(QStringLiteral("tab_parametrs"));
        horizontalLayout_9 = new QHBoxLayout(tab_parametrs);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        parametrsTable = new QTableWidget(tab_parametrs);
        if (parametrsTable->columnCount() < 2)
            parametrsTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        parametrsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        parametrsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (parametrsTable->rowCount() < 13)
            parametrsTable->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(8, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(9, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(10, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(11, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        parametrsTable->setVerticalHeaderItem(12, __qtablewidgetitem14);
        parametrsTable->setObjectName(QStringLiteral("parametrsTable"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(parametrsTable->sizePolicy().hasHeightForWidth());
        parametrsTable->setSizePolicy(sizePolicy4);
        parametrsTable->setMinimumSize(QSize(270, 0));
        parametrsTable->setMaximumSize(QSize(16777215, 480));
        parametrsTable->setShowGrid(true);
        parametrsTable->setGridStyle(Qt::SolidLine);
        parametrsTable->setWordWrap(true);
        parametrsTable->setCornerButtonEnabled(true);

        horizontalLayout_9->addWidget(parametrsTable);

        tab_panel->addTab(tab_parametrs, QString());
        tab_cascade = new QWidget();
        tab_cascade->setObjectName(QStringLiteral("tab_cascade"));
        tab_panel->addTab(tab_cascade, QString());

        toolsLayout->addWidget(tab_panel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        toolsLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        computeCamberButton = new QPushButton(centralWidget);
        computeCamberButton->setObjectName(QStringLiteral("computeCamberButton"));

        horizontalLayout_2->addWidget(computeCamberButton);

        computeSuctionSideButton = new QPushButton(centralWidget);
        computeSuctionSideButton->setObjectName(QStringLiteral("computeSuctionSideButton"));
        computeSuctionSideButton->setEnabled(false);

        horizontalLayout_2->addWidget(computeSuctionSideButton);


        toolsLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(toolsLayout);

        guiBladeDesignerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(guiBladeDesignerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1214, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        guiBladeDesignerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(guiBladeDesignerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        guiBladeDesignerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(guiBladeDesignerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        guiBladeDesignerClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionRead);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExport_to_AutoCad);
        menuFile->addSeparator();
        menuFile->addAction(actionConfig);
        menuFile->addAction(actionExit);
        mainToolBar->addAction(actionRead);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionExport_to_AutoCad);
        mainToolBar->addAction(actionConfig);

        retranslateUi(guiBladeDesignerClass);

        tab_panel->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(guiBladeDesignerClass);
    } // setupUi

    void retranslateUi(QMainWindow *guiBladeDesignerClass)
    {
        guiBladeDesignerClass->setWindowTitle(QApplication::translate("guiBladeDesignerClass", "guiBladeDesigner", nullptr));
        actionRead->setText(QApplication::translate("guiBladeDesignerClass", "Read...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRead->setToolTip(QApplication::translate("guiBladeDesignerClass", "<html><head/><body><p><span style=\" font-size:8pt; font-style:italic;\">Open and read parametrs from file</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRead->setShortcut(QApplication::translate("guiBladeDesignerClass", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("guiBladeDesignerClass", "Save as...", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("guiBladeDesignerClass", "Save as", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("guiBladeDesignerClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("guiBladeDesignerClass", "Exit", nullptr));
        actionConfig->setText(QApplication::translate("guiBladeDesignerClass", "Config", nullptr));
        actionExport_to_AutoCad->setText(QApplication::translate("guiBladeDesignerClass", "Export to AutoCad", nullptr));
        QTableWidgetItem *___qtablewidgetitem = parametrsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("guiBladeDesignerClass", "value", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = parametrsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("guiBladeDesignerClass", "increment", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = parametrsTable->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("guiBladeDesignerClass", "xMax", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = parametrsTable->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("guiBladeDesignerClass", "yMax", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = parametrsTable->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("guiBladeDesignerClass", "alpha1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = parametrsTable->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("guiBladeDesignerClass", "alpha2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = parametrsTable->verticalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("guiBladeDesignerClass", "R1", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = parametrsTable->verticalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("guiBladeDesignerClass", "R2", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = parametrsTable->verticalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("guiBladeDesignerClass", "omega1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = parametrsTable->verticalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("guiBladeDesignerClass", "omega2", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = parametrsTable->verticalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("guiBladeDesignerClass", "RMax", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = parametrsTable->verticalHeaderItem(9);
        ___qtablewidgetitem11->setText(QApplication::translate("guiBladeDesignerClass", "x RMax", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = parametrsTable->verticalHeaderItem(10);
        ___qtablewidgetitem12->setText(QApplication::translate("guiBladeDesignerClass", "RBend", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = parametrsTable->verticalHeaderItem(11);
        ___qtablewidgetitem13->setText(QApplication::translate("guiBladeDesignerClass", "x RBend", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = parametrsTable->verticalHeaderItem(12);
        ___qtablewidgetitem14->setText(QApplication::translate("guiBladeDesignerClass", "alphaBend", nullptr));
        tab_panel->setTabText(tab_panel->indexOf(tab_parametrs), QApplication::translate("guiBladeDesignerClass", "Blade", nullptr));
        tab_panel->setTabText(tab_panel->indexOf(tab_cascade), QApplication::translate("guiBladeDesignerClass", "Cascade", nullptr));
        computeCamberButton->setText(QApplication::translate("guiBladeDesignerClass", "compute Camberline ", nullptr));
        computeSuctionSideButton->setText(QApplication::translate("guiBladeDesignerClass", "compute Suction Side", nullptr));
        menuFile->setTitle(QApplication::translate("guiBladeDesignerClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiBladeDesignerClass: public Ui_guiBladeDesignerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIBLADEDESIGNER_H
