#include "/players/fred/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("joe");
set_race("human");
set_short(BOLD+GRN+"Joe"+NORM+", the shopkeeper");
set_long(
  " Joe is an older man with a gray beard. He stands patiently\n"+
  "waiting for you to decide if you would like anything. His only\n"+
  "goal in life is to serve others.\n");
 
set_level(30);
set_hp(750);
set_al(1000);
set_ac(27);
set_wc(40);
set_aggressive(0);
}




