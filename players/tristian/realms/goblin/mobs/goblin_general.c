inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

  ::reset(arg);
  if (arg) return;

  set_name("Goblin General");
  set_alt_name("general");
  set_race("goblin");
  set_alias("goblin");
  set_short("Goblin General");
  set_long("A goblin of slightly larger stature than any of the others thus\n"+
           "far. He is wearing some armor of better quality than his fellow\n"+
           "goblins, probably pillaged from an unlucky caravan.  He seems\n"+
           "stronger than the others of his race and you would do well\n"+
           "to be wary of him\n");
  set_level(10);
  set_ac(14);
  set_wc(8);
  set_hp(250);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The General glares at your for disturbing his meeting.\n");
      load_chat("The General orders you out of his tent.\n");
  set_a_chat_chance(8);
      load_a_chat("The General says, 'I will crush you!'\n");
      load_a_chat("The General says, 'I didn't get this position by being weak!'\n");
  set_dead_ob(this_object());

  move_object(
      clone_object("/players/tristian/realms/goblin/obj/general_sword.c"),
         (this_object()));
  init_command("wield sword");

move_object(
      clone_object("/players/tristian/realms/goblin/obj/general_armor.c"),
         (this_object()));
  init_command("wear armor");

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(450+random(150));
  move_object(gold, environment());
}