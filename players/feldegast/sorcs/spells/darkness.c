#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

reset(){
  spell = "darkness";
  spell_short = BOLD+BLK+"Darkness"+NORM;
  time = 3;
  size = 1;
  spcost = 10;
  hpcost = 0;
  type = "illusion";
}

check_spell(object mage,str){
  if(present("w_darkness",environment(mage))){
    tell_object(mage,"Darkness already fills the room.\n");
    return 0;
}
return 1;
}

cast_spell(object mage,str){
tell_object(mage,"You cast darkness and "+BOLD+BLK+"shadows"+NORM+" fill the room.\n");
mage->remote_say(mage->query_name()+" casts darkness upon the room.\n"+BOLD+BLK+"Shadows"+NORM+" fill every corner.\n",mage);
move_object(clone_object("/players/wocket/mages/obj/darkness_ob.c"),environment(mage));
}
