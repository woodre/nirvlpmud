#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

     set_name("chief");
     set_alias("chief");
     set_alt_name("wocawanee");
     set_race("american indian");
     set_short(HIB+"Chief Wocawanee"+NORM);
     set_gender("male");
     set_long(
       "The leader of the Anasazi tribe.  His wrinkling leathered \n"+
       "skin bears the markings of a hard life.  His hair, braided \n"+
       "on the sides with eagle feathers hanging, is quite gray now.\n"+
       "Sitting on the floor upon a blanket, he chants quietly in \n"+
       "low tones, praying to the gods for a good harvest.\n");

     set_level(20);
     set_hp(500);
     set_al(500);
     set_aggressive(0);

  if(!present("headdress")) {
     move_object(clone_object("players/dreamspeakr/mesa/OBJ/headres.c"),
       this_object()); 
     }

       init_command("wear headdress");

  if(!present("blanket")) {
     move_object(clone_object("players/dreamspeakr/mesa/OBJ/blanket.c"),
       this_object()); 
     }

       init_command("wear blanket");

  if(!present("basket")) {
     move_object(clone_object("players/dreamspeakr/mesa/OBJ/basket2.c"),
       this_object()); 
     }

  set_wc(30);
  set_ac(17);
}
