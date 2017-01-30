#include <ansi.h>
#include "defs.h"

inherit CMDBASE;

#define skill previous_object()->query_skill("telekinesis")

main(str){
  object what;

  skill_type = "telekinesis";
  if(USER->query_ghost()) return 0;
  if(skill_check(1)){ return 1; }
  if(cp_check(10)){ return 1;}
  
  if(!str) return 0;
  what = present(lower_case(str), environment(USER));
  if(!what) {
    write("You concentrate on "+str+", but can't locate it.\n");
    return 1;
  }
  
  if(previous_object()->query_carry_obj()) {
    write("You are already concentrating on the "+PO->query_carry_obj()->short()+".\n");
    return 1;
  }
  if(what->query_weight() > skill || !call_other(what, "get")) {
    write("You concentrate on the "+str+", but your concentration is too weak.\n");
    return 1;
  }
  write("You extend your hand towards the "+str+" and close your eyes.\n"+
    "The "+str+" raises from the ground and you pull it towards you.\n");
  say(NAME(USER)+" closes "+POS+" eyes and points toward the "+str+".\n"+
    "The "+str+" raises from the ground and floats to "+NAME(USER)+".\n");
  move_object(what, this_player());
  PO->set_carry_obj(what);
  PO->set_carry_obj_name(str);
  return 1;
}
