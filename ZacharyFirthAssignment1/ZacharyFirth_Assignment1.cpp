/*Name: Zachary Firth
Z - Number: Z23543282
Total Points : 10
Due Date : 1 / 26 / 2022
Course : C0P3014
Assignment : Assignment 1
Professor : Dr.Lofton Bullard
Description : This program gives the total cost of a certain quantity of plants that depend on a county's tax rate, the discount rate
which depends on the quantity, which are then applied totaled with the net cost after calculating both the tax and discount from 
the net cost.*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

string plant_name; //string that holds the plant name
string county_name; //string that holds the county name
double p_cost; //double that holds the cost of a plant
int quantity; //int that holds the number of plants purchased
double purchase_tax = 0; //double that holds the tax of the net cost 
double tax_rate = 0; //double that holds the selected county's tax percentage
double net_cost = 0; //double that holds the net cost of the plants excluding tax and discount 
double discount_rate = 0; //double that holds the discount percentage
double discount = 0; // double that holds the discount from the net cost
double total_cost = 0; // double that holds the total cost of the net cost, the tax, and the discount
    string user_response = "y";
    while (user_response == "y" || user_response == "Y")
    {
     
        //Input Statements
        cout << "Enter the Plant Name: ";
        cin >> plant_name;
        cout << "Enter the County Name: ";
        cin >> county_name;
        cout << "Enter the Plant Cost: ";
        cin >> p_cost;
        cout << "Enter the Quantity: ";
        cin >> quantity;
        //Calculation for net cost
        net_cost = quantity * p_cost;
        //Logic with if else statements for discount rate
        if (quantity <= 0)
            discount_rate = 0;
        else if (quantity >= 1 && quantity <= 6)
            discount_rate = 2;
        else if (quantity >= 7 && quantity <= 13)
            discount_rate = 4;
        else if (quantity >= 14 && quantity <= 25)
            discount_rate = 7;
        else if (quantity >= 26 && quantity <= 60)
            discount_rate = 9;
        else if (quantity > 60)
            discount_rate = 14;
        //Logic ...if else statements for tax rate
        if (county_name == "dade")
            tax_rate = 5.5;
        else if (county_name == "broward")
            tax_rate = 5;
        else if (county_name == "palm")
            tax_rate = 6;
        else
        {
         cout << "Error - In proper County Name\n" << endl;
         exit(1);
        }
        //Calculations for purchase tax, discount, and total cost
        discount = (net_cost * discount_rate / 100);
        purchase_tax = (net_cost * tax_rate / 100);
        total_cost = net_cost + purchase_tax - discount;
        //Outputs
        cout << endl << endl;
        cout << "\nPlant Name = " << plant_name;
        cout << "\nCounty Name = " << county_name;
        cout << "\nPlant Cost = $" << p_cost;//print Plant Cost
        cout << "\nQuantity = " << quantity;//print Quantity
        cout << "\nTax Rate = " << tax_rate << "%";//print Tax Rate
        cout << "\nNet Cost = $" << net_cost;//print Net Cost
        cout << "\nDiscount Rate = " << discount_rate << "%";//print Discount Rate
        cout << "\nDiscount = $" << discount;//print Discount
        cout << "\nPurchase Tax = $" << purchase_tax;//print Purchase Tax
        cout << "\nTotal Cost = $" << total_cost;//print Total Cost
        cout << "\nWould you like to do another calculation (Y or N): ";
        cin >> user_response;
    }
    return 0;
}


