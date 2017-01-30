#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("nat");
   set_alt_name("smurf");
   set_short(""+CYN+"Nat Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Nat loves to be outside playing with all kinds of different\n"+
      "creatures.  Most of the time he can be found trying to get\n"+
      "Puppy Smurf to learn smurfy tricks.\n");
   set_level(2);
   set_hp(75);
   set_wc(5);
   set_ac(4);
   set_al(10);
   move_object(clone_object("/players/puppy/s/eq/nathat.c"), this_object());
   init_command("wear hat");
   
}
