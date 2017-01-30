#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("dragon");
set_alt_name("cont_dragon");
set_race("dragon");
set_short(HIG+"Emerald "+NORM+GRN+"Dragon"+NORM+" (infant)");
set_long(
" This is a small infant Emerald Dragon. Its body is around six\n"+
"feet in length, and covered with thin translucent green scales.\n"+
"Its head is small and topped with stubby green spikes, with small\n"+
"teeth lining its narrow mouth. Its claws are short, but capable\n"+
"of dealing some damage. It seems afraid.\n");
set_level(10);
set_hp(100);
set_al(0);
set_aggressive(0);
set_wc(13);
set_ac(8);
set_heart_beat(1);
set_chat_chance(10);
load_chat("The infant dragon cringes in fright.\n");
}

query_emerald_dragon(){ return 1; }