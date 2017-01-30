#include "/players/fred/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("samson");
set_alias("merchant");
set_race("human");
set_short(BOLD+BLK+"Samson"+NORM+", the merchant");
set_long(
  " Samson is a tall man shrouded in a billowing white cloak. You\n"+
  "can't see his face under the large hood. Perhaps you could 'ask'\n"+
  "him what item he possess.\n");
 
set_level(30);
set_hp(750);
set_al(1000);
set_ac(27);
set_wc(40);
set_aggressive(0);
}




