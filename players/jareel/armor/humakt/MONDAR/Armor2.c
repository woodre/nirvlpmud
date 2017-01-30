inherit "/obj/armor.c";
#include "/players/jareel/define.h"

object ob;

  reset(arg) {
    ::reset(arg);

  set_name("death armor");
  set_type("armor");
  set_ac(4);
  set_weight(3);
 
  set_short("Iron "+HIK+"armor"+NORM+" of death");
  set_long(
           "The armor of death are a dull grey with two\n"+
           "inch protruding spikes from all across the chest.\n"+
           "The small spikes seem like they would pack quite a\n"+
           "wall up if they were to be hit by someone.\n");
  }

  do_special(owner) {
    int i;
      i = random(10);
        if (!ATT || i != 1)
      return 0;
        if(ATT->is_npc())
          ATT->heal_self(-(random(3)));
        else
          ATT->hit_player(random(3), "other|evil");
            tell_room(environment(USER),
            CAP(ATT->query_name())+" is pierced by the armors death aura.\n\n"+
            ""+ATT->query_name()+" looks wounded.\n");
        return 0;
  }
