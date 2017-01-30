#include "def.h"
inherit "obj/monster";

reset(arg) {
  ::reset();
  set_dead_ob(this_object());
}
monster_died(ob) {
  if(!random(3)) {
    move_object(clone_object(PATH+"Npc/parasite.c"),ob);
  tell_room(environment(ob),RED+"A gore covered parasite bursts forth from the dead man's skull!\n"+NORM);
  }
  else
    say(name+"'s skull bursts open as a gore covered arachnid screams in\n"+
         "it's death throes.\n");
}
