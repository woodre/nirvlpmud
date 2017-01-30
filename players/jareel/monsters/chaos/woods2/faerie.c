inherit "/obj/monster";
#include "/players/jareel/define.h"
    int number;
string mobname;

reset(arg)  {
  number = random(15);
    ::reset(arg);
  if (arg) return;
  set_race("faerie");
  set_al(500);
  set_ac(14);
  set_wc(24);
  set_hp(350);
  set_level(17);
  add_money(1800+random(300));
  
    if(number == 0) {mobname = HIM+"A laughing Faerie"+NORM;}
    if(number == 1) {mobname = HIG+"A magical Faerie"+NORM;}
    if(number == 2) {mobname = HIC+"A fluttering Faerie"+NORM;}
    if(number == 3) {mobname = HIR+"A giggling Faerie"+NORM;}
    if(number == 4) {mobname = HIY+"A mischievous  Faerie"+NORM;}
    if(number == 5) {mobname = HIC+"A laughing Faerie"+NORM;}
    if(number == 6) {mobname = HIM+"A magical Faerie"+NORM;}
    if(number == 7) {mobname = HIR+"A fluttering Faerie"+NORM;}
    if(number == 8) {mobname = HIY+"A giggling Faerie"+NORM;}
    if(number == 9) {mobname = HIM+"A mischievous  Faerie"+NORM;}
    if(number == 10) {mobname = HIG+"A laughing Faerie"+NORM;}
    if(number == 11) {mobname = HIR+"A magical Faerie"+NORM;}
    if(number == 12) {mobname = HIM+"A fluttering Faerie"+NORM;}
    if(number == 13) {mobname = HIC+"A giggling Faerie"+NORM;}
    if(number == 14) {mobname = HIG+"A mischievous  Faerie"+NORM;}
                     
  set_name(mobname);
  set_short(mobname);
  set_long(
    "A Tiny magical creature.  It has a beutiful human body with tiny wings that\n"+
    "flutter from its back.  Small glittering flecks of dust fall from the little\n"+
    "creatures wings as it flutters around the room.\n");

   add_spell(
      "faeriedust",""+BOLD+GRN+"The Faerie tosses some magical dust in your eyes!\n"+NORM+"",
                   HIG+"The Faerie tosses some magical dust in #TN# eyes!\n",
      4,30,"other|magical");

   add_spell(
      "faeriedust1",""+BOLD+MAG+"The Faerie tosses some magical dust in your eyes!\n"+NORM+"",
                   HIM+"The Faerie tosses some magical dust in #TN# eyes!\n",
      4,30,"other|magical");

   add_spell(
      "faeriedust2",""+BOLD+YEL+"The Faerie tosses some magical dust in your eyes!\n"+NORM+"",
                   HIY+"The Faerie tosses some magical dust in #TN# eyes!\n",
      4,30,"other|magical");

  set_chat_chance(5);
    load_chat("The faerie flutters her wings.\n");
    load_chat("The faerie leaves a trail of Faerie dust in the air behind her.\n");
    load_chat("The faerie flys around you.\n");
    load_chat("The faerie lets out a little chuckle and a faint whisper can be heard in the air.\n");
    load_chat("The faerie sprinkles faerie dust in the air.\n");
    load_chat("The faerie giggles as it hovers near your head.\n");

  set_a_chat_chance(15);
    load_a_chat("The faerie dodges the attack!\n");

}

