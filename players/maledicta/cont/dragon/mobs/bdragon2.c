#define WAR "/players/maledicta/cont/daemon"
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
bdelay = 0;
set_name("dragon");
set_alt_name("cont_dragon");
set_race("dragon");
set_short(HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" [infant]");
set_long(
"  This is an infant blue dragon. It is only about 5 feet\n"+
"long and gives little idea as to the menace it will pose\n"+
"later in life. It has short claws and tiny teeth that can\n"+
"still be very dangerous.\n");
set_level(3);
set_hp(45);
set_al(0);
set_wc(8);
set_ac(2);

set_a_chat_chance(25);
  load_a_chat("The little infant dragon hisses loudly in fear.\n");
  load_a_chat("The infant attempts to slither away.\n");
}

