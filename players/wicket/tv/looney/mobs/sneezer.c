inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/diaper.c"), this_object()); 
  command("wear diaper", this_object());
  set_name("sneezer");
  set_alt_name("mouse");
  set_race("toon");
  set_alias("toon sneezer");
  set_short(HIK+"Sneezer"+NORM+" the "+HIK+"Mouse"+NORM);
  set_long("\
   A dumbfounded baby mouse with a soft grey fur that has almost a purple\n\
  tint to it. He has a diaper pinned to his waist. His ears are massive, the\n\
  inside of them are bright pink. His eyes have a confused look to them. His\n\
  teeth stick out the top of his mouth past his lip. He twitches his black nose\n\
  asking questions to himself.\n");
  add_spell("sneezersneeze","#MN# $HY$sneezes$N$ releasing a blast of $HG$snot$N$ making you sick$N$.\n",
                       "#MN# $HY$sneezes$N$ releasing a blast of $HG$snot$N$ making #TN# sick.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(2000)+3000);
  }