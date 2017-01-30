#include "../../defs.h"

inherit "/obj/treasure.c";

reset(){
  set_id("bones");
  set_alias("pile of bones");
  set_short("A small pile of bones");
  set_long("A small pile of bones that seem to have come from a fallen skeleton.\n");
  set_weight(3);
  set_value(0);
  call_out("dustme",10);
}

dustme(){
if(environment()){
  tell_object(environment(this_object()),"The bones crumble to dust and fly away on the wind.\n");
  tell_room(environment(this_object()),"The bones crumble to dust and fly away on the wind.\n");
  destruct(this_object());
}
}