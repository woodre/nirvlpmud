inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/blazerjacket.c"), this_object()); 
  command("wear jacket", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/blazerpants.c"), this_object()); 
  command("wear pants", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/dressshoes.c"), this_object()); 
  command("wear shoes", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/greenshirt.c"), this_object()); 
  command("wear shirt", this_object());
  set_name("montana");
  set_alt_name("max");
  set_race("toon");
  set_alias("toon montana");
  set_short(BLU+"Montana Max"+NORM);
  set_long("\
   One of the biggest snobs and rich spoiled brats, hot headed and cranky.\n\
  He is of short height with a very big attitude, he has one of the worst\n\
  tempers imaginable. A deep blue suit covers his body with a small green\n\
  shirt underneath the coat. Leather black shoes just seem to shine as if\n\
  they where just polished. His brown hair is combed forward and greasy.\n");
  add_spell("moneybash","#MN# swings his $HK$Massive$N$ $HG$Moneybags$N$ at YOU $HR$PULVERIZING$N$ You.\n",
                        "#MN# swings his $HK$Massive$N$ $HG$Moneybags$N$ at #TN# $HR$PULVERIZING$N$ them.\n",
                        40,50,0,0);
  set_level(19);
  set_hp(540+ random(60));
  set_ac(16+ random(3));
  set_wc(27+ random(5));
  set_al(0);
  }