#include<iostream>
#include<windows.h>
using namespace std;
 
void gotoxy(int x,int y);
void erase(int x,int y);
void printPacman(int x, int y);
char getCharAtxy(short int x, short int y);
void printMaze();
void clear(int x, int y, char previous);
void showghost(int x, int y);
main()
{
  int gx = 1;
  int gy = 1;
  string direction = "right";
  char previousChar = ' ';
  int pacmanX = 4;
  int pacmanY = 4;
  bool gameRunning = true;
  system("cls");
  printMaze();
  showghost(gx ,gy);
  while(true)
  {
    Sleep(100);
    if(direction == "right")
    {
      char nextLocation1 = getCharAtxy(gx + 1, gy);
      if(nextLocation1 == '%')
      {
        direction = "left";
      }	 
      else if (nextLocation1 == ' ' || nextLocation1 == '.')
      {
	clear(gx, gy, previousChar);
        gx = gx + 1;
	previousChar = nextLocation1;
	showghost(gx,gy);
      }  
    }
    if(direction == "left")
    {
      char nextLocation1 = getCharAtxy(gx - 1, gy);
      if(nextLocation1 == '%')
      {
        direction = "right";
      }	 
      else if (nextLocation1 == ' ' || nextLocation1 == '.')
      {
	clear(gx, gy, previousChar);
        gx = gx - 1;
	previousChar = nextLocation1;
	showghost(gx,gy);
      }  
    }
  }
  printPacman(pacmanX,pacmanY);
  while(gameRunning)
  {
   if (GetAsyncKeyState(VK_LEFT))
    {
      char nextLocation = getCharAtxy(pacmanX-1, pacmanY);
      if(nextLocation == ' ')
	{
	  erase(pacmanX,pacmanY);
	  pacmanX = pacmanX-1;
	  printPacman(pacmanX,pacmanY);
        }
     }
   if (GetAsyncKeyState(VK_RIGHT))
    {
      char nextLocation = getCharAtxy(pacmanX+1, pacmanY);
      if(nextLocation == ' ')
	{
	  erase(pacmanX,pacmanY);
	  pacmanX = pacmanX+1;
	  printPacman(pacmanX,pacmanY);
	}
     }
   if (GetAsyncKeyState(VK_UP))
    {
      char nextLocation = getCharAtxy(pacmanX, pacmanY-1);
      if(nextLocation == ' ')
	{
	  erase(pacmanX,pacmanY);
	  pacmanY = pacmanY-1;
	  printPacman(pacmanX,pacmanY);
	}
     }
   if (GetAsyncKeyState(VK_DOWN))
    {
      char nextLocation = getCharAtxy(pacmanX, pacmanY+1);
      if(nextLocation == ' ')
	{
	  erase(pacmanX,pacmanY);
	  pacmanY = pacmanY+1;
	  printPacman(pacmanX,pacmanY);
	}
     }
   if (GetAsyncKeyState(VK_ESCAPE))
    {
     gameRunning = false;
    }
  Sleep(200);
   }

}
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates. Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
  CHAR_INFO ci;
  COORD xy = {0, 0};
  SMALL_RECT rect = {x, y, x, y};
  COORD coordBufsize;
  coordBufsize.X= 1;
  coordBufsize.Y= 1;
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void erase(int x, int y)
{
  gotoxy(x, y);
  cout << " ";
}
void printPacman(int x, int y)
{
  gotoxy(x,y);
  cout<<"P";
}
void printMaze()
{
cout << "%%%%%%%%%%"<<endl;
cout << "%        %"<<endl; 
cout << "%        %"<<endl;
cout << "%        %"<<endl;
cout << "%        %"<<endl;
cout << "%        %"<<endl;
cout << "%        %"<<endl;
cout << "%        %"<<endl;
cout << "%        %"<<endl;
cout << "%%%%%%%%%%"<<endl;
}
void clear(int x, int y, char previous)
{
 gotoxy(x,y);
 cout << previous;
}
void showghost(int x, int y)
{
  gotoxy(x,y);
  cout<<"G";
}
