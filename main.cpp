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
        void remove();
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
            remove();
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
    m:
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
    }

    if (token==1) {
        goto m;
    } else {
        data.open("data.txt", ios::app|ios::out);
        data << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }

    cout << "\t\t\t Product added successfully!" << endl;
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
            if (pkey==p) {
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

void shopping::remove() 
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
            if (pkey==p) {
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

void shopping::add() 
{
    
}