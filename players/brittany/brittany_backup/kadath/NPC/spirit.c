#include "/players/vertebraker/define.h"
inherit MONSTER
reset(arg) {
object ob;
  if(arg) return;
  ::reset(arg);
  set_name("spirit");
  set_short("A moaning spirit");
  set_long(
"  A forever changing mass of formless chaos -\n"+
"this moaning spirit is the result of a dead soul\n"+
"spawned from the eternity of Hell.\n");
  set_race("undead");
  set_a_chat_chance(10);
  load_a_chat("The spirit wisps right through its foe.\n");
   load_a_chat("The spirit moans . . .\n");
  load_a_chat("The spirit growls . . .\n");
  set_hp(50+random(50));
  set_level(5);
  set_ac(3+random(6));
ob=clone_object("/players/brittany/kadath/OBJ/dagger.c");
move_object(ob,this_object());
  init_command("wield dagger");
  set_wc(5+random(10));
  }
