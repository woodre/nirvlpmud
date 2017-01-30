#include "defs.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("vial");
  set_alias("plague vial");
  set_short("Plague vial");
  set_long(
"This vial contains a super-concentrated dose of one of the plaguelord's\n"+
"poisons.  You may <plague> a monster with it.\n");
  set_weight(1);
  set_value(800);
}

void init() {
  add_action("cmd_plague","plague");
}

int cmd_plague(string str) {
  object targ;
  object poison;
  if(!str) targ=(object)TP->query_attack();
  else targ=present(str,environment(TP));
  if(!targ) {
    notify_fail("Plague what?\n");
    return 0;
  }
  if(targ->is_player()) {
    notify_fail("You may not attack players with this.\n");
    return 0;
  }
  if(present("poison",targ)) {
    notify_fail((string)targ->query_name()+" already has the plague.\n");
    return 0;
  }
  poison=clone_object(OBJ_PATH+"poison2.c");
  poison->set_damage(4+random(4));
  move_object(poison,targ);
  write("You toss the plague vial at "+(string)targ->query_name()+"'s feet.\n"+
        "It shatters, creating a cloud of plague spores.\n");
  say(TPN+" tosses a vial at "+(string)targ->query_name()+"'s feet.  It\n"+
      "shatters, creating a cloud of plague spores.\n");
  targ->attacked_by(TP);
  this_player()->add_weight(-1);
  destruct(this_object());
  return 1;
}
