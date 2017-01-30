#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("farmer");
   set_alt_name("smurf");
   set_short(""+HIB+"Farmer Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Farmer Smurf is the most down to earth Smurf.  This is most\n"+
      "likely because he works in it all the time.  He likes the\n"+
      "simple things in life and usually doesn't bother the other\n"+
      "Smurfs.  His only passion in life is watching his crops grow.\n");
   set_level(7);
   set_hp(150);
   set_wc(5);
   set_ac(4);
   set_al(100);
   set_chat_chance(12);
   
   load_chat("Farmer Smurf digs in the dirt.\n");
   load_chat("Farmer Smurf checks his crops.\n");
   move_object(clone_object("/players/puppy/s/eq/gloves.c"), this_object());
   init_command("wear ring");
   move_object(clone_object("/players/puppy/s/eq/boots.c"), this_object());
   init_command("wear boots");
   move_object(clone_object("/players/puppy/s/eq/shovel.c"), this_object());
   init_command("wield weapon");
   
}
