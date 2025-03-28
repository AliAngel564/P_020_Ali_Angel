


#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void pressAnyKey();
void getMenu();
void getTasks(string array[], int size);

int main(){
    string usrTasks[5];
    int opt,deleteNum,taskCounter;

    
    do{
        getMenu();
        cin >> opt;
        cin.ignore();
        switch (opt)
        {
        case 1:
            for(int i=0;i<5;i++)
            {
                if(usrTasks[i].size() == 0)
                {
                    taskCounter+1;
                    cout << "\nTask N." << i+1 << " ";
                    getline(cin,usrTasks[i]);
                    break;   
                }else if(usrTasks[i].size() > 0)
                {
                    
                }
            }
            pressAnyKey();
            break;
        case 2:
            getTasks(usrTasks,5);
            cout << "Select a Task you want to delete: ";
            cin >> deleteNum;
            for(int i=0;i<5;i++)
            {
                if(i==deleteNum)
                {
                    usrTasks[deleteNum-1] = "";
                }
            }
            

            break;
        case 3:
            getTasks(usrTasks,5);
            pressAnyKey();
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

void pressAnyKey()
{
    cout << "PRESS ANY KEY TO CONTINUE";
    getch();
    system("cls");
}
void getMenu()
{
    cout << "1.Add Task\n2.Delete Task\n3.View Tasks\n9.Exit Program\n\nOption: ";
}
void getTasks(string array[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout << "Task N." << i+1 << ": " << array[i] << "\n";
    }
}