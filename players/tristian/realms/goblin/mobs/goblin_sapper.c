inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

  ::reset(arg);
  if (arg) return;

  set_name("Goblin Sapper");
  set_alt_name("sapper");
  set_race("goblin");
  set_alias("goblin_sapper");
  set_short("Goblin Sapper");
  set_long("This goblin has a death wish. He thinks nothing of\n"+
           "crawling up to a fortress and undermining the foundation\n"+
           "and then dropping in some high explosives.\n");
  set_level(3);
  set_ac(4);
  set_wc(7);
  set_hp(45);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(0);
  set_a_chat_chance(8);
      load_a_chat("The goblin hacks you with a shovel.\n");
  set_dead_ob(this_object());

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(90+random(10));
  move_object(gold, environment());
}