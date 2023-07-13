#include<iostream>
#include<fstream>

using namespace std;

class shopping 
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu();
        void admin();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};

void shopping::menu()
{   
    menu:
    int choice;
    string email, password;

    cout << "\t\t\t\t______________________________________________________" << endl;
    cout << "\t\t\t\t|                                                    |" << endl;   
    cout << "\t\t\t\t|                 Amazon Main Menu                   |" << endl;
    cout << "\t\t\t\t______________________________________________________" << endl;
    cout << "\t\t\t\t|                                                    |" << endl;
    cout << "\t\t\t\t| 1. Admin                                           |" << endl;
    cout << "\t\t\t\t| 2. Buyer                                           |" << endl;
    cout << "\t\t\t\t| 3. Exit                                            |" << endl;
    cout << "\t\t\t\t|____________________________________________________|" << endl;
    cout << "\t\t\t\t|                                                    |" << endl;
    cout << "\t\t\t\t| Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "\t\t\t Please Login to continue" << endl;
            cout << "\t\t\t Enter your email: " << endl;
            cin >> email;
            cout << "\t\t\t Enter your password: " << endl;
            cin >> password;
            
            if (email == "admin" && password == "admin")
            {
                admin();
            }
            else
            {
                cout << "\t\t\t Invalid email or password" << endl;
            }

        case 2:
            buyer();
        
        case 3:
            exit(0);
        
        default:
            cout << "\t\t\t Invalid choice" << endl;
    }
    goto menu;
}

void shopping::admin()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t Admin Menu" << endl;
    cout << "\t\t\t 1. Add product" << endl;
    cout << "\t\t\t 2. Edit product" << endl;
    cout << "\t\t\t 3. Remove product" << endl;
    cout << "\t\t\t 4. Back to main menu" << endl;

    cout << "\t\t\t Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            add();
            break;
        
        case 2:
            edit();
            break;
        
        case 3:
            rem();
            break;
        
        case 4:
            menu();
            break;
        
        default:
            cout << "\t\t\t Invalid choice" << endl;
    }
    goto m;
}

void shopping:: buyer() 
{
    m:
    int choice;
    cout << "\t\t\t Buyer" << endl;
    cout << "\t\t\t 1. Buy products" << endl;
    cout << "\t\t\t 2. Return" << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
            break;
        
        default:
            cout << "\t\t\t Invalid choice" << endl;
    }
    goto m;
}

void shopping::add() 
{
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;

    cout << "\t\t\t Add the record" << endl;
    cout << "\t\t\t Enter product code: ";
    cin >> pcode;
    cout << "\t\t\t Enter product name: ";
    cin >> pname;
    cout << "\t\t\t Enter product price: ";
    cin >> price;
    cout << "\t\t\t Enter product discount: ";
    cin >> dis;

    data.open("data.txt", ios::in);

    if (!data)
    {
        data.open("data.txt", ios::app|ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else 
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        } 

        data.close();
    

        if (token==1) {
            cout << "\t\t\t Product code already exists" << endl;
        } else {
            data.open("data.txt", ios::app|ios::out);
            data << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
            cout << "\t\t\t Product added successfully!" << endl;
        }
    }
}

void shopping::edit() 
{
    fstream data, data1;
    int pkey, token= 0, c;
    float p, d;
    string n;

    cout << "\t\t\t Modify the record" << endl;
    cout << "\t\t\t Enter product code: ";
    cin >> pkey;

    data.open("data.txt", ios::in);
    if (!data) {
        cout << "\t\t\t File not found" << endl;
    } else {
        data1.open("data1.txt", ios::app|ios::out);
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (pkey==c) {
                cout << "\t\t\t Enter product new code: ";
                cin >> pcode;
                cout << "\t\t\t Enter product name: ";
                cin >> pname;
                cout << "\t\t\t Enter product price: ";
                cin >> price;
                cout << "\t\t\t Enter product discount: ";
                cin >> dis;
                data1 << pcode << " " << pname << " " << price << " " << dis << endl;
                cout << "\t\t\t Record modified successfully!" << endl;
                token++;
            } else {
                data1 << c << " " << n << " " << p << " " << d << endl;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
        data1.close();

        remove("data.txt");
        rename("data1.txt", "data.txt");

        if (token==0) {
            cout << "\t\t\t Record not found" << endl;
        }
    }
}

void shopping::rem() 
{
    fstream data, data1;
    int pkey, token= 0, c;
    float p, d;
    string n;

    cout << "\t\t\t Delete the record" << endl;
    cout << "\t\t\t Enter product code: ";
    cin >> pkey;

    data.open("data.txt", ios::in);
    if (!data) {
        cout << "\t\t\t File not found" << endl;
    } else {
        data1.open("data1.txt", ios::app|ios::out);
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (pkey==c) {
                cout << "\t\t\t Record deleted successfully!" << endl;
                token++;
            } else {
                data1 << c << " " << n << " " << p << " " << d << endl;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
        data1.close();

        remove("data.txt");
        rename("data1.txt", "data.txt");

        if (token==0) {
            cout << "\t\t\t Record not found" << endl;
        }
    }
}

void shopping::list() 
{
    fstream data;
    data.open("data.txt", ios::in);
    cout << "\t\t\t Product code\t\t\t Product name\t\t\t Product price\t\t\t Product discount" << endl;
    data >> pcode >> pname >> price >> dis;
    while (!data.eof()) {
        cout << "\t\t\t " << pcode << "\t\t\t\t " << pname << "\t\t\t\t " << price << "\t\t\t\t " << dis << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt() 
{
    fstream data;
    int arrc[100], arrq[100];
    char choice;
    int c=0;
    float amount=0, total=0, dis=0;

    cout << "\n\n\t\t\t RECEIPT" << endl;
    data.open("data.txt", ios::in);
    if (!data) {
        cout << "\t\t\t File not found" << endl;
    }   else {
        data.close();

        list();
        cout << "\t\t\t Please place the order" << endl;

        do {
            cout << "\t\t\t Enter product code: ";
            cin >> arrc[c];
            cout << "\t\t\t Enter product quantity: ";
            cin >> arrq[c];
            for (int i=0; i<c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\t\t\t Product already ordered" << endl;
                    c--;
                }
            }
            c++;
            cout << "\t\t\t Do you want to place another order? (y/n): ";
            cin >> choice;
        } while (choice=='y' || choice=='Y');

        for (int i=0; i<c; i++) {
            data.open("data.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (arrc[i]==pcode) {
                    amount = (price*arrq[i]) - ((price*arrq[i])*dis/100);
                    cout << "\t\t\t " << pname << "\t\t\t\t " << price << "\t\t\t\t " << arrq[i] << "\t\t\t\t " << amount << endl;
                    total += amount;
                    break;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }

        cout << "\t\t\t Total amount: " << total << endl;
    }
}

int main() 
{
    shopping s;
    s.menu();
}