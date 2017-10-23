#include "Tests.h"
#include "Controller.h"

void testDress()
{
	Dress d;
	
	assert(d.getPrice() == 0);
	assert(d.getQuantity() == 0);
	d = d;
	assert(d.getPrice() == 0);
	Dress d1 = { "M","red",45,4,"www" };
	Dress d2 = { "L","black",30,2,"www.jgjh"};
	assert((d1 == d2) == false);
	assert(d1.getPrice() == 45);
	assert(d2.getPrice() == 30);
	assert(d1.getQuantity() == 4);
	assert(d1.getSize()=="M");
	assert(d1.getColour()=="red");
	assert(d1.getPhoto() == "www");
	d.destroyDress();
}

void testRepository()
{
	Repository repoT;
	repoT = repoT;
	assert(repoT.isEmpty() == true);
	Dress d1{ "S", "Red",150,3, "https://www.pinterest.com/pin/491173903096396967/://www.youtube.com/watch?v=2fngvQS_PmQ" };
	assert(repoT.addDress(d1) == 1);
	assert(repoT.getCapacity() == 1);
	assert(repoT.getOnPosition(0).getPrice() == 150);
	assert(repoT.addDress(d1) == -1);
	assert(repoT.getCapacity() == 1);
	Dress d;
	assert(repoT.findBySize("M") == d);
	Dress d2{ "M", "Burgundy",100,4, "https://www.pinterest.com/pin/491173903089888407/" };
	Dress d3{ "L", "Black",175,3,"https://www.pinterest.com/pin/491173903096382341/" };
	Dress d4{ "S","Green",185,4,"https://www.pinterest.com/pin/491173903096382343/" };
	repoT.addDress(d2);
	repoT.addDress(d3);
	repoT.addDress(d4);
	assert(repoT.getCapacity() == 4);
	d2 = d1;
	assert(d2 == d1);
	assert(repoT.findBySize("L") == d3);
	std::vector<Dress> vec{10};
	vec = repoT.getDresses();
	assert(vec.size() == 4);
	std::vector<Dress> v;
	v.push_back(d3);
	v.push_back(d4);
	Repository r{ v };
	assert(r.getOnPosition(1)== d4);
	Repository r1 = r;
	assert(r1.findBySize("M") == d);
	d.destroyDress();
	d1.destroyDress();
	d2.destroyDress();
	d3.destroyDress();
	d4.destroyDress();


}

void testCatalogue()
{
	Catalogue catalogT;
	catalogT.open();
	assert(catalogT.isEmpty() == true);
	Dress d;
	Dress d1{ "S", "Red",150,3, "https://www.pinterest.com/pin/491173903096396967/://www.youtube.com/watch?v=2fngvQS_PmQ" };
	catalogT.add(d1);
	assert(catalogT.isEmpty() == false);
	Dress d2{ "M", "Burgundy",100,4, "https://www.pinterest.com/pin/491173903089888407/" };
	Dress d3{ "L", "Black",175,3,"https://www.pinterest.com/pin/491173903096382341/" };
	Dress d4{ "S","Green",185,4,"https://www.pinterest.com/pin/491173903096382343/" };
	catalogT.add(d2);
	catalogT.add(d3);
	catalogT.add(d4);
	catalogT.open();
	assert(catalogT.next().getColour() == "Burgundy");
	assert(catalogT.getCurrentDress().getPrice() == 100);
	catalogT.next();
	catalogT.next();
	catalogT.seeAll();

	
}


void testShoppingBasket()
{
	ShoppingBasket b;
	Dress s;
	Dress b1 = { "S", "Red",150,3, "https://www.pinterest.com/pin/491173903096396967/://www.youtube.com/watch?v=2fngvQS_PmQ" };
	b.add(b1);
	assert(b.isEmpty() == false);
	assert(b.showPrice() == 150);
	Dress b2={ "L", "Black", 250, 3, "https://www.pinterest.com/pin/491173903097333898/" };
	b.add(b2);
	assert(b.showPrice() == 400);
	assert(b.getLen() ==2);
	assert(b.getDress(0) == b1);
	std::vector<Dress> basket = b.showShoppingBasket();
	assert(basket.empty() == false);

}

void testController()
{
	
	Repository repo{};
	FileShoppingBasket* basket;
	Controller ctrl{ repo,basket};
	assert(ctrl.getRepo().getCapacity() == 0);
	double p1,p2,p3,p4;
	int q1, q2,q3,q4;
	p1 = 100; p2 = 200; q1 = 5; q2 = 6;
	ctrl.addDressRepo("M", "Burgundy", p1, q1, "https://www.pinterest.com/pin/491173903089888407/");
	assert(ctrl.getRepo().getCapacity() == 1);
	ctrl.addDressRepo("M", "blue", p2, q2, "www.com");
	assert(ctrl.getRepo().getCapacity() == 2);
	assert(ctrl.getBasket()->isEmpty() == true);
	Dress d2{ "L", "Black",250,3, "https://www.pinterest.com/pin/491173903097333898/" };
	assert(ctrl.showCartPrice() == 0);
	ctrl.addDressToShoppingBasket(d2);
	assert(ctrl.getBasket()->getLen() == 1);
	std::vector<Dress> &b = ctrl.showBasket();
	assert(b.size() == 1);
	assert(ctrl.getCatalogue().isEmpty() == true);
	assert(ctrl.showCartPrice() == 250);
	p3 = 175; q3 = 3;
	p4 = 185; q4 = 4;
	ctrl.addDressRepo("L", "Black", p3, q3, "https://www.pinterest.com/pin/491173903096382341/");
	ctrl.addDressRepo("S", "Green", p4, q4, "https://www.pinterest.com/pin/491173903096382343/");
	ctrl.addAllDressesbySize("M");
	assert(ctrl.getCatalogue().showAllC().size() == 2);
	ctrl.addAllDresses();
	Dress d = ctrl.startCatalogue();
	assert(d.getColour()== "Burgundy");
	Dress d25 = ctrl.nextDressCatalogue();
	assert(d25.getColour() == "blue");
	ctrl.openDress();
	ctrl.displayDressC();
	Controller ctrl2 = ctrl;
}

void testAll() 
{
	testDress();
	testRepository();
	testShoppingBasket();
	testCatalogue();
	testController();
	
}
