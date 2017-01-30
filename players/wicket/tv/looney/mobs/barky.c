inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("barky");
  set_alt_name("markey");
  set_race("toon");
  set_alias("toon barky");
  set_short(YEL+"Barky Markey"+NORM);
  set_long("\
   A young bulldog with a huge body. His dark brown ears droop down from his\n\
  head flapping back and forth as he walks. He has a dark tan fur that is very\n\
  coarse and rough. His front legs are very strong and sturdy but his back legs\n\
  are short and stubby. The underbelly is a very light tan color and his paws\n\
  are huge. He looks very happy and very energetic\n");
  add_spell("barkybark","#MN# lets out an $HR$ear shattering $HK$bark $N$causing YOUR ears to $R$bleed$N$.\n",
                       "#MN# lets out an $HR$ear shattering $HK$bark $N$causing #TN#\'s ears to $R$bleed$N$.\n",
                       40,40,0,0);
  set_level(20);  /* Changed to 20 from 21 by Rumplemintz */
  set_hp(560+ random(40));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1500)+4500);
}
