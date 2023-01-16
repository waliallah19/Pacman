#include<iostream>
#include<windows.h>
using namespace std;
 
void gotoxy(int x,int y);
void erase(int x,int y);
void printPacman(int x, int y);
char getCharAtxy(short int x, short int y);
void printMaze();
void clear(int x, int y, char previous);
void showghost1(int x, int y);
void showghost2(int x, int y);
int score(int);
main()
{
  int points = 0;
  int gx1 = 1;
  int gy1 = 1;
  int gx2 = 7;
  int gy2 = 2;
  bool gameRunning = true;
  int pacmanX = 4;
  int pacmanY = 4;
  printPacman(pacmanX,pacmanY);
  string direction1 = "right";
  string direction2 = "down";
  char previousChar1 = ' ';
  char previousChar2 = ' ';
  system("cls");
  printMaze();
  while(gameRunning == true)
  {
  showghost1(gx1 ,gy1);
  while(true)
  {
    Sleep(100);
    if(direction1 == "right")
    {
      char nextLocation2 = getCharAtxy(gx1 + 1, gy1);
      if(nextLocation2 == '%' || nextLocation2 == '|' ||  nextLocation2 == '#')
      {
        direction1 = "left";
      }	 
      else if (nextLocation2 == ' ' || nextLocation2 == '.')
      {
	clear(gx1, gy1, previousChar1);
        gx1 = gx1 + 1;
	previousChar1 = nextLocation2;
	showghost1(gx1,gy1);
      }  
    }
    if(direction1 == "left")
    {
      char nextLocation2 = getCharAtxy(gx1 - 1, gy1);
      if(nextLocation2 == '%' || nextLocation2 == '|' ||  nextLocation2 == '#')
      {
        direction1 = "right";
      }	 
      else if (nextLocation2 == ' ' || nextLocation2 == '.')
      {
	clear(gx1, gy1, previousChar1);
        gx1 = gx1 - 1;
	previousChar1 = nextLocation2;
	showghost1(gx1,gy1);
      }  
    }
  showghost2(gx2 ,gy2);
    Sleep(100);
    if(direction2 == "down")
    {
      char nextLocation3 = getCharAtxy(gx2, gy2 + 1);
      if(nextLocation3 == '%' || nextLocation3 == '|' ||  nextLocation3 == '#')
      {
        direction2 = "up";
      }	 
      else if (nextLocation3 == ' ' || nextLocation3 == '.')
      {
	clear(gx2, gy2, previousChar2);
        gy2 = gy2 + 1;
	previousChar2 = nextLocation3;
	showghost2(gx2,gy2);
      }  
    }
    if(direction2 == "up")
    {
      char nextLocation3= getCharAtxy(gx2, gy2 - 1);
      if(nextLocation3 == '%' || nextLocation3 == '|' ||  nextLocation3 == '#')
      {
        direction2 = "down";
      }	 
      else if (nextLocation3 == ' ' || nextLocation3 == '.')
      {
	clear(gx2, gy2, previousChar2);
        gy2 = gy2 - 1;
	previousChar2 = nextLocation3;
	showghost2(gx2,gy2);
      }  
    }
   if (GetAsyncKeyState(VK_LEFT))
    {
      char nextLocation = getCharAtxy(pacmanX-1, pacmanY);
      if(nextLocation == ' ')
	{
	  erase(pacmanX,pacmanY);
	  pacmanX = pacmanX-1;
	  printPacman(pacmanX,pacmanY);
        }
      if(nextLocation == '.')
	{
	  erase(pacmanX,pacmanY);
	  pacmanX = pacmanX-1;
	  printPacman(pacmanX,pacmanY);
          points = score(points);
	  gotoxy(1,26);
	  cout<<"Score: "<<points;
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
      if(nextLocation == '.')
	{
	  erase(pacmanX,pacmanY);
	  pacmanX = pacmanX+1;
	  printPacman(pacmanX,pacmanY);
	  gotoxy(1,26);
          points = score(points);
	  cout<<"Score: "<<points;
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
      if(nextLocation == '.')
	{
	  erase(pacmanX,pacmanY);
	  pacmanY = pacmanY-1;
	  printPacman(pacmanX,pacmanY);
          points = score(points);
	  gotoxy(1,26);
	  cout<<"Score: "<<points;
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
      if(nextLocation == '.')
	{
	  erase(pacmanX,pacmanY);
	  pacmanY = pacmanY+1;
	  printPacman(pacmanX,pacmanY);
          points = score(points);
	  gotoxy(1,26);
	  cout<<"Score: "<<points;
        }
     }
   if (GetAsyncKeyState(VK_ESCAPE))
    {
     gameRunning = false;
    }
  Sleep(100);
   }
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
cout<<"########################################################################################" <<endl;
cout<<"||.. ......................................................................  .......  ||" <<endl;
cout<<"||   %%%%%%%%%%%%%%%%%%%%%        .....       %%%%%%%%%%%%%%%%%%%%%    |%|..   %%%%   ||" <<endl;
cout<<"||..           |%|     |%|     |%|.....       |%|               |%|    |%|..    |%|   ||" <<endl;
cout<<"||..           |%|     |%|     |%|.....       |%|               |%|    |%|..    |%|   ||" <<endl;
cout<<"||..           %%%%%%%%%%  . . |%|.....       %%%%%%%%%%%%%%%%%%%%%            %%%%.  ||" <<endl;
cout<<"||..           |%|         . . |%|.....       .....................   |%| ..       .  ||" <<endl;
cout<<"||..           %%%%%%%%%%%%. . |%|.....       %%%%%%%%%%%%%%%%%       |%| ..   %%%%.  ||" <<endl;
cout<<"||..                    |%|.                  |%|..........           |%| ..    |%|.  ||" <<endl;
cout<<"||..      ............. |%|.                  |%|..........|%|            ..    |%|.  ||" <<endl;
cout<<"||..|%|   |%|%%%%%%%|%|.|%|. |%|                 ..........|%|            ..|%| |%|.  ||" <<endl;
cout<<"||..|%|   |%|       |%|..    %%%%%%%%%%%%%%%%%%  ..........|%|             .|%|.      ||" <<endl;
cout<<"||..|%|   |%|       |%|..              .....|%|        %%%%%%%            . |%|.      ||" <<endl; 
cout<<"||..|%|                 .              .....|%|                       |%| ..|%|.      ||" <<endl;
cout<<"||..|%|   %%%%%%%%%%%%%%%%%%           .....|%|%%%%%%%%%%%%%%%        |%| ..|%|%%%%%  ||" <<endl;
cout<<"||...............................................................     |%| ..........  ||" <<endl;
cout<<"||   ............................................................            .......  ||" <<endl;
cout<<"||..|%|   |%|       |%|..    %%%%%%%%%%%%%%%%%%   ..........|%|       |%| ..|%|.      ||" <<endl;
cout<<"||..|%|   |%|       |%|..              .....|%|         %%%%%%%       |%| ..|%|.      ||" <<endl;
cout<<"||..|%|                 .              .....|%|                       |%| ..|%|.      ||" <<endl;
cout<<"||..|%|   %%%%%%%%%%%%%%%%%%%          .....|%|%%%%%%%%%%%%%%%%       |%| ..|%|%%%%%  ||" <<endl;
cout<<"||................................................................    |%| ..........  ||" <<endl;
cout<<"||  ..............................................................           .......  ||" <<endl;
cout<<"########################################################################################" <<endl;
}
void clear(int x, int y, char previous)
{
 gotoxy(x,y);
 cout << previous;
}
void showghost1(int x, int y)
{
  gotoxy(x,y);
  cout<<"G";
}
void showghost2(int x, int y)
{
  gotoxy(x,y);
  cout<<"G";
}
int score(int points)
{
 int p;
 p = points + 1;
 return p;
}