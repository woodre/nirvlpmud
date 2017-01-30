inherit "/obj/monster";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/wicket/tv/looney/armor/dizzyhat.c"), this_object()); 
  command("wear hat", this_object());
  move_object(clone_object("/players/wicket/tv/looney/armor/dizzywhirl.c"), this_object()); 
  command("wear whirlwind", this_object());
  set_name("dizzy");
  set_alt_name("devil");
  set_race("toon");
  set_alias("toon dizzy");
  set_short(MAG+"Dizzy Devil"+NORM);
  set_long("\
   A young tasmanian devil with a small beanie on his head is spinng about\n\
  the room in a frenzy. One of his eyes are pink the other is green, he is\n\
  very chaotic and energetic and seems to never stop moving. This little\n\
  monster is always looking for food, drool surrounds his mouth as he grunts\n\
  and babbles. His feet are huge and his arms are small and stubby.\n");
  add_spell("dizzydash","#MN# spins into a $HR$FRENZY$N$ $HK$smashing$N$ into YOU.\n",
                        "#MN# spins into #TN# in a $HR$mad FRENZY$N$ $HK$smashing$N$ them.\n",
                        50,45,0,0);
  set_level(19);
  set_hp(500+ random(100));
  set_ac(15+ random(4));
  set_wc(28+ random(4));
  set_al(0);
  add_money(random(2000)+3000);
  }