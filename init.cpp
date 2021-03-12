#include "init.h"

QVector<Football> fileRead(string fileName)
{
    QVector<Football> footballTeams;
    int count = 0;

    ifstream myFile;
    myFile.open(fileName);

    while (myFile)
    {
        string line;
        Football tempTeam;

        while(myFile && count < 9)
        {
            if (count == 8)
            {
                tempTeam = updateFromFile(myFile, count, tempTeam);
                footballTeams.push_back(tempTeam);
                count = 0;
            }
            else
            {
                tempTeam = updateFromFile(myFile, count, tempTeam);
                count++;
            }
        }
    }

    myFile.close();

    return footballTeams;
}

Football updateFromFile(ifstream& myFile, int lineNum, Football tempTeam)
{
    string text;

    switch(lineNum)
    {
    case 0:
        getline(myFile, text, '\t');
        tempTeam.setTeamName(text);
        break;
    case 1:
        getline(myFile, text, '\t');
        tempTeam.setStadiumName(text);
        break;
    case 2:
        getline(myFile, text, '\t');
        tempTeam.setSeatingCapacity(text);
        break;
    case 3:
        getline(myFile, text, '\t');
        tempTeam.setLocation(text);
        break;
    case 4:
        getline(myFile, text, '\t');
        tempTeam.setConference(text);
        break;
    case 5:
        getline(myFile, text, '\t');
        tempTeam.setDivision(text);
        break;
    case 6:
        getline(myFile, text, '\t');
        tempTeam.setSurfaceType(text);
        break;
    case 7:
        getline(myFile, text, '\t');
        tempTeam.setStadiumRoofType(text);
        break;
    case 8:
        getline(myFile, text, '\n');
        tempTeam.setDateOpened(text);
        break;
    default:
        break;
    }

    return tempTeam;
}
