#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

int broken;

short(){
string shortdesc;
  shortdesc = "A "+YEL+"Rubber Band"+OFF;
  if(broken == 1){
    shortdesc += " (broken)";
  } else {
    shortdesc += " (strechy)";
  }
  return shortdesc;
}

reset(arg){
  if(arg) return; 
  set_id("rubber band");
  set_long("This is a rubber band.\n");
}

init(){
add_action("shootband","shoot");
add_action("snapband","snap");
add_action("stretchband","stretch");
}

shootband(str){
  if(!str){
    notify_fail("What would you like to shoot?\n");
    return 0;
  }
return 1;
}

snapband(str){
  if(!str){
    notify_fail("What would you like to snap?\n");
    return 0;
  }
breakband("snap");

return 1;
}

strechband(str){
return 1;
}

breakband(str){
  write("You attempt to "+str+" the rubber band but it breaks.\n"+
    "The rubber band snaps back and smacks you in the face.\n"+
    "OUCH that stings.\n");
  say(this_player()->query_name()+" attempts to "+str+" the rubber band but it breaks and hit "+this_player()->query_objective()+"self in the face.\n");
  broken = 1;
}
