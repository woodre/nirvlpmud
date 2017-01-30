
inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: modaudio.c
 * Path: /players/karash/Outpost/items
 * Type: treasure
 * Created: September 2014 by Karash
 *
 * Purpose: A prepaid subscription for the audiobook of John Romero's biography
 *          used as a distraction when attacked as Romero the Proud
 *
 * History:
 *          
 ******************************************************************************/

  

reset(arg)  {
  if(arg) return;

   set_id("audiobook");
   SetMultipleIds( ({ "gift card", "masters of doom", "card", "giftcard" }) );
   set_short("A prepaid gift card for the '"+YEL+"Masters of Doom"+NORM+"' audiobook");
   set_long(
   "A prepaid gift card for the audiobook by David Kushner title '"+YEL+"Masters\n\
of Doom"+NORM+": "+CYAN+"How Two Guys Created an Empire and Transformed Pop Culture"+NORM+"', which\n\
is a biography of John Carmack and John Romero.  This audiobook is narrated\n\
by the actor Wil Wheaton.\n");
   set_weight(1);
   set_value(15);
}


