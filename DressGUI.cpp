#include "DressGUI.h"
#include<qapplication.h>

DressGUI::DressGUI(Controller* ctr, QWidget*parent) :QWidget{ parent }
{
	this->dresses = ctr->getRepo().getDresses();
	this->initGUI();
	this->connectSignalsAndSlots();
	this->populateList();
	
}

DressGUI::~DressGUI()
{
}


void DressGUI::openComboBox()
{
	shortdressesList = new QListWidget{};
	QWidget* displayWidget = new QWidget{};
	QGridLayout* combolayout = new QGridLayout(displayWidget);
	QStringList list = (QStringList() << "Detailed"<<"Short");
	
	this->comboBox->addItems(list);
	combolayout->addWidget(this->comboBox, 1, 1, 1, 1);
	combolayout->addWidget(shortdressesList, 2, 1, 1, 1);
	displayWidget->show();

	this->dressesList = new QListWidget{};
}


void DressGUI::initGUI()
{
	QVBoxLayout* layout = new QVBoxLayout{ this };
	this->dressesList = new QListWidget{};
	this->dressesList->setSelectionMode(QAbstractItemView::SingleSelection);
	layout->addWidget(this->dressesList);
	QWidget* middleSide = new QWidget{};
	QVBoxLayout* vLayout = new QVBoxLayout{ middleSide };
	QWidget* dressDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ dressDataWidget };
	this-> sizeEdit= new QLineEdit{};
	this->colorEdit = new QLineEdit{};
	this->priceEdit = new QLineEdit{};
	this->quantityEdit = new QLineEdit{};
	this->photoEdit = new QLineEdit{};
	QLabel* sizeLabel = new QLabel{ "&Size:" };
	sizeLabel->setBuddy(this->sizeEdit);
	QLabel* colorLabel = new QLabel{ "&Colour : " };
	colorLabel->setBuddy(this->colorEdit);
	QLabel* priceLabel = new QLabel{ "&Price:" };
	priceLabel->setBuddy(this->priceEdit);
	QLabel* quantityLabel = new QLabel{ "&Quantity:" };
	quantityLabel->setBuddy(this->quantityEdit);
	QLabel* photoLabel = new QLabel{ "&Link:" };
	photoLabel->setBuddy(this->photoEdit);
	formLayout->addRow(sizeLabel, this->sizeEdit);
	formLayout->addRow(colorLabel,this->colorEdit);
	formLayout->addRow(priceLabel,this->priceEdit);
	formLayout->addRow(quantityLabel, this->quantityEdit);
	formLayout->addRow(photoLabel, this->photoEdit);
	vLayout->addWidget(dressDataWidget);

	QWidget* buttonsWidget = new QWidget{};
	QHBoxLayout* hLayout = new QHBoxLayout{ buttonsWidget };
	this->addButton = new QPushButton("ADD");
	this->updateButton = new QPushButton("UPDATE");
	this->deleteButton = new QPushButton("DELETE");
	this->filterButton = new QPushButton("VIEW");
	this->exitButton = new QPushButton("EXIT");
	this->comboBox = new QComboBox();
	hLayout->addWidget(this->addButton);
	hLayout->addWidget(this->updateButton);
	hLayout->addWidget(this->deleteButton);
	hLayout->addWidget(this->filterButton);
	vLayout->addWidget(buttonsWidget);

	QWidget* belowSide = new QWidget{};
	QVBoxLayout* bLayout = new QVBoxLayout{ belowSide };
	QWidget* closeWidget = new QWidget{};
	QHBoxLayout*clayout = new QHBoxLayout{ closeWidget };
	clayout->addWidget(this->exitButton);
	bLayout->addWidget(closeWidget);
	


	layout->addWidget(this->dressesList);
	layout->addWidget(middleSide);
	layout->addWidget(belowSide);

	
	


}

int DressGUI::getSelectedIndex()
{
	if (this->dressesList->count() == 0)
		return -1;

	
	QModelIndexList index = this->dressesList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->sizeEdit->clear();
		this->colorEdit->clear();
		this->priceEdit->clear();
		this->quantityEdit->clear();
		this->photoEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void DressGUI::connectSignalsAndSlots()
{
	QObject::connect(this, SIGNAL(dressUpdatedSignal()), this, SLOT(populateList()));
	QObject::connect(this, &DressGUI::dressUpdatedSignal, this, &DressGUI::populateList);
	QObject::connect(this->dressesList, &QListWidget::itemSelectionChanged, this, [this]() {this->listItemChanged(); });

	// add button connections
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addButtonHandler()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteButtonHandler()));
	QObject::connect(this->updateButton,SIGNAL(clicked()),this,SLOT(updateButtonHandler()));
	//QObject::connect(this->exitButton,SIGNAL(clicked()),this,SLOT(quit()));
	QObject::connect(this->exitButton, &QPushButton::clicked, this, &QApplication::quit);
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(openComboBox()));
	QObject::connect(this->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeText()));
	// connect the addDress signal to the addDress slot, which adds a dress to vector
	QObject::connect(this, SIGNAL(addDressSignal(const std::string &, const std::string&, double , int , const std::string&)), this, SLOT(addDress(const std::string&, const std::string&, double , int, const std::string&)));

	
	

}

void DressGUI::shortList() 
{
	
	if (this->shortdressesList->count() > 0)
		this->shortdressesList->clear();

	for (auto d : this->dresses)
	{
		QString itemInList = QString::fromStdString(d.getSize() + " - " + d.getColour());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		this->shortdressesList->addItem(item);
	}

	// set the selection on the first item in the list
	if (this->dresses.size() > 0)
		this->shortdressesList->setCurrentRow(0);
}

void DressGUI::detailedList()
{

	if (this->shortdressesList->count() > 0)
		this->shortdressesList->clear();

	for (auto d : this->dresses)
	{
		QString itemInList = QString::fromStdString(d.getSize() + " - " + d.getColour()+" - "+d.getPhoto()+" - "+ std::to_string(d.getPrice()));
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		this->shortdressesList->addItem(item);
	}

	// set the selection on the first item in the list
	if (this->dresses.size() > 0)
		this->shortdressesList->setCurrentRow(0);
}



void DressGUI::populateList()
{
	if (this->dressesList->count() > 0)
		this->dressesList->clear();

	for (auto d : this->dresses)
	{
		QString itemInList = QString::fromStdString(d.getSize() + " - " + d.getColour()+" - "+d.getPhoto()+" -quantity: "+std::to_string(d.getQuantity())+" pret:"+std::to_string(d.getPrice()));
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		this->dressesList->addItem(item);
	}

	// set the selection on the first item in the list
	if (this->dresses.size() > 0)
		this->dressesList->setCurrentRow(0);
}

void DressGUI::listItemChanged()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;

	// get the song at the selected index
	if (idx >= this->dresses.size())
		return;
	Dress d = this->dresses[idx];

	this->sizeEdit->setText(QString::fromStdString(d.getSize()));
	this->colorEdit->setText(QString::fromStdString(d.getColour()));
	this->priceEdit->setText(QString::number(d.getPrice()));
	this->quantityEdit->setText(QString::number(d.getQuantity()));
	this->photoEdit->setText(QString::fromStdString(d.getSize()));
	
}
void DressGUI::addButtonHandler()
{
	// read data from the textboxes and add the new dress
	QString size = this->sizeEdit->text();
	QString color = this->colorEdit->text();
	QString price = this->priceEdit->text();
	QString quantity = this->quantityEdit->text();
	QString photo = this->photoEdit->text();

	// emit the add Drress signal
	emit addDressSignal(size.toStdString(), color.toStdString(), price.toDouble(),quantity.toInt(),photo.toStdString());

}

void DressGUI::updateButtonHandler()
{
	int idx = this->getSelectedIndex();

	if (idx < 0 || idx >= this->dresses.size())
		return;
	this->dresses.erase(this->dresses.begin() + idx);
	QString size = this->sizeEdit->text();
	QString color = this->colorEdit->text();
	QString price = this->priceEdit->text();
	QString quantity = this->quantityEdit->text();
	QString photo = this->photoEdit->text();

	emit addDressSignal(size.toStdString(), color.toStdString(), price.toDouble(), quantity.toInt(), photo.toStdString());


}

void DressGUI::deleteButtonHandler()
{
	// get the selected index and delete the gene
	int idx = this->getSelectedIndex();

	if (idx < 0 || idx >= this->dresses.size())
		return;

	this->dresses.erase(this->dresses.begin() + idx);

	// emit the signal: the genes were updated
	emit dressUpdatedSignal();
}

void DressGUI::exitButtonHandler()
{
	QApplication:quick_exit;
}


void DressGUI::addDress(const std::string & size, const std::string & colour, double price, int quantity, const std::string & photo)
{
	this->dresses.push_back(Dress{ size,colour,price,quantity,photo });
	emit dressUpdatedSignal();
}
void DressGUI::changeText()
{
	if (this->comboBox->currentText() == "Detailed") 
	{
		detailedList();
	}
	else 
	{
		shortList();
	}
}
