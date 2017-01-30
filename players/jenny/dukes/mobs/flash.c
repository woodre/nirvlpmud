inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Flash");
    set_race("dog");
    set_alias("velvet ears");
    set_alt_name("flash");
    set_al(35+random(20));
    set_level(7);
    set_hp(30+random(20));
    set_wc(7+random(2));
    set_ac(4+random(2));
    set_short(BOLD+""+YEL+"Flash"+NORM);
    set_long(
      "Flash is Rosco's old brown basset hound.  She is so old, she can\n"+
    "barely move.  Flash gets to ride with Rosco on all the car chases,\n"+
   "luckily, she has never been hurt due to Rosco's bad driving.  Flash\n"+
    "is generally a quiet dog, but does bark at Boss Hogg.  Rosco\n"+
    "affectionately calls her 'velvet ears'.\n"); 
}
