#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";
int bugs;

reset(arg){
  ::reset();
  if(arg) return;
  set_name("bugs");
  set_alias("bug");
  set_short("A group of small bugs");
  set_long("There are tons of little bugs that cover the ground.  All\n"+
    "different sizes and colors.  It would be almost impossible for\n"+
    "someone to kill them if they didn't 'step on' them.\n");
  set_level(1);
  set_hp(10);
  set_ac(100000);
  set_wc(0);
  bugs = random(10);
}

init(){
  ::init();
  add_action("step","step");
}

step(str){
  if(str != "on bugs"){
    notify_fail("What would you like to step on?\n");
    return 0;
  }
bugs--;
write("You step on some bugs.\n"+HIG+"Guts ooze out from underneath your foot.\n"+OFF);
this_player()->remote_say(this_player()->query_name()+" steps on some bugs.\n");
this_player()->add_exp(50);
if(bugs == 0){
write("You have squashed all the bugs.\n");
destruct(this_object());
}
return 1;
}
