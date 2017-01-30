#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("painter");
   set_alt_name("smurf");
   set_short(""+HIB+"Painter Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Painter Smurf always loved to draw as a child.  Now that he\n"+
      "is all grown, that is almost all he does.  He mostly paints\n"+
      "portraits of other Smurfs, but on a rare occasion he can be\n"+
      "found painting landscapes.\n");
   set_level(4);
   set_hp(150);
   set_wc(5);
   set_ac(4);
   set_al(75);
   move_object(clone_object("/players/puppy/s/eq/brush.c"), this_object());
   move_object(clone_object("/players/puppy/s/eq/apron.c"), this_object());
   init_command("wear shield");
   
   
}
