#ifndef QTRASHTABLEVIEW_HPP
#define QTRASHTABLEVIEW_HPP

#include <QTableView>
#include <KFileItem>

class QLabel;
class TableItemDelegate;
class FileTabSelector;
class QTrashTableModel;

class QTrashTableView : public QTableView {
	Q_OBJECT
public:
	explicit QTrashTableView(QWidget *parent = nullptr);

	KFileItemList getSelectedFiles();

	TableItemDelegate *itemDelegate() const {
		// return qobject_cast<TableItemDelegate *>(QTableView::itemDelegate());
		return (TableItemDelegate *)QTableView::itemDelegate();
	}
	void setTabOrderIndex(int index) { this->index = index; }
	void setLabel(QLabel *infoLabel) { this->infoLabel = infoLabel; }
	void init();

signals:
	void dirChanged(const QString dirName, int index);
	void contextMenuRequested(QPoint);
	void focusEvent(bool);

public slots:

	void on_doubleClicked(const QModelIndex &index);
	// void headerClicked(int section);
	void updateInfo();
	void openContextMenu(QPoint);


protected:
	void keyPressEvent(QKeyEvent *event) override;
	void focusInEvent(QFocusEvent *event) override;
	void focusOutEvent(QFocusEvent *event) override;
	bool isCurrent() const;
	bool parseItems(size_t &totalSize, int &dirCount, int &fileCount,
					const KFileItemList &items);
	QList<QUrl> getSelectedItems(QList<int> &rows);

private:
	int index{};
	QLabel *infoLabel = nullptr;
	QTabWidget *metaTab = nullptr;
	TableItemDelegate *delegate = nullptr;
	FileTabSelector *parent = nullptr;
	QTrashTableModel *trashModel;
	QMenu *menu;

	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // QTRASHTABLEVIEW_HPP
