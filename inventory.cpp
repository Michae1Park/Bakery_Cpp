//Key things to demonstrate

//####################################################################
// Design Pattern/OOP : Factory Method -- geeksforgeeks reason

// Usage of STL Libraries -- some data structure
// Functionality : some inventory application

// unit test with boost, will not work?

// Tree :: boost :: graph library

//#####################################################################

// Inventory app that uses factory method and some ds,
// +  maybe some searching algorithms (BFS, DFS)


// Use Observer Pattern for inventory system

//--------------------------------------------------------------
// 1) separate item and inven in case i want to change inventory structure later
// 2) used map in inventory because it is quick to add, delete, search O(1), unique ID
// 3) create_new_item function instead of constructor for user input + give more protection cuz it doesn't change like price and stock

#include <iostream>

class Item {
private:
	int id_;	// need int bound id checker
	std::string lable_;
	int stock_;
	int price_;

public:
	void createNewItem(int id, int stock, int price, std::string lable);
	void modifyPrice(int price);
	void modifyStock(int stock); // consistently use snake_case
	int getID(void);
	std::string getLabel(void);
	int getPrice(void);
	int getStock(void);
	// void show_detail(void);
};
void Item::createNewItem(int id, int stock, int price, std::string lable) {
	id_ = id;
	stock_ = stock;
	price_ = price;
	lable_ = lable;
}
void Item::modifyPrice(int price){
	price_ = price;
}
void Item::modifyStock(int stock){
	stock_ = stock;
}
int Item::getId(void){
	return id_;
}
std::string Item::getLabel(void){
	return lable_;
}
int Item::getStock(void){
	return stock_;
}
int Item::getPrice(void){
	return price_;
}

// item::show_detail(void){
// 	std::cout<<"id: " << id_ << std::endl;
// 	std::cout<<"lable: " << lable_ << std::endl;
// 	std::cout<<"stock: " << stock_ << std::endl; 
// 	std::cout<<"price: " << price_ << std::endl;
// }

class Subject {
public:
    virtual void registerObserver() = 0;
    virtual void unregisterObserver() = 0;
    virtual void notifyObservers() = 0;
};

class Inventory : public Subject{
private:
	std::unordered_map<int, Item> inventory; //maybe headerfile later?
public:
	void addItem(void);
	void removeItem(void);
	void sellItem(void);
	void displayAll(void);
};

void inventory::add_item(void)
{
	std::cout<<"\nEnter the item category    : ";
	std::cin>>name[z];
	std::cout<<"Enter the item id        : ";
	std::cin>>code[z];
	std::cout<<"Enter the price of the item: ";
	std::cin>>price[z];
	
}


void item :: delete_(void)
{
	int i,j;
	// clrscr();

	std::cout<<"\nPlease enter the item code:";
	std::cin>>i;
	for(j=0;j<z;j++)
	{
	  if(code[j]==i)
	  {
		price[j]=0;
		std::cout<<"\nThe item is deleted from the list.";
		getch();
		break;
	  }
	}
}

void item :: sell_(void)
{
	char a;
	int i,j;
	float total_price=0;
	// clrscr();

	std::cout<<"\nEnter the item code:";
	std::cin>>i;
	for(j=0;j<z;j++)
	{
	  if (code[j]==i)
	  {
		if(price[j]==0)
		{
		  std::cout<<"\nSorry.There is no item left in this catefory.";
		  std::cout<<"\nDo you want to buy another item? y\\n"<<endl;
		  std::cin>>a;
		  if (a=='y')
		  {
		std::cout<<"\nEnter the item code:";
		std::cin>>i;
		j=-1;
		  }
		  else if (a=='Y')
		  {
		std::cout<<"\nEnter the item code:";
		std::cin>>i;
		j=-1;
		  }
		  else
		  {
		if (total_price!=0)
		{
		  std::cout<<"\nYour total price is: ";
		  std::cout<<total_price<<" Taka."<<"\nThank You.";
		}
		std::cout<<"Bye...bye...";
		break;
		  }
		}
		else
		{
		  std::cout<<"Item category is: "<<name[j];
		  std::cout<<"\nItem price is   : "<<price[j]<<"tk."<<std::endl;
		  total_price+=price[j];
		  price[j]=0;
		  std::cout<<"\nDo you want to buy another item:y\\n";
		  std::cin>>a;
		  if (a=='y')
		  {
		std::cout<<"\nEnter the item code:";
		std::cin>>i;
		j=-1;
		  }
		  else if (a=='Y')
		  {
		std::cout<<"\nEnter the item code:";
		std::cin>>i;
		j=-1;
		  }
		  else
		  {  clrscr();
		std::cout<<"\nYour total price is: ";
		std::cout<<total_price<<"Taka."<<"\nThank You.";
		break;
		  }
		}
	  }
	}
	getch();
}

void item :: display_()
{
	int i,j=1;
	// clrscr();

	for(i=0;i<z;i++)
	{
		std::cout<<j<<".Item category is: "<<name[i];
		std::cout<<"\n  Item code is    : "<<code[i];
		std::cout<<"\n  Item price is   : "<<price[i]<<"tk."<<std::endl<<std::endl;
		j++;
	}
	getch();
}



int main (){
	int i;
	item shoping_mall;
	
	shoping_mall.initial();

	while(1){
	  std::cout<<"\n   What do you want to do?"<<std::endl;
	  std::cout<<"\n1: Add a new item.";
	  std::cout<<"\n2: Delete an item.";
	  std::cout<<"\n3: Sale an item.";
	  std::cout<<"\n4: Display all items.";
	  std::cout<<"\n5: Exit"<<std::endl;
	  std::cout<<"\n\n Choose a number:";
	  std::cin>>i;

	  switch(i)
	  {
		case 1:
		{
		  shoping_mall.add_();
		  break;
		}
		case 2:
		{
		  shoping_mall.delete_();
		  break;
		}
		case 3:
		{
		  shoping_mall.sell_();
		  break;
		}
		case 4:
		{
		  shoping_mall.display_();
		  break;
		}

		case 5:
		{
		  std::cout<<"Good Bye! Thank you.";
		  break;
		}
	  }
	  if (i==5)
		break;
	  // clrscr();
	}
	getch();
	return 0;
}

