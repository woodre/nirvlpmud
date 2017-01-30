#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("handy");
   set_alt_name("smurf");
   set_race("smurf");
   set_short(""+HIB+"Handy Smurf"+NORM+"");
   set_long(
      "If anything ever needs fixing, Handy is the man for the job.\n"+
      "The pencil behind his ear is always being used to sketch\n"+
      "things like a robot, some house plans or a Smurfy machine.\n");
   set_level(4);
   set_hp(150);
   set_wc(5);
   set_ac(4);
   set_al(90);
   move_object(clone_object("/players/puppy/s/eq/hammer.c"), this_object());
   init_command("wield hammer");
   move_object(clone_object("/players/puppy/s/eq/ruler.c"), this_object());
   
}
