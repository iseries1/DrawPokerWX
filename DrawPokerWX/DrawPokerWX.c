/**
 * @brief Let's play Draw Poker
 * @author Michael Burmeister
 * @date November 5, 2018
 * @version 1.0
 * 
*/
#include "DrawPokerWX.h"
#include "simpletools.h"
#include "SSD1306.h"
#include "timer.h"

void ShowCard(char, char);
void Display(void *);
char Buttons(void);
void ShowPoints(void);
void ShowHold(void);
void Input(void);
void Shuffle(void);
char Deal(void);
void Draw(void);
void Winnings(void);
char Royal(void);
char StraightFlush(void);
char Kind(char);
char FullHouse(void);
char Flush(void);
char Straight(void);
char Pairs(void);
char Jacks(void);

#define True 255;
#define False 0;

#define RGB_COUNT 4
#define BTNCL 14
#define BTNCR 15
#define BTNL 13
#define BTNC 12
#define BTNR 11
#define OLED_DAT 21
#define OLED_CLK 20
#define OLED_DC 22
#define OLED_RST 19
#define OLED_CS 18
#define RGB 10

#define BLL 0x20
#define BLC 0x10
#define BLR 0x08
#define BRL 0x04
#define BRC 0x02
#define BRR 0x01

#define CSPC 26
#define LLIN 36

int i;
char Deck[53];
volatile char cards[6];
volatile char hold[6];
char Suits[6];
char Faces[6];
char C[6] = {255, 255, 255, 255, 255, 0};
unsigned long PCNT;
volatile int Cursor;
volatile int Over;
char Buffer[25];
int WV[] = {0, 5, 10, 15, 20, 25, 40, 125, 250, 5000};
char Hold[][5] = {"    ", "HLD "};
char Win[10][16] = {"  Game Over", "Jacks or Better", "2 Pair", "3 of Kind", "Straight", "Flush", "Full House", "4 of Kind", "Staight Flush", "Royal Flush"};
int W;
int Pos;
int Points;


int main()
{
  
  high(17); // allow code updates

  // make deck of cards
  for (i=1;i<53;i++)
    Deck[i] = i;
  
  srand(time(NULL));

  Shuffle();
  
  Cursor = 0;
  
  Points = 100;
  
  cog_run(&Display, 128);
  
  while(1)
  {
    Draw();
    
    Over = 0;
    
    Input();
    
    Points -= 5;
    
    Draw();
    
    Winnings();
    
    Points += WV[W];
    
    pause(500);
    
    Over = 1;
    
    Input();
              
    pause(250);
    
    Shuffle();
  }  
}

void Display(void *par)
{
  int i, j, l;
  int p;
  int cnt;
  
  millis(&PCNT);
  cnt = 0;
  
  SSD1306_init(OLED_CLK, OLED_DAT, OLED_CS, OLED_DC, OLED_RST);
  SSD1306_cls();

  i = Cursor; //Wait to change
  j = Over; //Wait to change
  l = 0;
  while(1)
  {
    cnt += millis(&PCNT); // get how long
    if (cnt > 500) // do every half second
    {
      l = 1 - l;
      cnt -= 500;
      if (l)
      {
        if (i != Cursor)
          i = Cursor;
        if (j != Over)
          j = Over;
        if (j)
          SSD1306_writeSStr(5, 42, Win[W]);
        else
        {
          SSD1306_drawLine(i * CSPC + 2, LLIN, i * CSPC + 20, LLIN, 1);
          SSD1306_drawLine(i * CSPC + 1, LLIN + 1, i * CSPC + 21, LLIN + 1, 1);
          SSD1306_drawLine(i * CSPC + 2, LLIN + 2, i * CSPC + 20, LLIN + 2, 1);
        }
      }
      else
      {
        if (j)
          SSD1306_writeSStr(5, 42, "                ");
        else
        {
          SSD1306_drawLine(i * CSPC + 2, LLIN, i * CSPC + 20, LLIN, 0);
          SSD1306_drawLine(i * CSPC + 1, LLIN + 1, i * CSPC + 21, LLIN + 1, 0);
          SSD1306_drawLine(i * CSPC + 2, LLIN + 2, i * CSPC + 20, LLIN + 2, 0);
        }
      }
    }
    for (p=0;p<5;p++)
    {
      ShowCard(p, cards[p]);
    }
    ShowPoints();
    if (!j)
      ShowHold();
    SSD1306_update();
  }    
}

void ShowCard(char p, char c)
{
  int x, y;
  unsigned int i, z;
  
  if (C[p] == c)
    return;
  C[p] = c;
  
  p = p * CSPC;  //each card is x pixels
  
  for (x=0;x<24;x++)
  {
    z = 1 << 31;
    i = Cards[c][x];
    for (y=0;y<32;y++)
    {
      if (i & z)
        SSD1306_plot(x+p, y, 1);
      else
        SSD1306_plot(x+p, y, 0);
      z = z >> 1;
    }
  }
}

char Buttons()
{
  char sBtns;
  
  input(BTNCR);
  input(BTNCL);
  
  sBtns = 0;
  high(BTNL);
  if (input(BTNCL))
    sBtns = sBtns | BLL;
  if (input(BTNCR))
    sBtns = sBtns | BRL;
  input(BTNL);
  pause(1);
  high(BTNC);
  if (input(BTNCL))
    sBtns = sBtns | BLC;
  if (input(BTNCR))
    sBtns = sBtns | BRC;
  input(BTNC);
  pause(1);
  high(BTNR);
  if (input(BTNCL))
    sBtns = sBtns | BLR;
  if (input(BTNCR))
    sBtns = sBtns | BRR;
  input(BTNR);

  return sBtns;
}

void ShowPoints()
{
  sprinti(Buffer, "Points: %d  ", Points);
  SSD1306_writeSStr(0, 56, Buffer);
  sprinti(Buffer, "+%d ", WV[W]);
  if (W > 0)
    SSD1306_writeSStr(100, 56, Buffer);
  else
    SSD1306_writeSStr(90, 56, "    ");
}

void ShowHold()
{
  int i;
  
  for (i=0;i<6;i++)
  {
    SSD1306_writeSStr(i * CSPC, 42, Hold[hold[i]]);
  }
}

void Input()
{
  int i, j;
  
  Cursor = 0;
  i = 0;
  
  while (1)
  {
    if (j != Buttons())
    {
      j = Buttons();
      if (j == BLL)
      {
        if (--i < 0)
          i = 4;
      }
      if (j == BLC)
      {
        hold[Cursor] = 1 - hold[Cursor];
      }
      if (j == BLR)
      {
        if (++i > 4)
          i = 0;
      }
      if (j == BRC)
      {
        while (j == Buttons());
        return;
      }        
      Cursor = i;
    }      
  }    
}

void Shuffle()
{
  int i;
  int j;
  char v;
  
  for (i=1;i<53;i++)
  {
    j = rand() % 52 + 1;
    v = Deck[j];
    Deck[j] = Deck[i];
    Deck[i] = v;
  }
  Pos = 1;    
}

char Deal()
{
  if (Pos > 52)
    return 0;
  return Deck[Pos++];
}

void Draw()
{
  int i = 0;
  
  for (i=0;i<5;i++)
  {
    if (hold[i] == 0)
      cards[i] = Deal();
    else
      hold[i] = 0;
  }    
}

void Winnings()
{
  int i;
  
  for (i=0;i<5;i++)
  {
    Suits[i] = (cards[i] - 1) % 4;
    Faces[i] = (cards[i] - 1) / 4;
    if (Faces[i] == 0)
      Faces[i] = 13;
//    printi("%d (%d/%d)\n", cards[i], Suits[i], Faces[i]);
  }
//  printi("\n");
  W = 9;
  
  if (Royal())
    return;

  W--;
  if (StraightFlush())
    return;

  W--;
  if (Kind(4))
    return;

  W--;
  if (FullHouse())
    return;

  W--;
  if (Flush())
    return;

  W--;
  if (Straight())
    return;

  W--;
  if (Kind(3))
    return;

  W--;
  if (Pairs())
    return;

  W--;
  if (Jacks())
    return;

  W--;      
}
  
char Royal()
{
  int i;
  
  if (StraightFlush())
  {
    for (i=0;i<5;i++)
      if (Faces[i] == 13)
        return True;
  }
  return False;
}

char StraightFlush()
{
  if (Straight())
    if (Flush())
      return True;
  return False;
}

char Kind(char k)
{
  int i, j;
  int y = 0;
  
  for (i=0;i<3;i++)
  {
    y = 0;
    for (j=i;j<5;j++)
      if (Faces[i] == Faces[j])
        y++;
    if (y == k)
      return True;
  }
  return False;
}

char FullHouse()
{
  int i;
  int y = 0;
  int j = 0;
  
  for (i=0;i<5;i++)
  {
    if (Faces[4] == Faces[i])
      y++;
    else
      j = Faces[i];
  }
  
  if (y < 2)
    return False;
    
  for (i=0;i<5;i++)
    if (Faces[i] == j)
      y++;
  
  if (y == 5)
    return True;
  
  return False;
}

char Flush()
{
  int i;
  
  for (i=0;i<4;i++)
    if (Suits[i] != Suits[4])
      return False;
  return True;
}    

char Straight()
{
  int i, j;
  char u;
  int y = 0;
  
  // create binary
  for (i=0;i<5;i++)
    y = y | (1 << Faces[i]);

  while ((y & 1) == 0)
    y = y >> 1;
  
  if (y == 0x1f)
    return True;
  
  y = 0;
  
  for (i=0;i<5;i++)
    if (Faces[i] == 13)
      y = y | 1;
    else
      y = y | (1 << Faces[i]);
  
  while ((y & 1) == 0)
    y = y >> 1;
  
  if (y == 0x1f)
    return True;
   
   return False;
}

char Pairs()
{
  int i,j;
  int y = 0;
  
  for (i=0;i<4;i++)
  {
    for (j=i + 1;j<5;j++)
      if (Faces[i] == Faces[j])
        y++;
  }
  if (y == 2)
    return True;
  return False;
}

char Jacks()
{
  int i,j;
  int y;
  
  for (i=0;i<5;i++)
  {
    y = 0;
    for (j=i;j<5;j++)
      if (Faces[i] == Faces[j])
        if (Faces[i] > 9)
          y++;
    
    if (y == 2)
      return True;
  }
  return False;
}
