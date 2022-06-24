#include<iostream>
#include<string>
using namespace std;

char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

void showboard() // to show the board everytime it is called
{
    cout<<"  "<<board[0]<<" |"<<board[1]<<"  |"<<board[2]<<endl;
    cout<<"    |   | "<<endl;

    cout<<"--------------"<<endl;
    cout<<"  "<<board[3]<<" |"<<board[4]<<"  |"<<board[5]<<endl;
    cout<<"    |   | "<<endl;
    cout<<"--------------"<<endl;
    cout<<"  "<<board[6]<<" |"<<board[7]<<"  |"<<board[8]<<endl;
    cout<<"    |   | "<<endl;
}

void X_playerChoice()
{
    while(true){
    int n1;
    cout<<"Enter the position you want to enter (from 0-8)"<<endl;
    cin>>n1;
    if(n1<0 || n1>8) //if user enters the number less than 0 and more than 8 which is not in the table
    {
        cout<<"Enter number between 0-8"<<endl;
    }
    else if(board[n1]!=' ') //if user enters the position which is not empty
    {
        cout<<"Please select position which is empty"<<endl;
    }
    else
    {
        board[n1]='X';
        break;
    }
    }

}

void O_playerChoice()
{
    while(true){
    int n2;
    cout<<"Enter the position you want to enter (from 0-8)"<<endl;
    cin>>n2;
    if(n2<0 || n2>8) //if user enters the number less than 0 and more than 8 which is not in the table
    {
        cout<<"Enter number between 0-8"<<endl;
    }
    else if(board[n2]!=' ') //if user enters the position which is not empty
    {
        cout<<"Please select position which is empty"<<endl;
    }
    else
    {
        board[n2]='O';
        break;
    }
    }

}


int count_board(char symbol) //to count the presence of X and O
{
    int i,count=0;
    for(i=0;i<9;i++)
    {
        if(board[i]==symbol)
        {
            count++;
        }
    }
    return count;
}

char check_winner()
{
    //checking horizontally
    if(board[0]==board[1] && board[1]==board[2] && board[0]!=' ')
    return board[0];

    if(board[3]==board[4] && board[4]==board[5] && board[3]!=' ')
    return board[3];

    if(board[6]==board[7] && board[7]==board[8] && board[6]!=' ')
    return board[6];
    
    //checking vertically
    if(board[0]==board[3] && board[3]==board[6] && board[0]!=' ')
    return board[0];

    if(board[1]==board[4] && board[4]==board[7] && board[1]!=' ')
    return board[1];

    if(board[2]==board[5] && board[5]==board[8] && board[2]!=' ')
    return board[2];

    //checking diagonally
    if(board[0]==board[4] && board[4]==board[8] && board[0]!=' ')
    return board[0];

    if(board[2]==board[4] && board[4]==board[6] && board[2]!=' ')
    return board[2];

    if(count_board('X')+count_board('O') < 9)   //to continue
    return 'C';

    else
    return 'D'; //if the game is draw

}

void player_vs_player()
{
    string X_player_name,O_player_name;
    cout<<"Enter X player name : ";
    cin>>X_player_name;
    cout<<"Enter O player name : ";
    cin>>O_player_name;

    while(true)
    {
        system("cls");
        showboard();
        if(count_board('X') == count_board('O'))
        {
            cout<<X_player_name<<"'s turn"<<endl;
            X_playerChoice();
        }
        else
        {
            cout<<O_player_name<<"'s turn"<<endl;
            O_playerChoice();
        }

        char winner = check_winner();
        if(winner=='X')
        {
            system("cls");
            showboard();
            cout<<X_player_name<<" won the game"<<endl;
            break;
        }
        else if(winner=='O')
        {
            system("cls");
            showboard();
            cout<<O_player_name<<" won the game"<<endl;
            break;
        }
    
        else if(winner=='D')
        {
            system("cls");
            showboard();
            cout<<"Game draw"<<endl;
            break;
        }
    }
    
}

int main()
{
    showboard();
    player_vs_player();
}
