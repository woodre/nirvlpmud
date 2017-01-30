#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("hefty");
   set_alt_name("smurf");
   set_race("smurf");
   set_short(""+HIB+"Hefty Smurf"+NORM+"");
   set_long(
      "Hefty is the strongest Smurf in the village. He exercises,\n"+
      "he is a sportsman, and he even organizes the Smurf Olympics.\n"+
      "One can always depend on him if there is any work to be done.\n");
   set_level(6);
   set_hp(200);
   set_wc(5);
   set_ac(5);
   set_al(100);
   move_object(clone_object("/players/puppy/s/eq/bbell.c"), this_object());
   
}
