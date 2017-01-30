inherit "/obj/monster";
#include "/players/softly/closed/ansi.h"

reset(arg){
  move_object(clone_object("/players/softly/newbie/obj/coldfire.c"),this_object());   ::reset(arg);
  if(arg) return;

  set_name("firefly");
  set_race("insect");
  set_alias("bug");
  set_short("Lightning" + HIY + " Bug"+NORM);
  set_long("A firefly flits up and away, it's cool flame blinking.\n");
  set_level(1);
  set_hp(15);
  set_al(0);
  set_wc(5);
  set_ac(3);
  set_aggressive(0);
  set_chat_chance (1);
  load_chat("blink ....         blink ....\n");
  load_chat("The lightning bug disappears behind a leaf..\n");
}






