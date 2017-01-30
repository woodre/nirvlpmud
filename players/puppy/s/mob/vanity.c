#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("vanity");
   set_alt_name("smurf");
   set_short(""+HIB+"Vanity Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Vanity Smurf is the most selfish Smurf of them all.  He plans\n"+
      "to spend the rest of his life telling other Smurfs about how\n"+
      "great he is.  Someone will get tired of it sooner or later.\n");
   set_level(4);
   set_hp(150);
   set_wc(5);
   set_ac(4);
   set_al(99);
   set_chat_chance(10);
   load_chat("Vanity Smurf looks at himself in the mirror.\n");
   load_chat("Vanity Smurf says: look how Smurfy I am.\n");
   move_object(clone_object("/players/puppy/s/eq/mirror.c"), this_object());
   
   
}
