#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   set_name("Simoom");
   set_alias("fire elemental");
   set_alt_name("simoom");
   set_race("elemental");
   set_short(HIR+"Simoom"+NORM);
   set_long(
      "A cute, quick, fuzzy, "+BLK+BOLD+"black rabbit"+NORM+".\n");
   set_level(17);
   set_hp(900);
   set_al(0);
   set_wc(40);
   set_ac(20);
   set_aggressive(0);
   set_dead_ob(this_object());
   set_chat_chance(15);
   load_chat(HIR+"Simoom"+NORM+" slowly waves his hands in the air.\n");
   load_chat(HIR+"Simoom"+NORM+" slowly waves his hands in the air.\n");
   load_chat(HIR+"Simoom"+NORM+" murmurs a small chant.\n");
   load_chat(HIR+"Simoom"+NORM+" murmurs a small chant.\n");
   load_chat(HIR+"Flames"+NORM+" suffocate around "+HIR+"Simoom"+NORM+".\n");
}


