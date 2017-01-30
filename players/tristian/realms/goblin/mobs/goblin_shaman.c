inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

  ::reset(arg);
  if (arg) return;

  set_name("Goblin Shaman");
  set_alt_name("shaman");
  set_race("goblin");
  set_alias("goblin");
  set_short("Goblin Shaman");
  set_long("A goblin of slightly larger stature than all the rest.\n"+
           "His hair stands out in all directions, and he is squatting\n"+
           "in the center of the tent throwing something that appear to\n"+
           "be bones and muttering to himself.\n");
  set_level(10);
  set_ac(14);
  set_wc(5);
  set_hp(180);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The Shaman throws bones and reads the results.\n");
      load_chat("The Shaman shouts, 'The end is here' and points at your chest.\n");

  set_dead_ob(this_object());

  set_chance(35);
  set_spell_dam(5+random(10));

  set_spell_mess1(
    "\nThe shaman calls on his god and your " +HIK+"soul"+NORM+" shudders in "+BLINK+BRED+"agony"+NORM+".\n");
  set_spell_mess2(
    "\nThe shaman calls on his god and your " +HIK+"soul"+NORM+" shudders in "+BLINK+BRED+"agony"+NORM+".\n");

  move_object(
      clone_object("/players/tristian/realms/goblin/obj/shaman_staff.c"),
         (this_object()));
  init_command("wield staff");

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(300+random(50));
  move_object(gold, environment());
}