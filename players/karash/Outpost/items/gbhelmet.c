inherit "obj/armor";
#include <ansi.h>

/******************************************************************************
 * Program: gbhelmet.c
 * Path: /players/karash/Outpost/items
 * Type: armor - helmet
 * Created: September 2014 by Karash
 *
 * Purpose: Commander Keen's trusty Green Bay helmet (from the Commander Keen video game)
 *
 * History:
 *          
 ******************************************************************************/


reset(arg){
   ::reset(arg);

   set_id("helmet");
   set_short("An old "+HIY+"Green"+NORM+GRN+" Bay"+NORM+HIY+" Packers"+NORM+" helmet");
   SetMultipleIds( ({ "packers helmet", "helm", "green bay packers helmet" }) );
   set_long("Commander Keen's trusty old "+HIY+"Green"+NORM+GRN+" Bay"+NORM+HIY+" Packers"+NORM+" helmet, which is full of\n\
scratches and missing a face guard.\n");
   set_type("helmet");
   set_ac(1);
   set_weight(2);
   set_value(200);
}
