#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MappingView.h"
#include "WaferGraphicsItem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
private slots:
	void on_btn_generateMapping_clicked();

	void on_spinBox_mappingCol_valueChanged(int arg1);

	void on_spinBox_mappingRow_valueChanged(int arg1);

	void on_lineEdit_waferSize_textChanged(const QString& arg1);

	void on_lineEdit_width_textChanged(const QString& arg1);

	void on_lineEdit_refCol_textChanged(const QString& arg1);

	void on_lineEdit_height_textChanged(const QString& arg1);

	void on_lineEdit_refRow_textChanged(const QString& arg1);

	void on_lineEdit_refX_textChanged(const QString& arg1);

	void on_lineEdit_refY_textChanged(const QString& arg1);

	void on_comboBox_FlatNotchDir_currentIndexChanged(int index);

	void on_comboBox_FlatNotch_currentIndexChanged(int index);

	void on_lineEdit_xStep_textChanged(const QString& arg1);

	void on_lineEdit_yStep_textChanged(const QString& arg1);

	void on_spinBox_refCol_valueChanged(int arg1);

	void on_spinBox_refRow_valueChanged(int arg1);

	void on_comboBox_waferSize_currentIndexChanged(int index);

    void on_lineEdit_realSize_textEdited(const QString &arg1);

    void on_comboBox_startDir_currentIndexChanged(int index);

private:
	void testFunc();
private:
	Ui::MainWindow* ui;
	MappingView* mappingView;
	MappingDataStruct mapping;
	WaferGraphicsItem* curWafer;
	bool validOnce;
	//double wSizeList[8] = { 50.8,76.2,100,125,150,200,300,450 };
};
#endif // MAINWINDOW_H
