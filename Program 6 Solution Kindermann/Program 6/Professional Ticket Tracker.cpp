/********************************************
* FILENAME: Professional Ticket Tracker.cpp *
* PROGRAMMER: Alex Kindermann               *
* PURPOSE: tracks ticket sales and amounts  *
********************************************/

#include <string>
#include <ctime>
#include <iomanip>
#include <cmath>
#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;

int main()
{
	//function prototypes
	int get_ticket_type();
	double find_ticket_price(int typeOfTicket);
	double apply_discount(double costOfSale);
	void disp_purchase(int typeOfTicket, int amountOfTickets, double totalCostOfSale);
	void disp_final_report(const int maxSeatCount, int ticketsOverall, int ticketAmountAdult, int ticketAmountJunior, int ticketAmountFree, int ticketsExtra, double salesTotal);

	//declare variables and named constants
	const int MAXIMUM_SEAT_COUNT   = 25;
	int ticketAmount               = 0;
	int overallTickets             = 0;
	int extraTickets               = 0;
	int adultTicketAmount          = 0;
	int juniorTicketAmount         = 0;
	int freeTicketAmount           = 0;
	int indvTicketAmount1          = 0;
	int indvTicketAmount2          = 0;
	int indvTicketAmount3          = 0;
	int ticketType                 = 0;
	int discountDecision           = 0;
	double ticketPrice             = 0.00;
	double totalSales              = 0.0;
	double saleAmount              = 0.0;
	double totalSaleAmount         = 0.0;

	cout << fixed << setprecision(2);

	//Introduction
	cout << "SUMMERVILLE SEAWORLD TICKET MASTER v1.1" << endl;
	cout << "Used to track ticket costs, types, and overall gross." << endl;

	//Retrieve ticket type
	ticketType = get_ticket_type();
	if(ticketType == 4)
	{
		disp_final_report ( MAXIMUM_SEAT_COUNT, overallTickets, adultTicketAmount, juniorTicketAmount, freeTicketAmount, extraTickets, totalSales);
		system("pause");
		return 0;
	}


	//While loop for transactions
	while (overallTickets <= MAXIMUM_SEAT_COUNT)
	{	
		//if structure for determining ticket price of one ticket
		if (ticketType == 1)
		{
			ticketPrice = find_ticket_price (ticketType);
			cout << endl;
			cout << "The price of this ticket is free, or 0.00." << endl;
		}
		else if (ticketType == 2)
		{
			ticketPrice = find_ticket_price (ticketType);
			cout << endl;
			cout << "The price of this ticket is "<< ticketPrice <<"." << endl;
		}
		else if (ticketType == 3)
		{
			ticketPrice = find_ticket_price (ticketType);
			cout << endl;
			cout << "The price of this ticket is "<< ticketPrice <<"." << endl;
		}
		//end if structure

		//Input customer's ticket amount for retrieved ticket type
		cout << endl;
		cout << "Please enter the ticket amount desired.";
		cin >> ticketAmount;

		//while loop if zero is inputted
		while(ticketAmount == -1 || ticketAmount == -2 || ticketAmount == -3)
		{
			cout << endl;
			cout << endl; 
			cout << "Error: Existential crisis. Please enter the ticket amount desired.";
			cin >> ticketAmount;
			cout << endl;
		}
		//end while

		//if structure for ticket amounts
		if (ticketAmount > 10)
		{
			ticketAmount = 10;
			if(ticketType == 1)
			{
				indvTicketAmount1 = 10;
				freeTicketAmount = freeTicketAmount + indvTicketAmount1;
			}
			else if (ticketType == 2)
			{
				indvTicketAmount2 = 10;
				juniorTicketAmount = juniorTicketAmount + indvTicketAmount2;
			}
			else if (ticketType == 3)
			{
				indvTicketAmount3 = 10;
				adultTicketAmount = adultTicketAmount + indvTicketAmount3;
			}
			cout << endl;
			cout << "No more than ten may be purchased of any ticket type. Ticket amount has been"<<endl<<"set to ten.";
			cout << endl;
		}
		else if (ticketAmount <= 10 && ticketAmount != 0)
		{
			ticketAmount = ticketAmount;
			if(ticketType == 1)
			{
				indvTicketAmount1 = ticketAmount;
				freeTicketAmount = freeTicketAmount + indvTicketAmount1;
			}
			else if (ticketType == 2)
			{
				indvTicketAmount2 = ticketAmount;
				juniorTicketAmount = juniorTicketAmount + indvTicketAmount2;
			}
			else if (ticketType == 3)
			{
				indvTicketAmount3 = ticketAmount;
				adultTicketAmount = adultTicketAmount + indvTicketAmount3;
			}
			cout << endl;
			cout << ""<<ticketAmount<<" ticket(s) will be purchased.";
			cout << endl;
		}
		//end if structure

		overallTickets += ticketAmount;

		//ask if customer has discount coupon
		cout << endl;
		cout << "Does the customer have a discount coupon? Please input 1 for yes, or 2 for"<< endl <<"no.";
		cin >> discountDecision;	

		while (discountDecision != 1 && discountDecision != 2)
		{
			cout << endl;
			cout << "Please input one for yes, or two for"<< endl <<"no.";
			cin >> discountDecision;
		}

		//if structure for discount decision
		if (discountDecision == 1)
		{
			saleAmount = ticketPrice * ticketAmount;
			totalSaleAmount = apply_discount (saleAmount);
			cout << endl;
			cout << "The amount for this transaction is $"<< totalSaleAmount <<".";
			cout << endl;
		}
		else if (discountDecision == 2)
		{
			saleAmount = ticketPrice * ticketAmount;
			totalSaleAmount = saleAmount;
			cout << endl;
			cout << "The amount for this transaction is $"<< totalSaleAmount <<".";
			cout << endl;
		}
		//end if structure

		totalSales += totalSaleAmount;

		//display type of ticket bought, total price, and amount of tickets for one transaction
		cout << endl;
		disp_purchase (ticketType, ticketAmount, totalSaleAmount);

		if (overallTickets <= MAXIMUM_SEAT_COUNT)
		{
			ticketType = get_ticket_type();
		}
		else if (overallTickets >= MAXIMUM_SEAT_COUNT || ticketType == 4)
		{
			disp_final_report ( MAXIMUM_SEAT_COUNT, overallTickets, adultTicketAmount, juniorTicketAmount, freeTicketAmount, extraTickets, totalSales);
		}

	}//end while

	system ("pause");
	return 0;
}

/**********************************************************************
* PURPOSE: To present ticket menu and retrieve customer's ticket type *
* PASSED IN: Nothing                                                  *
* RETURNED: Customer's ticket type                                    *
**********************************************************************/

int get_ticket_type()
{
	//declare variables and named constants
	int ticketType = 0;

	//present ticket type menu
	cout << endl;
	cout << "Please choose ticket type from the following.";
	cout << endl;
	cout << "1. Free Admission (Children 5 and under)." << endl; 
	cout << "2. Junior (Children between 6 and 16)." << endl;
	cout << "3. Adult (Over 16)." << endl;
	cout << "4. Quit." << endl;
	cout << endl;
	cin >> ticketType;

	//while loop to get correct ticket type
	while (ticketType !=1 && ticketType !=2 && ticketType !=3 && ticketType !=4)
	{
		cout << endl;
		cout << "Error. Please input 1, 2, 3, or 4.";
		cin >> ticketType;
	}//end while

	return ticketType;
}//END GET_TICKET_TYPE

/**********************************************************************************
* PURPOSE: To receive the ticket type and return price of one ticket of that type *
* PASSED IN: Customers's ticket type                                              *
* RETURNED: Price for one ticket of the customer's ticket type                    *
**********************************************************************************/

double find_ticket_price(int typeOfTicket)
{
	//declare variables and named constants
	double ticketPrice = 0.0;
	const double ADULT_SEAT_PRICE  = 11.50;
	const double JUNIOR_SEAT_PRICE = 7.50;
	const double FREE_SEAT_PRICE   = 0.00;

	//find ticket price for one ticket of user's ticket type
	if(typeOfTicket == 1)
	{
		ticketPrice = FREE_SEAT_PRICE;
	}
	else if(typeOfTicket == 2)
	{
		ticketPrice = JUNIOR_SEAT_PRICE;
	}
	else if(typeOfTicket == 3)
	{
		ticketPrice = ADULT_SEAT_PRICE;
	}

	return ticketPrice;
}//END FIND_TICKET_PRICE

/************************************************************************
* PURPOSE: To apply discount to cost of purchase if customer has coupon *
* PASSED IN: Cost of purchase											*
* RETURNED: Discounted cost												*
************************************************************************/

double apply_discount(double costOfSale)
{
	//declare variables and named constants
	const double DISCOUNT = 0.25;
	double totalCostOfSale = 0.0;

	//apply discount to cost of purchase passed in
	totalCostOfSale = costOfSale - costOfSale * DISCOUNT;

	return totalCostOfSale;
}//END APPLY_DISCOUNT

/****************************************************************************************************************************
* PURPOSE: To display information for one customer's purchase																*
* PASSED IN: Customer's ticket type, amount of tickets to be purchased, and total cost of purchase with or without discount	*
* RETURNED: Nothing																											*
****************************************************************************************************************************/

void disp_purchase(int typeOfTicket, int amountOfTickets, double totalCostOfSale)
{
	//declare variables and named constants
		//NONE

	//display customer's ticket type, amount of tickets to be purchased, and total cost of purchase with or without discount

	//if structure to determine what type of seating to be displayed
	if(typeOfTicket == 1)
	{
		cout << "TICKET TYPE: FREE SEATING" << endl;
	}
	else if (typeOfTicket == 2)
	{
		cout << "TICKET TYPE: JUNIOR SEATING" << endl;
	}
	else if (typeOfTicket == 3)
	{
		cout << "TICKET TYPE: ADULT SEATING" << endl;
	}
	//end if structure
	
	cout << "TICKET AMOUNT: "<<amountOfTickets<<"" << endl;
	cout << "TOTAL COST OF PURCHASE: $"<<totalCostOfSale<<"" << endl;

	return;

}//END DISP_PURCHASE


/************************************************************************************************************************************************************
* PURPOSE: To display final report after end of all transactions                                                                                            *
* PASSED IN: Maximum seat count, overall tickets sold, ticket amounts for adult, junior, and free tickets respectively, extra tickets sold, and total gross *
* RETURNED: Nothing																																			*
************************************************************************************************************************************************************/

void disp_final_report(const int seatCountMax, int ticketsOverall, int ticketAmountAdult, int ticketAmountJunior, int ticketAmountFree, int ticketsExtra, double salesTotal)
{
	//declare variables and named constants
	char tmpbuf[128];
	_strdate_s(tmpbuf);

	//display maximum seat count, overall tickets sold, ticket amounts for adult, junior, and free tickets respectively, extra tickets sold, and total gross
	system("CLS");
	ticketsExtra = ticketsOverall - seatCountMax;
	if(ticketsExtra < 0)
	{
		ticketsExtra = 0;
	}

	cout << setw (45) << "TICKET SALES FOR DATE: " << tmpbuf <<"" << endl;
	cout << endl;
	cout << "NUMBER OF AVAILABLE SEATS" << setw (20) << "EXTRA TICKETS SOLD" << setw (26) << "TOTAL TICKETS SOLD" <<endl;
    cout << setw(12) << seatCountMax << setw (25) << ticketsExtra << setw (26) << ticketsOverall << endl;
	cout << endl;
	cout << "FREE ADMISSION TICKETS" << setw (29) << "JUNIOR ADMISSION TICKETS" << setw (25) << "ADULT ADMISSION TICKETS" << endl;
	cout << setw(11) << ticketAmountFree << setw (25) << ticketAmountJunior << setw (27) << ticketAmountAdult << endl;
    cout << endl;
	cout << "OVERALL SALES AMOUNT:" <<salesTotal<<"" << endl;
	system("pause");
	return;
}










	
	
	