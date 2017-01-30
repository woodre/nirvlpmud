inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/overalls.c"), this_object()); 
  command("wear overalls", this_object());
  set_name("hamton");
  set_alt_name("pig");
  set_race("toon");
  set_alias("toon hamton");
  set_short(HIM+"Hamton J"+NORM+"."+HIM+" Pig"+NORM);
  set_long("\
   A chunky little cartoon pig with his blue overalls that come down from\n\
  his shoulders. The overalls barely able to fit from his chunky little\n\
  belly, his little curly tail pokes out the back. He has a short stubby\n\
  pushed in snout with small floppy ears, his eyes wandering around looking\n\
  for food. Nothing is more big than the hunger this poor pig has for food.\n");
  add_spell("hamtonchomp","#MN# $HC$drools$N$ as he mistakes you for $G$food$N$ and $HW$bites $N$you.\n",
                       "#MN# $HC$drools$N$ as he mistakes #TN# for $G$food$N$ and $HW$bites$N$ them.\n",
                       40,40,0,0);
  set_level(19);
  set_hp(550+ random(50));
  set_ac(16+ random(3));
  set_wc(24+ random(8));
  set_al(0);
  add_money(random(1500)+2500);
  }