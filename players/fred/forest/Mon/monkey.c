#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object bow;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("monkey");
set_alias("archer");
set_race("creature");
set_short(YEL+"Archer Monkey"+NORM);
set_long(
  " This beast stands about 3 feet tall with dark black fur \n"+
  "that is matted with mud and other debris.  It's eyes are \n"+
  "a faint green and seem to follow your every move.\n");
 
set_level(15);
set_hp(225);
set_al(-500);
set_ac(12);
set_aggressive(1);
set_chat_chance(5);
  load_chat("The monkey glares at you with exposing it's fangs.\n");
  load_chat("The monkey jumps back and forth between the trees.\n");
  bow = clone_object("players/fred/forest/Obj/bow.c");

   move_object(bow, this_object());
   command("wield bow", this_object());
   set_wc(20);
}



