#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;


#pragma region Function

int GetDate()
{
	time_t getTime1 = time(0);
	tm* getTime2 = localtime(&getTime1);;
	return getTime2->tm_yday;
}

string GetString()
{
	cin.ignore();
	string s;
	getline(cin, s);
	return s;
}

int GetInt(int max)
{
	int i;
	cin >> i;

	if (i == 0)
		return 0;

	while (i > max)
	{
		cout << "Invalid input\n";
		cin >> i;
	}

	return i;
}

float GetFloat()
{
	float i;
	cin >> i;
	return i;
}

#pragma endregion

#pragma region Inventory	

class Inventory {

private:
	//attribute
	int ProductCode;
	string ProductName;
	string Descriptions;
	float CostPrice;
	float SellingPrice;
	int UnitsInStock;
	string Category;

public:
	//constructor
	Inventory()
	{
		ProductCode = 0;
		ProductName = "";
		Descriptions = "";
		CostPrice = 0;
		SellingPrice = 0;
		UnitsInStock = 0;
		Category = "";
	}

	Inventory(int code, string name, string desc, float costprice, float sellingprice, int stock, string category)
	{
		ProductCode = code;
		ProductName = name;
		Descriptions = desc;
		CostPrice = costprice;
		SellingPrice = sellingprice;
		UnitsInStock = stock;
		Category = category;
	}

	//functions
	void updateAll(int code, string name, string desc, float costprice, float sellingprice, int stock, string category)
	{
		ProductCode = code;
		ProductName = name;
		Descriptions = desc;
		CostPrice = costprice;
		SellingPrice = sellingprice;
		UnitsInStock = stock;
		Category = category;
	}

	void updateProductCode(int code) 
	{
		ProductCode = code;
	}
	void updateProductName(string name) 
	{
		ProductName = name;
	}
	void updateDescriptions(string desc) 
	{
		Descriptions = desc;
	}
	void updateCostPrice(float costprice)
	{
		CostPrice = costprice;
	}
	void updateSellingPrice(float sellingprice) 
	{
		SellingPrice = sellingprice;
	}
	void updateUnitsInStock(int stock) 
	{
		UnitsInStock = stock;
	}
	void updateCategory(string category)
	{
		Category = category;
	}

	string getProductName()
	{
		return ProductName;
	}
	
	string getDescriptions()
	{
		return Descriptions;
	}

	int getProductCode()
	{
		return ProductCode;
	}

	float getCostPrice()
	{
		return CostPrice;
	}

	float getSellingPrice()
	{
		return SellingPrice;
	}

	int getUnitsInStock()
	{
		return UnitsInStock;
	}

	string getCategory()
	{
		return Category;
	}

	void deleteInventory()
	{
		ProductCode = 0;
		ProductName = "";
		Descriptions = "";
		CostPrice = 0;
		SellingPrice = 0;
		UnitsInStock = 0;
		Category = "";
	}
};

Inventory i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
Inventory AllInventory[10] = {i1, i2, i3, i4, i5, i6, i7, i8, i9, i10};

void addInventory(Inventory source)
{
	for (int t = 0; t < 10; t++)
	{
		if (AllInventory[t].getProductCode() == 0)
		{
			AllInventory[t] = source;
			break;
		}
	}
}

void deleteInventory(int q)
{
	AllInventory[q-1].deleteInventory();
	
	for (int t1 = 0; t1 < 10; t1++)
	{
		if (AllInventory[t1].getProductCode() == 0)
		{
			for (int t2 = t1; t2 < 10; t2++)
			{
				if (AllInventory[t2+1].getProductCode() != 0)
					AllInventory[t2] = AllInventory[t2 + 1];
				else
					AllInventory[t2].deleteInventory();
			}
		}
	}
}

Inventory* searchInventory(int q)
{
	return &AllInventory[q-1];
}

float calculateTotalPrice()
{
	float total = 0;
	for (int t = 0; t < 10; t++)
	{
		total += AllInventory[t].getSellingPrice();
	}
	return total;
}

int calculateInventory()
{
	for (int t = 0; t < 10; t++)
	{
		if (AllInventory[t].getProductCode() == 0)
			return t;
	}
	return 10;
}

void InventoryMenu()
{

	while (true)
	{
		system("cls");

		string title = "Inventory Menu";
		cout << "________________________________________________\n";
		cout << endl;
		cout << setw((unsigned long long)(title.size() / 2) + 25) << title << endl;
		cout << "________________________________________________\n";
		cout << endl;

		cout << "_____________________________________\n";
		cout << "         Current Inventory :\n\n";

		for (int t = 0; t < calculateInventory(); t++)
		{
			cout << "         " << "[" << t+1 << "] " << AllInventory[t].getProductName() << endl;;
		}
		cout << "_____________________________________\n";

		cout << endl;

		cout << "   1. Add Inventory\n";
		cout << "   2. Delete Inventory\n";
		cout << "   3. Update Inventory\n";
		cout << "   4. Seach Inventory Details\n";
		cout << "   0. Exit to menu\n\n";

		cout << "Which option you would like to choose : ";
		int t1 = GetInt(4);

		cout << endl;

		if (t1 == 1)
		{
			if (calculateInventory() == 10)
			{
				cout << "Inventory is full. Please delete an inventory to proceed...";
				system("pause");
			}
			else
			{
				int code;
				string name;
				string desc;
				float costprice;
				float sellingprice;
				int stock;
				string category;

				cout << "Product Name : ";
				name = GetString();

				cout << "Product Code (0 is not allowed) : ";
				cin >> code;

				cout << "Description : ";
				desc = GetString();

				cout << "Cost Price : ";
				cin >> costprice;

				cout << "Selling Price : ";
				cin >> sellingprice;

				cout << "Units in Stock : ";
				cin >> stock;

				cout << "Category : ";
				category = GetString();

				AllInventory[calculateInventory()].updateAll(code, name, desc, costprice, sellingprice, stock, category);

				cout << endl;
				cout << "Inventory successfully added!\n\n";

				system("pause");
			}

		}
		else if (t1 == 2)
		{
			cout << "Which inventory would you like to delete ? : ";
			int t2 = GetInt(calculateInventory());

			deleteInventory(t2);

			cout << endl;
			cout << "Inventory successfully deleted!\n\n";

			system("pause");
		}
		else if (t1 == 3)
		{
			cout << "Which inventory would you like to update ? : ";
			int t3 = GetInt(calculateInventory()) - 1 ;

			cout << endl;
			cout << "[1]Product Name : " << AllInventory[t3].getProductName() << endl;

			cout << "[2]Product Code : " << AllInventory[t3].getProductCode() << endl;;

			cout << "[3]Descriptions : " << AllInventory[t3].getDescriptions() << endl;

			cout << "[4]Cost Price : " << AllInventory[t3].getCostPrice() << endl;

			cout << "[5]Selling Price : " << AllInventory[t3].getSellingPrice() << endl;

			cout << "[6]Units in Stock : " << AllInventory[t3].getUnitsInStock() << endl;

			cout << "[7]Category : " << AllInventory[t3].getCategory() << endl;

			cout << endl;
			cout << "Which attribute would you like to update  ? : ";
			int t4 = GetInt(7);

			if (t4 == 1)
			{
				cout << "New product name : ";
				AllInventory[t3].updateProductName(GetString());
			}
			else if (t4 == 2)
			{
				cout << "New product code : ";
				AllInventory[t3].updateProductCode(GetInt(9999));
			}
			else if (t4 == 3)
			{
				cout << "New descriptions : ";
				AllInventory[t3].updateDescriptions(GetString());
			}
			else if (t4 == 4)
			{
				cout << "New cost price : ";
				AllInventory[t3].updateCostPrice(GetFloat());
			}
			else if (t4 == 5)
			{
				cout << "New selling price : ";
				AllInventory[t3].updateSellingPrice(GetFloat());
			}
			else if (t4 == 6)
			{
				cout << "New units in stock : ";
				AllInventory[t3].updateUnitsInStock(GetInt(9999));
			}
			else if (t4 == 7)
			{
				cout << "New category : ";
				AllInventory[t3].updateCategory(GetString());
			}
			
			cout << endl;
			cout << "Inventory successfully updated!\n\n";

			system("pause");
		}
		else if (t1 == 4)
		{
			
			cout << "Which inventory would you like to search for details ? : ";
			Inventory* t5 = searchInventory(GetInt(calculateInventory()));

			cout << endl;

			cout << "Product Name : " << t5->getProductName() << endl;

			cout << "Product Code : " << t5->getProductCode() << endl;;

			cout << "Descriptions : " << t5->getDescriptions() << endl;

			cout << "Cost Price : " << t5->getCostPrice() << endl;

			cout << "Selling Price : " << t5->getSellingPrice() << endl;

			cout << "Units in Stock : " << t5->getUnitsInStock() << endl;

			cout << "Category : " << t5->getCategory() << endl;

			cout << endl;
			cout << "Inventory search succeeded!\n\n";

			system("pause");
		}
		else if (t1 == 0)
		{
			cout << "Returning to menu...\n";
			system("pause");
			break;
		}
	}

}

#pragma endregion

#pragma region PointOfSale

class PointOfSale
{
private:
	//Inventory ci1, ci2, ci3, ci4, ci5, ci6, ci7, ci8, ci9, ci10;
	Inventory copyOfAllInventories[21];// = { ci1, ci2, ci3, ci4, ci5, ci6, ci7, ci8, ci9, ci10 };

	int DateOfTransaction;
	//int ProductCode;
	string Description;
	int Quantity;
	//float UnitPrice;
	float TotalPrice ;
	int Queue ;

public:
	PointOfSale()
	{
		Quantity = 0;
		Queue = 0;
		DateOfTransaction = 0;
	    TotalPrice = 0.00;
	}

	void addInventory(Inventory i)
	{
		for (int t = 0; t < 10; t++)
		{
			if (copyOfAllInventories[t].getProductCode() == 0)
			{
				copyOfAllInventories[t] = i;
				break;
			}
		}
	}

	void updateDateOfTransaction()
	{
		DateOfTransaction = GetDate();
	}

	void deleteInventory(int q)
	{
		copyOfAllInventories[q - 1].deleteInventory();

		for (int t1 = 0; t1 < 20; t1++)
		{
			if (copyOfAllInventories[t1].getProductCode() == 0)
			{
				for (int t2 = t1; t2 < 20; t2++)
				{
					if (copyOfAllInventories[t2 + 1].getProductCode() != 0)
						copyOfAllInventories[t2] = copyOfAllInventories[t2 + 1];
					else
						copyOfAllInventories[t2].deleteInventory();
				}
			}
		}
		DateOfTransaction = GetDate();
	}

	void updateQueue(int q)
	{
		Queue = q;
	}

	Inventory getPointOfSaleInventory(int n)
	{
		return copyOfAllInventories[n];
	}

	float getTotalPrice()
	{
		TotalPrice = 0.00;
		for (int t = 0; t < 10; t++)
		{
			if (copyOfAllInventories[t].getProductCode() == 0)
				break;
			TotalPrice += copyOfAllInventories[t].getSellingPrice();
		}
		return (TotalPrice);
	}

	int getDateOfTransaction()
	{
		return DateOfTransaction;
	}

	int getQueue()
	{
		return Queue;
	}

	int getQuantity()
	{
		for (int t = 0; t < 10; t++)
		{
			if (copyOfAllInventories[t].getProductCode() == 0)
				return t;
		}
		return 10;
	}

	void deletePointOfSale()
	{
		DateOfTransaction = 0;
		Description = "";
		TotalPrice = 0.00;
		Queue = 0;
	}

};

PointOfSale AllPointOfSale[999];

int calculatePointOfSale()
{
	for (int t = 0; t < 999; t++)
	{
		if (AllPointOfSale[t].getQueue() == 0)
			return t;
	}
}

void addPointOfSale(PointOfSale pos)
{
	for (int t = 0; t < 999; t++)
	{
		if (AllPointOfSale[t].getQueue() == 0)// value
		{
			AllPointOfSale[t] = pos;
			break;
		}
	}
}

void deletePointOfSale(int q)
{
	int numofsalebfrdelete = calculatePointOfSale();
	AllPointOfSale[q - 1].deletePointOfSale();

	for (int t1 = 0; t1 < numofsalebfrdelete; t1++)
	{
		if (AllPointOfSale[t1].getQueue() == 0)
		{
			for (int t2 = t1; t2 < 20; t2++)
			{
				if (AllPointOfSale[t2 + 1].getQueue() != 0)
					AllPointOfSale[t2] = AllPointOfSale[t2 + 1];
				else
					AllPointOfSale[t2].deletePointOfSale();
			}
		}
	}
}

void viewPointOfSale()
{
	for (int t = 0; t < calculatePointOfSale(); t++)
	{
		cout << "____________________________________\n";
		cout << endl;
		cout << "Customer " << AllPointOfSale[t].getQueue() << "  /  " << "Point of Sale " << AllPointOfSale[t].getQueue() << endl;
		cout << endl;

		for (int t1 = 0; t1 < AllPointOfSale[t].getQuantity(); t1++)
		{
			cout << t1 + 1 << ". " << AllPointOfSale[t].getPointOfSaleInventory(t1).getProductName() + "   " << AllPointOfSale[t].getPointOfSaleInventory(t1).getSellingPrice() << endl;;
		}

		cout << endl;
		cout << setw(20) << "Total Price : " << AllPointOfSale[t].getTotalPrice() << endl;
		cout << "____________________________________\n";
		cout << endl;
	}
}

void viewPointOfSaleDaily() 
{
	for (int t = 0; t < calculatePointOfSale(); t++)
	{
		cout << "____________________________________\n";
		cout << endl;
		cout << "Day " << AllPointOfSale[t].getDateOfTransaction() << endl;
		cout << "Customer " << AllPointOfSale[t].getQueue() << "  /  " << "Point of Sale " << AllPointOfSale[t].getQueue() << endl;
		cout << endl;

		for (int t1 = 0; t1 < AllPointOfSale[t].getQuantity(); t1++)
		{
			cout << t1 + 1 << ". " << AllPointOfSale[t].getPointOfSaleInventory(t1).getProductName() + "   " << AllPointOfSale[t].getPointOfSaleInventory(t1).getSellingPrice() << endl;;
		}

		cout << endl;
		cout << setw(20) << "Total Price : " << AllPointOfSale[t].getTotalPrice() << endl;
		cout << "____________________________________\n";
		cout << endl;
	}
}

void viewPointOfSaleWeekly()
{
	for (int t = 0; t < calculatePointOfSale(); t++)
	{
		cout << "____________________________________\n";
		cout << endl;
		cout << "Week " << AllPointOfSale[t].getDateOfTransaction()/7 << endl;
		cout << "Customer " << AllPointOfSale[t].getQueue() << "  /  " << "Point of Sale " << AllPointOfSale[t].getQueue() << endl;
		cout << endl;

		for (int t1 = 0; t1 < AllPointOfSale[t].getQuantity(); t1++)
		{
			cout << t1 + 1 << ". " << AllPointOfSale[t].getPointOfSaleInventory(t1).getProductName() + "   " << AllPointOfSale[t].getPointOfSaleInventory(t1).getSellingPrice() << endl;;
		}

		cout << endl;
		cout << setw(20) << "Total Price : " << AllPointOfSale[t].getTotalPrice() << endl;
		cout << "____________________________________\n";
		cout << endl;
	}
}

void PointOfSaleMenu()
{
	system("cls");

	string title = "Point Of Sale Menu";
	cout << "________________________________________________\n";
	cout << endl;
	cout << setw((unsigned long long)(title.size() / 2) + 25) << title << endl;
	cout << "________________________________________________\n";
	cout << endl;

	cout << "   1. Add inventory in Point of Sale\n";
	cout << "   2. Delete inventory in Point of Sale\n";
	cout << "   3. View sales record daily\n";
	cout << "   4. View sales record weekly\n";
	cout << "   5. Exit\n\n";

	cout << "Which option you would like to choose : ";
	int t1 = GetInt(5);

	cout << endl;

	if (t1 == 1)
	{
		viewPointOfSale();

		cout << "Which point of sale would you like to add inventory into ? : ";
		int t2 = GetInt(calculatePointOfSale());

		cout << endl;
		for (int t2 = 0; t2 < calculateInventory(); t2++)
		{
			cout << "   " << "[" << t2 + 1 << "] " << AllInventory[t2].getProductName() << endl;;
		}

		cout << endl;
		cout << "Which inventory would you like to add ? : ";
		int t3 = GetInt(calculateInventory());

		AllPointOfSale[t2 - 1].addInventory(AllInventory[t3 - 1]);

		cout << endl;
		cout << "Inventory successfully added into point of sale!";
	}
	else if(t1 == 2)
	{
		viewPointOfSale();

		cout << "Which point of sale would you like to delete inventory from ? : ";
		int t2 = GetInt(calculatePointOfSale());

		cout << endl;
		for (int t = 0; t < AllPointOfSale[t2 - 1].getQuantity(); t++)
		{
			cout << "   " << "[" << t + 1 << "] " << AllPointOfSale[t2 - 1].getPointOfSaleInventory(t).getProductName() << endl;;
		}

		cout << endl;
		cout << "Which inventory would you like to delete ? : ";
		int t3 = GetInt(AllPointOfSale[t2 - 1].getQuantity());

		AllPointOfSale[t2 - 1].deleteInventory(t3);

		cout << endl;
		cout << "Inventory successfully deleted from point of sale!";
	}
	else if (t1 == 3)
	{
		viewPointOfSaleDaily();
	}
	else if (t1 == 4)
	{
		viewPointOfSaleWeekly();
	}
	else if (t1 == 5)
	{
		cout << endl;
		cout << "Returning to menu...\n";
		system("pause");
	}
}

#pragma endregion

#pragma region MainMenu

void MainMenu()
{
	system("cls");

	string title = "What's on our menu?";
	cout << "________________________________________________\n";
	cout << endl;
	cout << setw((unsigned long long)(title.size() / 2) + 25) << title << endl;
	cout << "________________________________________________\n";
	cout << endl;

	int t1 = calculateInventory();
	for (int t2 = 0; t2 < t1; t2++)
	{
		cout << "   " << t2 + 1 << ". " << AllInventory[t2].getProductName() << setw((unsigned long long)25 - AllInventory[t2].getProductName().size() + 5 ) /*allign*/ 
			<< "RM" << setprecision(2) << fixed << AllInventory[t2].getSellingPrice() << endl;
	}

	cout << endl;

	PointOfSale pos;

	cout << "How many foods and beverages would you like to order ? (Max 20) : ";
	int NumOfFoodAndBeverages = GetInt(20);
	int cNumOfFoodAndBeverages = NumOfFoodAndBeverages;


	while (cNumOfFoodAndBeverages != 0)
	{
		cout << "Order  " << -(cNumOfFoodAndBeverages - NumOfFoodAndBeverages) + 1 << ": ";
		int t3 = GetInt(t1) - 1;

		pos.addInventory(AllInventory[t3]);

		cNumOfFoodAndBeverages--;
	}

	cout << endl;

	cout << "Order Details : \n\n";
	for (int t = 0; t < NumOfFoodAndBeverages; t++)
	{
		cout << t + 1 << ". " << pos.getPointOfSaleInventory(t).getProductName() + "   " << pos.getPointOfSaleInventory(t).getSellingPrice() << endl;;
	}

	cout << "Total Price : " << pos.getTotalPrice() << endl;

	pos.updateQueue(calculatePointOfSale()+1);
	pos.updateDateOfTransaction();

	addPointOfSale(pos);

	cout << endl;

	cout << "Returning to menu...\n";
	system("pause");
}

#pragma endregion

int main()
{
	AllInventory[0].updateAll(1, "Theta Burger", "", 12.00, 13.00, 20, "Burger");
	AllInventory[1].updateAll(1, "Steamed Chessburger", "", 14.50, 14.50, 20, "Burger");
	AllInventory[2].updateAll(1, "Chimichurri Burger", "", 12.00, 15.00, 20, "Burger");
	AllInventory[3].updateAll(1, "Pastrami Burger", "", 12.00, 16.00, 20, "Burger");
	AllInventory[4].updateAll(1, "French Fries", "", 12.00, 17.00, 20, "Side Dish");

	while (true)
	{
		string title = "Welcome to Yummy Food Kiosk";
		cout << "________________________________________________\n";
		cout << endl;
		cout << setw((unsigned long long)(title.size() / 2) + 25) << title << endl;
		cout << "________________________________________________\n";
		cout << endl;
		cout << "   1. Main Menu\n";
		cout << "   2. Inventory\n";
		cout << "   3. Point of Sale\n";
		cout << "   4. Credit\n";
		cout << "   0. Exit\n";

		cout << endl;
		cout << "Where would you like to go ? : ";
		int f1 = GetInt(4);

		if (f1 == 1) //main menu
		{
			MainMenu();
		}
		else if (f1 == 2)
		{
			InventoryMenu();
		}
		else if (f1 == 3)
		{
			PointOfSaleMenu();
			system("pause");
		}
		else if (f1 == 4)
		{
			system("cls");

			cout << "By : \n\n";
			cout << "  Najmi \n";
			cout << "  Syarifuddin\n";
			cout << "  Amier\n\n";

			system("pause");
		}
		else if (f1 == 0)
		{
			cout << "Exiting... \n";
			break;
		}
		system("cls");
	}

	system("pause");

	return 0;
}
