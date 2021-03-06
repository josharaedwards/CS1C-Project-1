#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

class Teams
{
public:
    string name;
    string stadiumName;
    string seatingCapacity;
    string location;
    string AmerianFootballConference;
    void displayAllData()
    {
        cout << name << "\t" << seatingCapacity << "\t" << location << "\t" << stadiumName << "\t" << AmerianFootballConference << "\n";
    }
};
class Driver
{
public:
    vector<string> tokens;
    string intermediate;
    vector<Teams> teams;
    vector<Teams> temp;
    string myText;
    string file;
    int choice;
    Driver(string path)
    {
        this->file = path;
    }

    static bool comapreName(Teams a1, Teams a2)
    {
        return (a1.name.compare(a2.name) < 0) ? true : false;
    }
    static bool comapreLocation(Teams a1, Teams a2)
    {
        return (a1.location.compare(a2.location) < 0) ? true : false;
    }
    static bool comapreStadiumName(Teams a1, Teams a2)
    {
        return (a1.stadiumName.compare(a2.stadiumName) < 0) ? true : false;
    }
    static bool comapreSeatCapacity(Teams a1, Teams a2)
    {
        return (a1.seatingCapacity.compare(a2.seatingCapacity) > 0) ? true : false;
    }

    void sortTeamName()
    {
        sort(teams.begin(), teams.end(), this->comapreName);
    }
    void sortStadiumName()
    {
        sort(teams.begin(), teams.end(), this->comapreStadiumName);
    }
    void sortSeatingCapacity()
    {
        sort(teams.begin(), teams.end(), this->comapreSeatCapacity);
    }
    void sortLocation()
    {
        sort(teams.begin(), teams.end(), this->comapreLocation);
    }
    void help()
    {
        cout << "To select a option input the number associated with the option\n";
    }
    void contactus()
    {
        cout << "contact us on xyyz.com\n";
    }
    void calculateTotalCapacity()
    {
        int seats = 0;
        for (auto i : teams)
        {
            seats += stoi(i.seatingCapacity);
        }
        cout << "Total seats in National Football league: " << seats << "\n";
    }
    void displayAmericanFootball()
    {

        for (auto i : teams)
        {
            if (i.AmerianFootballConference.compare("1") == 0)
                temp.push_back(i);
        }
        sort(temp.begin(), temp.end(), comapreName);
        for (auto i : temp)
            i.displayAllData();
    }
    void updateTeams(string text)
    {
        ifstream MyReadFile(text);

        getline(MyReadFile, myText);

        while (getline(MyReadFile, myText))
        {
            Teams temp;
            stringstream check1(myText);
            getline(check1, intermediate, ',');
            temp.name = intermediate;
            getline(check1, intermediate, ',');
            temp.stadiumName = intermediate;
            getline(check1, intermediate, ',');
            temp.seatingCapacity = intermediate;
            getline(check1, intermediate, ',');
            temp.location = intermediate;
            getline(check1, intermediate, ',');
            temp.AmerianFootballConference = intermediate;
            teams.push_back(temp);
        }
        MyReadFile.close();
    }
    void menu()
    {
        cout << "----------------------Main menu choose any option--------------------\n";
        cout << "1. Help\n\
2.Contact us\n\
3.Display the original list of National Football teams sorted by team name.\n\
4.Display the original list of National Football teams sorted by stadium name.\n\
5.Display the original list of National Football teams sorted by seating capacity.\n\
6.Display the total capacity of the National Football league(note: count each stadium only once).\n\
7.Display the original list of National Football teams sorted by the location.\n\
8.Display the team in the American Football Conference sort by team name.\n\
9.Update the National Football teams.\n\
10.Display the updated list of National Football teams sorted by team name.\n\
11.Display the total capacity of the updated National Footbal league(note : count each stadium only once).\n\
12.Exit\n";
        cout << "------------------------------------------------------------------------------\n";
    }
    void loadData()
    {
        ifstream MyReadFile(file);

        getline(MyReadFile, myText);

        while (getline(MyReadFile, myText))
        {
            Teams temp;
            stringstream check1(myText);
            getline(check1, intermediate, ',');
            temp.name = intermediate;
            getline(check1, intermediate, ',');
            temp.stadiumName = intermediate;
            getline(check1, intermediate, ',');
            temp.seatingCapacity = intermediate;
            getline(check1, intermediate, ',');
            temp.location = intermediate;
            getline(check1, intermediate, ',');
            temp.AmerianFootballConference = intermediate;
            teams.push_back(temp);
        }
        MyReadFile.close();
    }
    void caller()
    {
        switch (choice)
        {
        case 1:
            help();
            break;
        case 2:
            contactus();
            break;
        case 3:
            sortTeamName();
            for (auto i : teams)
                i.displayAllData();
            break;
        case 4:
            sortStadiumName();
            for (auto i : teams)
                i.displayAllData();
            break;
        case 5:
            sortSeatingCapacity();
            for (auto i : teams)
                i.displayAllData();
            break;
        case 6:
            calculateTotalCapacity();
            break;
        case 7:
            sortLocation();
            for (auto i : teams)
                i.displayAllData();
            break;
        case 8:
            displayAmericanFootball();
            break;
        case 9:
            cout << "Enter the path to the new file: ";
            cin >> file;
            updateTeams(file);
            cout << "The teams are updated\n";
            break;
        case 10:
            sortTeamName();
            for (auto i : teams)
                i.displayAllData();
            break;
        case 11:
            calculateTotalCapacity();
            break;
        default:
            break;
        }
    }
    void run()
    {
        loadData();
        menu();
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice != 12)
        {
            caller();
            // menu();
            cout << "Enter your choice: ";
            cin >> choice;
                }
    }
};
int main()
{
    Driver driver("teams.txt");
    driver.run();
}
