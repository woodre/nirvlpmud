#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object microphone;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("chef");
set_alias("chef");
set_race("human");
set_short("Chef");
set_long(
  "  Chef is the children's best friend at school.  They go to him\n"+
  "with questions and when they need advice.  His answers usually\n"+
  "come in the form of a song that have no bearing on the problem.\n");

add_money(500);
set_level(12);
set_hp(180);
set_al(500);
set_wc(16);
set_ac(9);
set_aggressive(0);
set_chat_chance(8);
  load_chat("Chef says: Hello there Children.\n");
  load_chat("Chef asks: What seems to be the problem children?\n");
  load_chat("Chef breaks into a song: I'm gonna make love to your woman.\n");

	microphone  = clone_object("/players/fred/SP/Obj/micro.c");
      move_object(microphone, this_object());
}


