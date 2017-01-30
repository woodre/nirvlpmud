#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("puppy");
   set_alt_name("smurf");
   set_short(""+CYN+"Puppy Smurf"+NORM+"");
   set_race("canine");
   set_long(
      "Puppy was originally given to Papa Smurf as a pet.  Seeing\n"+
      "the energy that he had and the time it would take to train him\n"+
      "he decided it best to turn him over the the Smurflings.  He\n"+
      "has been a faithful friend and protector ever since.\n");
   set_wander(25, 0, ({ "southwest" }));
   set_level(3);
   set_hp(95);
   set_wc(4);
   set_ac(4);
   set_al(35);
   set_chat_chance(12);
   load_chat("Puppy slobbers all over you.\n");
   load_chat("Puppy rolls around in the grass.\n");
   load_chat("Puppy sniffs you.\n");
   load_chat("Puppy chases his tail around until he gets dizzy.\n");
   
   move_object(clone_object("/players/puppy/s/eq/collar.c"), this_object());
   init_command("wear collar");
   
}
