/*
Amerike University
Author: Ali Angel
Work #: 20
Date: 28/03/25
Description: This program will work as a task list and task manager for the user, using a switch, storing the tasks in an array
and letting the user add, delete and show tasks, it also uses functions to print the tasks and the task menu.
*/

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void pressAnyKey();
void getMenu();
void getTasks(string array[], int size);

int main(){
    string usrTasks[5];
    int opt,deleteNum;
    int taskCounter = 0;

    
    do{
        getMenu();
        cin >> opt;
        cin.ignore();
        switch (opt)
        {
        case 1:
        /*For loop that checks if the indexes are empty, if they are, they let the user input
        a task, it adds 1 to the taskCounter and calls a break so the tasks are added one at a time.*/
            for(int i=0;i<5;i++)
            {
                if(usrTasks[i].length() == 0)
                {
                    taskCounter++;
                    cout << "\nTask N." << i+1 << " ";
                    getline(cin,usrTasks[i]);
                    break;   
                }else if(taskCounter == 5) //If the taskCounter is full, no more tasks can be added until one task is deleted
                {
                    cout << "\nYour task list is full, try deleting a task and try again\n\n";
                    break;
                }
            }
            pressAnyKey();
            break;
        case 2:
            if(taskCounter == 0)
            {
                cout << "\nThere are no tasks to delete\n";
                pressAnyKey();
                break;
            }
            getTasks(usrTasks,5);
            cout << "Write the number of the task you want to delete: ";
            cin >> deleteNum;
            /*This for loop checks if the inputted deleteNum is equal to an index Number and that position
            in the array is empty, if the conditions are met, the position is filled with an empty string
            else if the inputted deleteNum is an empty array index it will be an invalid option*/
            for(int i=0;i<5;i++)
            {
                if(i==deleteNum-1 && usrTasks[i].length() > 0)
                {
                    usrTasks[deleteNum-1] = "";
                    taskCounter--;
                    cout << "\nTask Deleted\n";
                    break;
                }else if(usrTasks[i].length() == 0 || deleteNum > 5 || deleteNum < 0)
                {
                    cout << "Invalid Option\n\n";
                    break;
                }
            }
            /*This for loop sorts the tasks after one is deleted*/
            for(int i=0;i<5;i++)
            {
                if(usrTasks[i].length() == 0 && i < taskCounter)
                {
                    usrTasks[i] = usrTasks[i+1];
                    usrTasks[i+1] = "";
                }
            }
            pressAnyKey();
            break;
        case 3:
        /*If our taskCounter is equal to 0 there are no tasks to show, if it is bigger than 0 there are tasks to be shown*/
            if(taskCounter == 0)
            {
                cout << "\nThere are no task to show\n";
                pressAnyKey();
            }else{
            cout << "-----TASKS-----\n";
            getTasks(usrTasks,5);
            pressAnyKey();
            }
            break;
        case 9:

            break;
        default:
            cout << "Invalid Option\n";
            pressAnyKey();
            break;
    }
    }while(opt != 9);

    return 0;
}

// This function calls the getch() function and the system("cls") function to make
// the user press any key to continue and it then clears the screen.
void pressAnyKey()
{
    cout << "PRESS ANY KEY TO CONTINUE";
    getch();
    system("cls");
}
//This function prints out the option menu
void getMenu()
{
    cout << "1.Add Task\n2.Delete Task\n3.View Tasks\n9.Exit Program\n\nOption: ";
}
//This function prints out the tasks in order using a for loop
void getTasks(string array[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout << "Task N" << i+1 << ": " << array[i] << "\n";
    }
}