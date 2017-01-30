inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

  ::reset(arg);
  if (arg) return;

  set_name("Goblin Captain");
  set_alt_name("captain");
  set_race("goblin");
  set_alias("goblin");
  set_short("Goblin Captain");
  set_long("A stout goblin in dirty armor and with a gleem in his eye. He is\n"+
           "the real leader of the goblin army.  He has a devious and cunning\n"+
           "look about him and you can just bet he would be general if he could\n"+
           "scheme a way to do it.\n");
  set_level(8);
  set_ac(12);
  set_wc(12);
  set_hp(150+random(50));
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The Captain glares at your for disturbing the General.\n");
      load_chat("The Captain hollars for some guard.\n");
  set_a_chat_chance(8);
      load_a_chat("The Captain says, 'I will crush you!'\n");
      load_a_chat("The Captain cries, 'I wanna be General'\n");
  set_dead_ob(this_object());

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(300+random(100));
  move_object(gold, environment());
}