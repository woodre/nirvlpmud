#include "/players/nikki/ansi.h"
#include "/players/nikki/Tintagel/Mobs/Assist/guard_s.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIG+"Dwarven Guard"+NORM);
set_alias("guard");
set_alt_name("vasten");
set_race("dwarf");
set_long(HIG+
  "  Vasten nudges Sarern and grins as he looks at you.  He is an albino\n"+
  "looking dwarf, probably around 4ft 9 in tall with piercing pink eyes.\n"+
  "You can't help but stare in awe at him.\n"+NORM);

set_level(19);
set_hp(475);
set_al(100);
set_wc(28);
set_ac(16);
set_heal(5,5);
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIG+"Vasten says, 'Hey Saren, after our shift you want to go down to the pub?'\n"+NORM);
set_a_chat_chance(1);
  load_a_chat(HIG+"Vasten says, 'Fighting your kind always makes me thirsty afterwards.'\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIG+"\n\n\t\tVasten PIERCES "+capitalize(TP->query_real_name())+" with his sword and twists to the left!\n\n"+NORM);
set_spell_mess2(
  HIG+"\n\n\n\t\tVasten PIERCES you with his sword and twists it to the left!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIG+"\n\n\nVasten slumps over and lets out a loud moan as he dies.\n\n\n"+NORM);
      return 0;
      }
