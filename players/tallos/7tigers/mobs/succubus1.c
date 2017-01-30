inherit "/obj/monster.c";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("succubus");
  set_race("demon");
  set_short(BOLD+RED+"A Succubus"+NORM);
  set_long(
    "  This sexy creature is a demon most foul. She has\n"+
    "large leathery bat wings and wears nothing but naked\n"+
    "flesh. She is intoxicating to the eye.\n");
  
  add_money(4200+random(2150));
  set_level(21);
  set_hp(500+random(200));
  set_al(-800);
  set_ac(20+random(6));
  set_wc(33);
  set_aggressive(0);
  set_chat_chance(10);
  load_chat("The succubus says, \"Have you come for some...pleasure?\"\n");
  load_chat("The succubus licks her lips seductively.\n");
  add_spell("Poison",
  "#MN#'s claws drip with $HG$->P $N$$G$O $HG$I $N$$G$S $HG$O $N$$G$N"+HIG+"<-$N$.\n",
  "#MN#'s claws drip with $HG$->P $N$$G$O $HG$I $N$$G$S $HG$O $N$$G$N"+HIG+"<-$N$.\n",
  30,20,"other|poison");
}
