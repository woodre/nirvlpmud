#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/players/vertebraker/closed/std/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(HIK+"The Avatar of"+HIW+" Death"+NORM);
  set_alt_name("avatar");
  set_alias("death");
  set_short(HIK+"The Avatar of"+HIW+" Death"+NORM);
  set_long(
"This is an avatar of death.  Tall and robed all in black with\n"+
"only its skeletal hands visible.  Two pale glowing orbs of light\n"+
"flicker out from under the hood as it appears to watch passively.\n");
  set_race("death");
  set_level(20);
move_object(clone_object("/players/khrell/closed/underways/obj/deathscythe.c"));
init_command("wield scythe");  
  set_wc(60);
move_object(clone_object("/players/khrell/closed/underways/obj/deathrobe.c"));
init_command("wear robe");  
  set_ac(40);
  set_hp(2000);
  set_al(0);
  set_aggressive(0);
  set_heal(1000,1);
  set_chat_chance(10);
load_chat(HIK+"The Avatar of "+HIW+"Death"+NORM+" watches you silently.\n");
load_chat(HIK+"The Avatar of "+HIW+"Death"+NORM+" observes your actions silently.\n");
load_chat(HIK+"The Avatar of "+HIW+"Death"+NORM+" gazes at you.\n");

  set_chance(75);
  set_spell_dam(450);
  set_spell_mess1( 
HIK+"The Avatar of"+HIW+" Death"+NORM+" rips you into "+HIR+"BLOODY"+NORM+" chunks.\n");
set_spell_mess2(
HIK+"The Avatar of"+HIW+" Death"+NORM+" rips its target into "+HIR+"BLOODY"+NORM+" chunks.\n");

}

void heart_beat()
{
  ::heart_beat();
  if(attacker_ob && !attacker_ob->query_ghost())
{
  attacker_ob->death(HIK+"The Avatar of"+HIW+" Death"+NORM);
 }
}
