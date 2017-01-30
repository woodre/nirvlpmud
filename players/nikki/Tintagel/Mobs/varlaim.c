#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIW+"Frost Giant"+NORM);
set_alias("giant");
set_alt_name("varlaim");
set_race("stone giant");
set_long(HIW+
  "  Varlaim has skin of bone white and hair the colour of polar ice.\n"+
  "He gets up from the table and stands before you, blocking your passage\n"+
  "to the upper part of the tower.\n"+NORM);

set_level(20);
set_hp(500);
set_al(100);
set_wc(30);
set_ac(17);
set_heal(5,5);
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIW+"Varlaim says, 'What do you think you are doing up here?'\n"+NORM); 
set_a_chat_chance(1);
  load_a_chat(HIW+"Crystals of ice drop from Varlaim's beard as he swings his trident toward you!\n"+NORM);

set_chance(10);
set_spell_dam(50);

set_spell_mess1(
  HIW+"\n\n\n\t"+capitalize(TP->query_real_name())+"is PIERCED upon the icy tines of Varlaim's trident!\n\n"+NORM);
set_spell_mess2(
  HIW+"\n\n\n\tYou PIERCED upon the icy tines of Varlaim's trident!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(5000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIB+"\n\n\nVarlaim fills his lungs with one final breath into his icy lungs before he dies.\n\n\n"+NORM);
      return 0;
      }
