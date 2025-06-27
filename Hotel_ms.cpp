#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

// class customer
class Customer
{
public:
    char name[100];
    char address[100];
    char phone[10];
    char email[100];
    char from_date[20];
    char to_date[20];
    float advance_payment;
    int booking_id;
};

class Room
{
public:
    char room_type[15];
    int room_no = 0;
    float room_price;
    char room_status;

    class Customer cust;
};

Room rooms[100];
int availableRooms = 0;
string pname;
char qname[20];

// Room rooms[100]
// {
//     int count = 0;
// };

class Hotel_Management
{
public:
void manage_room();
    void check_in();
    void available_rooms();
    void searchCustomer(string pname);
    void check_out(int);
    void displayRoom(Room room);
    void guest_summary();
};

void Hotel_Management ::displayRoom(Room room)
{
    cout << "\t\t\t Room Number :" << room.room_no << endl;
    cout << "\t\t\t Room Type(AC/Non AC) :" << room.room_type << endl;
    cout << "\t\t\t Room Price :" << room.room_price << endl;
    cout << "\t\t\t Room Rent :" << room.room_price << endl;
}

void Hotel_Management ::check_in()
{
    int i, found = 0, room_no;

    // Room rooms[100];
    cout << "\t\t\t Enter the Room number : ";
    cin >> room_no;
    for (i = 0; i < availableRooms; i++)
    {
        if (rooms[i].room_no == room_no)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        if (rooms[i].room_status == 1)
            cout << "\t\t\t Room is already booked" << endl;
        getch();
    }
    else
    {
        float n;
        cout << "\t\t\t Enter Booking ID: ";
        cin >> rooms[i].cust.booking_id;
        cout << "\t\t ----------------------------------------" << endl;
        cout << "\t\t\t Enter Name:";
        cin >> rooms[i].cust.name;
        cout << "\t\t\t Enter Address:";
        cin >> rooms[i].cust.address;
        cout << "\t\t\t Enter Phone:";
        cin >> rooms[i].cust.phone;
        cout << "\t\t\t Enter Email:";
        cin >> rooms[i].cust.email;
        cout << "\t\t ----------------------------------------" << endl;
        cout << "\t\t\t Enter From date:";
        cin >> rooms[i].cust.from_date;
        cout << "\t\t ----------------------------------------" << endl;
        cout << "\t\t\t Enter To date:";
        cin >> rooms[i].cust.to_date;
        cout << "\t\t ----------------------------------------" << endl;
        cout << "\t\t\t Enter Advance Payment: ";
        cin >> n;
        rooms[i].cust.advance_payment = n;

        rooms[i].room_status = 1;
    }
};

void Hotel_Management ::available_rooms()
{
    int i, found = 0;
    for (i = 0; i < availableRooms; i++)
    {
        if (rooms[i].room_status == 0)
        {
            displayRoom(rooms[i]);
            cout << "\t\t\t Room is available" << endl;
            found = 1;
            getch();
        }
    }
}

void Hotel_Management ::check_out(int roomNum)
{
    int i = 0;
    int found = 0;
    int days, rno;
    float total_bill = 0;
    for (i = 0; i < availableRooms; i++)
    {
        if (rooms[i].room_no == roomNum && rooms[i].room_status == 1)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        cout << "\t\t\tEnter the number of days : ";
        cin >> days;
        total_bill = days * rooms[i].room_price;

        cout << "\t\t------------------------------------------" << endl;
        cout << "\t\t\tCustomer name : " << rooms[i].cust.name << endl;
        cout << "\t\t\tCustomer address : " << rooms[i].cust.address << endl;
        cout << "\t\t\tCustomer phone : " << rooms[i].cust.phone << endl;
        cout << "\t\t\t Room Type(AC/NonAC): " << rooms[i].room_type << endl;
        cout << "\t\t\t Room price: " << rooms[i].room_price << endl;
        cout << "\t\t\t Room Bill: " << total_bill << endl;
        cout << "\t\t\t Advance Payment: " << rooms[i].cust.advance_payment << endl;
        cout << "\t\t----------------------------------------" << endl;
        cout << "\t\t\t Remaining Payment: " << total_bill - rooms[i].cust.advance_payment << endl;

        rooms[i].room_status = 0;
    }
    else
    {
        cout << "\t\t\t Room is not booked" << endl;
        getch();
    }
}

void Hotel_Management ::searchCustomer(string pname)
{
    int i = 0;
    int found = 0;
    for (i = 0; i < availableRooms; i++)
    {
        if (rooms[i].room_status == 1 && (rooms[i].cust.name == pname) == 0)
        {
            cout << "\t\t\tCustomer name : " << rooms[i].cust.name << endl;
            cout << "\t\t\tRoom Number : " << rooms[i].room_no << endl;
            cout << "\t\t----------------------------------------" << endl;
            cout << "\t\t To see more details press yes or no :";
            char option[10];
            if (stricmp(option, "yes") == 0)
            {
                displayRoom(rooms[i]);
            }
            else
            {
                return;
            }
            found = 1;
            getch();
        }
    }
}

void Hotel_Management :: manage_room()
{
    int room_number, opt;
    string room_type, room_status;
    float room_price;
    system("cls");
    cout << "\t\t\t Manage Room" << endl;
    cout << "\t\t --------------------------------" << endl;
    cout << "\t\t 1.Add Room" << endl;
    cout << "\t\t 2.Delete Room" << endl;
    cout << "\t\t 3.Edit Room" << endl;
    cout << "\t\t 4.Back" << endl;
    cout << "\t\t ---------------------------------" << endl;
    cout << "\t\t Enter Your Choice:" << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
        for (int i = 0; i < 100; i++)
        {
            if (rooms[i].room_no == 0)
            {
                system("cls");
                cout << "\t\t\t Add Room" << endl;
                cout << "\t\t ---------------------------------" << endl;
                cout << "\t\t Enter Room Number: ";
                cin >> room_number;
                cout << "\t\t Enter Room type: ";
                cin >> room_type;
                cout << "\t\t Enter Room Price: ";
                cin >> room_price;
                cout << "\t\t Enter Room Status: ";
                cin >> room_status;
                availableRooms += 1;
                cout << "\t\t ---------------------------------:" << endl;
                cout << "\t\t Room added Successfully:" << endl;
                cout << "\t\t ---------------------------------:" << endl;
                cout << "\t\t Press any key to continue:" << endl;
                break;
            }
        }
        getch();
        break;
    case 2:
        system("cls");

        cout << "\t\t\t Delete Room" << endl;
        cout << "\t\t ------------------------------------" << endl;
        cout << "\t\t Enter room Number" << endl;
        cin >> room_number;
        availableRooms -= 1;
        cout << "\t\t -----------------------------------" << endl;
        cout << "\t\t Room deleted successfully" << endl;
        cout << "\t\t -----------------------------------" << endl;
        cout << "\t\t Press any key to continue" << endl;
        for (int i = 0; i < 100; i++)
        {
            if (rooms[i].room_no == room_number)
            {
                rooms[i].room_no = 0;
            }
        }
        getch();
        break;
    case 3:
        system("cls");
        cout << "\t\t\t Edit Room" << endl;
        cout << "\t\t --------------------------------------" << endl;
        cout << "\t\t Enter Room Number" << endl;
        cin >> room_number;
        cout << "\t\t Enter Room type" << endl;
        cin >> room_type;
        cout << "\t\t Enter Room price" << endl;
        cin >> room_price;
        cout << "\t\t Enter Room status" << endl;
        cin >> room_status;
    }
};

void Hotel_Management :: guest_summary(){
    if(availableRooms == 0){
        cout<<"\t\tNo Guest is staying in the hotel"<<endl;
    }
    for (int i = 0; i < availableRooms; i++)
    {
       if(rooms[i].room_status == 1){
        cout<<"\t\t\tCustomerv Name : "<<rooms[i].cust.name<<endl;
        cout<<"\t\t\t Customer Address : "<<rooms[i].cust.address<<endl;
        cout<<"\t\t\t Customer Phone : "<<rooms[i].cust.phone<<endl;
        cout<<"\t\t\t Customer Email : "<<rooms[i].cust.email<<endl;
        cout<<"\t\t\t Staying Since : "<<rooms[i].cust.from_date<<endl;
        cout<<"\t\t\t Staying Till : "<<rooms[i].cust.to_date<<endl;
        cout<<"\t\t---------------------------------------"<<endl;
        cout<<"\t\t\t Room Number : "<<rooms[i].room_no<<endl;
        cout<<"\t\t\tRoom Type(AC/Non AC) : "<<rooms[i].room_type<<endl;
        cout<<"\t\t---------------------------------------"<<endl;
       }
    }
    
}

int main()
{
    int i, j, opt, room_number, rno;
    Hotel_Management hotel;
    char c;
    Room rooms[100];

    system("cls");
    do
    {
        system("cls");
        cout << "\t\t\tHotel Management System" << endl;
        cout << "\t\t------------------------------------" << endl;
        cout << "\t\t 1.Manage Room" << endl;
        cout << "\t\t 2.Check-In room" << endl;
        cout << "\t\t 3.Available Room" << endl;
        cout << "\t\t 4.Check-Out Room" << endl;
        cout << "\t\t 5.Search Customer" << endl;
        cout << "\t\t 6.Guest Summary" << endl;
        cout << "\t\t 7.Exit" << endl;
        cout << "\t\t ---------------------------------" << endl;
        cout << "\t\t Enter your Choice" << endl;
        cin >> opt;

        switch (opt)
        {
        case 1:
            hotel.manage_room();
            break;
        case 2:
            if (availableRooms == 0)
            {
                cout << "\t\t ----------------------------------" << endl;
                cout << "\t\t No room Available" << endl;
                cout << "\t\t ----------------------------------" << endl;
                cout << "\t\t Press any key to continue" << endl;
                getch();
                break;
            }
            else
            {
                hotel.check_in();
            }
            break;
        case 3:
            if (availableRooms == 0)
            {
                cout << "\t\tRooms data is not available.\nPlease add the rooms first.";
                getch();
            }
            else
            {
                hotel.available_rooms();
            }
        case 4:
            if (availableRooms == 0)
            {
                cout << "\t\tRooms data is not available.\nPlease add the rooms first.";
            }
            else
            {
                cout << "\t\t\tEnter the room number";
                cin >> rno;
                hotel.check_out(rno);
            }

        case 5:
            if (availableRooms == 0)
            {
                cout << "\t\tRooms data is not available.\nPlease add the rooms first. ";
                getch();
            }
            else
            {
                cout << "\t\t\t Enter the name of the customer:";
                cin >> pname;
                hotel.searchCustomer(pname);
            }
        case 6:
            hotel.guest_summary();
        case 7:    
        cout<<"\t\t\tThank You for using the system"<<endl;
        break;
        default:
        cout<<"\t\t\t Please enter correct option"<<endl;
        break;
        }

    } while (opt != 7);
};