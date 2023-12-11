#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
void modifyProduct(string item[], float price[], int quantity[], int count1);
void loginHeader();
string getFieldData(string data, int count);
bool nameCheck(string name1);
bool passwordCheck(string pass);
void signupHeader();
void Datastorage(string name[], string password[], string role[], int count)
void gotoxy(int x, int y);
void logout(string name[], string password[], string role[], int count);
void removeProduct(string item[], float price[], int quantity[], int count1);
void addProduct(string item[], float price[], int quantity[], int &count1);
float brand(string item[], float price[], int quantity[], int count1, string product, int quantity1);
bool quantityCheck(int quantity1);
bool priceCheck(float pri);
void printheader();
void viewProducts(string item[], float price[], int quantity[], int count1);
void loginAdmin(string item[], float price[], int quantity[], int count1);
void signup(string name[], string password[], string role[], int &count);
void logincustomer(string item[], float price[], int quantity[], int count1, string name[], string password[], string role[], int count);
string roleChecker(string name2, string pass2, string name[], string password[], string role[], int count);void loadData(string name[], string password[], string role[], int &count);
void Datastorage(string name[], string password[], string role[], int count);
void login(string name[], string password[], string role[], int count, string item[], float price[], int quantity[], int &count1);
void products(string item[], float price[], int quantity[], int count1);
int main()
{
	/// variable for price name quantity of product
	int count1 = 0;
	int size = 1000;
	string item[size] = {""};
	float price[size] = {};
	int quantity[size] = {};
	// variable for login signup
	int count = 0;
	string name[100] = {""};
	string role[100] = {""};
	string password[100] = {""};
	printheader();
	cout << "ClickNShop Hub - Your One-Click Wonderland for Seamless Shopping Delight!" << endl;

	cout << "Welcome to ClickNShop Hub, where the world of online shopping meets convenience at your fingertips. Our hub is designed to revolutionize your shopping experience, offering a seamless and delightful journey from click to doorstep.At ClickNShop Hub, we believe that shopping should be an effortless joy, and we've curated a diverse range of products to cater to your every need. Whether you're a tech enthusiast, a fashionista, or a home decor connoisseur, our hub brings together a plethora of options for you to explore and choose from." << endl;
	cout << "Press any key to start";
	getch();
	while (true)
	{

	start:
		system("cls");
		printheader();

		cout << "Press 1 or 2:...." << endl;
		string press; /// string variable to press key
		cout << "1.login......." << endl
			 << "2.sign up........." << endl;
		cin >> press;
		if (press == "1")
		{
			login(name, password, role, count, item, price, quantity, count1);
		}
		else if (press == "2")
		{
			signup(name, password, role, count);
		}
		else
		{
			cout << "Invalid input..." << endl;
			Sleep(2000);
			goto start;
		}
	}
	return 0;
}

void Datastorage(string name[], string password[], string role[], int count)
{
	fstream storeFile;
	string data = "";
	storeFile.open("data.txt", ios::out);
	for (int i = 0; i < count; i++)
	{
		if (i == count - 1)
		{
			data += name[i] + "," + password[i] + "," + role[i];
		}
		else
		{
			data += name[i] + "," + password[i] + "," + role[i] + "\n";
		}
		storeFile << data;
		data = "";
	}
	storeFile.close();
}
string getFieldData(string data, int count)
{
	string result = "";
	int comma = 0;
	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] == ',')
		{
			comma++;
		}
		else if (comma == count)
		{
			result += data[i];
		}
		else if (comma > count)
		{
			break;
		}
	}
}
void loadData(string name[], string password[], string role[], int &count)
{
	fstream loadFile;
	string data = "";
	loadFile.open("data.txt", ios::in);
	while (!loadFile.eof())
	{
		getline(loadFile, data);
		name[count] = getFieldData(data, 0);
		password[count] = getFieldData(data, 1);
		role[count] = getFieldData(data, 2);
		count++;
	}
	loadFile.close();
}
void login(string name[], string password[], string role[], int count, string item[], float price[], int quantity[], int &count1)
{
start:
	system("cls");
	loginHeader();
	string name2; /// variable for login
	string pass2; /// variable for login
	cout << "Enter your name:...." << endl;
	cin >> name2;
	cout << "Enter your password:...." << endl;
	cin >> pass2;
	string result = roleChecker(name2, pass2, name, password, role, count);
	if (result == "admin")
	{
		loginAdmin(item, price, quantity, count1);
	}
	else if (result == "customer")
	{

		logincustomer(item, price, quantity, count1, name, password, role, count);
	}
	else
	{

		cout << "Invalid input......" << endl;
		cout << "Don't have account. want to register.." << endl;
		cout << "Press 1 or 2" << endl;
		cout << "want to register.." << endl;
		cout << "\t"
			 << "or" << endl;
		cout << "try again..." << endl;
		string press;
		cin >> press;
		if (press == "1")
		{

			signup(name, password, role, count);
		}
		else if (press == "2")
		{

			Sleep(2000);
			goto start;
		}
		else
		{
			cout << "Press correct key." << endl;
		}
	}
}
void signup(string name[], string password[], string role[], int &count)
{
	system("cls");
	signupHeader();
	cout << endl;
	string name1;
	// int count1=1;
	// while(count!=0){

start1:
	cout << "Enter your name:..." << endl;
	cin >> name1;
	if (!nameCheck(name1))
	{
		cout << "Incorrect Character Entered." << endl;
		// continue;
		cin.clear();
		cin.ignore();
		goto start1;
	}
// }
start:
	string pass;
	cout << "Set password....." << endl;
	cin >> pass;
	if (!passwordCheck(pass))
	{
		cout << "Password must have atleast eight characters." << endl;

		goto start;
	}
	string role1;
	cout << "You want to sign up as administrator or customer: ";
	cin >> role1;
	cout << "Congratulation! You have successfully created the account." << endl;
	name[count] = name1;
	password[count] = pass;
	role[count] = role1;
	count++;
}
bool nameCheck(string name1)
{
	for (int i = 0; name1[i] != '\0'; i++)
	{
		if (!((name1[i] >= 'A' && name1[i] <= 'Z') || (name1[i] >= 'a' && name1[i] <= 'z') || (name1[i] >= '0' && name1[i] <= '9') || (name1[i] == '_')))
		{
			return false;
		}
	}
	return true;
}
bool passwordCheck(string pass)
{
	if (pass.length() < 6)
	{
		return false;
	}
	return true;
}
void loginHeader()
{
	cout << R"(                                    mm              
*@@@@*                              @@              
  @@                                                
  @@        m@@*@@m  m@*@@@@@     *@@@  *@@@@@@@@m  
  @@       @@*   *@@m@@  @@         @@    @@    @@  
  @!     m @@     @@*!!@@@*         !@    @!    @@  
  @!    :@ @@     !@@!              !@    @!    !@  
  !!     ! !@     !!*!!!!!*         !!    !!    !!  
  !:    !! !!!   !!!!:              !!    !!    !!  
: :: !: :   : : : :  : :!: :      : : : : :::  :!: :
                    ::     ::                       
                    :::: ::                         
)";
}
void signupHeader()
{
	cout << R"((¯`·¯`·.¸¸.·´·´¯)
( \           / )
 ( ) Sign up ( ) 
  (/         \)  
   (.·´¯`·.¸¸)   )";
}
void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
float brand(string item[], float price[], int quantity[], int count1, string product, int quantity1)
{
	for (int i = 0; i < count1; i++)
	{
		if (item[i] == product)
		{
			if (quantity[i] >= quantity1)
			{
				quantity[i] -= quantity1;
				return price[i] * quantity1;
			}
			else
			{
				return -1.0f;
			}
		}
	}
	return -2.0f;
}

void printheader()
{

	cout << R"((‿ꜟ‿) ⒞⒧⒤⒞⒦⒩⒮⒣⒪⒫ ⒣⒰⒝ (｡)(｡))";
}
// void function for login function
string roleChecker(string name2, string pass2, string name[], string password[], string role[], int count)
{
	for (int i = 0; i <= count; i++)
	{
		if (name[i] == name2 && password[i] == pass2)
		{
			return role[i];
		}
	}
	return "user not found";
}

void addProduct(string item[], float price[], int quantity[], int &count1)
{
	string product;
	cout << "Enter product name: " << endl;
	cin >> product;
start:
	float pri;
	cout << "Entert price of product: " << endl;
	cin >> pri;
	if (!priceCheck(pri))
	{
		cout << "Incorrect Entry." << endl;
		goto start;
	}
	int quantity1;
start1:
	cout << "Enter quantity of products: " << endl;
	cin >> quantity1;
	if (!quantityCheck(quantity1))
	{
		cout << "Incorrect Entry" << endl;
		goto start1;
	}
	item[count1] = product;
	price[count1] = pri;
	quantity[count1] = quantity1;
	count1++;
	cout << "Press any key to go back." << endl;
	getch();
}
bool priceCheck(float pri)
{
	if (pri < 1)
	{
		return false;
	}
	return true;
}
bool quantityCheck(int quantity1)
{
	if (quantity1 < 1)
	{
		return false;
	}
	return true;
}
void modifyProduct(string item[], float price[], int quantity[], int count1)
{
	string name;
	cout << "Enter the name of the product to update: " << endl;
	cin >> name;
start:
	float pr;
	cout << "Enter new price: " << endl;
	cin >> pr;
	if (!priceCheck(pr))
	{
		cout << "Incorrect Entry" << endl;
		goto start;
	}
start1:
	int quantity1;
	cout << "Enter quantity:" << endl;
	cin >> quantity1;
	if (!quantityCheck(quantity1))
	{
		cout << "Incorrect Entry" << endl;
		goto start1;
	}
	for (int i = 0; i < count1; i++)
	{
		if (item[i] == name)
		{
			price[i] = pr;
			quantity[i] = quantity1;
		}
	}
	cout << "Press any key to go back." << endl;
	getch();
}
void removeProduct(string item[], float price[], int quantity[], int count1)
{
	string name;
	cout << "Enter the produt name to remove: " << endl;
	cin >> name;
	for (int i = 0; i < count1; i++)
	{
		if (item[i] == name)
		{
			for (int j = i; j < count1 - 1; j++)
			{
				item[j] = item[j + 1];
				price[j] = price[j + 1];
				quantity[j] = quantity[j + 1];
			}
			count1--;
			break;
		}
	}
	cout << "Press any key to go back." << endl;
	getch();
}
void viewProducts(string item[], float price[], int quantity[], int count1)
{
	cout << "Number \t\t\t\t"
		 << "Product Name \t\t\t\t"
		 << "Price \t\t\t\t"
		 << "Quantity" << endl;
	for (int i = 0; i < count1; i++)
	{
		cout << 1 + i << "\t\t\t\t" << item[i] << "\t\t\t\t" << price[i] << "\t\t\t\t" << quantity[i] << endl;
	}
	cout << "Press any key to go back." << endl;
	getch();
}
void loginAdmin(string item[], float price[], int quantity[], int count1)
{
start:
	cout << R"(                      mm                      mm                                                                      
      @@            *@@@                      @@                                                                      
     m@@m             @@                                                                                              
    m@*@@!       m@**@@@  *@@@@@@@@m@@@@@m  *@@@  *@@@@@@@@m       *@@@@@@@@m@@@@@m    mm@*@@ *@@@@@@@@m  *@@@  *@@@  
   m@  *@@     m@@    @@    @@    @@    @@    @@    @@    @@         @@    @@    @@   m@*   @@  @@    @@    @@    @@  
   @@@!@!@@    @!@    @!    !@    @@    @@    !@    @!    @@         !@    @@    @@   !@******  @!    @@    !@    @@  
  !*      @@   *!@    @!    !@    !@    @@    !@    @!    !@         !@    !@    @@   !@m    m  @!    !@    !@    @!  
   !!!!@!!@    !!!    !!    !!    !!    !!    !!    !!    !!         !!    !!    !!   !!******  !!    !!    !@    !!  
  !*      !!   *:!    !:    :!    :!    !!    !!    !!    !!         :!    :!    !!   :!!       !!    !!    !!    !!  
: : :   : :::   : : : ! : : :!:  :::   ::!: : : : : :::  :!: :     : :!:  :::   ::!:   : : :: : :::  :!: :  :: !: :!: 
                                                                                                                      
                                                                                                                      
)" << endl;
	string choice;
	cout << "........Admin menu........" << endl;
	cout << "1.Add Product" << endl;
	cout << "2.Modify Product" << endl;
	cout << "3.Remove Product" << endl;
	cout << "4.View products" << endl;
	cin >> choice;
	if (choice == "1")
	{
		addProduct(item, price, quantity, count1);
	}
	if (choice == "2")
	{
		modifyProduct(item, price, quantity, count1);
	}
	if (choice == "3")
	{
		removeProduct(item, price, quantity, count1);
	}
	else if (choice == "4")
	{
		viewProducts(item, price, quantity, count1);
	}
	else
	{
		cout << "Wrong input";
		Sleep(2000);
		goto start;
	}
}
void products(string item[], float price[], int quantity[], int count1)
{
	printheader();
	string product;
	int quantity1;
	cout << "Enter the product name: ";
	cin >> product;
	cout << "Enter the quantity: ";
	cin >> quantity1;
	float result;
	result = brand(item, price, quantity, count1, product, quantity1);
	if (result >= 0.0f)
	{
		// Successful transaction
		cout << "Transaction successful. Total price: " << result << endl;
	}
	else if (result == -1.0f)
	{
		// Insufficient quantity
		cout << "Required quantity is not available." << endl;
	}
	else if (result == -2.0f)
	{
		// Product not found
		cout << "Product not found." << endl;
	}
	printheader();
	gotoxy(20, 9);
	cout << "Product name";
	gotoxy(20, 10);
	cout << product;
	gotoxy(60, 9);
	cout << "Quantity";
	gotoxy(60, 10);
	cout << quantity;
	gotoxy(15, 14);
	cout << "______________________________";
	gotoxy(15, 16);
	cout << "Total price: ";
	gotoxy(30, 16);
	cout << "Rs " << result;
}
void logout(string name[], string password[], string role[], int count)
{
	string name1;
	cout << "Enter your name: " << endl;
	cin >> name1;
	for (int i = 0; i < count; i++)
	{
		if (name[i] == name1)
		{
			for (int j = i; j < count - 1; j++)
			{
				name[j] = name[j + 1];
				password[j] = password[j + 1];
				role[j] = role[j + 1];
			}
			count--;
			break;
		}
	}
}
void logincustomer(string item[], float price[], int quantity[], int count1, string name[], string password[], string role[], int count)
{
	string press;
	cout << "Press 1 0r 2" << endl;
	cout << "1.Buy Product" << endl;
	cout << "2.View products" << endl;
	cout << "3.Go Back" << endl;
	cout << "4.Log out" << endl;
	cin >> press;
	if (press == "1")
	{
		products(item, price, quantity, count1);
	}
	else if (press == "2")
	{
		viewProducts(item, price, quantity, count1);
	}
	else if (press == "3")
	{
		getch();
	}
	else if (press == "4")
	{
		logout(name, password, role, count);
	}
	else
	{
		cout << "Invalid Input" << endl;
	}
}