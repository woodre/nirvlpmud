
inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: mouse.c
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

   set_id("mouse");
   SetMultipleIds( ({ "mouse", "controller" }) );
   set_short("A computer mouse");
   set_long(
   "A custom-formed computer mouse with a scroll wheel and many buttons.\n\
All sensitivity settings have been set to maximum.\n");
   set_weight(1);
   set_value(5);
}


