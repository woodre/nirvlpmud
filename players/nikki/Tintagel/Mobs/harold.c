#include "/players/nikki/ansi.h"
#include "/players/nikki/Tintagel/Mobs/Assist/guard_l.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIB+"Dwarven Guard"+NORM);
set_alias("guard");
set_alt_name("harold");
set_race("dwarf");
set_long(HIB+
  "  Harold looks back at you and nods.  He's standing in front of the\n"+
  "entrance to the tower with his arms folded across his chest.  His\n"+
  "black hair flows down into his long braided beard. He carries the \n"+
  "crest of Pendragon on his shield.\n"+NORM);	

set_level(19);
set_hp(475);
set_al(100);
set_wc(28);
set_ac(16);
set_heal(5,5);
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIB+"Harold says, 'They should close off this area to outsiders.'\n"+NORM);
set_a_chat_chance(1);
  load_a_chat(HIB+"Harold yells, 'Kill'em all and let God sort them out!'\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIB+"\n\n\t\tHarold BASHES "+capitalize(TP->query_real_name())+" in the head with his club!\n\n"+NORM);
set_spell_mess2(
  HIB+"\n\n\n\t\tHarold BASHES you in the head with his club!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIW+"\n\n\nHarold takes one final swing at you before he dies.\n\n\n"+NORM);
      return 0;
      }
