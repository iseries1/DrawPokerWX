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

unsigned int i;
volatile char cards[6];
volatile char hold[6];
char C[6] = {255, 255, 255, 255, 255, 0};
unsigned long PCNT;
volatile int Cursor;
char Buffer[25];
char Hold[][4] = {"   ", "HLD"};


int main()
{
  unsigned int z;
  
  high(17); // allow code updates
  
  cards[0] = 1;
  cards[1] = 5;
  cards[2] = 32;
  cards[3] = 20;
  cards[4] = 0;
  hold[0] = 1;
  Cursor = 0;
  
  cog_run(&Display, 128);
  
  while(1)
  {
    Input();
      
    pause(250);
    
  }  
}

void Display(void *par)
{
  int i, l;
  int p;
  int cnt;
  
  millis(&PCNT);
  cnt = 0;
  
  SSD1306_init(OLED_CLK, OLED_DAT, OLED_CS, OLED_DC, OLED_RST);
  SSD1306_cls();

  i = Cursor;
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
        SSD1306_drawLine(i * CSPC + 2, LLIN, i * CSPC + 20, LLIN, 1);
        SSD1306_drawLine(i * CSPC + 1, LLIN + 1, i * CSPC + 21, LLIN + 1, 1);
        SSD1306_drawLine(i * CSPC + 2, LLIN + 2, i * CSPC + 20, LLIN + 2, 1);
      }
      else
      {
        SSD1306_drawLine(i * CSPC + 2, LLIN, i * CSPC + 20, LLIN, 0);
        SSD1306_drawLine(i * CSPC + 1, LLIN + 1, i * CSPC + 21, LLIN + 1, 0);
        SSD1306_drawLine(i * CSPC + 2, LLIN + 2, i * CSPC + 20, LLIN + 2, 0);
      }
    }
    for (p=0;p<5;p++)
    {
      ShowCard(p, cards[p]);
    }
    ShowPoints();
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
  sprinti(Buffer, "Points: %d", 0);
  SSD1306_writeSStr(26, 56, Buffer);
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
  
  for (i=0;i<5;i++)
    hold[i] = 0;
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
      Cursor = i;
    }      
  }    
}
  