#include "/players/nikki/ansi.h"
#include "/players/nikki/Tintagel/Mobs/Assist/guard_c.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIW+"Dwarven Guard"+NORM);
set_alias("guard");
set_alt_name("tesar");
set_race("dwarf");
set_long(HIW+
  "  Tesar is big boned.  His skin is a pale brown colour and his large\n"+
  "steel, blue eyes seem very cold and unfriendly as they pass over you.\n"+
  "He is very serious looking as he guards the door to the tower from all\n"+
  "intruders.\n"+NORM);	

set_level(19);
set_hp(475);
set_al(100);
set_wc(28);
set_ac(16);
set_heal(10,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat("Tesar grumbles, 'I don't like all these people around the Tower.'\n");
set_a_chat_chance(1);
  load_a_chat(HIW+"Tesar growls, 'There is no way you are getting past me!'\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIW+"\n\n\t\tTesar swings mightly at "+capitalize(TP->query_real_name())+" with a great force.\n\n"+NORM);
set_spell_mess2(
  HIW+"\n\n\n\t\tTesar swings mightly at you with a great force!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIW+"\n\n\nTesar tries to reach for the door as he slumps to the ground.\n\n\n"+NORM);
      return 0;
      }
