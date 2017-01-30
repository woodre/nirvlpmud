
inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: spaceorb.c
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

   set_id("spaceorb");
   SetMultipleIds( ({ "spaceorb", "360", "orb", "controller" }) );
   set_short("A SpaceOrb 360");
   set_long(
   "An advanced game controller with a rubber orb attached for controlling\n\
your avatar a full 360 degrees.\n");
   set_weight(1);
   set_value(5);
}


