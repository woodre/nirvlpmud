inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/hairbow.c"), this_object()); 
  command("wear hairbow", this_object());
  set_name("fifi");
  set_alt_name("fifi");
  set_race("toon");
  set_alias("toon fifi");
  set_short(HIM+"Fifi La Fume"+NORM);
  set_long("\
   A little purple skunk with a white stripe down her back, her fur is as\n\
  soft as cotton. A small pink ribbon is tied up in her hair that is fashionably\n\
  styled. She has a bright pink nose with soft puffy cheeks and a slap-happy\n\
  grin. An accent that sounds french flows from her mouth on every word she seems\n\
  to speak. A vapor trail of odor follows behind her. She looks around for someone\n\
  to love.\n");
  add_spell("skunkspray","#MN# lifts her tail in the air as she releases a$HG$ Horrible Odor$N$ spraying you making you vomit.\n",
                        "#MN# lifts her tail in the air releasing a $HG$Horrible Odor$N$ spraying #TN# making them vomit.\n",
                        50,30,0,0);
  set_level(19);
  set_hp(570+ random(30));
  set_ac(18+ random(1));
  set_wc(28+ random(4));
  set_al(0);
  add_money(random(1500)+2500);
  }