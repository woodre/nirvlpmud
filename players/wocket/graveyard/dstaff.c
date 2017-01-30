#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon";

reset(arg){
set_name("staff");
set_short("The "+HIC+"diamond"+NORM+" staff of "+MAG+"Vreeland"+NORM);
set_long("This eight foot staff is the belonging of the Lady Vreeland.  The oak\n"+
"shaft is very sturdy, supporting a huge white-gold diamond covered orb\n"+
"that ornates the top.\n");
set_class(18);
set_type("staff");
set_weight(7);
set_value(3000);
set_hit_func(this_object());
}

weapon_hit(){
int W;
W = random(5);
switch(W){
case 0: say(HIC+"Diamond chips fly everywhere slicing into "+this_player()->query_name()+"'s opponent.\n"+NORM);
       write(HIC+"Diamond chips fly everywhere slicing into your opponent.\n"+NORM);
     return 2;
      break;
case 1: say(HIR+"\n\nFURY LEAPS FROM THE DIAMOND STAFF DESTROYING EVERYTHING.\n\n"+NORM);
    write(HIR+"\n\nFURY LEAPS FROM THE DIAMOND STAFF DESTROYING EVERYTHING.\n\n"+NORM);
    this_player()->add_hit_point(-5);
    return 7;
     break;
case 2: return 0; break;
case 3:  return 0; break;
case 4: return 0; break;
}
}
