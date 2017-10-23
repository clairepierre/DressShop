#pragma once
#include <qwidget.h>
#include "Dress.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include<Controller.h>
#include <QComboBox.h>

class DressGUI : public QWidget
{
	Q_OBJECT

public:
	DressGUI(Controller*ctr, QWidget *parent = 0);
	~DressGUI();

private:
	std::vector<Dress> dresses;
	QComboBox* displaylist;
	QListWidget* dressesList;
	QListWidget* shortdressesList;
	QLineEdit* sizeEdit;
	QLineEdit* colorEdit;
	QLineEdit* priceEdit;
	QLineEdit* quantityEdit;
	QLineEdit* photoEdit;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* exitButton;
	QPushButton* filterButton;
	QComboBox* comboBox;
	QLineEdit* optionLine;

	void initGUI();
	int getSelectedIndex();
	void connectSignalsAndSlots();

	void shortList();
	void detailedList();
	
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();

signals:
	void dressUpdatedSignal();
	void addDressSignal(const std::string&size, const std::string&colour, double price, int quantity, const std::string&photo);

public slots:
	void addButtonHandler();
	void updateButtonHandler();
	void deleteButtonHandler();
	void exitButtonHandler();
	void openComboBox();
	//void catalogBox();
	void addDress(const std::string&size, const std::string&colour, double price, int quantity, const std::string&photo);
	void changeText();
	void populateList();
	
};