#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIG+"Concupiscetia"+NORM);
set_alias("lady");
set_alt_name("Concupiscetia");
set_race("green dragon");
set_long(HIG+
  "  Concupiscetia giggles lightly at your approach, her sparking emerald eyes\n"+
  "stare deeply into yours.  Her long blonde hair seems to shimmer about her rich\n"+
  "green robes that barely contain her firm figure.\n"+NORM;

set_level(21);
set_hp(500);
set_al(100);
set_wc(30);
set_ac(17);
set_heal(5,5);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIG+"Concupiscetia pouts her lucious full lips as she silently steps toward you.\n"+NORM);
set_a_chat_chance(1);
  load_a_chat(HIG+"Concupiscetia howls a feral snarl in your direction and dissapears in a cloud of green gas.\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIR+"\n\n\t\tSmashes "+capitalize(TP->query_real_name())+" with his warhammer!\n\n"+NORM);
set_spell_mess2(
  HIR+"\n\n\n\t\tSmashes you with his warhammer!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(5000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIR+"\n\n\n  \n\n\n"+NORM);
      return 0;
      }
