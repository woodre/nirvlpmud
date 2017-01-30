#include "/players/fred/ansi.h"
inherit "obj/monster.c";


reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("ned");
set_race("human");
set_short("Ned");
set_long(
  "  Ned is Jimbo's old Vietnam war buddy.  His favorite things\n"+
  "to do are hunting and fishing with automatic weapons and explosives\n"+
  "while intoxicated.\n");
  
add_money(600);
set_level(12);
set_hp(180);
set_al(500);
set_wc(16);
set_ac(9);
set_aggressive(0);
set_chat_chance(8);
  load_chat("Ned mumbles through his voice box: Mmm it's coming right for us.\n");
set_a_chat_chance(10);
  load_a_chat("Ned mumbles through his voice box: Mmm it hurts, it hurts.\n");
}


