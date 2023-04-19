#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
using namespace std;

const int rows = 3;
const int cols = 3;
int MaxShips = 3;

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
    cout << "Hrac 1 plocha" << endl;
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
    cout << "Hrac 1 radar" << endl;
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

void show_player2_board(){
    cout <<"Hrac 2 plocha" << endl;
    cout << endl;
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            cout << player2_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void show_player2_attack_board(){
    cout <<"Hrac 2 radar" << endl;
    cout << endl;
    for(int i=0; i < rows; i++)
    {   
        for(int j=0; j < cols; j++)
        {
            cout << player2_attack_board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void player_place_boats(){
    system("clear");
    int pos1,pos2;
    char prompt;
    cout << endl;
    for(int i=0; i < MaxShips; i++)
    {
        cout << "Na ploche sa zobrazuju 0 na pozicii kde lode niesu 1 kde lode su 2 kde su potopene lode a 3 je miesto kde si strielal avsak nic netrafil" << endl;
        cout << endl;
        cout << "-------------------------------------------------------- Hrac 1 poklada lodky --------------------------------------------------------" << endl;
        show_player1_board();
        cout << "Zadaj suradnice pre lodku " << i+1 << " (najprv riadok potom stlpec, kladne cisla 0-"<< rows-1 << " napr. 0 0 je prve policko): ";
        cin >> pos1 >> pos2;
        while(1) 
        {
            if((pos1 < 0) || (pos2 < 0) || (pos1 > (rows-1)) || (pos2 > (rows-1)))
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

void player2_place_boats(){
    system("clear");
    int pos1,pos2;
    char prompt;
    cout << endl;
    for(int i=0; i < MaxShips; i++)
    {   cout << "Na ploche sa zobrazuju 0 na pozicii kde lode niesu 1 kde lode su 2 kde su potopene lode a 3 je miesto kde si strielal avsak nic netrafil" << endl;
        cout << endl;
        cout << "-------------------------------------------------------- Hrac 2 poklada lodky --------------------------------------------------------" << endl;
        show_player2_board();
        cout << "Zadaj suradnice pre lodku " << i+1 << " (najprv riadok potom stlpec, kladne cisla 0-" << rows-1 << "napr. 0 0 je prve policko): ";
        cin >> pos1 >> pos2;
        while(1) 
        {
            if((pos1 < 0) || (pos2 < 0) || (pos1 > (rows-1)) || (pos2 > (rows-1)))
            {
                cout << "Zadal si zle suradnice!" << endl;
                cout << "Zadaj ich znovu: ";
                cin >> pos1 >> pos2;
            }
            else if(player2_board[pos1][pos2] == 1)
            {
                cout << "Na tychto suradniciach uz je lodka!" << endl;
                cout << "Zadaj ich znovu: ";
                cin >> pos1 >> pos2;
            }
            else
            {
                player2_board[pos1][pos2] = 1;
                break;
            }
        }
    }
    cout << endl;
}

void show_start_screen(){
    cout << setw(30)<<"Vitaj v mojej battleship hre!" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << setw(30)<<"Vyber si herny mod:" << endl;
    cout << setw(30)<< "1. Hrac vs PC" << endl;
    cout << setw(32)<< "2. Hrac vs Hrac" << endl;
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

int count_ships(int board[rows][cols]){
    int ships = 0;
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < cols; j++)
        {
            if(board[i][j] == 1)
            {
                ships++;
            }
        }
    }
    return ships;
}

void player1_shoot(){
    int pos1,pos2;
    cout << "Zadaj suradnice na ktore chces strielat (najprv riadok potom stlpec, kladne cisla 0-" << rows-1 << "napr. 0 0 je prve policko): ";
    cin >> pos1 >> pos2;
    while(1) 
    {   
        cout << "Zadaj suradnice na ktore chces strielat (najprv riadok potom stlpec, kladne cisla 0-" << rows-1 << "napr. 0 0 je prve policko): ";
        if((pos1 < 0) || (pos2 < 0) || (pos1 > (rows-1)) || (pos2 > (rows-1)))
        {
            cout << "Zadal si zle suradnice!" << endl;
            cout << "Zadaj ich znovu: ";
            cin >> pos1 >> pos2;
        }
        else if(player2_board[pos1][pos2] == 3)
        {
            cout << "Na tychto suradniciach si uz strielal!" << endl;
            cout << "Zadaj ich znovu: ";
            cin >> pos1 >> pos2;
        }
        else if(player2_board[pos1][pos2] == 2)
        {
            cout << "Na tychto suradniciach si uz strielal a potopil si lodku!" << endl;
            cout << "Zadaj ich znovu: ";
            cin >> pos1 >> pos2;
        }
        else if(player2_board[pos1][pos2] == 1)
        {
            player2_board[pos1][pos2] = 2;
            player1_attack_board[pos1][pos2] = 2;
            cout << "Potopil si lodku!" << endl;
            break;
        }
        else
        {
            player2_board[pos1][pos2] = 3;
            player1_attack_board[pos1][pos2] = 3;
            cout << "Nepotopil si lodku!" << endl;
            break;
        }
    }
}

void player2_shoot(){
    int pos1,pos2;
    cout << "Zadaj suradnice na ktore chces strielat (najprv riadok potom stlpec, kladne cisla 0-" << rows-1 << "napr. 0 0 je prve policko): ";
    cin >> pos1 >> pos2;
    while(1) 
    {   
        cout << "Zadaj suradnice na ktore chces strielat (najprv riadok potom stlpec, kladne cisla 0-" << rows-1 << "napr. 0 0 je prve policko): ";
        if((pos1 < 0) || (pos2 < 0) || (pos1 > (rows-1)) || (pos2 > (rows-1)))
        {
            cout << "Zadal si zle suradnice!" << endl;
            cout << "Zadaj ich znovu: ";
            cin >> pos1 >> pos2;
        }
        else if(player1_board[pos1][pos2] == 3)
        {
            cout << "Na tychto suradniciach si uz strielal!" << endl;
            cout << "Zadaj ich znovu: ";
            cin >> pos1 >> pos2;
        }
        else if(player1_board[pos1][pos2] == 2)
        {
            cout << "Na tychto suradniciach si uz strielal a potopil si lodku!" << endl;
            cout << "Zadaj ich znovu: ";
            cin >> pos1 >> pos2;
        }
        else if(player1_board[pos1][pos2] == 1)
        {
            player1_board[pos1][pos2] = 2;
            player2_attack_board[pos1][pos2] = 2;
            cout << "Potopil si lodku!" << endl;
            break;
        }
        else
        {
            player1_board[pos1][pos2] = 3;
            player2_attack_board[pos1][pos2] = 3;
            cout << "Nepotopil si lodku!" << endl;
            break;
        }

    }

}

void pc_shoot(){
    int pos1,pos2;
    pos1 = rand() % rows;
    pos2 = rand() % cols;
    while(1) 
    {
        if (player1_board[pos1][pos2] == 3)
        {
            pos1 = rand() % rows;
            pos2 = rand() % cols;
        }
        else if (player1_board[pos1][pos2] == 2)
        {
            pos1 = rand() % rows;
            pos2 = rand() % cols;
        }
        else if (player1_board[pos1][pos2] == 1)
        {
            player1_board[pos1][pos2] = 2;
            player2_attack_board[pos1][pos2] = 2;
            cout << "PC potopil lod" << endl;
            break;
        }
        else
        {
            player1_board[pos1][pos2] = 3;
            player2_attack_board[pos1][pos2] = 3;
            cout << "PC sa netrafil" << endl;
            break;
        }
    }
}

void player_vs_pc(){
    system("clear");
    cout << setw(30) << "Hrac vs PC" << endl;
    cout << "---------------------------------------------------------------" << endl;
    clear_boards();
    pc_place_ships();
    player_place_boats();
    int player1_ships = count_ships(player1_board);
    int player2_ships = count_ships(player2_board);
    int turn = 1;
    while (player1_ships > 0 && player2_ships > 0)
    {   
        int player1_ships = count_ships(player1_board);
        int player2_ships = count_ships(player2_board);
        cout << "pocet lodiek hraca 1: " << player1_ships;
        cout << setw(5) <<"pocet lodiek PC: " << player2_ships << endl;
        if (turn == 1)
        {
            show_player1_board();
            show_player1_attack_board();
            player1_shoot();
            turn = 2;
        }
        else if(turn == 2)
        {
            pc_shoot();
            turn = 1;
        }
        if(player1_ships == 0)
        {
            cout << "Vyhral hrac 2!" << endl;
            char answer;
            cin >> answer;
            if(answer == 'y')
            {
                player_vs_pc();
            }
            else
            {
                exit(0);
            }
        }
        else if(player2_ships == 0)
        {
            cout << "Vyhral hrac 1!" << endl;
            cout << "chces hrat znovu? (y/n): ";
            char answer;
            cin >> answer;
            if(answer == 'y')
            {
                player_vs_pc();
            }
            else
            {
                exit(0);
            }
        }
    }
}

void player_vs_player(){
    system("clear");
    cout << "Hrac vs Hrac" << endl;
    clear_boards();
    player_place_boats();
    system("clear");
    player2_place_boats();
    system("clear");
    int player1_ships = count_ships(player1_board);
    int player2_ships = count_ships(player2_board);
    int turn = 1;
    while (player1_ships > 0 && player2_ships > 0)
    {   
        system("clear");
        int player1_ships = count_ships(player1_board);
        int player2_ships = count_ships(player2_board);
        cout << "pocet lodiek hraca 1: " << player1_ships;
        cout << setw(5) <<"pocet lodiek hraca 2: " << player2_ships << endl;
        if(player1_ships == 0)
        {
            cout << "Vyhral hrac 2!" << endl;
            cout << "chces hrat znovu? (y/n): ";
            char answer;
            cin >> answer;
            if(answer == 'y')
            {
                player_vs_player();
            }
            else
            {
                cout << "dakujem za hru" << endl;
                exit(0);
            }
        }
        else if(player2_ships == 0)
        {
            cout << "Vyhral hrac 1!" << endl;
            cout << "chces hrat znovu? (y/n): ";
            char answer;
            cin >> answer;
            if(answer == 'y')
            {
                player_vs_player();
            }
            else
            {
                cout << "dakujem za hru" << endl;
                exit(0);
            }
        }
        
        if (turn == 1)
        {
            show_player1_board();
            show_player1_attack_board();
            player1_shoot();
            turn = 2; 
        }
        else if (turn == 2)
        {   
            show_player2_board();
            show_player2_attack_board();
            player2_shoot();
            turn = 1;
        }
    }
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

int main()
{
    srand(time(NULL));
    show_start_screen();
    choose_mode();
    return 0;
}