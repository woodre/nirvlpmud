#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIB+"Stone Giant"+NORM);
set_alias("giant");
set_alt_name("kuvnal");
set_race("stone giant");
set_long(HIB+
  "  Kuvnal stands before you with his huge muscular arms across his obsidian\n"+
  "coloured chest as he guards the stairs leading further up into the tower.\n"+
  "He slowly turns his clean, shaved head in your direction, staring with\n"+
  "glowing"+HIR+" red"+HIB+" eyes.\n"+NORM);

set_level(20);
set_hp(500);
set_al(100);
set_wc(30);
set_ac(17);
set_heal(5,5);
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(1);
  load_chat(HIB+"Kuvnal clenches his fist and a fine powder tumbles onto the floor!\n"+NORM); 
set_a_chat_chance(1);
  load_a_chat(HIB+"Kuvnal concentrates a moment and his skin suddenly produces a stonelike luster.\n"+NORM);

set_chance(10);
set_spell_dam(50);

set_spell_mess1(
  HIB+"\n\n\n\t"+capitalize(TP->query_real_name())+"'s bones SNAP as Kuvnal's fist pounds "+capitalize(TP->query_real_name())+" into the ground!\n\n"+NORM);
set_spell_mess2(
  HIB+"\n\n\n\tYour bones SNAP as Kuvnal's fist pounds you into the ground!\n\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(5000);
move_object(gold,this_object());
}

monster_died() {  
      tell_room(environment(this_object()),
      HIB+"\n\n\nKunval falls to the floor and groans as he dies.\n\n\n"+NORM);
      return 0;
      }
