#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

reset(){
  spell = "light";
  spell_short = HIY+"Light"+NORM;
  time = 3;
  size = 1;
  spcost = 10;
  hpcost = 0;
  type = "illusion";
}

check_spell(object mage,string str){
if(present("w_light",environment(mage))){
  tell_object(mage,"Light already fills this room.\n");
  return 0;
}
return 1;
}

cast_spell(object mage,str){
tell_object(mage,"You cast light and the room "+HIY+"glows"+NORM+" with brilliance.\n");
mage->remote_say(mage->query_name()+"casts light upon the room.\nThe room "+HIY+"glows"+NORM+".\n",mage);
move_object(clone_object("/players/wocket/mages/obj/light_ob.c"),environment(mage));
}
