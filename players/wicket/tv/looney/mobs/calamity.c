inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/runshoes2.c"), this_object()); 
  command("wear shoes", this_object());
  set_name("calamity");
  set_alt_name("coyote");
  set_race("toon");
  set_alias("toon calamity");
  set_short(HIK+"Calamity Coyote"+NORM);
  set_long("\
   A wild looking little coyote. He is a deep dark grey color, his fur rough\n\
  and dirty. He has a very long snout with a Bright red nose. His ears stick\n\
  straight up in the air listening for the sounds of everything around him. He\n\
  is very aware of his surroundings. He us wearing a pair of very big running\n\
  shoes. A mischevious grin always rests upon his face as he looks around. He\n\
  has a small patch of white fur on his chest. His eyebrows are very think and\n\
  bushy. A small bandaid is on his cheek.\n");
  add_spell("calamityhowl","#MN# $HK$howls$HR$ EXTREMELY$N$ loud causing your ears to $HR$bleed$N$.\n",
                       "#MN# $HK$howls$HR$ EXTREMELY$N$ loud causing #TN#\'s ears to $HR$bleed$N$.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(2000)+2500);
  }