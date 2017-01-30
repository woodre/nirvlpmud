inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

  ::reset(arg);
  if (arg) return;

  set_name("Goblin Regular");
  set_alt_name("regular");
  set_race("goblin");
  set_alias("goblin");
  set_short("Goblin Regular");
  set_long("A short dirty looking humanoid that you would guess\n"+
           "to be a goblin. He appears to be the run of the mill\n"+
           "goblin fighter.\n");
  set_level(3);
  set_ac(4);
  set_wc(7);
  set_hp(45);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The goblin trips over his feet.\n");
      load_chat("The goblins laugh at the clumsy one.\n");
  set_a_chat_chance(8);
      load_a_chat("The goblin stabs himself in the arm.\n");
  set_dead_ob(this_object());

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(90+random(10));
  move_object(gold, environment());
}