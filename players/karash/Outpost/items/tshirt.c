inherit "obj/armor";
#include <ansi.h>

/******************************************************************************
 * Program: tshirt.c
 * Path: /players/karash/Outpost/items
 * Type: armor - chest
 * Created: September 2014 by Karash
 *
 * Purpose: Commander Keen's favorite tshirt (from the Commander Keen video game)
 *
 * History:
 *          
 ******************************************************************************/


reset(arg){
   ::reset(arg);

   set_id("tshirt");
   set_short("A "+MAG+"purple t-shirt"+NORM);
   SetMultipleIds( ({ "shirt", "t-shirt" }) );
   set_long("Commander Keen's "+MAG+"purple t-shirt"+NORM+" with the words '"+YEL+"Goodbye Galaxy!"+NORM+"'\n");
   set_type("chest");
   set_ac(0);
   set_weight(1);
   set_value(100);
}
