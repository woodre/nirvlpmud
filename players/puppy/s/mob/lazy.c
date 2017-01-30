#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("lazy");
   set_alt_name("smurf");
   set_short(""+HIB+"Lazy Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Lazy Smurf spends most of his day trying to find a better\n"+
      "place to take a nap.  When he wakes in the morning, he starts\n"+
      "to think about sleep. Most of the other Smurfs don't really\n"+
      "mind this, though. Lazy seems to know all the good hiding\n"+
      "places away from Gargamel and Azrael.\n");
   set_level(5);
   set_hp(150);
   set_wc(3);
   set_ac(3);
   set_al(50);
   
}
