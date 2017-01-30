#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("snotling");
  set_alias("goblin");
  set_short("A"+HIG+ " snotling"+NORM);
  set_long("The snotling is the lowest in goblinoid society. Basically child like\n\
in mentality and not lacking in the cruel nature of children.\n");
  set_gender("male");
  set_race("snotling");
  set_level(7);
  set_wc(13);
  set_ac(6);
  set_hp(random (30)+90);
  set_al(-50);
  set_aggressive(1);

set_chat_chance(10);
load_chat("A glob of mucus drips from the snotlings nose.\n");

set_a_chat_chance(10);
load_a_chat("The snotlings are goaded into battle by their minder!\n");
  set_chance(10);
set_spell_dam(1);
set_spell_mess1( 
"The snotling hurls some fungus spores about.\n");

set_spell_mess2(
"A shrill cry escapes from the snotling.\n");

}
