#include "/players/nikki/ansi.h"
#include "/players/nikki/Tintagel/Mobs/Assist/guard_t.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIW+"Dwarven Guard"+NORM);
set_alias("guard");
set_alt_name("canute");
set_race("dwarf");
set_long(HIW+
  "  Canute stands about 4ft tall and is rather stocky.  His skin is a\n"+
  "deep tan colour and he has ruddy cheeks and bright green eyes.  His\n"+
  "dark gray hair is pulled back in a leather string and his beard is\n"+
  "braided in two long braids that hang down his burly chest.\n"+NORM);	

set_level(19);
set_hp(475);
set_al(100);
set_wc(28);
set_ac(16);
set_heal(5,5);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat("Canute says, 'Alls quiet in the tower today.'\n");
set_a_chat_chance(1);
  load_a_chat(HIW+"Canute yells, 'No one is allowed within the Tower!'\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIW+"\n\n\t\tCanute slashes at "+capitalize(TP->query_real_name())+" in a frenzy!\n\n"+NORM);
set_spell_mess2(
  HIW+"\n\n\n\t\tCanute slashes at you in a frenzy!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIW+"\n\n\nCanute makes one final atempt to run you through before he dies.\n\n\n"+NORM);
      return 0;
      }
