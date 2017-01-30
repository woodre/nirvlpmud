inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/rml/armor/hefferpants.c"), this_object()); 
  command("wear pants", this_object());
  move_object(clone_object("/players/wicket/tv/rml/heals/ppuffies.c"), this_object());
  set_name("heffer");
  set_alt_name("wolfe");
  set_race("toon");
  set_alias("toon heffer");
  set_short(HIY+"He"+HIR+"ff"+HIY+"er"+HIR+" Wo"+HIY+"l"+HIR+"fe"+NORM);
  set_long("\
   A friend of rocko this is a huge cow. He is very sloppy and rude,\n\
  He is very massive in size and very nasty looking. Always looking\n\
  for his favorite bag of Pasture Puffies.\n");
  add_spell("hefferfart","#MN# $HK$leans back$N$ and lets one $Y$rip$N$, the $G$foul odor$N$ causes you to $HK$stumble$N$ back $R$gagging$N$.\n",
                        "#MN# $HK$leans back and lets one $Y$rip$N$ causing #TN# to $HK$stumble$N$ back $R$gagging$N$ from the $G$foul odor$N$.\n",
                        40,50,0,0);
  set_level(19);
  set_hp(570+ random(30));
  set_ac(18+ random(1));
  set_wc(28+ random(4));
  set_al(0);
  add_money(random(2500)+1500);
  }