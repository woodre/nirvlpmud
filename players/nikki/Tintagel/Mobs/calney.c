#include "/players/nikki/ansi.h"
#include "/players/nikki/Tintagel/Mobs/Assist/guard_a.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIR+"Dwarven Guard"+NORM);
set_alias("guard");
set_alt_name("calney");
set_race("dwarf");
set_long(HIR+
  "  Calney looks to be about 4 1/2 ft tall with light coloured hair which\n"+
  "contrasts nicely with his reddish brown complexion.  He seems to be very\n"+
  "reserved and determined in his purpose.  Whatever that may be.\n"+NORM);

set_level(19);
set_hp(475);
set_al(100);
set_wc(28);
set_ac(16);
set_heal(5,5);
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIR+"Calney says, 'There's no need for your kind to be lurking around here.'\n"+NORM);
set_a_chat_chance(1);
  load_a_chat(HIR+"Calney yells, 'OH NO YOU DON'T! You aren't getting into this tower!'\n"+NORM);

set_chance(10);
set_spell_dam(45);

set_spell_mess1(
  HIR+"\n\n\t\tCalney smashes "+capitalize(TP->query_real_name())+" with his warhammer!\n\n"+NORM);
set_spell_mess2(
  HIR+"\n\n\n\t\tCalney smashes you with his warhammer!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIR+"\n\n\nCalney whispers his last breath, 'You will regret this in more ways than one.'\n\n\n"+NORM);
      return 0;
      }
