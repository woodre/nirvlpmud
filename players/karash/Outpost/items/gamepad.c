
inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: gamepad.c
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

   set_id("gamepad");
   SetMultipleIds( ({ "gamepad", "controller", "pad" }) );
   set_short("A keyboard gamepad");
   set_long(
   "A miniature-looking keyboard made to fit one hand with\n\
programmable keys made for pc gamers.\n");
   set_weight(1);
   set_value(5);
}


