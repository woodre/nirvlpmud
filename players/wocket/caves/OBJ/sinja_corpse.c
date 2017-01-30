#include "/players/wocket/closed/ansi.h"
inherit "/obj/corpse.c";

reset(arg){
  set_name(HIB+"Sinja"+NORM);
  set_corpse_level(40);
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
if(!this_player()->query_weapon()){
  write("You do not have a weapon to cut into the corpse with.\n");
  return 1;
}
wep = this_player()->query_weapon();
  if(wep->query_bloodcount()){
    write("You cut deep into the Sinja's corpse revealing it's heart.\n");
    say(this_player()->query_name()+" cuts deep into the Sinja's corpse revealing it's heart.\n");
    move_object(clone_object("/players/wocket/caves/OBJ/sinja_heart.c"),this_object());
    destruct(this_object());
    return 1;
   }
write("As you try to cut into the corpse your weapon SHATTERS!.\n");
wep->weapon_breaks();
return 1;
}
