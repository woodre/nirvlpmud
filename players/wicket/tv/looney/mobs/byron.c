inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("byron");
  set_alt_name("basset");
  set_race("toon");
  set_alias("toon byron");
  set_short(HIK+"Byron Basset"+NORM);
  set_long("\
   A small basset hound with brown and white fur. He has long droopy ears\n\
  with bloodshot eyes. His scent tracking skills are amazing. Energetic\n\
  personality is not this dogs thing. He is very lazy and loves to lay around\n\
  alot. A cold black nose is on the end of his snout. His drool covered lips\n\
  hang down past his bottom jaw. His eyes fill with a sad look that longs\n\
  attention.\n");
  add_spell("byronchomp","#MN# $HW$chomps $HK$down$N$ on your arm causing $Y$MASSIVE DAMAGE$N$.\n",
                       "#MN# $HW$chomps $HK$down$N$ on #TN#\'s arm causing $Y$MASSIVE DAMAGE$N$.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(2000)+3000);
  }