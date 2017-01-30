#include "/players/jareel/ansi.h"
inherit "/obj/weapon";

reset(arg){
    if(arg) return;
    ::reset(arg);

set_alt_name("maul");
set_alias("maul");
set_id("dagger");

set_name(HIK+"Maul"+NORM+" of "+HIK+"Darkness"+NORM);

set_long("This finely crafted razor sharp dagger drains\n"+
                 "all the light from the room.  Its hilt fits perfectly\n"+
                 "in your grasp.\n");
set_class(18);
    set_light(-1);
    set_type("club");
    set_weight(3);
    set_value(3000);
    set_hit_func(this_object());
}
weapon_hit(ob){
  int pain;
  object me;
  me = wielded_by;
  if(!me) me = environment();
  if(!me) return;
  if(!living(me)) return;
  if(!ob) return;
pain = random(3);
              if(pain==2){
write(BOLD+me->query_name()+"'s Maul unleashes . . . .\n\n"+
         "                "+HIK+"D  A  R  K  N  E  S  S  !  !\n\n"+NORM);
say(BOLD+me->query_name()+"'s Maul unleashes . . . .\n\n"+
         "                "+HIK+"D  A  R  K  N  E  S  S  !  !\n\n"+NORM);
return 6;
}
}
