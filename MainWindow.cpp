#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "QTrashTableModel.hpp"
#include <QFileIconProvider>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	ui->tableView->init();
	ui->tableView->setLabel(ui->label);
	QIcon trashIcon = icons.icon(QFileIconProvider::Trashcan);
	trashIcon.setIsMask(true);
	ui->pushButton->setIcon(trashIcon);
	ui->pushButton->setDisabled(true);

	/*
	trashModel = new QTrashModel(this);
	ui->tableView->verticalHeader()->setVisible(false);
	ui->tableView->setModel(trashModel);

	ui->tableView->horizontalHeader()->setStretchLastSection(true);
	ui->tableView->horizontalHeader()->setSectionsMovable(true);
	ui->tableView->horizontalHeader()->setSectionsClickable(true);
	ui->tableView->horizontalHeader()->setSortIndicatorShown(true);

	ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui->tableView->verticalHeader()->setDefaultSectionSize(
		fontMetrics().height() + 4);

	connect(ui->tableView, &QTableView::doubleClicked, trashModel,
			[trashModel = this->trashModel](QModelIndex index) {
				const auto &item = trashModel->itemAt(index.row());

				if (item.isDir())
					trashModel->cdTo(item.url());
			});

	*/
}

MainWindow::~MainWindow() { delete ui; }
