inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
int counter; 

reset(arg) {
  if (arg) return;
  counter = 150;
  set_heart_beat(1);
}

id(str){ return str == "shadowform_object_zeus"; }
query_value(){ return 0; }
query_weight(){ return 0; }
get(){ return 0; }

heart_beat(){
  if(!environment())
    return;
  if(!environment()->is_npc())
  {
    destruct(this_object());
  }
  else
  {
    counter--;
    if(counter <= 0)
    {
      destruct(environment(this_object()));
      destruct(this_object());
    }
  }
}
