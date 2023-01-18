/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *comboBox_waferSize;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QLineEdit *lineEdit_realSize;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox_mappingCol;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *spinBox_mappingRow;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit_width;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEdit_height;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSpinBox *spinBox_refCol;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QSpinBox *spinBox_refRow;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *lineEdit_refX;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *lineEdit_refY;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QComboBox *comboBox_FlatNotchDir;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QComboBox *comboBox_FlatNotch;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QLineEdit *lineEdit_xStep;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QLineEdit *lineEdit_yStep;
    QFrame *line_2;
    QPushButton *btn_generateMapping;
    QLabel *label_info;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinimumSize);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(120, 0));
        label_3->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_4->addWidget(label_3);

        comboBox_waferSize = new QComboBox(centralwidget);
        comboBox_waferSize->addItem(QString());
        comboBox_waferSize->addItem(QString());
        comboBox_waferSize->addItem(QString());
        comboBox_waferSize->addItem(QString());
        comboBox_waferSize->addItem(QString());
        comboBox_waferSize->addItem(QString());
        comboBox_waferSize->addItem(QString());
        comboBox_waferSize->addItem(QString());
        comboBox_waferSize->setObjectName(QString::fromUtf8("comboBox_waferSize"));
        comboBox_waferSize->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_4->addWidget(comboBox_waferSize);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(120, 0));
        label_14->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_15->addWidget(label_14);

        lineEdit_realSize = new QLineEdit(centralwidget);
        lineEdit_realSize->setObjectName(QString::fromUtf8("lineEdit_realSize"));
        lineEdit_realSize->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_15->addWidget(lineEdit_realSize);


        verticalLayout_2->addLayout(horizontalLayout_15);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(120, 0));
        label->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(label);

        spinBox_mappingCol = new QSpinBox(centralwidget);
        spinBox_mappingCol->setObjectName(QString::fromUtf8("spinBox_mappingCol"));
        spinBox_mappingCol->setMinimumSize(QSize(120, 0));
        spinBox_mappingCol->setMaximumSize(QSize(120, 16777215));
        spinBox_mappingCol->setMaximum(300);
        spinBox_mappingCol->setValue(10);

        horizontalLayout_2->addWidget(spinBox_mappingCol);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(120, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_2);

        spinBox_mappingRow = new QSpinBox(centralwidget);
        spinBox_mappingRow->setObjectName(QString::fromUtf8("spinBox_mappingRow"));
        spinBox_mappingRow->setMinimumSize(QSize(120, 0));
        spinBox_mappingRow->setMaximumSize(QSize(120, 16777215));
        spinBox_mappingRow->setMaximum(300);
        spinBox_mappingRow->setValue(10);

        horizontalLayout_3->addWidget(spinBox_mappingRow);


        verticalLayout_2->addLayout(horizontalLayout_3);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(120, 0));
        label_4->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_5->addWidget(label_4);

        lineEdit_width = new QLineEdit(centralwidget);
        lineEdit_width->setObjectName(QString::fromUtf8("lineEdit_width"));
        lineEdit_width->setMinimumSize(QSize(120, 0));
        lineEdit_width->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_5->addWidget(lineEdit_width);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(120, 0));
        label_5->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_6->addWidget(label_5);

        lineEdit_height = new QLineEdit(centralwidget);
        lineEdit_height->setObjectName(QString::fromUtf8("lineEdit_height"));
        lineEdit_height->setMinimumSize(QSize(120, 0));
        lineEdit_height->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_6->addWidget(lineEdit_height);


        verticalLayout_2->addLayout(horizontalLayout_6);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(120, 0));
        label_6->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_7->addWidget(label_6);

        spinBox_refCol = new QSpinBox(centralwidget);
        spinBox_refCol->setObjectName(QString::fromUtf8("spinBox_refCol"));
        spinBox_refCol->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_7->addWidget(spinBox_refCol);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(120, 0));
        label_7->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_8->addWidget(label_7);

        spinBox_refRow = new QSpinBox(centralwidget);
        spinBox_refRow->setObjectName(QString::fromUtf8("spinBox_refRow"));
        spinBox_refRow->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_8->addWidget(spinBox_refRow);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(120, 0));
        label_8->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_9->addWidget(label_8);

        lineEdit_refX = new QLineEdit(centralwidget);
        lineEdit_refX->setObjectName(QString::fromUtf8("lineEdit_refX"));
        lineEdit_refX->setMinimumSize(QSize(120, 0));
        lineEdit_refX->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_9->addWidget(lineEdit_refX);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(120, 0));
        label_9->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_11->addWidget(label_9);

        lineEdit_refY = new QLineEdit(centralwidget);
        lineEdit_refY->setObjectName(QString::fromUtf8("lineEdit_refY"));
        lineEdit_refY->setMinimumSize(QSize(120, 0));
        lineEdit_refY->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_11->addWidget(lineEdit_refY);


        verticalLayout_2->addLayout(horizontalLayout_11);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(120, 0));
        label_10->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_12->addWidget(label_10);

        comboBox_FlatNotchDir = new QComboBox(centralwidget);
        comboBox_FlatNotchDir->addItem(QString());
        comboBox_FlatNotchDir->addItem(QString());
        comboBox_FlatNotchDir->addItem(QString());
        comboBox_FlatNotchDir->addItem(QString());
        comboBox_FlatNotchDir->setObjectName(QString::fromUtf8("comboBox_FlatNotchDir"));
        comboBox_FlatNotchDir->setMinimumSize(QSize(120, 0));
        comboBox_FlatNotchDir->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_12->addWidget(comboBox_FlatNotchDir);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(120, 0));
        label_11->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_13->addWidget(label_11);

        comboBox_FlatNotch = new QComboBox(centralwidget);
        comboBox_FlatNotch->addItem(QString());
        comboBox_FlatNotch->addItem(QString());
        comboBox_FlatNotch->setObjectName(QString::fromUtf8("comboBox_FlatNotch"));
        comboBox_FlatNotch->setMinimumSize(QSize(120, 0));
        comboBox_FlatNotch->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_13->addWidget(comboBox_FlatNotch);


        verticalLayout_2->addLayout(horizontalLayout_13);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(120, 0));
        label_12->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_10->addWidget(label_12);

        lineEdit_xStep = new QLineEdit(centralwidget);
        lineEdit_xStep->setObjectName(QString::fromUtf8("lineEdit_xStep"));
        lineEdit_xStep->setMinimumSize(QSize(120, 0));
        lineEdit_xStep->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_10->addWidget(lineEdit_xStep);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(120, 0));
        label_13->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_14->addWidget(label_13);

        lineEdit_yStep = new QLineEdit(centralwidget);
        lineEdit_yStep->setObjectName(QString::fromUtf8("lineEdit_yStep"));
        lineEdit_yStep->setMinimumSize(QSize(120, 0));
        lineEdit_yStep->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_14->addWidget(lineEdit_yStep);


        verticalLayout_2->addLayout(horizontalLayout_14);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        btn_generateMapping = new QPushButton(centralwidget);
        btn_generateMapping->setObjectName(QString::fromUtf8("btn_generateMapping"));
        btn_generateMapping->setMaximumSize(QSize(120, 16777215));

        verticalLayout_2->addWidget(btn_generateMapping);

        label_info = new QLabel(centralwidget);
        label_info->setObjectName(QString::fromUtf8("label_info"));
        label_info->setMaximumSize(QSize(250, 16777215));

        verticalLayout_2->addWidget(label_info);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave);

        retranslateUi(MainWindow);

        comboBox_waferSize->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Wafer Size(mm)", nullptr));
        comboBox_waferSize->setItemText(0, QCoreApplication::translate("MainWindow", "50.8", nullptr));
        comboBox_waferSize->setItemText(1, QCoreApplication::translate("MainWindow", "76.2", nullptr));
        comboBox_waferSize->setItemText(2, QCoreApplication::translate("MainWindow", "100", nullptr));
        comboBox_waferSize->setItemText(3, QCoreApplication::translate("MainWindow", "125", nullptr));
        comboBox_waferSize->setItemText(4, QCoreApplication::translate("MainWindow", "150", nullptr));
        comboBox_waferSize->setItemText(5, QCoreApplication::translate("MainWindow", "200", nullptr));
        comboBox_waferSize->setItemText(6, QCoreApplication::translate("MainWindow", "300", nullptr));
        comboBox_waferSize->setItemText(7, QCoreApplication::translate("MainWindow", "450", nullptr));

        label_14->setText(QCoreApplication::translate("MainWindow", "Wafer Real Size", nullptr));
        lineEdit_realSize->setText(QCoreApplication::translate("MainWindow", "145", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mapping Cols", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Mapping Rows", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Device Width(mm)", nullptr));
        lineEdit_width->setText(QCoreApplication::translate("MainWindow", "3.5", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Device Height(mm)", nullptr));
        lineEdit_height->setText(QCoreApplication::translate("MainWindow", "2.5", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ref die col", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Ref die row", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Ref die x(mm)", nullptr));
        lineEdit_refX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Ref die y(mm)", nullptr));
        lineEdit_refY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Flat/Notch dir", nullptr));
        comboBox_FlatNotchDir->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        comboBox_FlatNotchDir->setItemText(1, QCoreApplication::translate("MainWindow", "90", nullptr));
        comboBox_FlatNotchDir->setItemText(2, QCoreApplication::translate("MainWindow", "180", nullptr));
        comboBox_FlatNotchDir->setItemText(3, QCoreApplication::translate("MainWindow", "270", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Flat/Notch", nullptr));
        comboBox_FlatNotch->setItemText(0, QCoreApplication::translate("MainWindow", "Flat", nullptr));
        comboBox_FlatNotch->setItemText(1, QCoreApplication::translate("MainWindow", "Notch", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "X step(mm)", nullptr));
        lineEdit_xStep->setText(QCoreApplication::translate("MainWindow", "3.8", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "y step(mm)", nullptr));
        lineEdit_yStep->setText(QCoreApplication::translate("MainWindow", "2.8", nullptr));
        btn_generateMapping->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220", nullptr));
        label_info->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
