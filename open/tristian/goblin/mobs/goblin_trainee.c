inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

  ::reset(arg);
  if (arg) return;

  set_name("Goblin Trainee");
  set_alt_name("trainee");
  set_race("goblin");
  set_alias("goblin");
  set_short("A goblin trainee");
  set_long("A short dirty lookin humanoid that you would guess\n"+
           "to be a goblin. He is in training to become a goblin\n"+
           "fighter.\n");
  set_level(2);
  set_ac(3);
  set_wc(6);
  set_hp(30);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The goblin trips over his feet.\n");
      load_chat("The goblin drops his practice sword.\n");
  set_a_chat_chance(8);
      load_a_chat("The goblin whacks at you with a wooden sword.\n");
  set_dead_ob(this_object());

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(90);
  move_object(gold, environment());
}