#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("chaos-spawn");
  set_alt_name("chaos");
  set_alias("spawn");
  set_short("A Chaos-Spawn");
  set_long("Chaos-spawn is the usual fate of those that fail in their \n\
damnation to chaos.  No two are alike and it is impossible \n\
describe or chart the mutations they bear for they are in a\n\
constant state of change.\n");
  set_race("spawn");
  set_level(17);
  set_wc(24+random(5));
  set_ac(14+random(5));
  set_hp(300+random(200));
  set_al(-100);
  set_aggressive(2);

set_chat_chance(10);
load_chat("The spawn randomly changes it's form.\n");

set_a_chat_chance(10);
load_a_chat("The spawn emits a loud scream!\n");
  set_chance(10);
  set_spell_dam(50);
  set_spell_mess1("The spawn pauses.........then...................             \n"+
                          RED+"V "+CYN+"O "+RED+"M "+CYN+"I "+RED+"T "+CYN+"S"+NORM+"!\n");           

  set_spell_mess2(
"The spawn "+RED+"V "+CYN+"O "+RED+"M "+CYN+"I "+RED+"T "+CYN+"S  on it's foe!\n");

}
