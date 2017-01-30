inherit "/obj/treasure.c";
#include <ansi.h>

reset(){
    set_id("bones");
    set_alias("pile of bones");
    set_short("A small "+BOLD+"pile of bones"+NORM);
    set_long("A small pile of bones that seem to have come from a fallen skeleton.\n");
    set_weight(3);
    set_value(0);
    call_out("dustme",10+random(10));
}

dustme(){
  if(environment()){
    tell_object(environment(this_object()),BOLD+"The bones crumble to dust and fly away on the wind.\n"+NORM);
    tell_room(environment(this_object()),BOLD+"The bones crumble to dust and fly away on the wind.\n"+NORM);
    destruct(this_object());
  }
}
