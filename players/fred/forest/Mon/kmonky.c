#include "/players/fred/ansi.h"
inherit "obj/monster.c";
#define tpn this_player()->query_name()
object bow;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("drablo");
  set_alt_name("king");
  set_short(HIC+"Drablo"+NORM+", the Archer King");
  set_long(
  "  This is the famed king of the archer monkeys.  He is\n"+
  "their fiercest warrior and has defeated all who have\n"+
  "dared to challenge him.  He holds his crossbow proudly\n"+
  "next to his side, prepared for anything.\n");

  set_level(20);
  set_hp(850);
  set_al(-1000);
  set_ac(20);
  set_aggressive(0);
  set_heart_beat(1);
  set_chance(20);
  set_spell_dam(30);  
  set_spell_mess1(
    "Drablo "+BOLD+"CHARGES"+NORM+" it's foe!\n");
  set_spell_mess2(
    "\n    Drablo "+BOLD+"CHARGES"+NORM+" at you knocking you to the ground!\n");  

 
  bow = clone_object("players/fred/forest/Obj/cbow.c");
  move_object(bow, this_object());
  command("wield bow", this_object());
  set_wc(30);
}
