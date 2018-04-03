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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_guiBladeDesignerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *plotLayout;
    QCustomPlot *globalPlot;
    QCustomPlot *additionalPlot;
    QVBoxLayout *toolsLayout;
    QHBoxLayout *xMaxLayout;
    QLabel *label;
    QLineEdit *xMaxEdit;
    QDoubleSpinBox *xMaxSpinBox;
    QComboBox *xMaxComboBox;
    QHBoxLayout *yMaxLayout;
    QLabel *label_2;
    QLineEdit *yMaxEdit;
    QDoubleSpinBox *yMaxSpinBox;
    QComboBox *yMaxComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *alpha1Edit;
    QDoubleSpinBox *alpha1DoubleSpinBox;
    QComboBox *alpha1ComboBox;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *tool2Layout;
    QPushButton *computeCamberButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *guiBladeDesignerClass)
    {
        if (guiBladeDesignerClass->objectName().isEmpty())
            guiBladeDesignerClass->setObjectName(QStringLiteral("guiBladeDesignerClass"));
        guiBladeDesignerClass->resize(1147, 755);
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
        xMaxLayout = new QHBoxLayout();
        xMaxLayout->setSpacing(5);
        xMaxLayout->setObjectName(QStringLiteral("xMaxLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(80, 20));
        label->setMaximumSize(QSize(100, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setLineWidth(0);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        xMaxLayout->addWidget(label);

        xMaxEdit = new QLineEdit(centralWidget);
        xMaxEdit->setObjectName(QStringLiteral("xMaxEdit"));
        sizePolicy3.setHeightForWidth(xMaxEdit->sizePolicy().hasHeightForWidth());
        xMaxEdit->setSizePolicy(sizePolicy3);
        xMaxEdit->setMinimumSize(QSize(80, 20));
        xMaxEdit->setMaximumSize(QSize(80, 20));
        xMaxEdit->setProperty("value", QVariant(0));

        xMaxLayout->addWidget(xMaxEdit);

        xMaxSpinBox = new QDoubleSpinBox(centralWidget);
        xMaxSpinBox->setObjectName(QStringLiteral("xMaxSpinBox"));
        sizePolicy3.setHeightForWidth(xMaxSpinBox->sizePolicy().hasHeightForWidth());
        xMaxSpinBox->setSizePolicy(sizePolicy3);
        xMaxSpinBox->setMinimumSize(QSize(80, 20));
        xMaxSpinBox->setMaximumSize(QSize(100, 20));

        xMaxLayout->addWidget(xMaxSpinBox);

        xMaxComboBox = new QComboBox(centralWidget);
        xMaxComboBox->addItem(QString());
        xMaxComboBox->addItem(QString());
        xMaxComboBox->addItem(QString());
        xMaxComboBox->setObjectName(QStringLiteral("xMaxComboBox"));
        sizePolicy3.setHeightForWidth(xMaxComboBox->sizePolicy().hasHeightForWidth());
        xMaxComboBox->setSizePolicy(sizePolicy3);
        xMaxComboBox->setMinimumSize(QSize(80, 20));
        xMaxComboBox->setMaximumSize(QSize(80, 20));

        xMaxLayout->addWidget(xMaxComboBox);


        toolsLayout->addLayout(xMaxLayout);

        yMaxLayout = new QHBoxLayout();
        yMaxLayout->setSpacing(5);
        yMaxLayout->setObjectName(QStringLiteral("yMaxLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setMinimumSize(QSize(80, 20));
        label_2->setMaximumSize(QSize(80, 20));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        yMaxLayout->addWidget(label_2);

        yMaxEdit = new QLineEdit(centralWidget);
        yMaxEdit->setObjectName(QStringLiteral("yMaxEdit"));
        sizePolicy3.setHeightForWidth(yMaxEdit->sizePolicy().hasHeightForWidth());
        yMaxEdit->setSizePolicy(sizePolicy3);
        yMaxEdit->setMinimumSize(QSize(80, 20));
        yMaxEdit->setMaximumSize(QSize(80, 20));

        yMaxLayout->addWidget(yMaxEdit);

        yMaxSpinBox = new QDoubleSpinBox(centralWidget);
        yMaxSpinBox->setObjectName(QStringLiteral("yMaxSpinBox"));
        sizePolicy3.setHeightForWidth(yMaxSpinBox->sizePolicy().hasHeightForWidth());
        yMaxSpinBox->setSizePolicy(sizePolicy3);
        yMaxSpinBox->setMinimumSize(QSize(80, 20));
        yMaxSpinBox->setMaximumSize(QSize(80, 20));

        yMaxLayout->addWidget(yMaxSpinBox);

        yMaxComboBox = new QComboBox(centralWidget);
        yMaxComboBox->addItem(QString());
        yMaxComboBox->addItem(QString());
        yMaxComboBox->addItem(QString());
        yMaxComboBox->setObjectName(QStringLiteral("yMaxComboBox"));
        sizePolicy3.setHeightForWidth(yMaxComboBox->sizePolicy().hasHeightForWidth());
        yMaxComboBox->setSizePolicy(sizePolicy3);
        yMaxComboBox->setMinimumSize(QSize(80, 20));
        yMaxComboBox->setMaximumSize(QSize(80, 20));

        yMaxLayout->addWidget(yMaxComboBox);


        toolsLayout->addLayout(yMaxLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);
        label_4->setMaximumSize(QSize(80, 16777215));
        label_4->setFont(font1);
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_4);

        alpha1Edit = new QLineEdit(centralWidget);
        alpha1Edit->setObjectName(QStringLiteral("alpha1Edit"));
        sizePolicy3.setHeightForWidth(alpha1Edit->sizePolicy().hasHeightForWidth());
        alpha1Edit->setSizePolicy(sizePolicy3);
        alpha1Edit->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(alpha1Edit);

        alpha1DoubleSpinBox = new QDoubleSpinBox(centralWidget);
        alpha1DoubleSpinBox->setObjectName(QStringLiteral("alpha1DoubleSpinBox"));
        sizePolicy3.setHeightForWidth(alpha1DoubleSpinBox->sizePolicy().hasHeightForWidth());
        alpha1DoubleSpinBox->setSizePolicy(sizePolicy3);
        alpha1DoubleSpinBox->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(alpha1DoubleSpinBox);

        alpha1ComboBox = new QComboBox(centralWidget);
        alpha1ComboBox->addItem(QString());
        alpha1ComboBox->addItem(QString());
        alpha1ComboBox->addItem(QString());
        alpha1ComboBox->setObjectName(QStringLiteral("alpha1ComboBox"));
        sizePolicy3.setHeightForWidth(alpha1ComboBox->sizePolicy().hasHeightForWidth());
        alpha1ComboBox->setSizePolicy(sizePolicy3);
        alpha1ComboBox->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(alpha1ComboBox);


        toolsLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        toolsLayout->addItem(verticalSpacer);

        tool2Layout = new QVBoxLayout();
        tool2Layout->setSpacing(6);
        tool2Layout->setObjectName(QStringLiteral("tool2Layout"));
        tool2Layout->setContentsMargins(20, 20, 20, 20);
        computeCamberButton = new QPushButton(centralWidget);
        computeCamberButton->setObjectName(QStringLiteral("computeCamberButton"));

        tool2Layout->addWidget(computeCamberButton);


        toolsLayout->addLayout(tool2Layout);


        horizontalLayout->addLayout(toolsLayout);

        guiBladeDesignerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(guiBladeDesignerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1147, 21));
        guiBladeDesignerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(guiBladeDesignerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        guiBladeDesignerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(guiBladeDesignerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        guiBladeDesignerClass->setStatusBar(statusBar);

        retranslateUi(guiBladeDesignerClass);

        QMetaObject::connectSlotsByName(guiBladeDesignerClass);
    } // setupUi

    void retranslateUi(QMainWindow *guiBladeDesignerClass)
    {
        guiBladeDesignerClass->setWindowTitle(QApplication::translate("guiBladeDesignerClass", "guiBladeDesigner", nullptr));
        label->setText(QApplication::translate("guiBladeDesignerClass", "xMax", nullptr));
        xMaxEdit->setText(QApplication::translate("guiBladeDesignerClass", "0.25", nullptr));
        xMaxComboBox->setItemText(0, QApplication::translate("guiBladeDesignerClass", "0.01", nullptr));
        xMaxComboBox->setItemText(1, QApplication::translate("guiBladeDesignerClass", "0.001", nullptr));
        xMaxComboBox->setItemText(2, QApplication::translate("guiBladeDesignerClass", "0.0001", nullptr));

        label_2->setText(QApplication::translate("guiBladeDesignerClass", "yMax", nullptr));
        yMaxEdit->setText(QApplication::translate("guiBladeDesignerClass", "0.11", nullptr));
        yMaxComboBox->setItemText(0, QApplication::translate("guiBladeDesignerClass", "0.01", nullptr));
        yMaxComboBox->setItemText(1, QApplication::translate("guiBladeDesignerClass", "0.001", nullptr));
        yMaxComboBox->setItemText(2, QApplication::translate("guiBladeDesignerClass", "0.0001", nullptr));

        label_4->setText(QApplication::translate("guiBladeDesignerClass", "alpha1", nullptr));
        alpha1ComboBox->setItemText(0, QApplication::translate("guiBladeDesignerClass", "0.01", nullptr));
        alpha1ComboBox->setItemText(1, QApplication::translate("guiBladeDesignerClass", "0.001", nullptr));
        alpha1ComboBox->setItemText(2, QApplication::translate("guiBladeDesignerClass", "0.0001", nullptr));

        computeCamberButton->setText(QApplication::translate("guiBladeDesignerClass", "compute Camberline ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiBladeDesignerClass: public Ui_guiBladeDesignerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIBLADEDESIGNER_H
