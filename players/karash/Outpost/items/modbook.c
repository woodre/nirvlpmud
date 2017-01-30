
inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: modbook.c
 * Path: /players/karash/Outpost/items
 * Type: treasure
 * Created: September 2014 by Karash
 *
 * Purpose: An autographed copy of John Romero's biography used as a distraction
 *          when attacked as Romero the Proud
 *
 * History:
 *          
 ******************************************************************************/

  

reset(arg)  {
  if(arg) return;

   set_id("book");
   SetMultipleIds( ({ "paperback", "masters of doom", "paperback book" }) );
   set_short("An autographed paperback book titled '"+YEL+"Masters of Doom"+NORM+"'");
   set_long(
   "A paperback book by David Kushner titled '"+YEL+"Masters of Doom"+NORM+": "+CYAN+"How Two Guys\n\
Created an Empire and Transformed Pop Culture"+NORM+"', which is a biography of\n\
John Carmack and John Romero.  The inside cover is autographed by John Romero.\n");
   set_weight(1);
   set_value(15);
}


