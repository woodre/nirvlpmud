#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("viper");
set_alt_name("snake");
set_race("serpent");
set_short("A viper");
set_long(
  "  A small serpent maybe the size of your arm if it is lucky.  The snake\n"+
  "cowers in fear as you approach it.  It is just trying to survive to make\n"+
  "through another day.\n");
 
set_level(15);
set_hp(250);
set_al(0);
set_wc(20);
set_ac(12);
set_aggressive(0);
set_chat_chance(2);
  load_chat("The viper slithers away to try and get away from you.\n");

}

