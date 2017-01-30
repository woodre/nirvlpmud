#include <ansi.h>
inherit "obj/weapon.c";


reset(arg) {   if(arg) return;    
  set_short(HIW+"A demons tooth"+NORM);
  set_hit_func(this_object());
}
id(str){ return str == "tooth" || str == "demons tooth";  }

long(){    
  write(
"This is a rather long and narrow off white tooth.  It has a very\n"+
"sharp tip and glistens a bit from a layer of saliva that coats it.\n"+
"The thick end is bloody, and small strands of flesh hang from it.\n"+
"This item could be quite valuble to the right person.\n");
}

weapon_class(){     return 13;          }
query_save_flag(){  return 1;           } /* not */
query_value(){      return random(666); }
get(){              return 1;           }
query_weight(){     return 1;           }

int weapon_hit(object x){
  if(666 == random(1000))
  {
    tell_room(environment(x),
      BOLD+BLK+"\n\n\t\t-- EVIL ENGULFS YOU! --\n"+NORM+
      RED+"\t     -- BLOODY CHAOS RAGES ON! --\n\n\n"+NORM);
    if(x->is_npc())
/*       x->heal_self(-50-random(200));   return 66; */ return -666;
    else
      return 6;
  }
  return 0;
}

