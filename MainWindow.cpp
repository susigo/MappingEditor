#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	validOnce = false;
	curWafer = new WaferGraphicsItem(WaferGraphicsItem::Flat, WaferGraphicsItem::Wafer150MM);
	mappingView = new MappingView();
	ui->verticalLayout->addWidget(mappingView);
	mappingView->setMaximumWidth(1000);
	this->resize(1200, 900);
	on_btn_generateMapping_clicked();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::testFunc()
{
	mappingView->DisplayMapping(mapping);
}


void MainWindow::on_btn_generateMapping_clicked()
{
	mapping.wafer_size = ui->comboBox_waferSize->currentIndex();
	if (mapping.wafer_size == 0)
	{
		ui->label_info->setText("Please enter a valid size!");
		return;
	}
	mapping.cols = ui->spinBox_mappingCol->value();
	if (mapping.cols == 0)
	{
		ui->label_info->setText("Please enter a valid cols!");
		return;
	}
	mapping.rows = ui->spinBox_mappingRow->value();
	if (mapping.rows == 0)
	{
		ui->label_info->setText("Please enter a valid rows!");
		return;
	}
	mapping.device_width = ui->lineEdit_width->text().toDouble();
	if (mapping.device_width == 0)
	{
		ui->label_info->setText("Please enter a valid width!");
		return;
	}
	mapping.device_height = ui->lineEdit_height->text().toDouble();
	if (mapping.device_height == 0)
	{
		ui->label_info->setText("Please enter a valid height!");
		return;
	}

	mapping.ref_col = ui->spinBox_refCol->value();
	mapping.ref_row = ui->spinBox_refRow->value();

	mapping.ref_x = ui->lineEdit_refX->text().toDouble();
	mapping.ref_y = ui->lineEdit_refY->text().toDouble();

	mapping.x_step = ui->lineEdit_xStep->text().toDouble();
	if (mapping.x_step == 0)
	{
		ui->label_info->setText("Please enter a valid x step!");
		return;
	}
	mapping.y_step = ui->lineEdit_yStep->text().toDouble();
	if (mapping.y_step == 0)
	{
		ui->label_info->setText("Please enter a valid y step!");
		return;
	}
	mapping.pos_ori_loc = ui->comboBox_startDir->currentIndex();
	mapping.flat_notch = ui->comboBox_FlatNotch->currentIndex();
	mapping.flat_notch_angle = ui->comboBox_FlatNotchDir->currentText().toInt();
	curWafer->setRealWaferSize(ui->lineEdit_realSize->text().toDouble());
	curWafer->GennerateMapping(mapping);

	mappingView->DisplayMapping(*curWafer);
	validOnce = true;
	ui->label_info->setText("Mapping generated!");
}


void MainWindow::on_spinBox_mappingCol_valueChanged(int arg1)
{
	on_btn_generateMapping_clicked();
}



void MainWindow::on_spinBox_mappingRow_valueChanged(int arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_waferSize_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_width_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_refCol_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_height_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_refRow_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_refX_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_refY_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_comboBox_FlatNotchDir_currentIndexChanged(int index)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_comboBox_FlatNotch_currentIndexChanged(int index)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_xStep_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_lineEdit_yStep_textChanged(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_spinBox_refCol_valueChanged(int arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_spinBox_refRow_valueChanged(int arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_comboBox_waferSize_currentIndexChanged(int index)
{
	on_btn_generateMapping_clicked();
}

void MainWindow::on_lineEdit_realSize_textEdited(const QString& arg1)
{
	on_btn_generateMapping_clicked();
}


void MainWindow::on_comboBox_startDir_currentIndexChanged(int index)
{
	on_btn_generateMapping_clicked();
}

