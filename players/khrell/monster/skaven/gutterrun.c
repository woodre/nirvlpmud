#include "/players/khrell/define.h"
#include <ansi.h>

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name(HIK+"gutter runner"+NORM);
  set_alt_name("gutter");
  set_alias("runner");
  set_short(HIK+"Gutter Runner"+NORM);
  set_long("\
Clan Eshin Gutter Runners are adepts of their shadowed arts.  Though\n\
they are nto full fledged assassins yet they are still quite deadly \n\
and never to be underestimated.  Garbed in all black cloth they stick\n\
to the shadows and await the perfect ti mto striek at their prey.    \n");
  set_gender("male");
  set_race("skaven");
  set_level(19);
  set_wc(30);
  set_ac(15);
  set_hp(500);
  set_al(-1000);
  set_aggressive(1);
  

set_chat_chance(10);
load_chat("The shadows seem to move.\n");
load_chat("Something moves outside your field of vision.\n");
load_chat("Disembodied eyes blink at you then vanish.\n");

set_a_chat_chance(25);
load_a_chat("The "+HIK+"Gutter Runner"+NORM+" easily dodges your clumsy attack.\n");
load_a_chat("With ease the "+HIK+"Gutter Runner"+NORM+" blocks your strike.\n");
  
  set_multi_cast(1);
  add_spell("shuriken-storm",
  "A number of $G$warpstone$N$ shuriken slice into you!\n",
  "#MN# becomes a blur of motion as it spins suddenly about releasing many glittering $G$shrukien$N$ at you!\n",
  10,({50,50}),({"other|physical","other|poison"}),1);  
  
  add_spell("shadow paw",
  "$HW$#MN#'s paws flash out striking #MP# multiple times!$N$\n",
  "$HW$#MN#'s paws flash out striking #TN# multiple times!$N$\n",
  25,40,"physical",1);
   
gold = clone_object("obj/money");
gold->set_money(random(2000));
move_object(gold,this_object());
}
