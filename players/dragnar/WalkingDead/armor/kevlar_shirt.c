inherit "obj/armor";

#include <ansi.h>
#include "../defs.h"

reset(arg){
   ::reset(arg);
	set_short("Kevlar Shirt with neckguard");
  set_long(
"A black kelvar chained shirt that has very strong, lightweight, thick \n\
metal links to make a hard protective barrier from any penetration to \n\
your body. A neck guard is at the top of the piece of armor made of solid \n\
plate metal. "+HIR+"Blood"+NORM+" stains are all over this metal and have just made the\n\
armor a horrific sight to anyone who might glance upon it.\n\
There is a small inscription stamped on the inside you could "+HIG+"read"+NORM+".\n");
   set_ac(4);
   set_weight(2);
   set_value(2500);
   set_name("kevlar shirt");
   SetMultipleIds( ({ "kevlar","shirt","kevlar shirt with neckguard", "walkerobj" }) );
   set_type("armor");
}

void init() 
{
  ::init();
  add_action("cmd_read", "read"); 
}

status cmd_read(string arg) {
  if(!id(arg) && arg != "inscription")
    return 0;
  tell_object(this_player(),
    "Manufactured by "+HIBLK+"Dragnar"+NORM+" under license from "+GRY+"Silverpaw.\n"+NORM);
  return 1;  
}

do_special( owner ) {
  int tot_stats, ret;
   
  if( owner ) {
    tot_stats =  owner->query_total_stats();
     
     /** ~ 20% chance for player with maxed stats **/     
    if( random(1500) < tot_stats ) {
      tell_object(owner,  HIBLK+"\tThe Kevlar Shirt vibrates slightly as it absorbs damage.\n"+NORM);
      tell_room(environment(owner), 
        HIBLK+owner->query_name()+"'s Kevlar Shirt vibrates the air around them.\n"+NORM
       , ({ owner }) );
      switch( tot_stats ) {
        case 0..100:
          ret = 0;
          break;
        case 101..150:
          ret = 1;
          break;
        case 151..200:
          ret = 1 + random(2);
          break;
        case 201..225:
          ret = 2 + random(3);
          break;
        case 226..250:
          ret = 2 + random(4);
          break;
        case 251..275:
          ret = 3 + random(5);
          break;
        case 276..1000:
          ret = 3 + random(6);
          break;
        default:
          ret = 0;
          break;
      }
      return ret;
    }
  }
}

query_walker_value() { return TIER_4_VALUE + random ( TIER_4_RAND ); }