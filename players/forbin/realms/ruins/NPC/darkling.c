#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("Darkling");
set_alias("creature");
set_race("darkling");
set_short(""+BOLD+""+BLK+"Darkling"+NORM+"");
set_long(
    "  This small creature seems to be all claws and teeth.  Its body is\n"+
    "covered in small black gleaming scales, which offers good protection\n"+
    "against any attack.  Its long arms and legs allow for great speed and\n"+
    "leaping, making this creature extremely dangerous.\n");
set_level(13);
set_hp(250);
set_al(-800);
set_wc(26);
set_ac(8);
set_heal(5,3);
set_aggressive(1);
set_chat_chance(15);
  load_chat("Darkling growls menacingly at you.\n");
  load_chat("Darkling scurries before you, watching your every move.\n");
set_a_chat_chance(15);
  load_a_chat("Darklings claws rake at your face!\n");
  load_a_chat("Darklings teeth snap at your throat!\n");
  load_a_chat("Darkling howls with bloodlust!\n");

set_chance(10);
set_spell_dam(20);

set_spell_mess1(
  ""+BOLD+""+BLK+"Darkling"+NORM+" rakes at his victim, tearing into flesh!\n");
set_spell_mess2(
  "\n\n\n"+BOLD+""+BLK+"Darkling"+NORM+" rakes at you, tearing into your flesh!\n\n\n");

}

init() {
  ::init();
  add_action("no_move", "north");
  add_action("no_move", "east");
  add_action("no_move", "climb");
}

no_move() {
  write(
    ""+BOLD+""+BLK+"Darkling"+NORM+" jumps in front of you and lashes out with its claws!\n");
  if(this_player()->query_ghost()) { return 0; }
  this_player()->hit_player(20);
  return 1;
}

monster_died() {
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif 
  return 1; 
} 