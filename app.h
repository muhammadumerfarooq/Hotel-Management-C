
#ifndef APP_H
#define APP_H

#include <stdbool.h>

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

void setCustomername();
void setCustomerCheckInDate();
void setCustomerCheckOutDatee();
bool setRoomfee();
void setTotalbookrooms();

char * getCustomername();
char * getCustomerCheckInDate();
char getCustomerCheckOutDatee();
float getRoomfee();
int getTotalbookrooms();
char *  PrintFullPath(char * partialPath, char * filename);
char * concate(char * firststr, char * secondstr);

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

void showTotalRoomABooked();
void showTotalRoomBBooked();
void showTotalRoomCBooked();
void showProfitRoomA();
void showProfitRoomB();
void showProfitRoomC();

void setOwner();
// hotels functions
struct  Hotel * setHotel();
void setHotelName(char name[50]);
bool getHotelName();
void searchRoomsA();
void searchRoomsB();
void searchRoomsC();
bool checkRoomAvaialabilty();
struct  Owner * getOwner();
bool updateHotelname();
void showFeedbacks();
void showProfitRooms();
void showProfits();
void readHotelName(char *fileptr);
int countRoomA();
int countRoomB();
int countRoomC();
char *  PrintFullPath(char * partialPath, char * filename);
char * concate(char * firststr, char * secondstr);
void getCustomerDetails();
float getTotalProfit();
struct Customer * getCustomer();
bool findCustomer(char * str);
struct  Bookingoperator * getBookingOperator();
void setBookingHotel(struct Hotel * hotel);
void resetBooking();
void resetCustomer();
void getBookingDetails();
char * concate(char * firststr, char * secondstr);
int valid_date(int day, int mon, int year);
int datesDifference(int day1, int mon1, int year1, int day2, int mon2, int year2);

void searchBooking(char name[50], char date[50]);
void searchBookingByName(char name[50]);
void searchBookingByDate(char date[50]);
bool registerCustomer();
bool bookRoom();
void readFile(char *ptr, char *fileptr);
void printData(char * data);
bool findCheckInCustomer(char * customername, char * str);
char *  PrintManagerPath(char * partialPath, char * filename);

int monthDifference(int day1, int mon1, int year1, int day2, int mon2, int year2);



struct Manager {
	char ManagerName[50];
	char ManagerPassword[50];

	struct Hotel * hotel;
};
struct Manager * resetManager();
bool changeRoomAprice();
bool changeRoomBprice();
bool changeRoomCprice();
void printAllRooms();
void printRoomA();
void printRoomB();
void printRoomC();
void readRoom(char *ptr, int index);
bool addDiscountRoomA();
bool addDiscountRoomB();
bool addDiscountRoomC();
void readDiscount(char *ptr, int index);
void printAllDiscount();
void readRoomsPrice();
void readAllDiscount();
char *  PrintFullPath(char * partialPath, char * filename);
char * concate(char * firststr, char * secondstr);

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
char * concateStr(char * firststr, char * secondstr);
void setCheckInOperator(struct Hotel * h, struct Customer * c);
bool searchRoomsCheckIn();
void printCustomerBookingInfo();
int getCustomerFeedback();
void changeBookingfee();
bool findBookingCustomer(char * customername, char * str);

struct Checkinoperator * getCheckIn();
struct Checkoutoperator * getCheckOut();
bool findBookingoutCustomer(char * customername, char * str);

bool findCheckoutBooking(char *str);
bool changeRoomNo(char * str, int customerRno, char c);
bool removeCheckinBooking(char *str, char c);
bool writeBookingdata();
bool writecustomerExperience();
void setCheckoutOperator(struct Hotel * h, struct Customer * c);
bool searchRoomsCheckOut();
void printCustomerBookingInfo();
void changeStayingDays();
bool addCustomerCheckout();
void printExperience();
void SearchCheckInCustomer();
void confirminBooking();
void confirmoutBooking();
char *  PrintFullPath(char * partialPath, char * filename);
int datesDifference(int day1, int mon1, int year1, int day2, int mon2, int year2);
int datesinoutDifference(int day1, int mon1, int year1, int day2, int mon2, int year2);
void readFile(char *ptr, char *fileptr);
bool removeCheckoutBooking(char *str, char c);


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

void setroomaPrice(float price);
void setroombPrice(float price);

void setroomcPrice(float price);

float getroomaPrice();
float getroombPrice();
float getroomcPrice();
#endif //APP_H


