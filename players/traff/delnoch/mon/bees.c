/*  BUTLER.C - Loads into KENTRY.C
    Changes as of 5-29-96:
    Color added
*/
#include "/players/traff/closed/ansi.h"
inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("bees");
  set_race("critter");
  set_alias("bee");
  set_short(YEL+"Swarm of BEES"+NORM);
    if(random(100)>90) { set_aggressive(1); }
    if(random(100)>10) { set_whimpy(1); }
  set_long(HIR+
"An angry swarm of bees. (buzzing).\n"+NORM);
  set_level(16);
  set_hp(400);
  set_al(500);
  set_wc(22);
  set_ac(13);
  set_dead_ob(this_object());
  set_chat_chance(20);
  set_a_chat_chance(25);
  load_chat("The bees BUZZZZ.\n");
  load_a_chat("Bees buzz around you: You are stung many times!\n");
  set_chance(20);
  set_spell_mess1("Bees sting it's victim!\n");
  set_spell_mess2("Bees sting you!\n");
  set_spell_dam(random(6));
/* testing
  set_heart_beat(1);
end test */
}
monster_died() {
  call_other("/players/traff/delnoch/forest/forest2.c","dead_mon");
  write_file("/players/traff/delnoch/forest/DEAD",ctime()+"bees killed\n");
  return 0; }
