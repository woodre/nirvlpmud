#include "/players/wocket/closed/ansi.h"
#include "/players/stark/cmd/_iwho.h"
inherit "/players/wocket/std/wiztell.c";

reset(arg){
  if(arg) return;
  owner = "stark";
  cap_owner = "Stark";
  color = BOLD+BLK;
  extra_look = "Stark's wings stretch out behind him";
}
init(){
::init();
add_action("cmd_idlers","iwho");
}
