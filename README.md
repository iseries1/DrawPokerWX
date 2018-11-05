# DrawPokerWX
Draw Poker for Badge WX

The Badge WX unit and the original eBadge have a 128X64 screen that is large enough to display cards on them.

So I had the idea of building a Draw Poker program patterned after a unit I had laying around at home.

The first thing that I needed to do was build a deck of cards to display on the screen. The cards are 24X32 in size so I broke out my paint program and started making some cards.

I then created a Visual Studio C# program to read in the PNG file and convert it to 32 bit encoded data that could be used by the C program on the BadgeWX unit.  So each card takes up 24 words times 53 cards or about 5K bytes of data.

To display the card is just a mater of converting back each pixel bit in each word.

Next I need to build the logic to allow selecting cards to keep and keep track of the winnings.

Mike
