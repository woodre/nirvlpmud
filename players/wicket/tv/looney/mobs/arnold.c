inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/slimshades.c"), this_object()); 
  command("wear shades", this_object());
  set_name("arnold");
  set_alt_name("bull");
  set_race("toon");
  set_alias("toon arnold");
  set_short(HIW+"Arnold"+NORM+" the "+HIW+"Pit Bull"+NORM);
  set_long("\
   A very muscular pit bull. His body is massive from bodybuilding from\n\
  head to feet. He is wearing a pair of black mirror shades. He stands\n\
  very high in height and is very intimidating in size. His six pack abs\n\
  are rock hard. A very cocky attitude radiates from his pores. He has a\n\
  solid white coat of fur that is very short and seems to be fresh shaved.\n");
  add_spell("jawsnap","#MN# growls and snaps his jaws, $HK$Massive$N$ $HW$Teeth$N$ Pierce Your flesh.\n",
                        "#MN# growls and snaps his jaws, $HK$Massive$N$ $HW$Teeth$N$ Pierce #TN#'s flesh.\n",
                        60,40,0,0);
  set_level(19);
  set_hp(500+ random(100));
  set_ac(17+ random(2));
  set_wc(28+ random(4));
  set_al(0);
  add_money(random(2000)+3000);
  }