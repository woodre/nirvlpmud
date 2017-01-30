#include "/players/stark/defs.h"

plague_one(str) {
  object target;

  if(!str) {
    target=TP->query_attack();
  }
  else
  target=present(str,environment(this_player()));
  if(!target) {
    write("That target isn't here.\n");
    return 1;
  }

if(target->is_npc()){
write("plague given to "+str);
MOCO("/players/stark/druid/obj/plague_one.c"),target);
return 1;
}
else
write("can't plague players\n");
}
