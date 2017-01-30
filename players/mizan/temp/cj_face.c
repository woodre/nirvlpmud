#include <ansi.h>

inherit "/obj/armor";

void reset(int x){
  ::reset(x);
  if(x) return;
  
  set_id("face of cyberjesus");
  set_alias("face");
  set_weight(1);
  set_short("the face of "+HIK+"CyberJesus"+NORM);
  
  set_type("helmet");
  set_ac(1);
  
  set_long("\
This is the human part of "+HIK+"CyberJesus"+NORM+" -- the face.\n"+
"There is a black hole in the middle of the eyes from which cross\n\
shaped rockets will fire when you are struck in combat.\n"+
"You must be wearing the face for it to have an effect.\n");
  set_params("other|laser", 1, 0, "do_special");
}

int do_special(object owner){
  if(!random(5)){
    if(owner->query_attack()){
      tell_room(environment(owner), "\n\
A cross-shaped rocket fires from "+short()+"!\n\
\n\t"+RED+"---|-------\n\n"+NORM);
      owner->query_attack()->hit_player(10+random(10), "other|laser");
    }
  }
}
