#define _CRT_SECURE_NO_WARNINGS
// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 //#include "app.h"

#include <time.h>

#define MAXCHAR 1000


struct Bookingoperator {
	char bookingName[50];
	char bookingPassword[50];
	struct Hotel * hotel;

};

struct Customer {
	char experience[256];
	char customerName[50];
	char customerCheckInDate[11];
	char customerCheckOutDate[11];
	char address[50];
	char telephone[30];
	int stayingDays;
	char roomType;
	float roomFee;
	int totalbookrooms;
	int roomNo;
};

struct Hotel {

	struct Rooms * rooms;
	char hotelName[50];
};


struct Owner
{

	char ownerName[50];
	char ownerPassword[50];
	struct Hotel * hotel;
};



struct Manager {
	char ManagerName[50];
	char ManagerPassword[50];

	struct Hotel * hotel;
};

struct Checkinoperator {
	char checkinName[50];
	char checkinPassword[50];
	struct Hotel * hotel;
	struct Customer * customer;


};


struct Checkoutoperator {
	char checkoutName[50];
	char checkoutPassword[50];
	struct Hotel * hotel;
	struct Customer * customer;

};


struct Rooma {

	bool booked;
	char bookedStartDate[10];
	char bookedEndDate[10];
	int roomno;
	float discount;
};

struct Roomb {

	bool booked;
	char bookedStartDate[10];
	char bookedEndDate[10];
	int roomno;
	float discount;
};

struct Roomc {

	bool booked;
	char bookedStartDate[10];
	char bookedEndDate[10];
	int roomno;
	float discount;
};
struct Rooms {

	struct Rooma * rooma;
	struct Roomb * roomb;
	struct Roomc * roomc;
	float roomaPrice;
	float roombPrice;
	float roomcPrice;
};

static struct Customer * customer;
static struct Bookingoperator * bookingOperator;


struct  Bookingoperator * getBookingOperator()
{
	return bookingOperator;
}

void setBookingHotel(struct Hotel * myhotel) {
	bookingOperator->hotel = myhotel;
}

void resetBooking(struct Hotel * myhotel) {
	bookingOperator = (struct Bookingoperator*) malloc(sizeof(struct Bookingoperator));

	int j = 0;
	while (j < 50) {
		bookingOperator->bookingName[j] = '\0';
		bookingOperator->bookingPassword[j] = '\0';
		j++;
	}
	bookingOperator->hotel = myhotel;
}

struct Customer * getCustomer() {
	return customer;
}

void resetCustomer() {

	customer = (struct Customer*) malloc(sizeof(struct Customer));

	int j = 0;

	while (j < 11) {
		customer->customerCheckInDate[j] = '\0';
		customer->customerCheckOutDate[j] = '\0';
		j++;
	}

	j = 0;
	while (j < 50) {
		customer->customerName[j] = '\0';
		customer->address[j] = '\0';
		j++;
	}
	customer->roomFee = 0.0;
	customer->totalbookrooms = 0;

	customer->roomType = '\0';
	customer->roomNo = 0;

	j = 0;
	while (j < 30) {
		customer->telephone[j] = '\0';
		j++;
	}

	j = 0;
	while (j < 256) {
		customer->experience[j] = '\0';
		j++;
	}
}
char * concate(char * firststr, char * secondstr) {
	char *a = firststr;
	char *b = secondstr;


	// pointing to the end of the 1st string
	while (*a)   // till it doesn't point to NULL-till string is not empty
	{
		a++;    // point to the next letter of the string
	}
	while (*b)   // till second string is not empty
	{
		*a = *b;
		b++;
		a++;
	}
	*a = '\0';  // string must end with '\0'

	return firststr;
}

char *  PrintFullPath(char * partialPath, char * filename)
{
	// char full[_MAX_PATH];

	char *full = malloc(_MAX_PATH);
	// char *filename = "bookingdata.txt";

	if (_fullpath(full, partialPath, _MAX_PATH) != NULL)
	{

		char *a = full;
		char *b = filename;

		// pointing to the end of the 1st string
		while (*a)   // till it doesn't point to NULL-till string is not empty
		{
			a++;    // point to the next letter of the string
		}
		while (*b)   // till second string is not empty
		{
			*a = *b;
			b++;
			a++;
		}
		*a = '\0';  // string must end with '\0'

		return full;
	}
	else
		return NULL;

}

bool getRoomavailabilty(char * str, int option) {

	int i = 0;

	bool roomNo = false;
	bool isbooked = false;


	char ptrdata[3];
	int k = 0;
	while (k < 3) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (roomNo == false) {
				roomNo = true;
				int x = 0;
				//		sscanf(ptrdata[k], "%d", &x);
				x = ptrdata[0] - '0';
				x = ptrdata[1] != '\0' ? 10 + ptrdata[1] - '0' : x;
				bookingOperator->hotel->rooms->rooma->roomno = option == 1 ? x : 0;
				bookingOperator->hotel->rooms->roomb->roomno = option == 2 ? x : 0;
				bookingOperator->hotel->rooms->roomc->roomno = option == 3 ? x : 0;

				k = 0;
				while (k < 3) {
					ptrdata[k] = '\0';
					k++;
				}
				k = 0;
			}
			else if (isbooked == false) {
				isbooked = true;
				if (ptrdata[0] == 'f') {
					bookingOperator->hotel->rooms->rooma->booked = option == 1 ? false : true;
					bookingOperator->hotel->rooms->roomb->booked = option == 2 ? false : true;
					bookingOperator->hotel->rooms->roomc->booked = option == 3 ? false : true;

					return true;
				}
				else if (ptrdata[0] == 't') {
					bookingOperator->hotel->rooms->rooma->booked = option == 1 ? true : false;
					bookingOperator->hotel->rooms->roomb->booked = option == 2 ? true : false;
					bookingOperator->hotel->rooms->roomc->booked = option == 3 ? true : false;

				}

				k = 0;
				while (k < 3) {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			k = 0;
			while (k < 3) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			roomNo = false;
			isbooked = false;

		}

	}
	return false;
}


void getBookingDetails() {

	//	resetCustomer();

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "bookingdata.txt");


	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);
	if (str[0] == '\0')
	{
		printf("\n No Booing Result Found \n");
		return;
	}

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool stayingdays = false;
	bool type = false;
	bool roomno = false;

	char ptrdata[50];
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerCheckInDate[k] = '\0';
					customer->customerCheckInDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerCheckOutDate[k] = '\0';
					customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				customer->roomFee = ftemp;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (type == false) {
				type = true;

				customer->roomType = ptrdata[0];

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (roomno == false) {
				roomno = true;

				customer->roomNo = atoi(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (stayingdays == false) {
				stayingdays = true;

				int days = atoi(ptrdata);
				customer->stayingDays = days;

			}

		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			printf("\n");

			printf("Customer Name: %s\n", customer->customerName);
			printf("Customer customerCheckInDate: %s\n", customer->customerCheckInDate);
			printf("Customer customerCheckOutDate: %s\n", customer->customerCheckOutDate);
			printf("Customer Room Type: %c\n", customer->roomType);
			printf("Customer Staying Days: %d\n", customer->stayingDays);

			printf("Customer Amount Paid : %f\n", customer->roomFee);
			printf("\n");

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			stayingdays = false;
			type = false;
			roomno = false;

		}

	}
}




void getCustomerDetails() {

	//	resetCustomer();

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "customerdata.txt");

	if (ptr != NULL) {
		printf("Full path is: %s\n", ptr);
	}

	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	int i = 0;

	bool name = false;
	bool address = false;
	bool telephone = false;


	char ptrdata[50];
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (address == false) {
				address = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->address[k] = '\0';
					customer->address[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (telephone == false) {
				telephone = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->telephone[k] = '\0';
					customer->telephone[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			printf("\n");

			printf("Customer Name: %s\n", customer->customerName);
			printf("Customer Address: %s\n", customer->address);
			printf("Customer Telephone: %s\n", customer->telephone);


			printf("\n");

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			name = false;
			address = false;
			telephone = false;

		}

	}
}

float getTotalProfit() {
	float totalprofit = 0.0;
	//	resetCustomer();

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "bookingdata.txt");


	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool stayingdays = false;

	char ptrdata[50];
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerCheckInDate[k] = '\0';
					customer->customerCheckInDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerCheckOutDate[k] = '\0';
					customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				customer->roomFee = ftemp;

			}
			else if (stayingdays == false) {
				stayingdays = true;

				int days = atoi(ptrdata);
				customer->stayingDays = days;

			}

		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			printf("\n");

			printf("Customer Name: %s\n", customer->customerName);
			printf("Customer Amount Paid : %f\n", customer->roomFee);
			printf("\n");
			totalprofit = totalprofit + customer->roomFee;
			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			stayingdays = false;
		}

	}
	return totalprofit;
}

void printData(char * data) {
	int i = 0;
	while (i < sizeof(data))
	{
		printf("%c", data[i]);
		i++;
	}
}

void readFile(char *ptr, char *fileptr) {

	FILE *fptr;
	char str[MAXCHAR];
	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		fileptr[j] = '\0';
		j++;
	}

	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");
	}



	while (fgets(str, MAXCHAR, fptr) != NULL) {
		//	printf("%s\n", str);
		concate(fileptr, str);
	}

	//	printf("%s\n", fileptr);
	fclose(fptr);


}

void searchBooking(char custname[50], char checkindate[50]) {

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "bookingdata.txt");



	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;


	char ptrdata[50];
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerCheckInDate[k] = '\0';
					customer->customerCheckInDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerCheckOutDate[k] = '\0';
					customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				customer->roomFee = ftemp;

			}

		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (strcmp(customer->customerName, custname) == 0 || strcmp(customer->customerCheckInDate, checkindate) == 0) {

			printf("Customer Name: %s\n", customer->customerName);
			printf("Customer customerCheckInDate: %s\n", customer->customerCheckInDate);
			printf("Customer customerCheckOutDate: %s\n", customer->customerCheckOutDate);
			printf("Customer totalbookrooms: %d\n", customer->totalbookrooms);
			printf("Customer roomFee: %f\n", customer->roomFee);


			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			break;
		}

	}

}

bool findRoom(char * str) {


	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool stayingDays = false;
	bool roomFee = false;
	bool roomNo = false;

	int checkinday = 0;
	int checkinmon = 0;

	int checkoutday = 0;
	int checkoutmon = 0;

	int day = 0;
	int mon = 0;

	char ptrdata[50];
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (indate == false) {
				indate = true;

				day = (customer->customerCheckInDate[3] - '0') * 10;
				day = day + customer->customerCheckInDate[4] - '0';

				mon = (customer->customerCheckInDate[0] - '0') * 10;
				mon = mon + customer->customerCheckInDate[1] - '0';

				checkinday = (ptrdata[3] - '0') * 10;
				checkinday = checkinday + (ptrdata[4] - '0');

				checkinmon = (ptrdata[0] - '0') * 10;
				checkinmon = checkinmon + (ptrdata[1] - '0');


				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				day = (customer->customerCheckInDate[3] - '0') * 10;
				day = day + customer->customerCheckInDate[4] - '0';

				mon = (customer->customerCheckInDate[0] - '0') * 10;
				mon = mon + customer->customerCheckInDate[1] - '0';

				checkoutday = (ptrdata[3] - '0') * 10;
				checkoutday = checkoutday + (ptrdata[4] - '0');

				checkoutmon = (ptrdata[0] - '0') * 10;
				checkoutmon = checkoutmon + (ptrdata[1] - '0');




				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (roomFee == false) {
				roomFee = true;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (stayingDays == false) {
				stayingDays = true;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (roomNo == false) {
				roomNo = true;

				int rNo = atoi(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;



				if (rNo == customer->roomNo && mon >= checkinmon && checkoutmon <= mon) {
					if (day >= checkinday || day <= checkoutday) {
						return false;
					}
					else if (day >= checkinday) {
						return false;
					}
					else if (day <= checkoutday) {
						return false;
					}
				}

				day = (customer->customerCheckOutDate[3] - '0') * 10;
				day = day + customer->customerCheckOutDate[4] - '0';

				mon = (customer->customerCheckOutDate[0] - '0') * 10;
				mon = mon + customer->customerCheckOutDate[1] - '0';

				if (rNo == customer->roomNo && (mon >= checkinmon && checkoutmon <= mon)) {
					if (day >= checkinday || day <= checkoutday) {
						return false;
					}
					else if (day >= checkinday) {
						return false;
					}
					else if (day <= checkoutday) {
						return false;
					}
				}
			}

		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;


		if (str[i] == '\n') {

			day = 0; checkinday = 0;  checkoutday = 0;
			mon = 0; checkinmon = 0;  checkoutmon = 0;

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}
			k = 0;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			stayingDays = false;
			roomNo = false;
			roomFee = false;

		}

	}

	return true;

}


void searchBookingByName(char name[50]) {
}

void searchBookingByDate(char date[50]) {
}

bool bookRoom() {

	bool isregister = registerCustomer();

	if (isregister == true) {
		printf("You are successfully Registered! \n");
		printf("What Rooms do you like? \n Press 1 -> Class A \n Press 2 -> Class B \n Press 3 -> Class C \n");

		int option = 0;
		scanf("%d", &option);

		char  *ptr = malloc(_MAX_PATH);
		if (option == 1) {
			ptr = PrintFullPath(".\\", "roomadata.txt");
		}
		else if (option == 2) {
			ptr = PrintFullPath(".\\", "roombdata.txt");
		}
		else if (option == 3) {
			ptr = PrintFullPath(".\\", "roomcdata.txt");
		}

		FILE *fptr;
		char str[MAXCHAR];

		int j = 0;
		while (j < MAXCHAR) {
			str[j] = '\0';
			j++;
		}

		readFile(ptr, str);

		ptr = PrintFullPath(".\\", "checkincustomer.txt");

		char checkInData[MAXCHAR];

		j = 0;
		while (j < MAXCHAR) {
			checkInData[j] = '\0';
			j++;
		}
		readFile(ptr, checkInData);


		bool roomAvail = getRoomavailabilty(str, option);

		bool incustomer = findCheckInCustomer(customer->customerName, checkInData);

		if (incustomer == false) {
			printf(" Sorry, customer with same name has already applied for booking! \n");
			printf("\n");
			return false;
		}
		customer->roomNo = option == 1 ? bookingOperator->hotel->rooms->rooma->roomno :
			option == 2 ? bookingOperator->hotel->rooms->roomb->roomno :
			option == 3 ? bookingOperator->hotel->rooms->roomc->roomno : 0;

		if (roomAvail) {

			j = 0;
			while (j < MAXCHAR) {
				str[j] = '\0';
				j++;
			}
			char * printptr = malloc(_MAX_PATH);;
			printptr = PrintFullPath(".\\", "checkincustomer.txt");

			readFile(printptr, checkInData);


			option == 1 ? printf("Luckly Room Available for Class %s\n", "A") :
				option == 2 ? printf("Luckly Room Available for Class %s\n", "B") :
				option == 3 ? printf("Luckly Room Available for Class %s\n", "C") :
				printf("\n");

			int day1 = 0, mon1 = 0, year1 = 0, day2 = 0, mon2 = 0, year2 = 0;

			printf("Enter Check In Data (MM/DD/YY): ");
			scanf("%s", option == 1 ? &bookingOperator->hotel->rooms->rooma->bookedStartDate :
				option == 2 ? &bookingOperator->hotel->rooms->roomb->bookedStartDate :
				option == 3 ? &bookingOperator->hotel->rooms->roomc->bookedStartDate :
				&bookingOperator->hotel->rooms->rooma->bookedStartDate);

			int  a = 0;
			while (a < 8) {


				customer->customerCheckInDate[a] =
					(option == 1 ? bookingOperator->hotel->rooms->rooma->bookedStartDate[a] :
						option == 2 ? bookingOperator->hotel->rooms->roomb->bookedStartDate[a] :
						option == 3 ? bookingOperator->hotel->rooms->roomc->bookedStartDate[a] : '\0');
				a++;
			}
			mon1 = option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedStartDate[0] - '0') * 10 :
				option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedStartDate[0] - '0') * 10 :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedStartDate[0] - '0') * 10 :
				0;
			mon1 = mon1 + option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedStartDate[1] - '0') :
				option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedStartDate[1] - '0') :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedStartDate[1] - '0') :
				0;


			//	mon2 + (bookingOperator->hotel->rooms->rooma->bookedEndDate[1] - '0');

			day1 = option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedStartDate[3] - '0') * 10 :
				option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedStartDate[3] - '0') * 10 :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedStartDate[3] - '0') * 10 :
				0;

			day1 = day1 + (option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedStartDate[4] - '0') :
				option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedStartDate[4] - '0') :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedStartDate[4] - '0') :
				0);


			if (option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedStartDate[6] == '2' &&
				bookingOperator->hotel->rooms->rooma->bookedStartDate[7] == '0')
				: option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedStartDate[6] == '2' &&
					bookingOperator->hotel->rooms->roomb->bookedStartDate[7] == '0') :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedStartDate[6] == '2' &&
					bookingOperator->hotel->rooms->roomc->bookedStartDate[7] == '0') : false) {

				year1 = 2020;
			}



			printf("Enter Check Out Data (MM/DD/YY): ");
			scanf("%s", option == 1 ? &bookingOperator->hotel->rooms->rooma->bookedEndDate :
				option == 2 ? &bookingOperator->hotel->rooms->roomb->bookedEndDate :
				option == 3 ? &bookingOperator->hotel->rooms->roomc->bookedEndDate :
				&bookingOperator->hotel->rooms->rooma->bookedStartDate);

			a = 0;
			while (a < 8) {

				customer->customerCheckOutDate[a] =
					(option == 1 ? bookingOperator->hotel->rooms->rooma->bookedEndDate[a] :
						option == 2 ? bookingOperator->hotel->rooms->roomb->bookedEndDate[a] :
						option == 3 ? bookingOperator->hotel->rooms->roomc->bookedEndDate[a] : '\0');
				a++;
			}


			mon2 = option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedEndDate[0] - '0') * 10 :
				option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedEndDate[0] - '0') * 10 :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedEndDate[0] - '0') * 10 :
				0;
			mon2 = mon2 + option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedEndDate[1] - '0') :
				option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedEndDate[1] - '0') :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedEndDate[1] - '0') :
				0;


			//	mon2 + (bookingOperator->hotel->rooms->rooma->bookedEndDate[1] - '0');

			day2 = option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedEndDate[3] - '0') * 10 :
				option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedEndDate[3] - '0') * 10 :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedEndDate[3] - '0') * 10 :
				0;

			day2 = day2 + (option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedEndDate[4] - '0') :
				option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedEndDate[4] - '0') :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedEndDate[4] - '0') :
				0);


			if (option == 1 ? (bookingOperator->hotel->rooms->rooma->bookedEndDate[6] == '2' &&
				bookingOperator->hotel->rooms->rooma->bookedEndDate[7] == '0')
				: option == 2 ? (bookingOperator->hotel->rooms->roomb->bookedEndDate[6] == '2' &&
					bookingOperator->hotel->rooms->roomb->bookedEndDate[7] == '0') :
				option == 3 ? (bookingOperator->hotel->rooms->roomc->bookedEndDate[6] == '2' &&
					bookingOperator->hotel->rooms->roomc->bookedEndDate[7] == '0') : false) {

				year2 = 2020;
			}

			time_t t = time(NULL);
			struct tm tm = *localtime(&t);

			if (!valid_date(day1, mon1, year1) && tm.tm_year + 1900 != year1)
			{
				printf("First date is invalid.\n");
				return false;
			}

			int datediff = datesDifference(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, day1, mon1, year1);
			int monthdiff = monthDifference(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, day1, mon1, year1);

			if (datediff > tm.tm_mday && monthdiff < 0) {
				printf(" Check In date not valid \n");
			}
			if (monthdiff > 0 || day1 < tm.tm_mday) {
				printf(" Check In date not valid \n");
				return false;
			}

			if (!valid_date(day2, mon2, year2) && tm.tm_year + 1900 != year2)
			{
				printf(" Check Out date not valid \n");
			}

			int inoutdiff = datesDifference(day1, mon1, year1, day2, mon2, year2);
			monthdiff = monthDifference(day1, mon1, year1, day2, mon2, year2);

			if (monthdiff < 0) {
				printf(" Check Out date not valid \n");
				return false;
			}
			bool discountapp = false;

			if (monthdiff > 0 && (day1 > day2 ? false : inoutdiff >= 0)) {
				printf(" Congrats!! Your checkIn data is prior to month from Today, \n");
				printf(" Now discount of %f%\n", &bookingOperator->hotel->rooms->rooma->discount);
				discountapp = true;

				if (day1 == day2) {
					inoutdiff = datesDifference(day2, mon2, year2, day1, mon1, year1) + 1;
				}
				else {
					inoutdiff = datesDifference(day2, mon2, year2, day1, mon1, year1);
				}
			}
			else {

				int ind = customer->roomNo;
				int lastindex = option == 1 ? 10 : 20;
				for (; ind < lastindex; ind++) {
					bool isroomfound = findRoom(checkInData);

					if (isroomfound) {
						customer->roomNo = ind;
						break;
					}
					else {
						customer->roomNo = ind + 1;
					}

				}

			}


			float price = option == 1 ? bookingOperator->hotel->rooms->roomaPrice :
				option == 2 ? bookingOperator->hotel->rooms->roombPrice :
				option == 3 ? bookingOperator->hotel->rooms->roomcPrice : 0;

			float discount = option == 1 ? bookingOperator->hotel->rooms->rooma->discount :
				option == 2 ? bookingOperator->hotel->rooms->roomb->discount :
				option == 3 ? bookingOperator->hotel->rooms->roomc->discount : 0;

			float totalpayment = inoutdiff * price;
			if (discountapp) {
				totalpayment = totalpayment - (totalpayment * discount);
			}

			printf("\n");
			printf(" Per Room Price of Type %c  is %f \n", option == 1 ? 'A' :
				option == 2 ? 'B' :
				option == 3 ? 'C' : '\n', price);

			printf("\n");

			printf(" Your Total Payment %f will be collected on check In Time", totalpayment);

			char payRoom[12] = { '\0' };
			snprintf(payRoom, sizeof payRoom, "%f", totalpayment);

			int i = 0;
			char customerData[MAXCHAR] = { '\0' };

			int j = 0;
			customerData[i] = '$';
			i++;
			int k = 0;
			while (customer->customerName[k] != '\0') {
				customerData[i] = customer->customerName[k];
				i++;
				k++;
			}
			customerData[i] = '#';
			i++;
			customerData[i] = '$';
			i++;
			k = 0;
			if (option == 1) {
				while (bookingOperator->hotel->rooms->rooma->bookedStartDate[k] != '\0') {
					customerData[i] = bookingOperator->hotel->rooms->rooma->bookedStartDate[k];
					i++;
					k++;
				}
			}
			else if (option == 2) {
				while (bookingOperator->hotel->rooms->roomb->bookedStartDate[k] != '\0') {
					customerData[i] = bookingOperator->hotel->rooms->roomb->bookedStartDate[k];
					i++;
					k++;
				}
			}
			else if (option == 3) {
				while (bookingOperator->hotel->rooms->roomc->bookedStartDate[k] != '\0') {
					customerData[i] = bookingOperator->hotel->rooms->roomc->bookedStartDate[k];
					i++;
					k++;
				}
			}

			customerData[i] = '#';
			i++;
			customerData[i] = '$';
			i++;
			k = 0;
			k = 0;
			if (option == 1) {
				while (bookingOperator->hotel->rooms->rooma->bookedEndDate[k] != '\0') {
					customerData[i] = bookingOperator->hotel->rooms->rooma->bookedEndDate[k];
					i++;
					k++;
				}
			}
			else if (option == 2) {
				while (bookingOperator->hotel->rooms->roomb->bookedEndDate[k] != '\0') {
					customerData[i] = bookingOperator->hotel->rooms->roomb->bookedEndDate[k];
					i++;
					k++;
				}
			}
			else if (option == 3) {
				while (bookingOperator->hotel->rooms->roomc->bookedEndDate[k] != '\0') {
					customerData[i] = bookingOperator->hotel->rooms->roomc->bookedEndDate[k];
					i++;
					k++;
				}
			}

			customerData[i] = '#';
			i++;
			customerData[i] = '$';
			i++;
			k = 0;
			while (payRoom[k] != '\0') {
				customerData[i] = payRoom[k];
				i++;
				k++;
			}

			customerData[i] = '#';
			i++;
			customerData[i] = '$';
			i++;
			k = 0;
			customerData[i] = option == 1 ? 'A' :
				option == 2 ? 'B' :
				option == 3 ? 'C' : '\0';

			i++;
			customerData[i] = '#';
			i++;

			customerData[i] = '$';
			i++;

			if (inoutdiff > 9) {
				customerData[i] = (inoutdiff / 10) + '0';
				i++;
				customerData[i] = (inoutdiff % 10) + '0';
			}
			else {
				customerData[i] = inoutdiff + '0';
			}
			customer->stayingDays = inoutdiff;
			i++;
			customerData[i] = '#';
			i++;

			customerData[i] = '$';
			i++;

			int roomno = option == 1 ? customer->roomNo :
				option == 2 ? customer->roomNo :
				option == 3 ? customer->roomNo : 0;

			if (roomno <= 9) {
				customerData[i] = roomno + '0';
			}
			else {
				char fdigit = (roomno / 10) + '0';
				char sdigit = (roomno % 10) + '0';
				customerData[i] = fdigit;
				i++;
				customerData[i] = sdigit;

			}
			i++;
			customerData[i] = '#';
			i++;

			customerData[i] = '$';
			i++;
			customerData[i] = 'f';
			i++;
			customerData[i] = '#';
			i++;
			customerData[i] = '\n';
			i++;
			char  *ptr = malloc(_MAX_PATH);
			// Get current directory
			ptr = PrintManagerPath(".\\", "checkincustomer.txt");

			FILE *fptr;
			if ((fptr = fopen(ptr, "w")) == NULL) {
				printf("Error! opening file");

			}
			concate(checkInData, customerData);

			i = 0;
			while (checkInData[i] != '\0') {

				i++;
			}
			fwrite(checkInData, i, 1, fptr);
			fclose(fptr);
			customer->roomFee = totalpayment;
			printf("\n ");
			printf(" ** Congratualtions!  Your Booking completed Successfully ** \n\n");
			printf("\n Heres Your Booking Info \n");
			printf("\n Name: %s\n", customer->customerName);
			printf("\n Check In Date: %s \n", customer->customerCheckInDate);
			printf("\n Check Out Date: %s \n", customer->customerCheckOutDate);
			printf("\n Staying Days: %d \n", customer->stayingDays);
			printf("\n Total Amount: %f \n", customer->roomFee);

			printf("\n ");
			return true;
		}
		else
		{
			printf(" Sorry! we have no rooms, You can check rooms for other class \n");
			return false;

		}
	}
	return false;
}

int datesDifference(int day1, int mon1, int year1, int day2, int mon2, int year2) {
	if (day2 < day1)
	{
		// borrow days from february
		if (mon2 == 3)
		{
			//  check whether year is a leap year
			if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
			{
				day2 += 29;
			}

			else
			{
				day2 += 28;
			}
		}

		// borrow days from April or June or September or November
		else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12)
		{
			day2 += 30;
		}

		// borrow days from Jan or Mar or May or July or Aug or Oct or Dec
		else
		{
			day2 += 31;
		}

		mon2 = mon2 - 1;
	}

	if (mon2 < mon1)
	{
		mon2 += 12;
		year2 -= 1;
	}

	int day_diff = day2 - day1;
	//	mon_diff = mon2 - mon1;
	//	year_diff = year2 - year1;

	//	printf("Difference: %d years %02d months and %02d days.", year_diff, mon_diff, day_diff);

	return day_diff; // return 0 to operating system
}

int monthDifference(int day1, int mon1, int year1, int day2, int mon2, int year2) {

	if (day2 < day1)
	{
		// borrow days from february
		if (mon2 == 3)
		{
			//  check whether year is a leap year
			if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
			{
				day2 += 29;
			}

			else
			{
				day2 += 28;
			}
		}

		// borrow days from April or June or September or November
		else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12)
		{
			day2 += 30;
		}

		// borrow days from Jan or Mar or May or July or Aug or Oct or Dec
		else
		{
			day2 += 31;
		}

		mon2 = mon2 - 1;
	}

	if (mon2 < mon1)
	{
		mon2 += 12;
		year2 -= 1;
	}

	int	mon_diff = mon2 - mon1;
	//	year_diff = year2 - year1;

	//	printf("Difference: %d years %02d months and %02d days.", year_diff, mon_diff, day_diff);

	return mon_diff;
}

bool findCustomer(char * str) {


	int i = 0;

	bool name = false;
	bool address = false;
	bool telephone = false;


	char ptrdata[50];
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;



				if (strcmp(customer->customerName, ptrdata) == 0) {
					return true;
				}
				k = 0;
				while (ptrdata[k] != '\0') {
					//	CustName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}

		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			name = false;
			address = false;
			telephone = false;

		}

	}
	return false;
}
bool registerCustomer() {

	printf("%s", "Enter Your Name: ");
	fgets(customer->customerName, sizeof(customer->customerName), stdin);
	int index = 0;
	while (customer->customerName[index] != '\0') {
		if (customer->customerName[index] == '\n') {
			customer->customerName[index] = '\0';
			break;
		}
		index++;
	}

	///
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "customerdata.txt");



	FILE *fptr;
	char str[MAXCHAR];


	char customerData[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		customerData[j] = '\0';
		j++;
	}

	readFile(ptr, customerData);

	bool exists = findCustomer(customerData);


	if (exists == true) {

		printf(" Customer with Same name Already Registered ");
		return true;
	}
	/////
	int i = 0;

	printf("%s", "Enter Your Address: ");
	fgets(customer->address, sizeof(customer->address), stdin);

	i = 0;
	while (i < 30)
	{
		if (customer->address[i] == '\n') {
			customer->address[i] = '\0';
		}
		if (customer->customerName[i] == '\n') {
			customer->customerName[i] = '\0';
		}
		i++;
	}
	printf("%s", "Enter Your Telephone No: ");
	fgets(customer->telephone, sizeof(customer->telephone), stdin);

	i = 0;
	while (i < 30)
	{
		if (customer->telephone[i] == '\n') {
			customer->telephone[i] = '\0';
		}
		i++;
	}




	j = 0;
	while (j < MAXCHAR) {
		customerData[j] = '\0';
		j++;
	}



	char fchar = customer->customerName[0];
	char schar = customer->customerName[0];
	customer->customerName[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = customer->customerName[i];
		customer->customerName[i] = fchar;

		i++;

		if (schar == '\0') {
			customer->customerName[i] = '#';
			break;
		}
	}

	fchar = customer->address[0];
	schar = customer->address[0];
	customer->address[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = customer->address[i];
		customer->address[i] = fchar;

		i++;

		if (schar == '\0') {
			customer->address[i] = '#';
			break;
		}
	}

	fchar = customer->telephone[0];
	schar = customer->telephone[0];
	customer->telephone[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = customer->telephone[i];
		customer->telephone[i] = fchar;

		i++;

		if (schar == '\0') {
			customer->telephone[i] = '#';
			break;
		}
	}


	j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}
	i = 0;
	while (i < MAXCHAR) {

		j = 0;
		while (j < 50 && customer->customerName[j] != '\0') {
			str[i] = customer->customerName[j];
			j++;
			i++;
		}
		j = 0;

		while (j < 50 && customer->address[j] != '\0') {

			str[i] = customer->address[j];
			j++;
			i++;
		}
		j = 0;
		while (j < 30 && customer->telephone[j] != '\0') {

			str[i] = customer->telephone[j];
			j++;
			i++;
		}
		str[i] = '\n';
		break;
	}


	concate(str, customerData);

	//	printf("%s\n", str);

	if ((fptr = fopen(ptr, "wb")) == NULL) {
		printf("Error! opening file");

	}
	i = 0;
	while (i < MAXCHAR && str[i] != '\0') {
		i++;
	}
	fwrite(str, i, 1, fptr);
	fclose(fptr);

	i = 0;
	while (i < MAXCHAR && str[i] != '\0') {
		i++;
	}

	return true;
}


int valid_date(int day, int mon, int year)
{
	int is_valid = 1, is_leap = 0;

	if (year >= 1800 && year <= 9999)
	{

		//  check whether year is a leap year
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			is_leap = 1;
		}

		// check whether mon is between 1 and 12
		if (mon >= 1 && mon <= 12)
		{
			// check for days in feb
			if (mon == 2)
			{
				if (is_leap && day == 29)
				{
					is_valid = 1;
				}
				else if (day > 28)
				{
					is_valid = 0;
				}
			}

			// check for days in April, June, September and November
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			{
				if (day > 30)
				{
					is_valid = 0;
				}
			}

			// check for days in rest of the months 
			// i.e Jan, Mar, May, July, Aug, Oct, Dec
			else if (day > 31)
			{
				is_valid = 0;
			}
		}

		else
		{
			is_valid = 0;
		}

	}
	else
	{
		is_valid = 0;
	}

	return is_valid;

}


bool findCheckInCustomer(char * customername, char * str) {
	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	bool namefound = false;
	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				if (strcmp(customer->customerName, ptrdata) == 0)
				{
					namefound = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					customer->customerCheckOutDate[k] = '\0';
					customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				customer->roomFee = ftemp;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				customer->roomType = roomType;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				customer->stayingDays = days;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (roomno == false) {
				roomno = true;
				customer->roomNo = atoi(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (namefound
			&& found == 'f') {
			return false;
		}
		if (str[i] == '\n') {

			found = '\0';
			days = 0;
			roomType = '\0';

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			namefound = false;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}
	}

	return true;
}






static struct Hotel * hotel;


void resetHotel() {

	hotel = (struct Hotel*) malloc(sizeof(struct Hotel));
	hotel->rooms = (struct Rooms*) malloc(sizeof(struct Rooms));
	hotel->rooms->rooma = (struct Rooma*) malloc(sizeof(struct Rooma));
	hotel->rooms->roomb = (struct Roomb*) malloc(sizeof(struct Roomb));
	hotel->rooms->roomc = (struct Roomc*) malloc(sizeof(struct Roomc));
	hotel->rooms->rooma->booked = false;
	hotel->rooms->rooma->roomno = 0;

	hotel->rooms->roomb->booked = false;
	hotel->rooms->roomb->roomno = 0;

	hotel->rooms->roomc->booked = false;
	hotel->rooms->roomc->roomno = 0;

	int i = 0;
	while (i < 10) {

		hotel->rooms->rooma->bookedEndDate[i] = '\0';
		hotel->rooms->rooma->bookedStartDate[i] = '\0';

		hotel->rooms->roomb->bookedEndDate[i] = '\0';
		hotel->rooms->roomb->bookedStartDate[i] = '\0';

		hotel->rooms->roomc->bookedEndDate[i] = '\0';
		hotel->rooms->roomc->bookedStartDate[i] = '\0';

		i++;
	}

}

struct  Hotel * setHotel() {


	hotel = (struct Hotel*) malloc(sizeof(struct Hotel));



	int i = 0;
	while (i < 50) {
		hotel->hotelName[i] = '\0';

		i++;
	}
	hotel->rooms = (struct Rooms*) malloc(sizeof(struct Rooms));
	hotel->rooms->rooma = (struct Rooma*) malloc(sizeof(struct Rooma));
	hotel->rooms->roomb = (struct Roomb*) malloc(sizeof(struct Roomb));
	hotel->rooms->roomc = (struct Roomc*) malloc(sizeof(struct Roomc));

	hotel->rooms->roomaPrice = 0.0;
	hotel->rooms->roombPrice = 0.0;
	hotel->rooms->roomcPrice = 0.0;

	hotel->rooms->rooma->booked = false;
	hotel->rooms->roomb->booked = false;
	hotel->rooms->roomc->booked = false;

	hotel->rooms->rooma->roomno = 0;
	hotel->rooms->roomb->roomno = 0;
	hotel->rooms->roomc->roomno = 0;

	i = 0;
	while (i < 10) {
		hotel->rooms->rooma->bookedEndDate[i] = '\0';
		hotel->rooms->roomb->bookedEndDate[i] = '\0';
		hotel->rooms->roomc->bookedEndDate[i] = '\0';

		hotel->rooms->rooma->bookedStartDate[i] = '\0';
		hotel->rooms->roomb->bookedStartDate[i] = '\0';
		hotel->rooms->roomc->bookedStartDate[i] = '\0';
		i++;
	}
	return hotel;
}

void setHotelName(char name[50]) {
	int i = 0;
	while (name[i] != '\0') {
		hotel->hotelName[i] = name[i];
		i++;
	}

}


void showTotalBookedRooms() {

	int CountA = countRoomA();
	int CountB = countRoomB();
	int CountC = countRoomC();
	int Total = CountA + CountB + CountC;

	printf("Total No of Booked Rooms: %d\n", Total);

}

void showTotalRoomABooked() {
	int CountA = countRoomA();

	printf("Total No of Booked Rooms of A Class: %d\n", CountA);
}
void showTotalRoomBBooked() {
	int CountB = countRoomB();

	printf("Total No of Booked Rooms of B Class: %d\n", CountB);
}
void showTotalRoomCBooked() {
	int CountC = countRoomC();

	printf("Total No of Booked Rooms of B Class: %d\n", CountC);
}
void showProfitRoomA() {}
void showProfitRoomB() {}
void showProfitRoomC() {}

void searchRoomsA() {

}
void searchRoomsB() {}
void searchRoomsC() {}
bool checkRoomAvaialabilty() { return false; }

int countRoomA() {
	return 0;

}

int countRoomB() {
	return 0;
}

int countRoomC() {
	return 0;
}



static struct Manager * manager;

struct Manager * resetManager() {
	manager = (struct Manager*) malloc(sizeof(struct Manager));

	int i = 0;
	while (i < 50) {
		manager->ManagerName[i] = '\0';
		manager->ManagerPassword[i] = '\0';
		i++;
	}

	manager->hotel = (struct Hotel*) malloc(sizeof(struct Hotel));
	manager->hotel->rooms = (struct Rooms*) malloc(sizeof(struct Rooms));
	manager->hotel->rooms->rooma = (struct Rooma*) malloc(sizeof(struct Rooma));
	manager->hotel->rooms->roomb = (struct Roomb*) malloc(sizeof(struct Roomb));
	manager->hotel->rooms->roomc = (struct Roomc*) malloc(sizeof(struct Roomc));

	manager->hotel->rooms->roomaPrice = 0.0;
	manager->hotel->rooms->roombPrice = 0.0;
	manager->hotel->rooms->roomcPrice = 0.0;

	manager->hotel->rooms->roomaPrice = 0.0;
	manager->hotel->rooms->roombPrice = 0.0;
	manager->hotel->rooms->roomcPrice = 0.0;

	manager->hotel->rooms->rooma->booked = false;
	manager->hotel->rooms->roomb->booked = false;
	manager->hotel->rooms->roomc->booked = false;

	manager->hotel->rooms->rooma->roomno = 0;
	manager->hotel->rooms->roomb->roomno = 0;
	manager->hotel->rooms->roomc->roomno = 0;

	i = 0;
	while (i < 10) {
		manager->hotel->rooms->rooma->bookedEndDate[i] = '\0';
		manager->hotel->rooms->roomb->bookedEndDate[i] = '\0';
		manager->hotel->rooms->roomc->bookedEndDate[i] = '\0';

		manager->hotel->rooms->rooma->bookedStartDate[i] = '\0';
		manager->hotel->rooms->roomb->bookedStartDate[i] = '\0';
		manager->hotel->rooms->roomc->bookedStartDate[i] = '\0';
		i++;
	}

	return manager;
}

char *  PrintManagerPath(char * partialPath, char * filename)
{
	// char full[_MAX_PATH];

	char *full = malloc(_MAX_PATH);
	// char *filename = "bookingdata.txt";

	if (_fullpath(full, partialPath, _MAX_PATH) != NULL)
	{

		char *a = full;
		char *b = filename;

		// pointing to the end of the 1st string
		while (*a)   // till it doesn't point to NULL-till string is not empty
		{
			a++;    // point to the next letter of the string
		}
		while (*b)   // till second string is not empty
		{
			*a = *b;
			b++;
			a++;
		}
		*a = '\0';  // string must end with '\0'

		return full;
	}
	else
		return NULL;

}

void deepManagercopy(struct Hotel * hotel) {

}

bool changeRoomAprice() {

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomapricedata.txt");

	FILE *fptr;

	readRoom(ptr, 1);

	if (manager->hotel->rooms->roomaPrice == 0.0) {
		printf("Price Not Set ");

		printf(" Enter Price for Class A Room: ");
		scanf("%f", &manager->hotel->rooms->roomaPrice);

		if ((fptr = fopen(ptr, "w")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", manager->hotel->rooms->roomaPrice);
		fclose(fptr);

		return true;
	}
	else {
		printf("Price For Class A Room: %f\n", manager->hotel->rooms->roomaPrice);

		printf(" Enter Price for Class A Room: ");
		scanf("%f", &manager->hotel->rooms->roomaPrice);

		if ((fptr = fopen(ptr, "wb")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", &manager->hotel->rooms->roomaPrice);
		fclose(fptr);

		return true;
	}

	return false;
}

bool changeRoomBprice() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roombpricedata.txt");

	FILE *fptr;
	readRoom(ptr, 1);

	if (manager->hotel->rooms->roombPrice == 0.0) {
		printf("Price Not Set ");

		printf(" Enter Price for Class B Room: ");
		scanf("%f", &manager->hotel->rooms->roombPrice);

		if ((fptr = fopen(ptr, "w")) == NULL) {
			printf("Error! opening file");
		}

		fprintf(fptr, "%f", manager->hotel->rooms->roombPrice);
		fclose(fptr);

		return true;
	}
	else {
		printf("Price For Class B Room: %f\n", manager->hotel->rooms->roombPrice);

		printf(" Enter Price for Class B Room: ");
		scanf("%f", &manager->hotel->rooms->roombPrice);

		if ((fptr = fopen(ptr, "wb")) == NULL) {
			printf("Error! opening file");
		}

		fprintf(fptr, "%f", &manager->hotel->rooms->roombPrice);
		fclose(fptr);

		return true;
	}

	return false;
}
bool changeRoomCprice() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomcpricedata.txt");

	FILE *fptr;

	readRoom(ptr, 1);

	if (manager->hotel->rooms->roomcPrice == 0.0) {
		printf("Price Not Set ");

		printf(" Enter Price for Class C Room: ");
		scanf("%f", &manager->hotel->rooms->roomcPrice);

		if ((fptr = fopen(ptr, "w")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", manager->hotel->rooms->roomcPrice);
		fclose(fptr);

		return true;
	}
	else {
		printf("Price For Class C Room: %f\n", manager->hotel->rooms->roomcPrice);

		printf(" Enter Price for Class C Room: ");
		scanf("%f", &manager->hotel->rooms->roomcPrice);

		if ((fptr = fopen(ptr, "wb")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", &manager->hotel->rooms->roomcPrice);
		fclose(fptr);

		return true;
	}

	return false;
}
void printAllRooms() {

	printRoomA();
	printRoomB();
	printRoomC();

}


void printRoomA() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomapricedata.txt");


	FILE *fptr;


	readRoom(ptr, 1);

	if (manager->hotel->rooms->roomaPrice == 0.0) {
		printf("Price Not Set \n");
	}
	else {
		printf("Price For Class A Room: %f\n", manager->hotel->rooms->roomaPrice);
	}

	//readRoomaPrice(ptr, &str);

}
void printRoomB() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roombpricedata.txt");

	FILE *fptr;

	readRoom(ptr, 2);

	if (manager->hotel->rooms->roombPrice == 0.0) {
		printf("Price Not Set \n");
	}
	else {
		printf("Price For Class B Room: %f\n", manager->hotel->rooms->roombPrice);
	}

}

void printRoomC() {

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomcpricedata.txt");



	FILE *fptr;

	readRoom(ptr, 3);

	if (manager->hotel->rooms->roomcPrice == 0.0) {
		printf("Price Not Set \n");
	}
	else {
		printf("Price For Class C Room: %f\n", manager->hotel->rooms->roomcPrice);
	}

}
bool addDiscountRoomA() {

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomadiscountdata.txt");

	FILE *fptr;

	readDiscount(ptr, 1);

	if (manager->hotel->rooms->rooma->discount == 0.0) {
		printf("Discount Not Set \n");

		printf(" Enter Discount for Class A Room: ");
		scanf("%f", &manager->hotel->rooms->rooma->discount);

		if ((fptr = fopen(ptr, "w")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", manager->hotel->rooms->rooma->discount);
		fclose(fptr);

		return true;
	}
	else {
		printf("Dicount on Class A Room: %f\n", manager->hotel->rooms->rooma->discount);

		printf(" Dicount on Class A Room: ");
		scanf("%f", &manager->hotel->rooms->rooma->discount);

		if ((fptr = fopen(ptr, "wb")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", &manager->hotel->rooms->rooma->discount);
		fclose(fptr);

		return true;
	}

	return false;
}
bool addDiscountRoomB() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roombdiscountdata.txt");

	FILE *fptr;

	readDiscount(ptr, 2);

	if (manager->hotel->rooms->roomb->discount == 0.0) {
		printf("Discount Not Set \n");

		printf(" Enter Discount for Class B Room: ");
		scanf("%f", &manager->hotel->rooms->roomb->discount);

		if ((fptr = fopen(ptr, "w")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", manager->hotel->rooms->roomb->discount);
		fclose(fptr);

		return true;
	}
	else {
		printf("Dicount on Class B Room: %f\n", manager->hotel->rooms->roomb->discount);

		printf(" Dicount on Class B Room: ");
		scanf("%f", &manager->hotel->rooms->roomb->discount);

		if ((fptr = fopen(ptr, "wb")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", &manager->hotel->rooms->roomb->discount);
		fclose(fptr);

		return true;
	}

	return false;
}
bool addDiscountRoomC() {

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomcdiscountdata.txt");

	FILE *fptr;

	readDiscount(ptr, 3);

	if (manager->hotel->rooms->roomc->discount == 0.0) {
		printf("Discount Not Set \n");

		printf(" Enter Discount for Class C Room: ");
		scanf("%f", &manager->hotel->rooms->roomc->discount);

		if ((fptr = fopen(ptr, "w")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", manager->hotel->rooms->roomc->discount);
		fclose(fptr);

		return true;
	}
	else {
		printf("Dicount on Class C Room: %f\n", manager->hotel->rooms->roomc->discount);

		printf(" Dicount on Class C Room: ");
		scanf("%f", &manager->hotel->rooms->roomc->discount);

		if ((fptr = fopen(ptr, "wb")) == NULL) {
			printf("Error! opening file");

		}

		fprintf(fptr, "%f", &manager->hotel->rooms->roomc->discount);
		fclose(fptr);

		return true;
	}

	return false;
}


void readRoom(char *ptr, int index) {

	FILE *fptr;

	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");
	}
	float val = 0.0;

	fscanf(fptr, "%f", &val);

	fclose(fptr);

	if (index == 1) {
		manager->hotel->rooms->roomaPrice = val;
	}
	else if (index == 2) {
		manager->hotel->rooms->roombPrice = val;
	}
	else if (index == 3) {
		manager->hotel->rooms->roomcPrice = val;
	}
}

void readDiscount(char *ptr, int index) {

	FILE *fptr;

	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");
	}
	float val = 0.0;

	fscanf(fptr, "%f", &val);

	fclose(fptr);

	if (index == 1) {
		manager->hotel->rooms->rooma->discount = val;
	}
	else if (index == 2) {
		manager->hotel->rooms->roomb->discount = val;
	}
	else if (index == 3) {
		manager->hotel->rooms->roomc->discount = val;
	}
}

void printAllDiscount() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomadiscountdata.txt");



	readDiscount(ptr, 1);
	printf("Discount For Class A: %f\n", manager->hotel->rooms->rooma->discount);
	ptr = PrintManagerPath(".\\", "roombdiscountdata.txt");

	readDiscount(ptr, 2);

	printf("Discount For Class A: %f\n", manager->hotel->rooms->roomb->discount);
	ptr = PrintManagerPath(".\\", "roomcdiscountdata.txt");

	readDiscount(ptr, 3);
	printf("Discount For Class A: %f\n", manager->hotel->rooms->roomc->discount);

}

void readAllDiscount() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomadiscountdata.txt");



	readDiscount(ptr, 1);
	//	printf("Discount For Class A: %f\n", manager->hotel->rooms->rooma->discount);
	ptr = PrintManagerPath(".\\", "roombdiscountdata.txt");

	readDiscount(ptr, 2);

	//	printf("Discount For Class A: %f\n", manager->hotel->rooms->roomb->discount);
	ptr = PrintManagerPath(".\\", "roomcdiscountdata.txt");

	readDiscount(ptr, 3);
	//	printf("Discount For Class A: %f\n", manager->hotel->rooms->roomc->discount);

}

void readRoomsPrice() {

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintManagerPath(".\\", "roomapricedata.txt");



	FILE *fptr;

	readRoom(ptr, 1);

	ptr = PrintManagerPath(".\\", "roombpricedata.txt");

	readRoom(ptr, 2);

	ptr = PrintManagerPath(".\\", "roomcpricedata.txt");

	readRoom(ptr, 3);


}


static struct Checkinoperator * checkinOperator;
static struct Checkoutoperator * checkoutOperator;

struct Checkinoperator * getCheckIn() {
	return checkinOperator;
}

struct Checkoutoperator * getCheckOut() {
	return checkoutOperator;
}

void setCheckInOperator(struct Hotel * h, struct Customer * c) {
	checkinOperator = (struct Checkinoperator*) malloc(sizeof(struct Checkinoperator));
	int i = 0;
	while (i < 50)
	{
		checkinOperator->checkinName[i] = '\0';
		i++;
	}

	i = 0;
	while (i < 50)
	{
		checkinOperator->checkinPassword[i] = '\0';
		i++;
	}


}

void setCheckoutOperator(struct Hotel * h, struct Customer * c) {
	checkoutOperator = (struct Checkoutoperator*) malloc(sizeof(struct Checkoutoperator));

	int i = 0;
	while (i < 50)
	{
		checkoutOperator->checkoutName[i] = '\0';
		i++;
	}

	i = 0;
	while (i < 50)
	{
		checkoutOperator->checkoutPassword[i] = '\0';
		i++;
	}

	checkinOperator->hotel = h;

}

bool searchRoomsCheckIn(char * customername) {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "checkincustomer.txt");


	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	bool exists = findBookingCustomer(customername, str);
	if (exists == false) {
		printf(" Customer Not found! ");
		return false;
	}
	return true;
}

bool findBookingCustomer(char * customername, char * str) {
	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkinOperator->customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkinOperator->customer->customerCheckInDate[k] = '\0';
					checkinOperator->customer->customerCheckInDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkinOperator->customer->customerCheckOutDate[k] = '\0';
					checkinOperator->customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				checkinOperator->customer->roomFee = ftemp;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				checkinOperator->customer->roomType = roomType;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				checkinOperator->customer->stayingDays = days;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (roomno == false) {
				roomno = true;
				checkinOperator->customer->roomNo = atoi(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {
			if (found == 'f' && strcmp(checkinOperator->customer->customerName, customername) == 0) {
				printf("Customer Name: %s\n", checkinOperator->customer->customerName);
				printf("Check In Date: %s\n", checkinOperator->customer->customerCheckInDate);
				printf("Check Out Date: %s\n", checkinOperator->customer->customerCheckOutDate);
				printf("Total Payment: %f\n", checkinOperator->customer->roomFee);
				printf("Room Class: %c\n", checkinOperator->customer->roomType);
				printf("Total Staying Days: %d\n", checkoutOperator->customer->stayingDays);

				return true;
			}
			else {
				found = '\0';
				days = 0;
				roomType = '\0';

			}
			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;

			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}
	if (found == '\0') {
		return false;
	}
}



bool resetcheckIn(char * customername, char * str) {

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	bool foundname = false;
	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				if (strcmp(checkoutOperator->customer->customerName, ptrdata) == 0) {
					foundname = true;
				}
				k = 0;
				while (ptrdata[k] != '\0') {
					//checkinOperator->customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					//	checkinOperator->customer->customerCheckInDate[k] = '\0';
					//	checkinOperator->customer->customerCheckInDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					//	checkinOperator->customer->customerCheckOutDate[k] = '\0';
					//	checkinOperator->customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				//checkinOperator->customer->roomFee = ftemp;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				//checkinOperator->customer->roomType = roomType;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				//checkinOperator->customer->stayingDays = days;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (roomno == false) {
				roomno = true;
				//checkinOperator->customer->roomNo = atoi(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];
				if (found == 'f' && foundname == true) {
					str[i - 1] = 't';
					return true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			found = '\0';
			days = 0;
			roomType = '\0';


			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			found = '\0';
			foundname = false;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}
	return false;
}

void readOperatorFile(char *ptr, char *fileptr) {

	FILE *fptr;
	char str[MAXCHAR];
	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		fileptr[j] = '\0';
		j++;
	}

	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");
	}



	while (fgets(str, MAXCHAR, fptr) != NULL) {
		//	printf("%s\n", str);
		concate(fileptr, str);
	}

	//	printf("%s\n", fileptr);
	fclose(fptr);


}

void printCustomerBookingCheckIn() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "checkincustomer.txt");



	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkinOperator->customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkinOperator->customer->customerCheckInDate[k] = '\0';
					checkinOperator->customer->customerCheckInDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkinOperator->customer->customerCheckOutDate[k] = '\0';
					checkinOperator->customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				checkinOperator->customer->roomFee = ftemp;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {
			printf("Customer Name: %s\n", checkinOperator->customer->customerName);
			printf("Check In Date: %s\n", checkinOperator->customer->customerCheckInDate);
			printf("Check Out Date: %s\n", checkinOperator->customer->customerCheckOutDate);
			printf("Total Payment: %f\n", checkinOperator->customer->roomFee);
			printf("Room Class: %c\n", roomType);
			printf("Total Staying Days: %d\n", days);

			found = '\0';
			days = 0;
			roomType = '\0';

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				checkinOperator->customer->customerName[k] = '\0';
				k++;
			}

			k = 0;
			while (k < 11) {
				checkinOperator->customer->customerCheckInDate[k] = '\0';
				checkinOperator->customer->customerCheckOutDate[k] = '\0';
				k++;
			}
			k = 0;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}


}
void changeStayingDays() {}


bool searchRoomsCheckOut(char * customername) {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "checkoutcustomer.txt");


	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	bool exists = findBookingCustomer(customername, str);
	if (exists == false) {
		printf(" Customer Not found! ");
		return false;
	}
	return true;
}

void printCustomerBookingCheckOut() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "checkoutcustomer.txt");


	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkoutOperator->customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkoutOperator->customer->customerCheckInDate[k] = '\0';
					checkoutOperator->customer->customerCheckInDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkoutOperator->customer->customerCheckOutDate[k] = '\0';
					checkoutOperator->customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				checkoutOperator->customer->roomFee = ftemp;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			printf("\n");
			printf("Customer Name: %s\n", checkoutOperator->customer->customerName);
			printf("Check In Date: %s\n", checkoutOperator->customer->customerCheckInDate);
			printf("Check Out Date: %s\n", checkoutOperator->customer->customerCheckOutDate);
			printf("Total Payment Paid: %f\n", checkoutOperator->customer->roomFee);
			printf("Room Class: %c\n", roomType);
			printf("Total Staying Days: %d\n", days);
			printf("\n");

			found = '\0';
			days = 0;
			roomType = '\0';

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				checkoutOperator->customer->customerName[k] = '\0';
				k++;
			}

			k = 0;
			while (k < 11) {
				checkoutOperator->customer->customerCheckInDate[k] = '\0';
				checkoutOperator->customer->customerCheckOutDate[k] = '\0';
				k++;
			}
			k = 0;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}

}

void SearchCheckInCustomer() {
	char customername[50] = { '\0' };
	printf("Enter Customer Name: ");

	fgets(customername, sizeof(customername), stdin);

	int index = 0;
	while (customername[index] != '\0')
	{
		if (customername[index] == '\n') {
			customername[index] = '\0';
			break;
		}
		index++;
	}

	char  *ptr = malloc(_MAX_PATH);



	// Get current directory
	ptr = PrintFullPath(".\\", "checkincustomer.txt");



	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	bool exists = findBookingCustomer(customername, str);
	printf("\n");

}

void confirminBooking() {
	char customername[50] = { '\0' };
	printf("Enter Customer Name: ");

	fgets(customername, sizeof(customername), stdin);
	int index = 0;
	while (customername[index] != '\0')
	{
		if (customername[index] == '\n') {
			customername[index] = '\0';
			break;
		}
		index++;
	}

	char  *ptr = malloc(_MAX_PATH);



	// Get current directory
	ptr = PrintFullPath(".\\", "checkincustomer.txt");



	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	bool exists = findBookingCustomer(customername, str);


	if (checkinOperator->customer->roomType == 'A')
		ptr = PrintFullPath(".\\", "roomadata.txt");
	else if (checkinOperator->customer->roomType == 'B')
		ptr = PrintFullPath(".\\", "roombdata.txt");
	else if (checkinOperator->customer->roomType == 'C')
		ptr = PrintFullPath(".\\", "roomcdata.txt");


	char roomData[MAXCHAR];

	j = 0;
	while (j < MAXCHAR) {
		roomData[j] = '\0';
		j++;
	}

	readFile(ptr, roomData);

	int day = (checkinOperator->customer->customerCheckInDate[3] - '0') * 10;
	day = day + checkinOperator->customer->customerCheckInDate[4] - '0';

	int mon = (checkinOperator->customer->customerCheckInDate[0] - '0') * 10;
	mon = mon + checkinOperator->customer->customerCheckInDate[1] - '0';

	int year = (checkinOperator->customer->customerCheckInDate[6] - '0') * 10;
	year = year + checkinOperator->customer->customerCheckInDate[7] - '0';

	year = year == 20 ? 2020 : year;


	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int todayIndiff = datesDifference(day, mon, year, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	int monthIndiff = monthinoutDifference(day, mon, year, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

	if (exists) {
		bool cancelBooking = false;

		if (todayIndiff == 0 || monthIndiff == 0) {

			if (todayIndiff == 0) {
				if (monthIndiff > 0) {
					if (tm.tm_mon + 1 > mon) {
						printf(" Your Check In Date was %s but Today is %d/%d/%d \n\n", checkinOperator->customer->customerCheckInDate, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
						printf(" You arrieved late than your Check In date \n\n ");
						printf(" To continue this booking now, create new by going back to menu \n\n");

						cancelBooking = true;
					}
					else if (mon > tm.tm_mon + 1) {
						printf(" You arrieved earlier than your Check In date \n\n ");
						printf(" To continue this booking now, update your booking by going back to menu \n\n");

						return;

					}
				}
				else if (monthIndiff == 0) {
					// check in completed successfully
				}
			}
			else if (monthIndiff == 0) {
				if (todayIndiff > 0) {
					if (tm.tm_mday > day) {
						printf(" Your Check In Date was %s but Today is %d/%d/%d \n\n", checkinOperator->customer->customerCheckInDate, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
						printf(" You arrieved late than your Check In date \n\n ");
						printf(" To continue this booking now, create new booking by going back to menu \n\n");

						cancelBooking = true;
					}
					else if (day > tm.tm_mday + 1) {
						printf(" You arrieved earlier than your Check In date \n\n ");
						printf(" To continue this booking now, update your booking by going back to menu \n\n");

						return;
					}
				}
				else if (todayIndiff == 0) {
					// check in completed successfully

				}
			}


		}
		else if (todayIndiff > 0 && monthIndiff > 0) {
			printf(" Your Check In Date was %s but Today is %d/%d/%d \n\n", checkinOperator->customer->customerCheckInDate, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			printf(" To continue this booking now, update your booking by going back to menu \n\n");

			removeCheckinBooking(str, 'b');


			if (checkinOperator->customer->roomType == 'A')
				ptr = PrintFullPath(".\\", "roomadata.txt");
			else if (checkinOperator->customer->roomType == 'B')
				ptr = PrintFullPath(".\\", "roombdata.txt");
			else if (checkinOperator->customer->roomType == 'C')
				ptr = PrintFullPath(".\\", "roomcdata.txt");

			if (changeRoomNo) {
				if ((fptr = fopen(ptr, "wb")) == NULL) {
					printf("Error! opening file");

				}
				int i = 0;
				while (i < MAXCHAR && roomData[i] != '\0') {
					i++;
				}
				fwrite(roomData, i, 1, fptr);
				fclose(fptr);
			}

			if ((fptr = fopen(ptr, "wb")) == NULL) {
				printf("Error! opening file");

			}
			int i = 0;
			while (i < MAXCHAR && str[i] != '\0') {
				i++;
			}
			fwrite(str, i, 1, fptr);
			fclose(fptr);

			return;
		}


		printf("\n\n");

		if (cancelBooking) {

			removeCheckinBooking(str, 'b');

			ptr = PrintFullPath(".\\", "checkincustomer.txt");
			if ((fptr = fopen(ptr, "wb")) == NULL) {
				printf("Error! opening file");

			}
			int i = 0;
			while (i < MAXCHAR && str[i] != '\0') {
				i++;
			}
			fwrite(str, i, 1, fptr);
			fclose(fptr);

			return;
		}

		printf(" You have to pay 50 percent for your Total Payment to Check In! \n");
		printf("Press 1 to Pay \n");
		printf("Press 2 to Cancel Booking \n");
		int option = 0;

		scanf("%d", &option);
		getchar();
		if (option == 1) {
			printf("\n");
			bool updated = resetcheckIn(checkinOperator->customer->customerName, str);

			if (checkinOperator->customer->roomType == 'A')
				ptr = PrintFullPath(".\\", "roomadata.txt");
			else if (checkinOperator->customer->roomType == 'B')
				ptr = PrintFullPath(".\\", "roombdata.txt");
			else if (checkinOperator->customer->roomType == 'C')
				ptr = PrintFullPath(".\\", "roomcdata.txt");

			readFile(ptr, roomData);

			int rNo = checkinOperator->customer->roomNo;
			char rc = 't';
			bool changeRoom = changeRoomNo(roomData, rNo, rc);


			if (changeRoom) {
				if ((fptr = fopen(ptr, "wb")) == NULL) {
					printf("Error! opening file");

				}
				int i = 0;
				while (i < MAXCHAR && roomData[i] != '\0') {
					i++;
				}
				fwrite(roomData, i, 1, fptr);
				fclose(fptr);
			}

			if (updated) {
				ptr = PrintFullPath(".\\", "checkincustomer.txt");

				if ((fptr = fopen(ptr, "wb")) == NULL) {
					printf("Error! opening file");

				}
				int i = 0;
				while (i < MAXCHAR && str[i] != '\0') {
					i++;
				}
				fwrite(str, i, 1, fptr);
				fclose(fptr);

				checkinOperator->customer->roomFee = checkinOperator->customer->roomFee - (checkinOperator->customer->roomFee * 0.50);
				addCustomerCheckout();

				printf(" \n\n");
				printf("Congratulations! You have successfully Checked In \n");
				printf(" \n");

			}
		}
		else if (option == 2) {
			printf(" Are You Sure? you want to cancel your booking? (Y/N) ");
			char op;
			getchar();
			op = getchar();


			if (op == 'y' || op == 'Y') {
				removeCheckinBooking(str, 't');


				if (checkinOperator->customer->roomType == 'A')
					ptr = PrintFullPath(".\\", "roomadata.txt");
				else if (checkinOperator->customer->roomType == 'B')
					ptr = PrintFullPath(".\\", "roombdata.txt");
				else if (checkinOperator->customer->roomType == 'C')
					ptr = PrintFullPath(".\\", "roomcdata.txt");

				if (changeRoomNo) {
					if ((fptr = fopen(ptr, "wb")) == NULL) {
						printf("Error! opening file");

					}
					int i = 0;
					while (i < MAXCHAR && roomData[i] != '\0') {
						i++;
					}
					fwrite(roomData, i, 1, fptr);
					fclose(fptr);
				}

				if ((fptr = fopen(ptr, "wb")) == NULL) {
					printf("Error! opening file");

				}
				int i = 0;
				while (i < MAXCHAR && str[i] != '\0') {
					i++;
				}
				fwrite(str, i, 1, fptr);
				fclose(fptr);

			}
		}
	}
	else {
		printf(" You don't have any booking Sorry !");
	}

}

bool addCustomerCheckout() {
	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "checkoutcustomer.txt");


	FILE *fptr;
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);

	int i = 0;
	char fchar = checkinOperator->customer->customerName[0];
	char schar = checkinOperator->customer->customerName[0];
	checkinOperator->customer->customerName[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = checkinOperator->customer->customerName[i];
		checkinOperator->customer->customerName[i] = fchar;

		i++;

		if (schar == '\0') {
			checkinOperator->customer->customerName[i] = '#';
			break;
		}
	}

	i = 0;
	fchar = checkinOperator->customer->customerCheckInDate[0];
	schar = checkinOperator->customer->customerCheckInDate[0];
	checkinOperator->customer->customerCheckInDate[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = checkinOperator->customer->customerCheckInDate[i];
		checkinOperator->customer->customerCheckInDate[i] = fchar;

		i++;

		if (schar == '\0') {
			checkinOperator->customer->customerCheckInDate[i] = '#';
			break;
		}
	}

	i = 0;
	fchar = checkinOperator->customer->customerCheckOutDate[0];
	schar = checkinOperator->customer->customerCheckOutDate[0];
	checkinOperator->customer->customerCheckOutDate[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = checkinOperator->customer->customerCheckOutDate[i];
		checkinOperator->customer->customerCheckOutDate[i] = fchar;

		i++;

		if (schar == '\0') {
			checkinOperator->customer->customerCheckOutDate[i] = '#';
			break;
		}
	}
	char payment[10] = { '\0' };

	snprintf(payment, sizeof payment, "%f", checkinOperator->customer->roomFee);

	i = 0;
	while (str[i] != '\0') {

		i++;
	}


	concateStr(str, checkinOperator->customer->customerName);


	concateStr(str, checkinOperator->customer->customerCheckInDate);

	concateStr(str, checkinOperator->customer->customerCheckOutDate);


	i = 0;
	while (str[i] != '\0') {

		i++;
	}
	str[i] = '$';

	concateStr(str, payment);

	i = 0;
	while (str[i] != '\0') {

		i++;
	}
	str[i] = '#';
	i++;
	str[i] = '$';
	i++;
	str[i] = checkinOperator->customer->roomType;
	i++;
	str[i] = '#';
	i++;
	str[i] = '$';
	i++;
	if (checkinOperator->customer->stayingDays > 9) {
		str[i] = (checkinOperator->customer->stayingDays / 10) + '0';
		i++;
		str[i] = (checkinOperator->customer->stayingDays % 10) + '0';
	}
	else {
		str[i] = checkinOperator->customer->stayingDays + '0';
	}
	i++;
	str[i] = '#';
	i++;
	str[i] = '$';
	i++;

	if (checkinOperator->customer->roomNo > 9) {
		str[i] = (checkinOperator->customer->roomNo / 10) + '0';
		i++;
		str[i] = (checkinOperator->customer->roomNo % 10) + '0';
	}
	else {
		str[i] = checkinOperator->customer->roomNo + '0';
	}


	i++;
	str[i] = '#';
	i++;

	str[i] = '$';
	i++;
	str[i] = 'f';
	i++;
	str[i] = '#';
	i++;
	str[i] = '\n';
	ptr = PrintFullPath(".\\", "checkoutcustomer.txt");

	if ((fptr = fopen(ptr, "wb")) == NULL) {
		printf("Error! opening file");

	}
	i = 0;
	while (i < MAXCHAR && str[i] != '\0') {
		i++;
	}
	fwrite(str, i, 1, fptr);
	fclose(fptr);



}

char * concateStr(char * firststr, char * secondstr) {
	char *a = firststr;
	char *b = secondstr;


	// pointing to the end of the 1st string
	while (*a)   // till it doesn't point to NULL-till string is not empty
	{
		a++;    // point to the next letter of the string
	}
	while (*b)   // till second string is not empty
	{
		*a = *b;
		b++;
		a++;
	}
	*a = '\0';  // string must end with '\0'

	return firststr;
}

bool removeCheckinBooking(char *str, char c) {

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	bool findname = false;
	bool findcheckin = false;
	bool findcheckout = false;
	bool findpayment = false;
	bool findclass = false;
	bool finddays = false;
	bool findroom = false;

	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				if (strcmp(checkinOperator->customer->customerName, ptrdata) == 0) {
					findname = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				if (strcmp(checkinOperator->customer->customerCheckInDate, ptrdata) == 0) {
					findcheckin = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				if (strcmp(checkinOperator->customer->customerCheckOutDate, ptrdata) == 0) {
					findcheckout = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				checkinOperator->customer->roomFee = ftemp;

				if (checkinOperator->customer->roomFee == ftemp) {
					findpayment = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				if (checkinOperator->customer->roomType == roomType) {
					findclass = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				if (checkinOperator->customer->stayingDays == days) {
					finddays = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (roomno == false) {
				roomno = true;
				int rNo = atoi(ptrdata);

				if (checkinOperator->customer->roomNo == rNo) {
					findroom = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

				if (findname && findcheckin && findcheckout && findroom
					&& findclass && findpayment && finddays) {
					str[i + 2] = c;
					return true;
				}
			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];



				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			/*printf("Customer Name: %s\n", checkinOperator->customer->customerName);
			printf("Check In Date: %s\n", checkinOperator->customer->customerCheckInDate);
			printf("Check Out Date: %s\n", checkinOperator->customer->customerCheckOutDate);
			printf("Total Payment: %f\n", checkinOperator->customer->roomFee);
			printf("Room Class: %c\n", roomType);
			printf("Total Staying Days: %d\n", days);
			*/
			found = '\0';
			days = 0;
			roomType = '\0';

			findname = false;
			findcheckin = false;
			findcheckout = false;
			findclass = false;
			finddays = false;
			findpayment = false;
			findroom = false;

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				//				checkinOperator->customer->customerName[k] = '\0';
				k++;
			}


			k = 0;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}
}


bool findCheckinBooking(char *str) {

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	bool findname = false;
	bool findcheckin = false;
	bool findcheckout = false;
	bool findpayment = false;
	bool findclass = false;
	bool finddays = false;
	bool findroom = false;

	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				if (strcmp(checkoutOperator->customer->customerName, ptrdata) == 0) {
					findname = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				if (strcmp(checkoutOperator->customer->customerCheckInDate, ptrdata) == 0) {
					findcheckin = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				if (strcmp(checkoutOperator->customer->customerCheckOutDate, ptrdata) == 0) {
					findcheckout = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				checkinOperator->customer->roomFee = atof(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				if (checkoutOperator->customer->roomType == roomType) {
					findclass = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				if (checkoutOperator->customer->stayingDays == days) {
					finddays = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (roomno == false) {
				roomno = true;
				int rNo = atoi(ptrdata);

				if (checkinOperator->customer->roomNo == rNo) {
					findroom = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;


			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];


				if (found == 't' && findname && findcheckin && findcheckout && findroom
					&& findclass  && finddays) {

					return true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			found = '\0';
			days = 0;
			roomType = '\0';

			findname = false;
			findcheckin = false;
			findcheckout = false;
			findclass = false;
			finddays = false;
			findpayment = false;
			findroom = false;

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}


			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}
}

bool findCheckoutBooking(char *str) {

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	bool findname = false;
	bool findcheckin = false;
	bool findcheckout = false;
	bool findpayment = false;
	bool findclass = false;
	bool finddays = false;
	bool findroom = false;

	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				if (strcmp(checkoutOperator->customer->customerName, ptrdata) == 0) {
					findname = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				if (strcmp(checkoutOperator->customer->customerCheckInDate, ptrdata) == 0) {
					findcheckin = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				if (strcmp(checkoutOperator->customer->customerCheckOutDate, ptrdata) == 0) {
					findcheckout = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				checkoutOperator->customer->roomFee = atof(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				if (checkoutOperator->customer->roomType == roomType) {
					findclass = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				if (checkoutOperator->customer->stayingDays == days) {
					finddays = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (roomno == false) {
				roomno = true;
				int rNo = atoi(ptrdata);

				if (checkoutOperator->customer->roomNo == rNo) {
					findroom = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;


			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];


				if (found == 'f' && findname && findcheckin && findcheckout && findroom
					&& findclass  && finddays) {

					return true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			found = '\0';
			days = 0;
			roomType = '\0';

			findname = false;
			findcheckin = false;
			findcheckout = false;
			findclass = false;
			finddays = false;
			findpayment = false;
			findroom = false;

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}
			k = 0;

			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}
	return false;
}

int getCustomerFeedback() { return 0; }
void changeBookingfee() {


}

int monthinoutDifference(int day1, int mon1, int year1, int day2, int mon2, int year2) {

	if (day2 < day1)
	{
		// borrow days from february
		if (mon2 == 3)
		{
			//  check whether year is a leap year
			if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
			{
				day2 += 29;
			}

			else
			{
				day2 += 28;
			}
		}

		// borrow days from April or June or September or November
		else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12)
		{
			day2 += 30;
		}

		// borrow days from Jan or Mar or May or July or Aug or Oct or Dec
		else
		{
			day2 += 31;
		}

		mon2 = mon2 - 1;
	}

	if (mon2 < mon1)
	{
		mon2 += 12;
		year2 -= 1;
	}

	// int day_diff = day2 - day1;
	int	mon_diff = mon2 - mon1;
	//	year_diff = year2 - year1;

	//	printf("Difference: %d years %02d months and %02d days.", year_diff, mon_diff, day_diff);

	return mon_diff; // return 0 to operating system
}

void confirmoutBooking() {
	char customername[50] = { '\0' };
	printf("Enter Customer Name: ");

	fgets(customername, sizeof(customername), stdin);
	int index = 0;
	while (customername[index] != '\0')
	{
		if (customername[index] == '\n') {
			customername[index] = '\0';
			break;
		}
		index++;
	}

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "checkoutcustomer.txt");



	FILE *fptr;
	char str[MAXCHAR];
	char checkoutstr[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		checkoutstr[j] = '\0';
		j++;
	}

	readFile(ptr, checkoutstr);

	ptr = PrintFullPath(".\\", "checkincustomer.txt");

	readFile(ptr, str);

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	int day = 0;
	int mon = 0;
	int year = 0;




	bool checkinexists = findBookingCustomer(customername, str);

	ptr = PrintFullPath(".\\", "checkoutcustomer.txt");

	readFile(ptr, str);

	bool checkoutexists = findCheckoutBooking(checkoutstr);

	if (checkoutexists) {

		day = (checkoutOperator->customer->customerCheckOutDate[3] - '0') * 10;
		day = day + (checkoutOperator->customer->customerCheckOutDate[4] - '0');

		mon = (checkoutOperator->customer->customerCheckOutDate[0] - '0') * 10;
		mon = mon + (checkoutOperator->customer->customerCheckOutDate[1] - '0');

		year = (checkoutOperator->customer->customerCheckOutDate[6] - '0') * 10 +
			(checkoutOperator->customer->customerCheckOutDate[7] - '0');

		year = year == 20 ? 2020 : year;


		int todayoutdiff = 0;
		// datesinoutDifference(day, mon, year, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

		int monthdiff = 0;// monthinoutDifference(day, mon, year, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);


		if (mon < tm.tm_mon + 1) {
			if (day < tm.tm_mday) {
				todayoutdiff = datesinoutDifference(day, mon, year, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			}
			else if (day >= tm.tm_mday) {
				todayoutdiff = datesDifference(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, day, mon, year);
			}

			if (mon < tm.tm_mon + 1) {
				monthdiff = monthinoutDifference(day, mon, year, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			}
			else if (mon >= (tm.tm_mon + 1)) {
				monthdiff = monthinoutDifference(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, day, mon, year);
			}
		}
		else if (mon >= (tm.tm_mon + 1)) {
			if (mon < tm.tm_mon + 1) {
				monthdiff = monthinoutDifference(day, mon, year, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			}
			else if (mon >= (tm.tm_mon + 1)) {
				monthdiff = monthinoutDifference(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, day, mon, year);
			}

			if (day < tm.tm_mday) {
				todayoutdiff = datesinoutDifference(day, mon, year, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
			}
			else if (day >= tm.tm_mday) {
				todayoutdiff = datesDifference(tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, day, mon, year);
			}
		}

		if (todayoutdiff == 0 && monthdiff == 0) {

			printf("\n Your Total Bill \n ");
			printf(" Amount Paid at Check In %f\n", checkoutOperator->customer->roomFee);
			printf(" Amount have to pay at Check Out %f\n", checkoutOperator->customer->roomFee);

			printf("\n Your Pending Amount %f\n", checkoutOperator->customer->roomFee);

			printf(" Thank You For Staying with us \n");
			printf("\n Kindly write your Experience with us here! \n");

			removeCheckoutBooking(str, 't');

			ptr = PrintFullPath(".\\", "checkoutcustomer.txt");

			if ((fptr = fopen(ptr, "wb")) == NULL) {
				printf("Error! opening file");

			}
			int i = 0;
			while (i < MAXCHAR && str[i] != '\0') {
				i++;
			}

			fwrite(str, i, 1, fptr);
			fclose(fptr);

			writecustomerExperience();

			writeBookingdata();
			return;
		}
		else {
			float price = 0.0;
			if (monthdiff == 0) {
				if (todayoutdiff > 0) {
					if (day < tm.tm_mday) {
						printf("\n\n");
						printf(" You are late than your check out date \n\n");
						printf(" Your check out date was %s and today is %d/%d/%d\n\n", checkoutOperator->customer->customerCheckOutDate, (tm.tm_mon + 1), tm.tm_mday, tm.tm_year);
						printf("\n");
						printf(" You have to pay the extra staying days \n");
						printf("\n\n");
						///////////////////////////////////////
						float roomamount = checkoutOperator->customer->roomType == 'A' ? checkoutOperator->hotel->rooms->roomaPrice
							: checkoutOperator->customer->roomType == 'B' ? checkoutOperator->hotel->rooms->roombPrice
							: checkoutOperator->customer->roomType == 'C' ? checkoutOperator->hotel->rooms->roomcPrice
							: 0.0;

						roomamount = roomamount * todayoutdiff;
						price = price + (checkoutOperator->customer->roomFee) + roomamount;

						printf("Your remaining Amount to be paid %f\n", price);
						printf("\n\n");

						printf(" How was your stay at hotel \n");
						printf(" Press - 1 for good \n");
						printf(" Press - 2 for bad \n");
						int feedback = 0;
						scanf("%d", &feedback);
						getchar();
						if (feedback == 1) {
							printf(" Happy to know you like stayingwith us \n\n");
							//	checkoutOperator->customer->roomFee = price;

							printf("Your remaining Amount to be paid %f\n", price);

							printf("\n\n");
						}
						else if (feedback == 2) {
							printf("\n\n");
							if (price > 0) {
								if ((price * 0.50) > 0) {
									printf(" Sorry for bad experience, How about i will cut your 50% of remaining amount \n");
									price = price - (price*0.50);
									//	checkoutOperator->customer->roomFee = price;

									printf("Your remaining Amount to be paid %f\n", price);

									printf("\n\n");

								}
								else
								{
									printf(" Sorry for bad experience, How about i will cut your remaining amount \n");
									price = 0;
									//	checkoutOperator->customer->roomFee = price;
									printf("Your remaining Amount to be paid %f\n", price);
									printf("\n\n");

								}
							}

						}
						///////////////////////////////////////
					}
					else if (day > tm.tm_mday) {

						printf("\n\n");
						printf(" You are leaving hotel earlier than your check out date \n\n");
						printf(" Your check out date was %s and today is %d/%d/%d\n\n", checkoutOperator->customer->customerCheckOutDate, (tm.tm_mon + 1), tm.tm_mday, tm.tm_year);
						printf("\n\n");

						float roomamount = checkoutOperator->customer->roomType == 'A' ? checkoutOperator->hotel->rooms->roomaPrice
							: checkoutOperator->customer->roomType == 'B' ? checkoutOperator->hotel->rooms->roombPrice
							: checkoutOperator->customer->roomType == 'C' ? checkoutOperator->hotel->rooms->roomcPrice
							: 0.0;

						roomamount = roomamount * todayoutdiff;
						price = price + (checkoutOperator->customer->roomFee) - roomamount;

						printf("Your remaining Amount to be paid %f\n", price);
						printf("\n\n");

						printf(" How was your stay at hotel \n");
						printf(" Press - 1 for good \n");
						printf(" Press - 2 for bad \n");
						int feedback = 0;
						scanf("%d", &feedback);
						getchar();
						if (feedback == 1) {
							printf(" Happy to know you like staying with us \n\n");
							//	checkoutOperator->customer->roomFee = price;
							if (price < 0) {
								printf(" here's your remaining amount %f \n", (-1 * price));
							}
							else {
								printf("Your remaining Amount to be paid %f\n", price);
							}
							printf("\n\n");
						}
						else if (feedback == 2) {
							printf("\n\n");
							if (price > 0) {
								if ((price * 0.50) > 0) {
									printf(" Sorry for bad experience, How about i will cut your 50 percent remaining amount \n");
									price = price - (price*0.50);
									//		checkoutOperator->customer->roomFee = price;

									printf("Your remaining Amount to be paid %f\n", price);

									printf("\n\n");

								}
								else
								{
									printf(" Sorry for bad experience, How about i will cut your remaining amount \n");
									price = 0;
									//		checkoutOperator->customer->roomFee = price;
									printf("Your remaining Amount to be paid %f\n", price);
									printf("\n\n");

								}
							}
							else {
								printf(" sorry for the bad experience, Applogies \n\n");
								printf(" I am cutting off the 50 percent that you paid on Check In \n\n");
								printf(" Here's Your Amount:  %f \n\n", checkoutOperator->customer->roomFee);
							}

						}
					}
				}
			}
			else if (todayoutdiff == 0) {
				if (monthdiff > 0) {
					if (mon > (tm.tm_mon + 1)) {
						printf("\n\n");
						printf(" You are late than your check out date \n\n");
						printf(" Your check out date was %s and today is %d/%d/%d\n\n", checkoutOperator->customer->customerCheckOutDate, tm.tm_mon, tm.tm_mday, tm.tm_year);
						printf("\n");
						printf(" You have to pay the extra staying days \n");
						printf("\n\n");
						///////////////////////////////////////
						float roomamount = checkoutOperator->customer->roomType == 'A' ? checkoutOperator->hotel->rooms->roomaPrice
							: checkoutOperator->customer->roomType == 'B' ? checkoutOperator->hotel->rooms->roombPrice
							: checkoutOperator->customer->roomType == 'C' ? checkoutOperator->hotel->rooms->roomcPrice
							: 0.0;

						roomamount = roomamount * (monthdiff * 29);
						price = price + (checkoutOperator->customer->roomFee * 2) - (monthdiff * 29);

						printf("Your remaining Amount to be paid %f\n", price);
						printf("\n\n");

						printf(" How was your stay at hotel \n");
						printf(" Press - 1 for good \n");
						printf(" Press - 2 for bad \n");
						int feedback = 0;
						scanf("%d", &feedback);
						getchar();
						if (feedback == 1) {
							printf(" Happy to know you like stayingwith us \n\n");
							//	checkoutOperator->customer->roomFee = price;

							printf("Your remaining Amount to be paid %f\n", price);

							printf("\n\n");
						}
						else if (feedback == 2) {
							printf("\n\n");
							if (price > 0) {
								if ((price * 0.50) > 0) {
									printf(" Sorry for bad experience, How about i will cut your 50 percent of remaining amount \n");
									price = price - (price*0.50);
									//		checkoutOperator->customer->roomFee = price;

									printf("Your remaining Amount to be paid %f\n", price);

									printf("\n\n");

								}
								else
								{
									printf(" Sorry for bad experience, How about i will cut your remaining amount \n");
									price = 0;
									//	checkoutOperator->customer->roomFee = price;
									printf("Your remaining Amount to be paid %f\n", price);
									printf("\n\n");

								}
							}

						}
						///////////////////////////////////////
					}
					else if (mon < (tm.tm_mon + 1)) {

						printf("\n\n");
						printf(" You are leaving hotel earlier than your check out date \n\n");
						printf(" Your check out date was %s and today is %d/%d/%d\n\n", checkoutOperator->customer->customerCheckOutDate, tm.tm_mon, tm.tm_mday, tm.tm_year);
						printf("\n\n");

						float roomamount = checkoutOperator->customer->roomType == 'A' ? checkoutOperator->hotel->rooms->roomaPrice
							: checkoutOperator->customer->roomType == 'B' ? checkoutOperator->hotel->rooms->roombPrice
							: checkoutOperator->customer->roomType == 'C' ? checkoutOperator->hotel->rooms->roomcPrice
							: 0.0;

						roomamount = roomamount * (monthdiff * 29);
						price = price + (checkoutOperator->customer->roomFee) - roomamount;

						printf("Your remaining Amount to be paid %f\n", price);
						printf("\n\n");

						printf(" How was your stay at hotel \n");
						printf(" Press - 1 for good \n");
						printf(" Press - 2 for bad \n");
						int feedback = 0;
						scanf("%d", &feedback);
						getchar();
						if (feedback == 1) {
							printf(" Happy to know you like stayingwith us \n\n");
							//	checkoutOperator->customer->roomFee = price;

							printf("Your remaining Amount to be paid %f\n", price);

							printf("\n\n");
						}
						else if (feedback == 2) {
							printf("\n\n");
							if (price > 0) {
								if ((price * 0.50) > 0) {
									printf(" Sorry for bad experience, How about i will cut your 50 percent remaining amount \n");
									price = price - (price*0.50);
									//		checkoutOperator->customer->roomFee = price;

									printf("Your remaining Amount to be paid %f\n", price);

									printf("\n\n");

								}
								else
								{
									printf(" Sorry for bad experience, How about i will cut your remaining amount \n");
									price = 0;
									//		checkoutOperator->customer->roomFee = price;
									printf("Your remaining Amount to be paid %f\n", price);
									printf("\n\n");

								}
							}

						}
					}
				}
			}
			else if (monthdiff > 0 && todayoutdiff > 0) {
				if (mon > (tm.tm_mon + 1)) {
					printf(" You have stayed more than check out date \n\n");
					printf(" Your checkout date was %s and today is %d/%d/%d \n\n", checkoutOperator->customer->customerCheckOutDate, tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
					printf(" You have to pay extra staying days price \n\n");

					float roomamount = checkoutOperator->customer->roomType == 'A' ? checkoutOperator->hotel->rooms->roomaPrice
						: checkoutOperator->customer->roomType == 'B' ? checkoutOperator->hotel->rooms->roombPrice
						: checkoutOperator->customer->roomType == 'C' ? checkoutOperator->hotel->rooms->roomcPrice : 0.0;

					int totaldays = tm.tm_mday + ((tm.tm_mon + 1) * 29);
					float amountpaid = totaldays * roomamount;

					price = price + (checkoutOperator->customer->roomFee) + amountpaid;
					printf("\n You paying amount is %f \n\n", price);



				}
				else if (mon < (tm.tm_mon + 1)) {
					printf(" You have stayed more than check out date \n\n");
					printf(" Your checkout date was %s and today is %d/%d/%d \n\n", checkoutOperator->customer->customerCheckOutDate, tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
					printf(" You have to pay extra staying days price \n\n");

					float roomamount = checkoutOperator->customer->roomType == 'A' ? checkoutOperator->hotel->rooms->roomaPrice
						: checkoutOperator->customer->roomType == 'B' ? checkoutOperator->hotel->rooms->roombPrice
						: checkoutOperator->customer->roomType == 'C' ? checkoutOperator->hotel->rooms->roomcPrice : 0.0;

					int totaldays = tm.tm_mday + ((tm.tm_mon + 1) * 29);
					float amountpaid = totaldays * roomamount;

					price = price + (checkoutOperator->customer->roomFee) - amountpaid;
					printf("\n Your paying amount is %f \n\n", price);

				}

				int feedback = 0;
				printf(" How was you stay ? \n");
				printf(" Press 1 for good  \n");
				printf(" Press 2 for bad  \n");

				scanf("%d", &feedback);
				getchar();
				if (feedback == 1) {
					printf(" \n\n Thank You for staying with us \n\n");
					//	checkoutOperator->customer->roomFee = price;
				}
				else if (feedback == 2) {
					price = price - (price * 0.50);
					if ((price - (price * 0.50)) < 0) {
						printf(" \n\n Sorry For bad experience, How about i will cut of 100 percent of your paying amount  \n\n");

					}
					else {
						printf(" \n\n Sorry For bad experience, How about i will cut of 50 percent of your paying amount  \n\n");

					}
					//			printf("\n You paying amount after 50% cut off %f \n\n", price);
							//	checkoutOperator->customer->roomFee = price;
				}
			}

			/*
					if (monthdiff == 0) {
						if (day > tm.tm_mday && todayoutdiff > 0) {
							printf(" You have stayed less than check out date %s \n", checkoutOperator->customer->customerCheckOutDate);
							printf(" Your Totol Staying Days  %d \n", checkoutOperator->customer->stayingDays);

							printf(" You to pay %f per day more than check out date  \n",
								checkoutOperator->customer->roomType == 'A' ?
								checkoutOperator->hotel->rooms->roomaPrice :
								checkoutOperator->customer->roomType == 'B' ?
								checkoutOperator->hotel->rooms->roombPrice :
								checkoutOperator->hotel->rooms->roomcPrice);
							float roomprice = checkoutOperator->customer->roomType == 'A' ?
								checkoutOperator->hotel->rooms->roomaPrice :
								checkoutOperator->customer->roomType == 'B' ?
								checkoutOperator->hotel->rooms->roombPrice :
								checkoutOperator->hotel->rooms->roomcPrice;
							printf(" Your Total Payment %f \n", (checkoutOperator->customer->roomFee - (roomprice * (day - tm.tm_mday))));
							checkinOperator->customer->roomFee = (checkoutOperator->customer->roomFee - (roomprice * (day - tm.tm_mday)));

						}
					}
					else if (monthdiff == 1) {
						 todayoutdiff = (tm.tm_mday + 30) - day;

						printf(" You have stayed more than check out date %s \n", checkoutOperator->customer->customerCheckOutDate);
						printf(" Your Totols Staying Days  %d \n", (todayoutdiff ));

						printf(" You to pay %f per day more than check out date  \n",
							checkoutOperator->customer->roomType == 'A' ?
							checkoutOperator->hotel->rooms->roomaPrice :
							checkoutOperator->customer->roomType == 'B' ?
							checkoutOperator->hotel->rooms->roombPrice :
							checkoutOperator->hotel->rooms->roomcPrice);
					}
					else if (monthdiff > 1){
						todayoutdiff = ((tm.tm_mday + 30) - day) * monthdiff;

						printf(" You have stayed more than check out date %s \n", checkoutOperator->customer->customerCheckOutDate);
						printf(" Your Totols Staying Days  %d \n", (todayoutdiff) );

						printf(" You to pay %f per day more than check out date  \n",
							checkoutOperator->customer->roomType == 'A' ?
							checkoutOperator->hotel->rooms->roomaPrice :
							checkoutOperator->customer->roomType == 'B' ?
							checkoutOperator->hotel->rooms->roombPrice :
							checkoutOperator->hotel->rooms->roomcPrice);
					}
		*/

		//	price = todayoutdiff * price;

			printf("\n Your Total Bill \n ");
			printf(" Amount Paid at Check In %f\n", checkoutOperator->customer->roomFee);
			checkoutOperator->customer->roomFee = price;

			printf(" Amount have to pay at Check Out %f\n", checkoutOperator->customer->roomFee);


			printf("\n");
			printf("\n");

			printf(" Thank You For Staying with us \n");
			printf("\n Kindly write your Experience with us here! \n");

			char roomData[MAXCHAR] = { '\0' };

			if (checkoutOperator->customer->roomType == 'A')
				ptr = PrintFullPath(".\\", "roomadata.txt");
			else if (checkoutOperator->customer->roomType == 'B')
				ptr = PrintFullPath(".\\", "roombdata.txt");
			else if (checkoutOperator->customer->roomType == 'C')
				ptr = PrintFullPath(".\\", "roomcdata.txt");

			readFile(ptr, roomData);

			int rNo = checkinOperator->customer->roomNo;
			char rc = 'f';
			bool changeRoom = changeRoomNo(roomData, rNo, rc);

			if ((fptr = fopen(ptr, "wb")) == NULL) {
				printf("Error! opening file");

			}
			int i = 0;
			while (roomData[i] != '\0') {
				i++;
			}
			fwrite(roomData, i, 1, fptr);

			fclose(fptr);

			removeCheckoutBooking(str, 't');

			ptr = PrintFullPath(".\\", "checkoutcustomer.txt");

			if ((fptr = fopen(ptr, "wb")) == NULL) {
				printf("Error! opening file");

			}
			i = 0;
			while (i < MAXCHAR && str[i] != '\0') {
				i++;
			}

			fwrite(str, i, 1, fptr);
			fclose(fptr);
			writecustomerExperience();


			writeBookingdata();
		}
	}
	else {
		printf(" \n Customer  %s Not Found \n", customername);
	}
}


bool writeBookingdata() {

	FILE *fptr;

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "bookingdata.txt");

	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");

	}
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);


	if ((fptr = fopen(ptr, "wb")) == NULL) {
		printf("Error! opening file");

	}

	int i = 0;

	char fchar = checkoutOperator->customer->customerName[0];
	char schar = checkoutOperator->customer->customerName[0];
	/*checkoutOperator->customer->customerName[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = checkoutOperator->customer->customerName[i];
		checkoutOperator->customer->customerName[i] = fchar;

		i++;

		if (schar == '\0') {
			checkoutOperator->customer->customerName[i] = '#';
			break;
		}
	}
	*/
	concate(str, checkoutOperator->customer->customerName);

	i = 0;

	fchar = checkoutOperator->customer->customerCheckInDate[0];
	schar = checkoutOperator->customer->customerCheckInDate[0];
	checkoutOperator->customer->customerCheckInDate[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = checkoutOperator->customer->customerCheckInDate[i];
		checkoutOperator->customer->customerCheckInDate[i] = fchar;

		i++;

		if (schar == '\0') {
			checkoutOperator->customer->customerCheckInDate[i] = '#';
			break;
		}
	}

	concate(str, checkoutOperator->customer->customerCheckInDate);


	i = 0;

	fchar = checkoutOperator->customer->customerCheckOutDate[0];
	schar = checkoutOperator->customer->customerCheckOutDate[0];
	checkoutOperator->customer->customerCheckOutDate[0] = '$';
	i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = checkoutOperator->customer->customerCheckOutDate[i];
		checkoutOperator->customer->customerCheckOutDate[i] = fchar;

		i++;

		if (schar == '\0') {
			checkoutOperator->customer->customerCheckOutDate[i] = '#';
			break;
		}
	}

	concate(str, checkoutOperator->customer->customerCheckOutDate);


	i = 0;
	while (i < MAXCHAR && str[i] != '\0') {
		i++;
	}

	str[i] = '#';
	i++;
	str[i] = '$';
	i++;
	char payRoom[12] = { '\0' };
	snprintf(payRoom, sizeof payRoom, "%f", checkoutOperator->customer->roomFee);
	int index = 0;
	while (payRoom[index] != '\0') {
		str[i] = payRoom[index];

		index++;
		i++;
	}

	str[i] = '#';
	i++;
	str[i] = '$';
	i++;
	str[i] = checkoutOperator->customer->roomType;
	i++;
	str[i] = '#';
	i++;
	str[i] = '$';
	i++;
	if (checkoutOperator->customer->roomNo > 9) {
		str[i] = (checkoutOperator->customer->roomNo + '0') * 10;
		i++;
		str[i] = (checkoutOperator->customer->roomNo + '0') / 10;
	}
	else {
		str[i] = (checkoutOperator->customer->roomNo + '0');
	}
	i++;
	str[i] = '#';


	i++;
	str[i] = '$';
	i++;
	if (checkoutOperator->customer->stayingDays > 9) {
		str[i] = (checkoutOperator->customer->stayingDays + '0') * 10;
		i++;
		str[i] = (checkoutOperator->customer->stayingDays + '0') / 10;
	}
	else {
		printf("%d\n", checkoutOperator->customer->stayingDays);
		str[i] = (checkoutOperator->customer->stayingDays + '0');
	}

	i++;
	str[i] = '#';
	i++;
	str[i] = '\n';

	while (i < MAXCHAR && str[i] != '\0') {
		i++;
	}

	fwrite(str, i, 1, fptr);
	fclose(fptr);
}

void printExperience() {
	FILE *fptr;

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "customerexdata.txt");



	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}
	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");

	}

	readFile(ptr, str);


	int i = 0;

	bool experience = false;
	bool customername = false;


	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (customername == false) {
				customername = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkoutOperator->customer->customerName[k] = '\0';
					checkoutOperator->customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (experience == false) {
				experience = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkoutOperator->customer->experience[k] = '\0';
					checkoutOperator->customer->experience[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}


		if (str[i] == '\n') {
			printf("\n");
			printf("Customer Name:   %s\n", checkoutOperator->customer->customerName);
			printf("Customer Feedback:   %s\n", checkoutOperator->customer->experience);
			printf("\n");



			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;

			experience = false;
			customername = false;
		}


		i++;
	}

	fclose(fptr);
}
bool writecustomerExperience() {

	FILE *fptr;

	char  *ptr = malloc(_MAX_PATH);
	// Get current directory
	ptr = PrintFullPath(".\\", "customerexdata.txt");

	printf("Enter Your Experince : ");

	int i = 0;
	while (i < 256)
	{
		checkoutOperator->customer->experience[i] = '\0';
		i++;
	}
	fgets(checkoutOperator->customer->experience, sizeof(checkoutOperator->customer->experience), stdin);

	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");

	}
	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readFile(ptr, str);


	i = 0;

	char fchar = checkoutOperator->customer->customerName[0];
	char schar = checkoutOperator->customer->customerName[0];
	checkoutOperator->customer->customerName[0] = '$';
	i = 1;
	while (i < 50)
	{
		fchar = schar;
		schar = checkoutOperator->customer->customerName[i];
		checkoutOperator->customer->customerName[i] = fchar;

		i++;

		if (schar == '\0') {
			checkoutOperator->customer->customerName[i] = '#';
			break;
		}
	}


	i = 0;

	while (i < 256)
	{
		if (checkoutOperator->customer->experience[i] == '\n')
		{
			checkoutOperator->customer->experience[i] = '\0';
		}
		i++;
	}



	fchar = checkoutOperator->customer->experience[0];
	schar = checkoutOperator->customer->experience[0];
	checkoutOperator->customer->experience[0] = '$';

	i = 1;
	while (i < 256)
	{

		fchar = schar;
		schar = checkoutOperator->customer->experience[i];
		checkoutOperator->customer->experience[i] = fchar;

		i++;

		if (schar == '\0') {
			checkoutOperator->customer->experience[i] = '#';
			break;
		}
	}

	concate(str, checkoutOperator->customer->customerName);

	concate(str, checkoutOperator->customer->experience);


	while (i < MAXCHAR && str[i] != '\0') {
		i++;
	}
	str[i] = '\n';
	fwrite(str, i, 1, fptr);

	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");

	}
	fclose(fptr);
}
int datesinoutDifference(int day1, int mon1, int year1, int day2, int mon2, int year2) {
	if (day2 < day1)
	{
		// borrow days from february
		if (mon2 == 3)
		{
			//  check whether year is a leap year
			if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))
			{
				day2 += 29;
			}

			else
			{
				day2 += 28;
			}
		}

		// borrow days from April or June or September or November
		else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12)
		{
			day2 += 30;
		}

		// borrow days from Jan or Mar or May or July or Aug or Oct or Dec
		else
		{
			day2 += 31;
		}

		mon2 = mon2 - 1;
	}

	if (mon2 < mon1)
	{
		mon2 += 12;
		year2 -= 1;
	}

	int day_diff = day2 - day1;
	//	mon_diff = mon2 - mon1;
	//	year_diff = year2 - year1;

	//	printf("Difference: %d years %02d months and %02d days.", year_diff, mon_diff, day_diff);

	return day_diff; // return 0 to operating system
}
bool findBookingoutCustomer(char * customername, char * str) {
	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkoutOperator->customer->customerName[k] = '\0';
					checkoutOperator->customer->customerName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkoutOperator->customer->customerCheckInDate[k] = '\0';
					checkoutOperator->customer->customerCheckInDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				k = 0;
				while (ptrdata[k] != '\0') {
					checkoutOperator->customer->customerCheckOutDate[k] = '\0';
					checkoutOperator->customer->customerCheckOutDate[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);
				checkoutOperator->customer->roomFee = ftemp;

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				checkoutOperator->customer->roomType = roomType;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				checkoutOperator->customer->stayingDays = days;
				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (roomno == false) {
				roomno = true;
				checkoutOperator->customer->roomNo = atoi(ptrdata);

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {
			if (found == 'f' && strcmp(checkoutOperator->customer->customerName, customername) == 0) {
				printf("Customer Name: %s\n", checkoutOperator->customer->customerName);
				printf("Check In Date: %s\n", checkoutOperator->customer->customerCheckInDate);
				printf("Check Out Date: %s\n", checkoutOperator->customer->customerCheckOutDate);
				printf("Total Payment: %f\n", checkoutOperator->customer->roomFee);
				printf("Room Class: %c\n", roomType);
				printf("Total Staying Days: %d\n", days);
				printf("Room Class: %c\n", roomType);

				return true;
			}
			else {
				found = '\0';
				days = 0;
				roomType = '\0';

			}
			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;

			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}
	if (found == '\0') {
		return false;
	}
}

bool changeRoomNo(char * str, int customerRno, char c) {


	int i = 0;

	bool rNo = false;
	bool status = false;

	int roomNo = 0;

	char ptrdata[50];
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (rNo == false) {
				rNo = true;

				roomNo = atoi(ptrdata);

				if (customerRno == roomNo) {
					str[i + 2] = c;
					return true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					//	CustName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			if (status == false) {
				status = true;


				k = 0;
				while (ptrdata[k] != '\0') {
					//	CustName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}

		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;
			roomNo = 0;
			status = false;
			rNo = false;
		}

	}
	return false;
}



bool removeCheckoutBooking(char *str, char c) {

	int i = 0;

	bool name = false;
	bool indate = false;
	bool outdate = false;
	bool price = false;
	bool Roomclass = false;
	bool stayingdays = false;
	bool roomno = false;
	bool exists = false;

	bool findname = false;
	bool findcheckin = false;
	bool findcheckout = false;
	bool findpayment = false;
	bool findclass = false;
	bool finddays = false;
	bool findroom = false;

	char found = '\0';
	int days = 0;
	char ptrdata[50];
	char roomType = '\0';
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (name == false) {
				name = true;

				if (strcmp(checkoutOperator->customer->customerName, ptrdata) == 0) {
					findname = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (indate == false) {
				indate = true;

				if (strcmp(checkoutOperator->customer->customerCheckInDate, ptrdata) == 0) {
					findcheckin = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (outdate == false) {
				outdate = true;

				if (strcmp(checkoutOperator->customer->customerCheckOutDate, ptrdata) == 0) {
					findcheckout = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}
			else if (price == false) {
				price = true;

				float ftemp = atof(ptrdata);

				if (checkoutOperator->customer->roomFee == ftemp) {
					findpayment = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;
			}

			else if (Roomclass == false) {
				Roomclass = true;

				roomType = ptrdata[0] == 'A' ? 'A' : ptrdata[0] == 'B' ? 'B' :
					ptrdata[0] == 'C' ? 'C' : '\0';

				if (checkoutOperator->customer->roomType == roomType) {
					findclass = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (stayingdays == false) {
				stayingdays = true;
				int days = atoi(ptrdata);

				if (checkinOperator->customer->stayingDays == days) {
					finddays = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
			else if (roomno == false) {
				roomno = true;
				int rNo = atoi(ptrdata);

				if (checkoutOperator->customer->roomNo == rNo) {
					findroom = true;
				}

				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

				if (findname && findcheckin && findcheckout && findroom
					&& findclass && finddays) {
					str[i + 2] = c;
					return true;
				}
			}
			else if (exists == false) {
				exists = true;
				found = ptrdata[0];



				k = 0;
				while (ptrdata[k] != '\0') {
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			/*printf("Customer Name: %s\n", checkinOperator->customer->customerName);
			printf("Check In Date: %s\n", checkinOperator->customer->customerCheckInDate);
			printf("Check Out Date: %s\n", checkinOperator->customer->customerCheckOutDate);
			printf("Total Payment: %f\n", checkinOperator->customer->roomFee);
			printf("Room Class: %c\n", roomType);
			printf("Total Staying Days: %d\n", days);
			*/
			found = '\0';
			days = 0;
			roomType = '\0';

			findname = false;
			findcheckin = false;
			findcheckout = false;
			findclass = false;
			finddays = false;
			findpayment = false;
			findroom = false;

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				//				checkinOperator->customer->customerName[k] = '\0';
				k++;
			}


			k = 0;
			name = false;
			indate = false;
			outdate = false;
			price = false;
			Roomclass = false;
			stayingdays = false;
			roomno = false;
			exists = false;
		}

	}
}


static struct Owner * owner;
void showFeedbacks() {}
void showProfitRooms() {}
void showProfits() {}

void setOwner() {
	owner = (struct Owner*) malloc(sizeof(struct Owner));

	owner->hotel = (struct Hotel*) malloc(sizeof(struct Hotel));

	int k = 0;
	while (k < 50) {
		owner->ownerName[k] = '0';
		owner->ownerPassword[k] = '0';
		k++;
	}

}
bool updateHotelname() {
	printf("Enter Hotel Name: ");

	fgets(owner->hotel->hotelName, sizeof(owner->hotel->hotelName), stdin);
	int index = 0;
	while (owner->hotel->hotelName[index] != '\0')
	{
		if (owner->hotel->hotelName[index] == '\n') {
			owner->hotel->hotelName[index] = '\0';
			break;
		}
		index++;
	}

	char fchar = owner->hotel->hotelName[0];
	char schar = owner->hotel->hotelName[0];
	owner->hotel->hotelName[0] = '$';
	int i = 1;
	while (i < 50)
	{

		fchar = schar;
		schar = owner->hotel->hotelName[i];
		owner->hotel->hotelName[i] = fchar;

		i++;

		if (schar == '\0') {
			owner->hotel->hotelName[i] = '#';
			break;
		}
	}
	i++;
	owner->hotel->hotelName[i] = '\n';

	char  *ptr = malloc(_MAX_PATH);
	ptr = PrintFullPath(".\\", "hotelnamedata.txt");

	FILE *fptr;


	if ((fptr = fopen(ptr, "wb")) == NULL) {
		printf("Error! opening file");

	}

	fwrite(owner->hotel->hotelName, i + 1, 1, fptr);
	fclose(fptr);
}

struct  Owner * getOwner() {
	return owner;
}

void readHotelName(char *fileptr) {

	char  *ptr = malloc(_MAX_PATH);
	ptr = PrintFullPath(".\\", "hotelnamedata.txt");

	char str[MAXCHAR];

	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	FILE *fptr;
	j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		fileptr[j] = '\0';
		j++;
	}

	if ((fptr = fopen(ptr, "r")) == NULL) {
		printf("Error! opening file");
	}



	while (fgets(str, MAXCHAR, fptr) != NULL) {
		//	printf("%s\n", str);
		concate(fileptr, str);
	}

	//	printf("%s\n", fileptr);
	fclose(fptr);


}


bool getHotelName() {
	int i = 0;

	bool hotelname = false;

	char str[MAXCHAR];
	int j = 0;
	while (j < MAXCHAR) {
		str[j] = '\0';
		j++;
	}

	readHotelName(str);


	char ptrdata[50];
	int k = 0;
	while (k < 50) {
		ptrdata[k] = '\0';
		k++;
	}

	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#') {
			if (hotelname == false) {
				hotelname = true;

				k = 0;
				while (owner->hotel->hotelName[k] != '\0') {
					owner->hotel->hotelName[k] = '\0';
					k++;
				}
				k = 0;
				while (ptrdata[k] != '\0') {
					owner->hotel->hotelName[k] = '\0';
					owner->hotel->hotelName[k] = ptrdata[k];
					ptrdata[k] = '\0';
					k++;
				}

				k = 0;

			}
		}
		if (str[i] != '#' && str[i] != '$' && str[i] != '\n') {

			ptrdata[k] = str[i];

			k++;

		}
		i++;

		if (str[i] == '\n') {

			k = 0;
			while (k < 50) {
				ptrdata[k] = '\0';
				k++;
			}

			k = 0;

			hotelname = false;

			//			printf("Hotel Name: %s \n",&owner->hotel->hotelName);

			break;
		}
	}

	return true;
}


static struct Rooms * rooms;

void setRoom(struct Rooms * myrooms) {
	rooms = myrooms;
}
void setroomaPrice(float price) {
	rooms->roomaPrice = price;
}
void setroombPrice(float price) {
	rooms->roombPrice = price;
}

void setroomcPrice(float price) {
	rooms->roomcPrice = price;
}

float getroomaPrice() {
	return rooms->roomaPrice;
}
float getroombPrice() {
	return rooms->roombPrice;
}
float getroomcPrice() {
	return rooms->roomcPrice;
}

