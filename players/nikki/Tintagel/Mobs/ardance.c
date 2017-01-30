#include "/players/nikki/ansi.h"
#include "/players/nikki/Tintagel/Mobs/Assist/guard_cal.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIR+"Dwarven Guard"+NORM);
set_alias("guard");
set_alt_name("ardance");
set_race("dwarf");
set_long(HIR+
  "  Ardance stands in front of the entrance to the tower very solemnly, with his\n"+
  "shield and axe protecting him and his duty.  Although he is short in stature he\n"+
  "does not seem like he would be easily defeated in a battle.\n"+NORM);

set_level(19);
set_hp(475);
set_al(100);
set_wc(28);
set_ac(16);
set_heal(5,5);
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIR+"Ardance pierces your soul with a look of defiance.\n"+NORM);
set_a_chat_chance(1);
  load_a_chat(HIR+"Ardance laugh loudly as you try to damage him with your pitiful attempts.\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIR+"\n\n\t\tArdance pounds "+capitalize(TP->query_real_name())+" in the head with the hilt of his sword!\n\n"+NORM);
set_spell_mess2(
  HIR+"\n\n\n\t\tArdance pounds you in the head with the hilt of his sword!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIR+"\n\n\nArdance moans, 'How can one be so dense in this day and age?'\n\n\n"+NORM);
      return 0;
      }
