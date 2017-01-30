#include "/players/nikki/ansi.h"
#include "/players/nikki/Tintagel/Mobs/Assist/guard_v.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIG+"Dwarven Guard"+NORM);
set_alias("guard");
set_alt_name("sarern");
set_race("dwarf");
set_long(HIG+
  "  Sarern scrutinizes you and smirks.  He looks to be quite sure of\n"+
  "himself as he guards the entrance to the tower.  He is not very tall\n"+
  "but he is very stout looking.\n"+NORM);

set_level(19);
set_hp(475);
set_al(100);
set_wc(28);
set_ac(16);
set_heal(5,5);
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIG+"Sarern grins and says, 'If I were you I'd leave while I had the chance.'\n"+NORM);
set_a_chat_chance(1);
  load_a_chat(HIG+"Sarern laughs, 'I love it when your kind doesn't listen to good advice.'\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIG+"\n\n\t\tSarern grabs "+capitalize(TP->query_real_name())+" by the ears and "+BLINK+HIY+"SMASHES"+NORM+HIG+" your face with his forehead!\n\n"+NORM);
set_spell_mess2(
  HIG+"\n\n\n\t\tSarern grabs you by the ears and "+BLINK+HIY+"SMASHES"+NORM+HIG+" you in the face with his forehead !\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIG+"\n\n\nSarern groans in disbelief as he slumps the the ground.\n\n\n"+NORM);
      return 0;
      }
