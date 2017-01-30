
inherit "obj/treasure";
#include <ansi.h>

/******************************************************************************
 * Program: pogo.c
 * Path: /players/karash/Outpost/items
 * Type: treasure
 * Created: July 2014 by Karash
 *
 * Purpose: Commander Keen's trusted pogo stick (from the Commander Keen video game)
 *
 * History:
 *          
 ******************************************************************************/

  
#define tp this_player()->query_name()


reset(arg)  {
  if(arg) return;

   set_id("pogo");
   SetMultipleIds( ({ "pogo", "pogo stick", "stick" }) );
   set_short("A pogo stick");
   set_long(
   "A large 'pogo' stick with strong springs for jumping extra high.\n");
   set_weight(5);
   set_value(250);
}

init()
{  
  add_action("pogo_stick", "pogo");
}


pogo_stick(str)  {

  write("You jump on the pogo stick as high as you can go.\n WHHHHEEEEeeeeEEEEeeeeEEEEeeeeEEEE!\n");
  
  say(tp+" jumps extremely high on a pogo stick.\n WHHHHEEEEeeeeEEEEeeeeEEEEeeeeEEEE!\n");

  return 1;
}

