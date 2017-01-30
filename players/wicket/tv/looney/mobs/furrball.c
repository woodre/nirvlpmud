inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("furrball");
  set_alt_name("cat");
  set_race("toon");
  set_alias("toon furrball");
  set_short(BLU+"Furrball"+NORM+" the "+BLU+"Cat"+NORM);
  set_long("\
   A small little cat that seems to wander the alleyways homeless. His fur\n\
  a deep blue color that is very coarse. Fleas jump on to his coat and\n\
  he smells very bad. The tail is bandaged up with white gauze and tape.\n\
  His ear has a small hole in it. He is very clumsy and always stumbling into\n\
  something and getting hurt. He looks around the surrounding area for food\n\
  and a warm dry place to sleep.\n");
  add_spell("furrballunlucky","#MN# $HK$curse$N$ you with $HK$bad luck$N$ as a piano falls from the sky $HR$SMASHING$N$ you.\n",
                       "#MN# $HK$curse$N$ #TN# as a piano falls from the sky $HR$SMASHING$N$ them.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(540+ random(60));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1500)+3500);
  }