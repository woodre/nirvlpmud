inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("gogo");
  set_alt_name("dodo");
  set_race("toon");
  set_alias("toon gogo");
  set_short(HIG+"Gogo Dodo"+NORM);
  set_long("\
   A small green multi-colored bird, his head is green with a small pink\n\
  umbrella sticking out of his head. His lower body a aquamarine color. He\n\
  has no arms only some small tail feathers. Big clumsy feet stick out from\n\
  the feathers at the bottom of his torso. The feet are a sea blue color. He\n\
  bounces around the room in a goofy style.\n");
 add_spell("dodohole","#MN# causes a $HK$hole$N$ to appear sucking you inside of it and spitting You back out.\n",
                       "#MN# causes a $HK$hole$N$ to appear sucking #TN# inside of it and spitting them back out.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(2000)+3000);
  }