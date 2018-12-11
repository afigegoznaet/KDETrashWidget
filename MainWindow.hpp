#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMenu>
#include <QFileIconProvider>

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
	QFileIconProvider icons;
	QIcon trashIconE;
	QIcon trashIconF;
};

#endif // MAINWINDOW_HPP
