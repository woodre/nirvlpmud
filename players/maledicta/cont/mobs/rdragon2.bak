#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
set_name("dragon");
set_alt_name("cont_dragon");
set_race("dragon");
set_short(HIR+"Red "+NORM+RED+"Dragon"+NORM+" [infant]");
set_long(
"This is an infant red dragon. Its body is nearly seven feet\n"+
"long, although most of that is tail.  It has a smallish head\n"+
"with numerous small rows of teeth filling its maw, and small\n"+
"stubs of horns growing from its forehead and sweeping back.\n"+
"It has sharp claws adorning its short arms and legs. It could\n"+
"be very dangerous if harassed.\n");
set_level(10);
set_hp(150);
set_al(-200);
set_wc(20);
set_ac(4);
set_aggressive(0);
set_heart_beat(1);
set_chance(20);
set_spell_dam(15);
set_spell_mess1(
"The infant red dragon bites down on its opponent hard!\n");
set_spell_mess2(
"You feel tiny teeth pierce your flesh as the infant drake bites you!\n");
set_chat_chance (10);
load_chat("The infant dragon curls up and hisses at you.\n");
load_chat("With wide eyes, the infant dragon stares at you.\n");
}


