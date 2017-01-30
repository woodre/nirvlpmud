#include "/players/wocket/closed/ansi.h"
inherit "/obj/corpse.c";
int removed;
int AMOUNT;
reset(arg){
  set_name("deer");
  set_corpse_level(40);
  AMOUNT = 1;
}

init(){
    add_action("cutme","cut");
    add_action("cutme","carve");
}

cutme(string str){
object wep;
  if(!str || str != "corpse"){
    notify_fail("What would you like to carve?\n");
    return 0;
}
if(!this_player()->query_weapon()){
  write("You do not have a weapon to cut into the corpse with.\n");
  return 1;
}
if(removed >= AMOUNT){
   write("There is not enough meat on this corpse to crave from.\n");
   return 1;
}
write("You cut out a chunk of deer meat from the corpse.\n");
say(this_player()->query_name()+" cuts out a chunk of deer meat from the corpse.\n");
removed++;
move_object(clone_object("/players/wocket/f_forest/OBJ/deermeat.c"),this_player());
return 1;
 }

long(){ 
  write("This is the corpse of a deer.  There is meat all over it.\n"+
        "Perhaps one should try to 'carve' some off of it.\n");
  return 1;
}

set_ammount(i){ AMOUNT = i; }