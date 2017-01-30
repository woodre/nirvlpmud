inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/rml/armor/filbertpants.c"), this_object()); 
  command("wear pants", this_object());
  move_object(clone_object("/players/wicket/tv/rml/armor/filbertshirt.c"), this_object()); 
  command("wear shirt", this_object());
  move_object(clone_object("/players/wicket/tv/rml/armor/filbertglasses.c"), this_object()); 
  command("wear glasses", this_object());
  move_object(clone_object("/players/wicket/tv/rml/armor/filbertshell.c"), this_object()); 
  command("wear shell", this_object());
  set_name("filbert");
  set_alt_name("turtle");
  set_race("toon");
  set_alias("toon filbert");
  set_short(HIK+"Fil"+HIC+"ber"+HIK+"t"+NORM+" the"+HIK+" Tu"+HIC+"rt"+HIK+"le"+NORM+"" );
  set_long("\
   A friend of rocko this is a turtle. He is very nerdy and has a \n\
  huge fear of germs and getting hurt. But looks can be deceiving he\n\
  is actually very smart.\n");
  add_spell("filbertbite","#MN# $HK$bites YOU $Y$very hard$N$, the $Y$bite wound$N$ starts $R$bleeding$N$ causing $HK$massive$R$ blood$N$ loss$N$.\n",
                        "#MN# $HK$bites #TN# $Y$very hard$N$, the $Y$bite wound starts$N$ $R$bleeding causing $HK$massive$R$ blood$N$ loss$N$.\n",
                        40,30,0,0);
  set_level(19);
  set_hp(570+ random(30));
  set_ac(18+ random(1));
  set_wc(28+ random(4));
  set_al(0);
  add_money(random(1000)+1000);
  }