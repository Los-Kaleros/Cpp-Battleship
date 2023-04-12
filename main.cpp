#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
using namespace std;

const int rows = 8;
const int cols = 8;
int MaxShips = 7;

int matrix[rows][cols];
int player1_board[rows][cols];
int player1_attack_board[rows][cols];

int player2_board[rows][cols];
int player2_attack_board[rows][cols];



void clear_boards(){
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            player1_board[i][j] = 0;
            player1_attack_board[i][j] = 0;
            player2_board[i][j] = 0;
            player2_attack_board[i][j] = 0;
        }
    }
}

void show_player1_board(){
    cout << "-------------------------------------------------------- Hrac 1 plocha --------------------------------------------------------" << endl;
    cout << endl;
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            cout << player1_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void show_player1_attack_board(){
    cout << "-------------------------------------------------------- Hrac 1 radar --------------------------------------------------------" << endl;
    cout << endl;
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            cout << player1_attack_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void player_place_boats(){
    system("cls");
    show_player1_board();
    int pos1,pos2;
    char prompt;
    cout << endl;
    cout << "Na ploche sa zobrazuju 0 na pozicii kde lode niesu 1 kde lode su 2 kde su potopene lode a 3 je miesto kde si strielal avsak nic netrafil" << endl;
    cout << endl;
    cout << "-------------------------------------------------------- Hrac 1 poklada lodky --------------------------------------------------------" << endl;
    cout << endl;
    for(int i=0; i < MaxShips; i++)
    {
        cout << "Zadaj suradnice pre lodku " << i+1 << " (najprv riadok potom stlpec, kladne cisla 0-5 napr. 0 0 je prve policko): ";
        cin >> pos1 >> pos2;
        while(1) 
        {
            if((pos1 < 0) || (pos2 < 0) || (pos1 > 5) || (pos2 > 5))
            {
                cout << "Zadal si zle suradnice!" << endl;
                cout << "Zadaj ich znovu: ";
                cin >> pos1 >> pos2;
            }
            else if(player1_board[pos1][pos2] == 1)
            {
                cout << "Na tychto suradniciach uz je lodka!" << endl;
                cout << "Zadaj ich znovu: ";
                cin >> pos1 >> pos2;
            }
            else
            {
                player1_board[pos1][pos2] = 1;
                break;
            }
        }
    }
    cout << endl;
}


void show_start_screen(){
    cout << setw(30)<<"Vitaj v mojej simple battleship hre!" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << setw(30)<<"Vyber si herny mod:" << endl;
    cout << setw(30)<< "1. Hrac vs PC" << endl;
    cout << setw(30)<< "2. Hrac vs Hrac" << endl;
}


void pc_place_ships(){
    int s = 0;
    while(s < MaxShips)
    {
        int x = rand() % rows;
        int y = rand() % cols;
        if(player2_board[x][y] != 1)
        {
            s++;
            player2_board[x][y] = 1;
        }
    }
}

void player_vs_pc(){
    clear_boards();
    pc_place_ships();
    player_place_boats();
    show_player1_board();
    show_player1_attack_board();


}

void player_vs_player(){
    clear_boards();
    player_place_boats();
    show_player1_board();
    show_player1_attack_board();
}



void choose_mode(){
    int mode;
    cout << "Zadaj cislo modu: ";
    cin >> mode;
    while(1)
    {
        if(mode == 1)
        {
            player_vs_pc();
            break;
        }
        else if(mode == 2)
        {
            player_vs_player();
            break;
        }
        else
        {
            cout << "Zadal si zle cislo modu, zadaj znovu: ";
            cin >> mode;
        }
    }
}






// void Clear()
// {    
//     for(int i=0; i < rows; i++)
//     {
//         for(int j=0; j < cols; j++)
//         {
//             matrix[i][j] = 0;
//         }
//     }
// }

// void Show()
// {
//     for(int i=0; i < rows; i++)
//     {
//         for(int j=0; j < cols; j++)
//         {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }


// void SetShips()
// {
//     int s = 0;
//     while(s < MaxShips)
//     {
//         int x = rand() % rows;
//         int y = rand() % cols;
//         if(matrix[x][y] != 1)
//         {
//             s++;
//             matrix[x][y] = 1;
//         }
//     }
// }

// int NumberOfShips()
// {
//     int c=0;
//     for(int i=0; i < rows; i++)
//     {
//         for(int j=0; j < cols; j++)
//         {
//             if(matrix[i][j] == 1)
//             {
//                 c++;
//             }
//         }
//     }
    
//     return c;
// }

// bool Attack(int x, int y)
// {
//     if(matrix[x][y] == 1)
//     {
//         matrix[x][y] = 2;
//         return true;
//     }
//     if(matrix[x][y] == 0)
// 	{
//     	matrix[x][y] = 3;
// 		return false;	
// 	}
// 	else
// 	{
// 		return false;
// 	}
    
// }


int main()
{
    srand(time(NULL));
    show_start_screen();
    choose_mode();
    player_vs_pc();


    
    return 0;
}