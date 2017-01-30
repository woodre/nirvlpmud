#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object botl;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Elaine"+NORM);
set_alias("elaine");
set_alt_name("benes");
set_race("human");
set_short("Elaine Benes");
set_long(
  "  Looks like you caught Elaine right after a workout.  She's\n"+
  "dressed in Spandex tights and a T-shirt and appears to be\n"+
  "breathing quite heavily.  However, she also looks pretty\n"+
  "buff from that workout and could probably pack a mean punch\n"+
  "if given the opportunity.  Elaine carries a bottle of water,\n"+
  "made by the company for which she works.\n");

set_level(11);
  set_hp(150);
  set_al(0);
  set_wc(17);
  set_ac(8);
  set_heal(3,20);
  set_aggressive(0);
  set_dead_ob(this_object());

set_chance(10);
set_spell_dam(40);
set_spell_mess1(
  "\nElaine screams: "+RED+"GET OUT!"+NORM+"\n");
set_spell_mess2(
  "\nElaine pushes you in the chest with two hands and screams:\n"+
  RED+"                G E T  O U T !"+NORM+"\n");

botl = clone_object("/players/cosmo/apt/obj/msprings");
move_object(botl,this_object());
}

