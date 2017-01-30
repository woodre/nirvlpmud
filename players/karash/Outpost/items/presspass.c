
inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: presspass.c
 * Path: /players/karash/Outpost/items
 * Type: treasure
 * Created: July 2014 by Karash
 *
 * Purpose: Insignificant Fanboy Item
 *
 * History:
 *          
 ******************************************************************************/

  



reset(arg)  {
  if(arg) return;

   set_id("presspass");
   SetMultipleIds( ({ "presspass", "pass", "press pass" }) );
   set_short("A press pass");
   set_long(
   "A laminated ID card attached to a lanyard with a graphic\n\
that reads PC Gamer magazine.\n");
   set_weight(1);
   set_value(5);
}


