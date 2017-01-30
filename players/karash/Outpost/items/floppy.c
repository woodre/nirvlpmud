
inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: floppy.c
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

   set_id("floppy");
   SetMultipleIds( ({ "floppy", "disk", "floppy disk" }) );
   set_short("A 3.5 inch floppy disk");
   set_long(
   "A 3.5 inch floppy disk with custom-made configuration files for the\n\
owner's favorite pc games.  Never go to a LAN party without it.\n");
   set_weight(1);
   set_value(5);
}


