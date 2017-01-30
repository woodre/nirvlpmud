inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/familyguy/weapons/raygun.c"), this_object()); 
  command("wield raygun", this_object());
  move_object(clone_object("/players/wicket/tv/familyguy/armors/ddiaper.c"), this_object()); 
  command("wear diaper", this_object());
  move_object(clone_object("/players/wicket/tv/familyguy/armors/jeanover.c"), this_object()); 
  command("wear overalls", this_object());
  move_object(clone_object("/players/wicket/tv/familyguy/armors/redshirt.c"), this_object()); 
  command("wear shirt", this_object());
  set_name("stewie");
  set_alt_name("griffin");
  set_race("toon");
  set_alias("baby stewie");
  set_short(HIR+"Stewie Griffin"+NORM);
  set_long("\
   A small baby with a huge football head. He wears some red overalls.\n\
  his eyes are very round and big in size. He is carrying a lazer gun in\n\
  his hand planning on how to become an evil genius. He is very cranky and\n\
  has a very short temper.\n");
  add_spell("lazerstew","#MN# laughs $HK$demonically$N$ as he $HY$zaps$N$ you with his $HR$ray gun$N$.\n",
                        "#MN# laughs $HK$demonically$N$ as he $HY$zaps$N$ #TN# with his $HR$ray gun$N$.\n",
                        60,40,0);
  set_level(21);
  set_hp(450+ random(150));
  set_ac(17+ random(2));
  set_wc(29+ random(3));
  set_al(0);
  add_money(random(2000)+4000);
  }