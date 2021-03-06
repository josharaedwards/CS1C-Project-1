#include "init.h"


void stringGetter(QString &str)
{
    getline(cin, str);        #Joshara - Get this operable within QT
    while(str=="")
    getline(cin, str);
}

void display(QVector<Football> arr) {

    for (int i = 0; i < arr.size(); i++) {

        cout << "======>> Team # " << i + 1 << " <<=========" << endl;
        cout << endl;
        cout << "Name: " << arr[i].name << endl;
        cout << "Seating Capacity: " << arr[i].seating_capacity << endl;
        cout << "Stadium Name: " << arr[i].stadium << endl;
        cout << "Address: " << arr[i].address << endl;
        cout << endl;
    }

}

void fileWrite(QVector<Football> arr, QDataStream &fout)
{
    for (int i = 0; i < arr.size(); i++) {
            if (i != 0)
                fout << endl;
            fout << arr[i].getTeamName() << ',';
            fout << arr[i].getSeatingCapacity() <<',';
            fout << arr[i].getStadiumName() << ',';
            fout << arr[i].address;
        }
        fout.close();
}

void fileRead(QVector<Football> &arr, QDataStream &fin)
{
    /*arr.clear();
        while (!fin.eof()) {
            if (fin.eof())
                break;
            Team obj;
            string num;
            getline(fin, obj.name, ',');
            getline(fin, num, ',');
            obj.seating_capacity = stoi(num);
            getline(fin, obj.stadium, ',');
            getline(fin, obj.address);
            arr.push_back(obj);
        }
        fin.close();*/
}

void testInit()
{
    ifstream fin;
        ofstream fout;
        vector<Team> NFL;
        vector<Team> AFC;


        fin.open("Login.txt");
        if (!fin)
            cout << "Unable to open Login.txt";
        else {
            string _user;
            string _pass;

            while (!fin.eof()) {
                if (fin.eof())
                    break;
                getline(fin, _user);
                getline(fin, _pass);
            }
            fin.close();

            while (1)
            {
                string pass;
                string user;
                cout << "==============>> Login <<==============" << endl;
                cout << "=====>> National Football League <<===" << endl;
                cout << "Enter Username: ";
                StringGetter(user);
                cout << "Enter Password: ";
                StringGetter(pass);
                if (user == _user&&pass == _pass) {
                    break;
                }
                else {
                    cout << "Incorrect username/password" << endl;
                    system("pause");
                    system("cls");
                }
            }

            while (1)
            {
                NFL.clear();
                fin.open("NFL.txt");
                if (!fin) {
                    cout << "Unable to open NFL.txt";
                    exit(1);
                }
                else {

                    while (!fin.eof()) {
                        if (fin.eof())
                            break;
                        Team obj;
                        string num;
                        getline(fin, obj.name, ',');
                        getline(fin, num, ',');
                        obj.seating_capacity = stoi(num);
                        getline(fin, obj.stadium, ',');
                        getline(fin, obj.address);
                        NFL.push_back(obj);
                    }
                    fin.close();
                }

                fin.open("AFC.txt");
                if (!fin) {
                    cout << "Unable to open AFC.txt";
                    exit(1);
                }
                else {
                    AFC.clear();
                    while (!fin.eof()) {
                        if (fin.eof())
                            break;
                        Team obj;
                        string num;
                        getline(fin, obj.name, ',');

                        getline(fin, num, ',');
                        obj.seating_capacity = stoi(num);
                        getline(fin, obj.stadium, ',');
                        getline(fin, obj.address);
                        AFC.push_back(obj);
                    }
                    fin.close();
                }
                //Now All the Files have been read from the txt files...
                int opt = 0;

                int cap = 0;
                system("pause");
                system("cls");
                cout << "==============>> Menu <<==============" << endl;
                cout << "=====>> National Football League <<===" << endl;
                cout << "============>> Pamphlet <<============" << endl;
                cout << "(0) EXIT" << endl;
                cout << "(1) Help Option" << endl;
                cout << "(2) Contact Us" << endl;
                cout << "(3) Show National Football Teams (Sorted by Team Name)" << endl;
                cout << "(4) Show National Football Teams (Sorted by Stadium Name)" << endl;
                cout << "(5) Show National Football Teams (Sorted by Seating Capacity)" << endl;
                cout << "(6) Show Total Capacity of National Football League" << endl;
                cout << "(7) Show National Football Teams (Sorted by Location)" << endl;
                cout << "(8) Show American Conference Teams (Sorted by Team Name)" << endl;
                cout << "(9) Show Updated List of National Football League (Sorted by Team Name)" << endl;
                cout << "(10) Show Updated Total Capacity of National Football League" << endl;
                cout << "(11) Sort according to your choice" << endl;

                cout << endl << "Choice :>> ";
                cin >> opt;
                switch (opt)
                {
                case 0:
                    return 0;
                case 1:
                    cout << "Use the keys assigned for the mentioned tasks in the menu" << endl;
                    cout << "These keys will perform the desired operation mentioned in the menu" << endl;
                    break;
                case 2:
                    cout << "Contact Number: 212-1234567" << endl;
                    break;
                case 3:
                    //Sorting by Team name
                    sort(NFL.begin(), NFL.end(), CompareName);
                    Display(NFL);
                    break;
                case 4:
                    //Sorting by Stadium name
                    sort(NFL.begin(), NFL.end(), CompareStadium);
                    Display(NFL);
                    break;
                case 5:
                    //Sorting By Seating Capacity
                    Sort(NFL);
                    Display(NFL);
                    break;
                case 6:
                    cap = 0;
                    for (int i = 0; i < NFL.size(); i++) {
                        cap = cap + NFL[i].seating_capacity;
                    }
                    cout << "Total Capacity of National Football League: " << cap << endl;
                    break;
                case 7:
                    sort(NFL.begin(), NFL.end(), CompareAddress);
                    Display(NFL);
                    break;
                case 8:
                    sort(AFC.begin(), AFC.end(), CompareName);
                    Display(AFC);
                    break;
                case 9:
                    sort(NFL.begin(), NFL.end(), CompareName);
                    Display(NFL);
                    break;
                case 10:
                    cap = 0;
                    for (int i = 0; i < NFL.size(); i++) {
                        cap = cap + NFL[i].seating_capacity;
                    }
                    cout << "Updated Total Capacity of National Football League: " << cap << endl;
                    break;
                case 11:

                    fout.open("NFL Initial.txt");
                    if (!fout) {
                        cout << "Unable to open NFL Initial.txt";
                    }
                    else
                        FileWrite(NFL, fout);
                    fout.open("AFC Initial.txt");
                    if (!fout)
                        cout << "Unable to open AFC Initial.txt";
                    else {
                        FileWrite(AFC, fout);
                    }




                    while (1) {
                        system("pause");
                        system("cls");
                        int choice = 0;
                        cout << "==============>> Menu <<==============" << endl;
                        cout << "(1) American Football Conference" << endl;
                        cout << "(2) National Football League" << endl;
                        cout << "(0) EXIT" << endl;
                        cout << endl << "Choice: >> :";
                        cin >> choice;
                        if (choice == 1) {

                            while (1) {
                                system("pause");
                                system("cls");
                                int opt2 = 0;
                                cout << "==============>> Sorting Menu <<==============" << endl;
                                cout << "(1) Sort By Name" << endl;
                                cout << "(2) Sort By Location" << endl;
                                cout << "(3) Sort By Seating Capacity" << endl;
                                cout << "(4) Sort By Stadium Name" << endl;
                                cout << "(5) Reset to Initial Position" << endl;
                                cout << "(6) Cancel Previous Sort" << endl;
                                cout << "(0) Exit" << endl;
                                cout << endl << "Choice: >> :";
                                cin >> opt2;
                                if (opt2 == 1) {
                                    fout.open("AFC Reset.txt");
                                    if (!fout) {
                                        cout << "Unable to open AFC Reset.txt";
                                    }
                                    else
                                        FileWrite(AFC, fout);
                                    //Sorting by Team name
                                    sort(AFC.begin(), AFC.end(), CompareName);
                                    Display(AFC);
                                }
                                else if (opt2 == 2) {
                                    sort(AFC.begin(), AFC.end(), CompareAddress);
                                    Display(AFC);
                                    fout.open("AFC Reset.txt");
                                    if (!fout) {
                                        cout << "Unable to open AFC Reset.txt";
                                    }
                                    else
                                        FileWrite(AFC, fout);
                                }
                                else if (opt2 == 3) {
                                    //Sorting By Seating Capacity
                                    fout.open("AFC Reset.txt");
                                    if (!fout) {
                                        cout << "Unable to open AFC Reset.txt";
                                    }
                                    else
                                        FileWrite(AFC, fout);
                                    Sort(AFC);
                                    Display(AFC);
                                }
                                else if (opt2 == 4) {
                                    //Sorting by Stadium name
                                    fout.open("AFC Reset.txt");
                                    if (!fout) {
                                        cout << "Unable to open AFC Reset.txt";
                                    }
                                    else
                                        FileWrite(AFC, fout);
                                    sort(AFC.begin(), AFC.end(), CompareStadium);
                                    Display(AFC);
                                }
                                else if (opt2 == 5) {
                                    fin.open("AFC Reset.txt");
                                    if (!fin)
                                        cout << "Unable to open AFC Reset.txt";
                                    else {
                                        FileRead(AFC, fin);
                                    }
                                }
                                else if (opt2 == 6) {
                                    fin.open("AFC Initial.txt");
                                    if (!fin)
                                        cout << "Unable to open AFC Initial.txt";
                                    else {
                                        FileRead(AFC, fin);
                                    }
                                }
                                else if (opt2 == 0) {
                                    break;
                                }
                                else {
                                    cout << "Invalid Entry!" << endl;
                                    system("pause");
                                    system("cls");
                                }
                            }

                        }
                        else if (choice == 2) {

                            while (1) {
                                system("pause");
                                system("cls");
                                int opt1 = 0;
                                cout << "==============>> Sorting Menu <<==============" << endl;
                                cout << "(1) Sort By Name" << endl;
                                cout << "(2) Sort By Location" << endl;
                                cout << "(3) Sort By Seating Capacity" << endl;
                                cout << "(4) Sort By Stadium Name" << endl;
                                cout << "(5) Reset to Initial Position" << endl;
                                cout << "(6) Cancel Previous Sort" << endl;
                                cout << "(0) Exit" << endl;
                                cout << "\nChoice :>> ";
                                cin >> opt1;


                                if (opt1 == 1) {
                                    fout.open("NFL Reset.txt");
                                    if (!fout) {
                                        cout << "Unable to open NFL Reset.txt";
                                    }
                                    else
                                        FileWrite(NFL, fout);
                                    //Sorting by Team name
                                    sort(NFL.begin(), NFL.end(), CompareName);
                                    Display(NFL);
                                }
                                else if (opt1 == 2) {
                                    sort(NFL.begin(), NFL.end(), CompareAddress);
                                    Display(NFL);
                                    fout.open("NFL Reset.txt");
                                    if (!fout) {
                                        cout << "Unable to open NFL Reset.txt";
                                    }
                                    else
                                        FileWrite(NFL, fout);
                                }
                                else if (opt1 == 3) {
                                    //Sorting By Seating Capacity
                                    fout.open("NFL Reset.txt");
                                    if (!fout) {
                                        cout << "Unable to open NFL Reset.txt";
                                    }
                                    else
                                        FileWrite(NFL, fout);
                                    Sort(NFL);
                                    Display(NFL);
                                }
                                else if (opt1 == 4) {
                                    //Sorting by Stadium name
                                    fout.open("NFL Reset.txt");
                                    if (!fout) {
                                        cout << "Unable to open NFL Reset.txt";
                                    }
                                    else
                                        FileWrite(NFL, fout);
                                    sort(NFL.begin(), NFL.end(), CompareStadium);
                                    Display(NFL);
                                }
                                else if (opt1 == 5) {
                                    fin.open("NFL Reset.txt");
                                    if (!fin)
                                        cout << "Unable to open NFL Reset.txt";
                                    else {
                                        FileRead(NFL, fin);
                                    }
                                }
                                else if (opt1 == 6) {
                                    fin.open("NFL Initial.txt");
                                    if (!fin)
                                        cout << "Unable to open NFL Initial.txt";
                                    else {
                                        FileRead(NFL, fin);
                                    }
                                }
                                else if (opt1 == 0) {
                                    break;
                                }
                                else {
                                    cout << "Invalid Entry!" << endl;
                                    system("pause");
                                    system("cls");
                                }
                            }

                        }
                        else if (choice == 0) {
                            break;
                        }
                        else {
                            cout << "Invalid Entry!" << endl;
                        }
                    }



                    fout.open("NFL.txt");
                    if (!fout) {
                        cout << "Unable to open NFL.txt";
                    }
                    else
                        FileWrite(NFL, fout);
                    fout.open("AFC.txt");
                    if (!fout)
                        cout << "Unable to open AFC.txt";
                    else {
                        FileWrite(AFC, fout);
                    }




                    break;
                default:
                    cout << "Invalid Entry!" << endl;
                    break;
                }
            }
        }
}
