inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/familyguy/armors/dpants.c"), this_object()); 
  command("wear pants", this_object());
  move_object(clone_object("/players/wicket/tv/familyguy/armors/dshirt.c"), this_object()); 
  command("wear shirt", this_object());
  move_object(clone_object("/players/wicket/tv/familyguy/armors/glasses.c"), this_object()); 
  command("wear glasses", this_object());
  set_name("peter");
  set_alt_name("griffin");
  set_race("toon");
  set_alias("peter griffin");
  set_short(HIW+"Peter Griffin"+NORM);
  set_long("\
   A chubby fat man that is a HUGE moron. He is wearing a white button up\n\
  dress shirt with a tan pair of dress pants. His chin is so fat he has no\n\
  neck. He wears a pair of ugly round glasses on his face. His hairy is greasy\n\
  and lays flat on his head.\n");
  add_spell("beerbash","#MN# laughs and pounds down a beer as he $HR$smashes the $Y$bottle$N$ on your head.\n",
                        "#MN# laughs and pounds down a beer as he $HR$smashes the $Y$bottle$N$ on #TN#\'s head.\n",
                        60,40,0,0);
  set_level(21);
  set_hp(500+ random(100));
  set_ac(18+ random(1));
  set_wc(28+ random(4));
  set_al(0);
  add_money(random(2000)+4000);
  }