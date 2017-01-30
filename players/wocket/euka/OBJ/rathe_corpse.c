#include "/players/wocket/closed/ansi.h"
#include "../Def.h"
inherit "/obj/corpse.c";
int cutup;
long(){
  write("This is the dead body of a "+HIR+"rathe"+OFF+".\n"+
    "It looks like you might be able to cut into it.\n");
}

reset(arg){
  set_name(HIR+"rathe"+OFF);
  set_corpse_level(19);
}

init(){
  add_action("cutme","cut");
    add_action("cutme","carve");
}

cutme(string str){
object wep;
  if(!str || str != "corpse"){
    notify_fail("Cut what?\n");
    return 0;
}
if(cutup == 1){
  write("The rathe's heart has already been cut from it.\n");
  return 1;
}
if(!this_player()->query_weapon()){
  write("You do not have a weapon to cut into the corpse with.\n");
  return 1;
}
  write("You cut deep into the rathe's corpse revealing its heart.\n");
  say(TPN+" cuts deep into the rathe's corpse revealing its heart.\n");
  move_object(clone_object(EPATH+"OBJ/rathe_heart.c"),this_object());
  cutup = 1;
return 1;
}
