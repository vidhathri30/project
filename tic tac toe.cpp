#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<MMsystem.h>
#include<random>
#include<ctime>
#include<math.h>
#include<ios>
#include<iomanip>
using namespace std;

char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
       void game_board(){

           cout<<"BEST OF LUCK :):)";
             cout<<endl;
           cout<<endl;
cout<< "                      "<< "   "<<"    |   "<<"    |   "<<endl;
cout<< "                      "<<  "   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
cout<< "                      "<<  "   "<<"    |   "<<"    |   "<<endl;
cout<< "                      "<<  "-----------------------"<<endl;
cout<< "                      "<<  "   "<<"    |   "<<"    |   "<<endl;
cout<< "                      "<<  "   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
cout<< "                      "<<  "   "<<"    |   "<<"    |   "<<endl;
cout<< "                      "<<  "-----------------------"<<endl;
cout<< "                      "<<  "   "<<"    |   "<<"    |   "<<endl;
cout<< "                      "<<  "   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;
cout<< "                      "<<  "   "<<"    |   "<<"    |   "<<endl;
cout<<endl;
cout<<"                    **-**-TIC-**-TAC-**-TOE-**-**";
cout<<endl;
cout<<endl;
}
void x_player_choice(){
while(true){
    cout<<"select your postion from 1-9:";
    int choice;
    cin>>choice;
    choice--;
    if(choice<0 || choice >8){

        cout<<"please select your choice from 1-9."<<endl;
         }
         else if(board[choice] != ' '){
            cout<<"please select an empty position"<<endl;
         }
         else{
            board[choice]='X';
            break;
         }
}

}
void o_player_choice(){
while(true){
    cout<<"select your postion from 1-9:";
    int choice;
    cin>>choice;
    choice--;
    if(choice<0 || choice >8){

        cout<<"please select your choice from 1-9."<<endl;
         }
         else if(board[choice] != ' '){
            cout<<"please select an empty position"<<endl;
         }
         else{
            board[choice]='O';
            break;
         }
}

}
void computer_choice(){

srand(time(0));
int choice;
do{
    choice=rand()%10;
}while(board[choice] !=' ');
board[choice]='O';

}
int count_board(char symbol){
int total=0;
for(int i=0;i<9;i++){
    if(board[i]==symbol)
        total +=1;
}
return total;
}
char check_winner(){
    //to check winner in row
if(board[0]==board[1] && board[1]==board[2] && board[0] != ' ')
    return board[0];
if(board[3]== board[4] && board[4] == board[5] && board[3] !=' ')
    return board[3];
if(board[6]== board[7] && board[7] == board[8] && board[6] !=' ')
    return board[6];
    //to check winner in column
    if(board[0]==board[3] && board[3]==board[6] && board[0] != ' ')
    return board[0];
if(board[1]== board[4] && board[4] == board[7] && board[1] !=' ')
    return board[1];
if(board[2]== board[5] && board[5] == board[8] && board[2] !=' ')
    return board[2];
    //checking winner in diagonal
     if(board[0]==board[4] && board[4]==board[8] && board[0] != ' ')
    return board[0];
if(board[2]== board[4] && board[4] == board[6] && board[2] !=' ')
    return board[2];
if(count_board('X')+ count_board('O')<9)
    return 'C';
else
    return 'D';
}
void computer_vs_player(){
    string player_name;
    cout<<"enter your name: ";
    cin>>player_name;
    while(true){
        system("cls");
        game_board();
        if(count_board('X')== count_board('O')){
            cout<<player_name<<"s turn."<<endl;
            x_player_choice();
        }
        else{
            computer_choice();
        }
        char winner=check_winner();
        if(winner=='X'){
            system("cls");
            game_board();
            cout<<"HURRAYYYY!!!!:)"<< player_name<<" WON THE GAME."<<endl;
            break;
        }
        else if(winner == 'O'){
            system("cls");
            game_board();
            cout<<"HURRAYYYY!!!!:)"<< "COMPUTER WON THE GAME."<<endl;
            break;
        }
        else if(winner=='D'){
            cout<<"SORRYYYY!! GAME IS DRAW :|"<<endl;
            break;
        }
    }

}
void player_vs_player(){
 string  player_name_1, player_name_2;
 cout<<"ENTER FIRST PLAYER NAME:";
 cin>>player_name_1;
  cout<<"ENTER SECOND PLAYER NAME:";
 cin>>player_name_2;
 while(true){
    system("cls");
    game_board();
    if(count_board('X') == count_board('O')){
        cout<<player_name_1<<" 's turns."<<endl;
         x_player_choice();

    }
    else{
        cout<<player_name_2<<"s turns."<<endl;
         o_player_choice();
    }
    char winner = check_winner();
    if(winner == 'X'){
    system("cls");
    game_board();
    cout<<"HURRAYYYY!!! :)  "<<player_name_1<<"  WON THE GAME.."<<endl;
      cout<<"SADDDDD!!!!! :(  "<<player_name_2<<"  LOST THE GAME.."<<endl;
    cout<<"BETTER TRY NEXT TIME^_^";
    cout<<endl;
    break;
 }
 else if (winner =='O'){
    system("cls");
    game_board();
    cout<<"HURRAYYYY!!! :) "<<player_name_2<<"  WON THE GAME.."<<endl;
    cout<<"SADDDDDDD!!! :( "<<player_name_1<<" LOST THE GAME.."<<endl;
     cout<<"BETTER TRY NEXT TIME^_^";
     cout<<endl;
     cout<<endl;
    break;
 }
 else if(winner == 'D'){
    cout<<"GAME IS DRAW...."<<endl;
 }
}

}
int quitnumber;
void quit(){
cout<<"ARE YOU READY TO QUIT?? (if yes please enter 5)"<<endl;
cin>>quitnumber;
if(quitnumber==5){
}
}
int main(){

system("COLOR 80");

cout << "                                    *** W E L C O M E ***"<<endl;
cout << endl ;
cout << "       *-*-*- RULES OF THE GAME -*-*-* "<< endl ;
cout << endl ;
int col_width(10);
cout<<right;
cout <<setw(5)<<"1)." << setw(col_width)<<"Play occurs on a 3 by 3 grid of 9 squares .";
      cout<<endl ;
cout <<setw(5)<<"2)."<< setw(col_width) <<"Two players take turns marking empty squares , the first marking X's ,the second O's ." ;
      cout<<endl ;
cout <<setw(5)<<"3)."<< setw(col_width) <<"A row is any three squares on the grid,adjacent diagonally,vertically or horizontally." ;
       cout<<endl ;
cout <<setw(5)<<"4)."<< setw(col_width)<<"If one player places three of the same marks in a row , the player wins .";
       cout<<endl ;
cout <<setw(5)<<"5)."<< setw(col_width)<<"If the spaces are all filled and there is no winner , the game ends in a row .";
       cout<<endl ;
cout<<endl;
cout<<endl;
cout<<endl;
cout<<"               "<<":)*** TIC-------TAC-------TOE :)***"<<endl;
cout<<endl;
 int number;
       cout<<"                 1).COMPUTER_VS_PLAYER"<<endl;
       cout<<"                 2).PLAYER_VS_PLAYER"<<endl;
       cout<<"                 3).TO QUIT GAME"<<endl;
       cout<<endl;
       cout<<"                " <<"PLEASE SELECT EITHER OF 1,2,3::"<<endl;
       cin>>number;
      switch(number){

      case 2:
        player_vs_player();
        break;
      case 1:
           computer_vs_player();
           break;
      case 3:
          quit();
          break;

    }
    //c++ graphics---
    initwindow(800,500);
setbkcolor(9);
cleardevice();
settextstyle(2,0,18);
setcolor(1);
outtextxy(250,150,"THANK YOU");
settextstyle(2,0,19);
setcolor(5);
outtextxy(220,230,"TIC-TAC-TOE");
setcolor(14);
settextstyle(4,3,18);
outtextxy(450,330,":)");
outtextxy(700,200,":)");
outtextxy(200,200,":)");
settextstyle(4,0,11);
setcolor(4);
outtextxy(250,480,"COPYRIGHTS ARE NOT ALLOWED@VAP");
setlinestyle(SOLID_LINE,0,3);
readimagefile("4774982.jpg",350,10,500,150);

getch();
closegraph();
return 0;
}
