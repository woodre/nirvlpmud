inherit "/obj/monster.c";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bone devil");
  set_race("demon");
  set_alias("devil");
  set_short(BOLD+RED+"A Bone Devil"+NORM);
  set_long(
    "  This Tall creature looks skeletal and wretched, almost\n"+
    "a husk of a humanoid form, with dried skin stretched so\n"+
    "tight as to outline and emphasize every bone. It has a\n"+
    "fearsome, skull-like head and a tail like a scorpion's,\n"+
    "and a foul odor of decay hangs in the air around it.\n");
  
  add_money(6000);
  set_level(21);
  set_hp(500+random(200));
  set_al(-1000);
  set_ac(20+random(6));
  set_wc(33);
  set_aggressive(0);
  set_armor_params("other|evil",0,20,0);
  set_armor_params("other|fire",0,20,0);
  set_armor_params("other|electric",0,10,0);
  set_armor_params("other|good",0,-15,0);
  set_chat_chance(10);
  load_chat("The bone devil rasps, \"Your soul is mine!\"\n");
  load_chat("The bone devil sharpens his talons.\n");
  add_spell("Poisonsting",
  "#MN#'s scorpion tail hits you and you are $HG$->P $N$$G$O $HG$I $N$$G$S $HG$O $N$$G$N $HG$E $N$$G$D"+HIG+"<-$N$.\n",
  "#MN#'s scorpion tail strikes with $HG$->P $N$$G$O $HG$I $N$$G$S $HG$O $N$$G$N"+HIG+"<-$N$.\n",
  30,30,"other|poison");
}
