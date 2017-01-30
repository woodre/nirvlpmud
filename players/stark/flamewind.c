#include "/players/feldegast/closed/guild/defines.h"

do_command(str) {
  object target;
  if(TP->query_sp()<30) {
    write("You do not have enough spell points.\n");
  return 1;
  }
  if(!str) {
    target=TP->query_attack();
  }
  else
  target=present(str,environment(this_player()));
  if(!target) {
    write("That target isn't here.\n");
    return 1;
  }
  write("You summon a "+HIR+"wind of flame"+NORM+" to engulf "+target->query_name()+".\n");
  say(TPN+" summons a "+HIR+"wind of flame"+NORM+" to engulf "+target->query_name()+".\n");
  TP->spell_object(target,"flamewind", 10+random(40),20+random(10),"");
  return 1;
}
