#include "defs.h"

inherit "/obj/treasure.c";

int charges;

void reset(int arg) {
  if(arg) return;
  set_id("skull");
  set_alias("skull of mantuok");
  set_short(HIW+"Skull"+NORM+" of "+HIR+"Mantuok"+NORM);
  set_long(
"The skull of a demon is of important mystical significance.  Mantuok\n"+
"was a prominent captain among the legions of Demonlord Kruarg's forces\n"+
"until he attempted a betrayal.  Now, his skull has been used to\n"+
"harness a fragment of his power for a mortal's use.  To use it,\n"+
"type: mantuok <target>.\n");
  set_value(3500);
  set_weight(2);
  charges=4;
}

void init() {
  add_action("cmd_attack", "mantuok");
}

long(str) {
  ::long(str);
  write("There are "+charges+" charges remaining.\n");
}

int cmd_attack(string str) {
  object targ;
  object shad;
  if(!str) targ=(object)TP->query_attack();
  else targ=present(str,environment(TP));
  if(charges <= 0) {
    notify_fail("The skull's power has already been expended.\n");
    return 0;
  }
  if(!targ) {
    notify_fail("Invalid target.\n");
    return 0;
  }
  if(!living(targ) || (int)targ->is_player()) {
    notify_fail("You cannot use this spell on that.\n");
    return 0;
  }
  if((int)this_player()->valid_attack(targ) == 0) {
    write("Your spell fails.\n");
    return 1;
  }
  if((int)targ->query_cursed()) {
    notify_fail("It is already cursed.\n");
    return 0;
  }
  write("You raise the "+(string)short()+" into the air and bellow:\n"+
        "\t\tIN THE NAME OF MANTUOK I CURSE THEE!\n");
  say(TPN+" raises the "+(string)short()+" into the air and bellows:\n"+
      "\t\tIN THE NAME OF MANTUOK I CURSE THEE!\n");
  tell_room(environment(TP),(string)targ->query_name()+" is cursed.\n");
  shad=clone_object(OBJ_PATH+"skullshad.c");
  shad->start_shadow(targ);
  targ->attacked_by(TP);
  charges--;
  return 1;
}

locker_arg() {
  return charges+"";
}

locker_init(arg) {
  sscanf(arg,"%d",charges);
}
    
generic_object() { return 1; } 

restore_thing(str) {
  restore_object(str);
  return 1;
}

save_thing(str) {
  save_object(str);
  return 1;
}
