#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("king");
   set_alt_name("smurf");
   set_short(""+HIB+"King Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "King Smurf thought that while Papa Smurf was away, he would\n"+
      "appoint himself leader of the Smurfs.  The other Smurfs\n"+
      "allowed him to think that he was in charge for a while, but\n"+
      "tired of him being so bossy.  These days, he walks around\n"+
      "holding his head high, trying to get everyone to think he\n"+
      "is something he is not.\n");
   set_level(5);
   set_hp(150);
   set_wc(5);
   set_ac(4);
   set_al(10);
   
   move_object(clone_object("/players/puppy/s/eq/scepter.c"), this_object());
   init_command("wield weapon");
   move_object(clone_object("/players/puppy/s/eq/crown.c"), this_object());
   init_command("wear helmet");
   move_object(clone_object("/players/puppy/s/eq/cape.c"), this_object());
   init_command("wear cape");
   
}
