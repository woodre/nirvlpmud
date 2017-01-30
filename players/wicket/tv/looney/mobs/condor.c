inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/feathernecklace.c"), this_object()); 
  command("wear necklace", this_object());
  set_name("concord");
  set_alt_name("condor");
  set_race("toon");
  set_alias("toon concord");
  set_short(MAG+"Conc"+HIM+"ord Co"+NORM+MAG+"ndor"+NORM);
  set_long("\
   A young goofy looking condor that is a purple color. He has a wacky\n\
  looking Bowl cut of feathers on top of his head. His feet are a very\n\
  bright orange and chunky. He is very short and stocky but very dumbfounded.\n\
  His eyes are even crossed and he is not the brightest of the bunch. A\n\
  small collar of feathers pad his neck.\n");
  add_spell("beakdriller","#MN# $HK$pecks$N$ the $HR$HELL$N$ out of your chest causing $HR$blood $N$to pour.\n",
                       "#MN# $HK$pecks$N$ the $HR$HELL$N$ out of #TN#\'s chest causing $HR$blood $N$to pour.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(2000)+2500);
  }