#include "graphic.h"

Graphic::Graphic(Controller* cont, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->makePlot();
}

Graphic::~Graphic()
{
	

}

void Graphic::makePlot()
{
	QLinearGradient gradient(0, 1, 1, 0);
	gradient.setColorAt(0, QColor(204, 204, 255));
	gradient.setColorAt(0.38, QColor(230, 230, 255));
	gradient.setColorAt(1, QColor(230, 230, 255));
	ui.customPlot->setBackground(QBrush(gradient));

	// create empty bar chart objects:
	
	QCPBars *red = new QCPBars(ui.customPlot->xAxis, ui.customPlot->yAxis);
	QCPBars *green = new QCPBars(ui.customPlot->xAxis, ui.customPlot->yAxis);
	QCPBars *pink = new QCPBars(ui.customPlot->xAxis, ui.customPlot->yAxis);
	QCPBars *burgundy = new QCPBars(ui.customPlot->xAxis, ui.customPlot->yAxis);
	QCPBars *black = new QCPBars(ui.customPlot->xAxis, ui.customPlot->yAxis);
	QCPBars *blue = new QCPBars(ui.customPlot->xAxis, ui.customPlot->yAxis);
	QCPBars *white = new QCPBars(ui.customPlot->xAxis, ui.customPlot->yAxis);
	QCPBars *grey = new QCPBars(ui.customPlot->xAxis, ui.customPlot->yAxis);
	
	green->setAntialiased(false);
	pink->setAntialiased(false);
	red->setAntialiased(false);
	red->setStackingGap(1);
	green->setStackingGap(1);
	pink->setStackingGap(1);
	// set names and colors:
	red->setName("Red ");
	red->setPen(QPen(QColor(255, 0, 0)));
	red->setBrush(QColor(255, 0, 0));

	green->setName("Green ");
	green->setPen(QPen(QColor(0, 179, 60)));
	green->setBrush(QColor(0, 179, 60));

	pink->setName("Pink");
	pink->setPen(QPen(QColor(255, 153, 255)));
	pink->setBrush(QColor(255, 153, 255));

	burgundy->setName("Burgundy");
	burgundy->setPen(QPen(QColor(255, 153, 255)));
	burgundy->setBrush(QColor(128, 0, 0));

	black->setName("Black");
	black->setPen(QPen(QColor(0, 0, 0)));
	black->setBrush(QColor(0, 0, 0));

	white->setName("White");
	white->setPen(QPen(QColor(255, 255, 255)));
	white->setBrush(QColor(255, 255, 255));

	grey->setName("Grey");
	grey->setPen(QPen(QColor(166, 166, 166).lighter(130)));
	grey->setBrush(QColor(166, 166, 166));

	blue->setName("Blue");
	blue->setPen(QPen(QColor(102, 179, 255)));
	blue->setBrush(QColor(102, 179, 255));
	
	// prepare x axis with country labels:
	QVector<double> ticks;
	QVector<QString> labels;
	ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8;
	labels << "Red" << "Green" << "Pink" << "Burgundy" << "Black" << "Blue" << "White"<<"Grey";
	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, labels);
	ui.customPlot->xAxis->setTicker(textTicker);
	ui.customPlot->xAxis->setTickLabelRotation(60);
	ui.customPlot->xAxis->setSubTicks(false);
	ui.customPlot->xAxis->setTickLength(0, 4);
	ui.customPlot->xAxis->setRange(0, 8);
	ui.customPlot->xAxis->setBasePen(QPen(Qt::black));
	ui.customPlot->xAxis->setTickPen(QPen(Qt::black));
	ui.customPlot->xAxis->grid()->setVisible(true);
	ui.customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
	ui.customPlot->xAxis->setTickLabelColor(Qt::black);
	ui.customPlot->xAxis->setLabelColor(Qt::black);

	// prepare y axis:
	ui.customPlot->yAxis->setRange(0, 12.1);
	ui.customPlot->yAxis->setPadding(5); 
	ui.customPlot->yAxis->setLabel("DressUP Shop\nCatalogue (2017)");
	QFont titleFont = font();
	titleFont.setPointSize(20);
	ui.customPlot->yAxis->setLabelFont(titleFont);
	ui.customPlot->yAxis->setBasePen(QPen(Qt::black));
	ui.customPlot->yAxis->setTickPen(QPen(Qt::black));
	ui.customPlot->yAxis->setSubTickPen(QPen(Qt::black));
	ui.customPlot->yAxis->grid()->setSubGridVisible(true);
	ui.customPlot->yAxis->setTickLabelColor(Qt::black);
	ui.customPlot->yAxis->setLabelColor(Qt::black);
	ui.customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
	ui.customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(1, 0, 0), 0, Qt::DotLine));

	// Add data:
	QVector<double> redData,greenData,pinkData,burgundyData,blackData,blueData,whiteData,greyData;
	
	redData << 1 * 3 << 0 << 0 << 0 << 0 << 0 << 0 <<0;
	greenData << 0 << 1*4 << 0 << 0 << 0 << 0 << 0 << 0;
	pinkData << 0<<0<<1*2 << 0 << 0 << 0 << 0 << 0 << 0;
	burgundyData << 0 << 0 << 0 << 1 * 4 << 0 << 0 << 0 << 0 << 0;
	blackData << 0 << 0 << 0 << 0 << 1 * 6 << 0 << 0 << 0 << 0;
	blueData << 0 << 0 << 0 << 0 << 0 << 1 * 10 << 0 << 0 << 0;
	whiteData << 0 << 0 << 0 << 0 << 0 << 0 << 1 * 7 << 0 ;
	greyData << 0 << 0 << 0 << 0 << 0 << 0 << 0 <<1*1;
		
	red->setData(ticks, redData);
	green->setData(ticks, greenData);
	pink->setData(ticks, pinkData);
	burgundy->setData(ticks, burgundyData);
	black->setData(ticks, blackData);
	blue->setData(ticks, blueData);
	white->setData(ticks, whiteData);
	grey->setData(ticks, greyData);
	

	// setup legend:
	ui.customPlot->legend->setVisible(true);
	ui.customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
	ui.customPlot->legend->setBrush(QColor(179, 255, 179));
	ui.customPlot->legend->setBorderPen(Qt::SolidLine);
	QFont legendFont = font();
	legendFont.setPointSize(10);
	ui.customPlot->legend->setFont(legendFont);
	ui.customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
