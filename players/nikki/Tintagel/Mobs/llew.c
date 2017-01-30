#include "/players/nikki/ansi.h"
#include "/players/nikki/Tintagel/Mobs/Assist/guard_h.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIB+"Dwarven Guard"+NORM);
set_alias("guard");
set_alt_name("llewellyn");
set_race("dwarf");
set_long(HIB+
  "  Llewellyn is a short and stout looking dwarf.  He is here to guard\n"+
  "the entrance into the tower from strangers.  His armour shines brightly\n"+
  "and fits him tightly.\n"+NORM);

set_level(19);
set_hp(475);
set_al(100);
set_wc(28);
set_ac(16);
set_heal(5,5);
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIB+"Llewellyn sighs deeply.\n"+NORM);
set_a_chat_chance(1);
  load_a_chat(HIB+"Llewellyn yells, 'I KNEW you were going to start trouble!'\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIB+"\n\n\t\tLlewellyn SLAMS into "+capitalize(TP->query_real_name())+" with his mace!\n\n"+NORM);
set_spell_mess2(
  HIB+"\n\n\n\t\Llewellyn SLAMS into you with his mace!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIB+"\n\n\nLlewellyn laughs loudly and then falls to the ground dead.\n\n\n"+NORM);
      return 0;
      }
