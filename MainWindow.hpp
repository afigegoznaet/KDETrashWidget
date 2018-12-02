#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMenu>

class QTrashTableModel;

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();


private:
	Ui::MainWindow *ui;
	QTrashTableModel *trashModel;
};

#endif // MAINWINDOW_HPP
