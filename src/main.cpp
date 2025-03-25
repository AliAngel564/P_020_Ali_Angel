


#include <iostream>
#include <conio.h>

using namespace std;

void pressAnyKey();
void getMenu();
void getTasks(string array[], int size);

int main(){
    string usrTasks[5];
    int opt;

    
    do{
        getMenu();
        cin >> opt;
        switch (opt)
        {
        case 1:
            for(int i=0;i<5;i++)
            {
                cout << i+1 << ". ";
                cin >> usrTasks[i];
            }
            pressAnyKey();
            break;
        case 2:
                getTasks(usrTasks,5);
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
        cout << "Task N." << i+1 << ": " << array[i];
    }
}