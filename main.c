#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <direct.h>
#define MAXCHAR 1000
#include <stdbool.h>
#include <time.h>
#include "app.h"
/*#include "Bookingoperator.h"
#include "Operator.h"
#include "Hotel.h"
#include "Manager.h"
#include "Rooms.h"
#include "Rooma.h"
#include "Roomb.h"
#include "Roomc.h"
#include "Customer.h"*/

int main()
{

	struct Hotel * hotel = (struct Hotel*) malloc(sizeof(struct Hotel));

	struct Manager * manager = (struct Manager*) malloc(sizeof(struct Manager));
	
	struct Bookingoperator * bookingoperator = (struct Bookingoperator*) malloc(sizeof(struct Bookingoperator));

	struct Checkinoperator * checkinOp = (struct Checkinoperator*) malloc(sizeof(struct Checkinoperator));

	struct Checkoutoperator * checkoutOp = (struct Checkoutoperator*) malloc(sizeof(struct Checkoutoperator));

	struct Customer * customer = (struct Customer*) malloc(sizeof(struct Customer));

	struct Owner * owner = (struct Owner*) malloc(sizeof(struct Owner));

	setOwner();

	setCheckInOperator(hotel, customer);
	setCheckoutOperator(hotel , customer);

	checkinOp = getCheckIn();
	checkoutOp = getCheckOut();

	hotel = setHotel();

	
	manager = resetManager();
	manager->hotel = hotel;

	
	resetCustomer();

	customer = getCustomer();

	resetBooking(hotel);

	bookingoperator = getBookingOperator();

	readAllDiscount();
	readRoomsPrice();
	
	setBookingHotel(hotel);

	bookingoperator = getBookingOperator();

	//bookRoom();
	
	checkinOp->customer = customer;
	checkinOp->hotel = hotel;

	checkoutOp->customer = customer;
	checkoutOp->hotel = hotel;

	// confirminBooking();
	owner = getOwner();

	 owner->hotel = hotel;

	// updateHotelname();
	 getHotelName();

	 printf("**********************************************************************************\n");

	 printf("	Welcome to %s \n\n", hotel->hotelName);
	 printf("**********************************************************************************\n");

	 printf("Press 1 For Owner Options \n");
	 printf("Press 2 For Manager Options \n");
	 printf("Press 3 For Booking Operator Options \n");
	 printf("Press 4 For Check In Operator Options \n");
	 printf("Press 5 For Check out Operator Options \n");
	 printf("press any other no to exit \n");
	 int option = 0;
	 scanf("%d", &option);

	 while (option>0 && option <6) {
		 if (option == 1) {
			 printf("Press 1 to update hotel name \n");
			 printf("Press 2 to check Total bookings \n");
			 printf("Press 3 to check total profit \n");
			 printf("Press 4 to see customer feedback \n");
			 printf("Press 5 for Registered Customer Details \n");

			 int op = 0;
			 getchar();
			 scanf("%d", &op);
			 getchar();
			 if (op == 1) {
				 printf("\n");
				 updateHotelname();
				 printf("\n");
			 }
			 else if (op == 2) {
				 printf("\n");
				 getBookingDetails();
				 printf("\n");
			 }
			 else if (op == 3) {
				 float totalprofit = getTotalProfit();
				 printf("\n");
				 printf(" Total Profit so far %f\n", totalprofit);
				 printf("\n");

			 }
			 else if (op == 4) {
				 printf("\n");
				 printExperience();
				 printf("\n");
			 }

			 else if (op == 5) {
				 printf("\n");
				 getCustomerDetails();
				 printf("\n");
			 }
		 }
		 else if (option == 2) {
			 printf("Press 1 to print Class A price  \n");
			 printf("Press 2 to print  Class B price \n");
			 printf("Press 3 to print  Class C pricet \n");
			 printf("Press 4 to Update Class A price  \n");
			 printf("Press 5 to Update  Class B price \n");
			 printf("Press 6 to Update  Class C pricet \n");
			printf("Press 7 to Update Class A discount  \n");
			 printf("Press 8 to Update  Class B discount \n");
			 printf("Press 9 to Update  Class C discount \n");
			 printf("Press 10 for Registered Customer Details \n");
			 int op = 0;
			 getchar();
			 scanf("%d", &op);
			 getchar();
			 if (op == 1) {
				 printf("\n");
				 printRoomA();
				 printf("\n");
			 }else if (op == 2) {
				 printf("\n");
				 printRoomB();
				 printf("\n");
			 }
			 else if (op == 3) {
				 printf("\n");
				 printRoomC();
				 printf("\n");
			 }
			 else if (op == 4) {
				 printf("\n");
				 changeRoomAprice();
				 printf("\n");
			 }

			 else if (op == 5) {
				 printf("\n");
				 changeRoomBprice();
				 printf("\n");
			 }

			 else if (op == 6) {
				 printf("\n");
				 changeRoomCprice();
				 printf("\n");
			 }
			 else if (op == 7) {
				 printf("\n");
				 addDiscountRoomA();
				 printf("\n");
			 }
			 else if (op == 8) {
				 printf("\n");
				 addDiscountRoomB();
				 printf("\n");
			 }
			 else if (op == 9) {
				 printf("\n");
				 addDiscountRoomC();
				 printf("\n");
			 }
			 else if (op == 10) {
				 printf("\n");
				 getCustomerDetails();
				 printf("\n");
			 }
		 }
		 else if (option == 3) {
			 printf("Press 1 to Register Customer \n");
			 printf("Press 2 to Register Booking \n");

			 int op = 0;
			 getchar();
			 scanf("%d", &op);
			 getchar();
			 if (op == 1) {
				 printf("\n");
				 registerCustomer();
				 printf("\n");
			 }else if (op == 2) {
				 printf("\n");
				 bookRoom();
				 printf("\n");
			 }
		 }
		 else if (option == 4) {
			 printf("Press 1 to Check In Customer \n");
			 printf("Press 2 to Search Booking of particular Customer \n");

			 int op = 0;
			 getchar();
			 scanf("%d", &op);
			 getchar();
			 if (op == 1) {
				 printf("\n");
				 confirminBooking();
				 printf("\n");
			 }
			 else if (op == 2) {
				 printf("\n");
				 SearchCheckInCustomer();
				 printf("\n");
			 }
		 }
		 else if (option == 5) {
			 printf("Press 1 to Confirm Check out \n");
			 

			 int op = 0;
			 getchar();
			 scanf("%d", &op);
			 getchar();

			 if (op == 1) {
				 printf("\n");
				 confirmoutBooking();
				 printf("\n");
			 }
			
		 }
		 else if (option == 6) {
			 printf("Press 1 to confirm Check Out \n");

			 int op = 0;
			 getchar();
			 scanf("%d", &op);
			 getchar();

			 if (op == 1) {
				 printf("\n");
				 confirmoutBooking();
				 printf("\n");
			 }
			
		 }

		 printf("Press 1 For Owner Options \n");
		 printf("Press 2 For Manager Options \n");
		 printf("Press 3 For Booking Operator Options \n");
		 printf("Press 4 For Check In Operator Options \n");
		 printf("Press 5 For Check out Operator Options \n");
		 printf("press any other no to exit \n");
		 option = 0;
		 scanf("%d", &option);
		 
	 }

	return 1;
}
