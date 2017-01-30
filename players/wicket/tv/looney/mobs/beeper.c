inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/runshoes.c"), this_object()); 
  command("wear shoes", this_object());
  set_name("beeper");
  set_alt_name("little");
  set_race("toon");
  set_alias("toon beeper");
  set_short(YEL+"Little Beeper"+NORM);
  set_long("\
   A young roadrunner with a orange colored feathers. He has a long slender\n\
  neck with a short yellow beack. His Fan of feathers on top of his head are\n\
  a bright red. His pink little tounge flaps in and out of his beak. His small\n\
  wings on his body just flutter around as if they cannot stay still. He is\n\
  wearing a pair of blue running shoes with white laces. His long slender\n\
  yellow legs he has make him very quick in speed.\n");
  add_spell("beeperspin","#MN# $HK$Bursts$N$ into a $HW$dash $HK$slaughtering$N$ you with multiple hits.\n",
                       "#MN# $HK$Bursts$N$ into a $HW$dash $HK$slaughtering$N$ #TN# with multiple hits.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(2000)+2000);
  }