#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("baby");
   set_alt_name("smurf");
   set_short(""+CYN+"Baby Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "No one really knows where it is that Baby Smurf came from,  \n"+ 
      "or for that matter really cares.  He has been adopted by all\n"+
      "of the Smurfs and they all really care for him a lot.  He \n"+
      "loves to play with his block set that Handy Smurf gave him.\n");
   set_level(2);
   set_hp(50);
   set_wc(5);
   set_ac(2);
   set_al(50);
   set_chat_chance(5);
   
   load_chat("Baby Smurf looks over the different sides of the blocks.\n");
   load_chat("Baby Smurf stacks the blocks on top of each other.\n");
   load_chat("Baby Smurf plays with his blocks.\n");
   
   move_object(clone_object("/players/puppy/s/eq/block.c"), this_object());
   move_object(clone_object("/players/puppy/s/eq/block.c"), this_object());
   move_object(clone_object("/players/puppy/s/eq/block.c"), this_object());
   
}
