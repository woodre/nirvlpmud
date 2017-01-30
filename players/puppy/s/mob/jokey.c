#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("jokey");
   set_alt_name("smurf");
   set_short(""+HIB+"Jokey Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Jokey Smurf spends all his time concocting pranks. He builds\n"+
      "gift wrapped packages that explode in your face. Sometimes\n"+
      "he gets on Smurfs nerves.  Once in a while, his jokes backfire.\n");
   set_level(4);
   set_hp(150);
   set_wc(5);
   set_ac(4);
   set_al(0);
   move_object(clone_object("/players/puppy/s/eq/present.c"), this_object());
   
}
