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
    QCustomPlot *globalPlot;
    QCustomPlot *additionalPlot;
    QVBoxLayout *toolsLayout;
    QTabWidget *tab_panel;
    QWidget *tab_parametrs;
    QHBoxLayout *horizontalLayout_9;
    QTableWidget *parametrsTable;
    QWidget *tab_cascade;
    QVBoxLayout *tool2Layout;
    QSpacerItem *verticalSpacer;
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
        plotLayout->setSpacing(20);
        plotLayout->setObjectName(QStringLiteral("plotLayout"));
        plotLayout->setContentsMargins(20, 20, 20, -1);
        globalPlot = new QCustomPlot(centralWidget);
        globalPlot->setObjectName(QStringLiteral("globalPlot"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(15);
        sizePolicy1.setHeightForWidth(globalPlot->sizePolicy().hasHeightForWidth());
        globalPlot->setSizePolicy(sizePolicy1);
        globalPlot->setBaseSize(QSize(0, 0));

        plotLayout->addWidget(globalPlot);

        additionalPlot = new QCustomPlot(centralWidget);
        additionalPlot->setObjectName(QStringLiteral("additionalPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(6);
        sizePolicy2.setHeightForWidth(additionalPlot->sizePolicy().hasHeightForWidth());
        additionalPlot->setSizePolicy(sizePolicy2);

        plotLayout->addWidget(additionalPlot);


        horizontalLayout->addLayout(plotLayout);

        toolsLayout = new QVBoxLayout();
        toolsLayout->setSpacing(10);
        toolsLayout->setObjectName(QStringLiteral("toolsLayout"));
        toolsLayout->setContentsMargins(20, 20, 20, 20);
        tab_panel = new QTabWidget(centralWidget);
        tab_panel->setObjectName(QStringLiteral("tab_panel"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tab_panel->sizePolicy().hasHeightForWidth());
        tab_panel->setSizePolicy(sizePolicy3);
        tab_panel->setMinimumSize(QSize(0, 0));
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
        parametrsTable->setMinimumSize(QSize(270, 0));
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

        tool2Layout = new QVBoxLayout();
        tool2Layout->setSpacing(6);
        tool2Layout->setObjectName(QStringLiteral("tool2Layout"));
        tool2Layout->setContentsMargins(20, 20, 20, 20);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        tool2Layout->addItem(verticalSpacer);

        computeCamberButton = new QPushButton(centralWidget);
        computeCamberButton->setObjectName(QStringLiteral("computeCamberButton"));

        tool2Layout->addWidget(computeCamberButton);

        computeSuctionSideButton = new QPushButton(centralWidget);
        computeSuctionSideButton->setObjectName(QStringLiteral("computeSuctionSideButton"));
        computeSuctionSideButton->setEnabled(false);

        tool2Layout->addWidget(computeSuctionSideButton);


        toolsLayout->addLayout(tool2Layout);


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
