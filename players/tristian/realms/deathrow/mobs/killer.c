#include "/players/tristian/lib/DR_define.h"
inherit "/players/vertebraker/closed/std/monster.c";
object gold;

id(str) { return (::id(str) || str == "con" || str == "convict"); }

reset(arg){
  ::reset(arg);
    if (arg) return;

  set_name("killer");
  set_alt_name("killer");
  set_race("human");
  set_alias("criminal");
  set_gender("male");
  set_short("killer");
  set_long("A killer\n");
  set_level(40);
  set_ac(50);
  set_wc_bonus(20);
  set_ac_bonus(15);
  set_wc(65);
  set_hp(3000);
  set_al(-250);
  set_heal(25,15);
  set_aggressive(0);


  set_dead_ob(this_object());
  set_chance(40);
  set_spell_dam(100-random(20));

  set_spell_mess1(
    "\nThe killer pulls out a shiv and " +HIY+"plunges"+NORM+" it into your "+BLINK+BRED+"chest"+NORM+".\n");
  set_spell_mess2(
    "\nThe killer pulls out a shiv and " +HIY+"plunges"+NORM+" it into your "+BLINK+BRED+"chest"+NORM+".\n");

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the killer.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(30000);
  move_object(gold, environment());

}