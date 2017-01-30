inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

  ::reset(arg);
  if (arg) return;

  set_name("Goblin Lieutenant");
  set_alt_name("lieutenant");
  set_race("goblin");
  set_alias("goblin");
  set_short("Goblin Lieutenant");
  set_long("A common goblin who was promoted to fill a slot vacated by a\n"+
           "recent death. He is nervous and fidgety. Maybe you should \n"+
           "make the slot vacant again.\n");
  set_level(7);
  set_ac(11);
  set_wc(10);
  set_hp(115+random(35));
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The Lieutenant fidgets nervously.\n");
      load_chat("The Lieutenant hollars for some guard.\n");
  set_a_chat_chance(8);
      load_a_chat("The Lieutenant says, 'I just got this position'\n");
      load_a_chat("The Lieutenant cries, 'Leave me alone, please?'\n");
  set_dead_ob(this_object());

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(300);
  move_object(gold, environment());
}