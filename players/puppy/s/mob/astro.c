#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("astro");
   set_short(""+HIB+"Astro"+NORM+"");
   set_alt_name("smurf");
   set_race("smurf");
   set_long(
      "Astro Smurf is one of those few Smurfs that dream of leaving\n"+
      "this place.  He gazes at the stars almost every night while\n"+
      "wondering what else could be out there.  He has managed to\n"+
      "create a working ship, and is just waiting for Papa Smurf to\n"+
      "find the right source of fuel.\n");
   set_level(5);
   set_hp(150);
   set_wc(5);
   set_ac(4);
   set_al(140);
   set_chat_chance(7);
   load_chat("Astro Smurf looks up at the sky.\n");
   load_chat("Astro Smurf dreams of what is beyond this land.\n");
   move_object(clone_object("/players/puppy/s/eq/space.c"), this_object());
   init_command("wear armor");
   
}
