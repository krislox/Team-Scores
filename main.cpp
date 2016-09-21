//
//
//  team_scores.cpp
//
//  Creates an array of 5 teams, with a name and a score, and arranges them from highest score to lowest
//
//  Created by Van Ralf Aguas on 2/15/15.
//  Copyright (c) 2015 Van Ralf Aguas. All rights reserved.
//

#include <iostream>
using namespace std;

void initializeArrays(string[],int[],int);
void sortData(string[],int[],int);
void displayData(string[],int[],int);
void swapper(int& x, int&y);
void name_swapper(string& x, string&y);

int main()
{
    string team_names[5];
    int team_score[5];
    initializeArrays(team_names, team_score, 5);
    sortData(team_names, team_score, 5);
    displayData(team_names, team_score, 5);
    
    return 0;
}

void sortData(string team_names[], int team_score[], int size)
{
    int lowestVal, lowestPos;
    string lowestSVal;
    for(int i =0; i < size-1; i++)
    {
        lowestVal = team_score[i];
        lowestPos = i;
        for(int j=i+1;j<size;j++)
        {
            if(team_score[j]<lowestVal)
            {
                lowestPos = j;
                lowestVal = team_score[j];
                lowestSVal = team_names[j];
                
            }
        }
        swapper(team_score[i], team_score[lowestPos]);
        name_swapper(team_names[i], team_names[lowestPos]);
    }
}

void swapper(int& x, int&y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void name_swapper(string& x, string&y)
{
    string temp;
    temp = x;
    x = y;
    y = temp;
}

void initializeArrays(string team_names[],int team_score[],int size)
{
    string *name = NULL;
    int *score = NULL;
    for (int i=0; i < size; i++)
    {
        cout << "Enter team # " << i+1 << " " << endl;
        cin >> team_names[i];
        cout << "Enter the wins for team # " << i+1 << " " << endl;
        cin >> team_score[i];
    }
}

void displayData(string team_names[],int team_score[], int size)
{
    for (int i =4; i >= 0; i--)
        cout <<  team_names[i] <<  ": " << team_score[i] << "\n";
}
