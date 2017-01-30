#include "/players/puppy/define.h"
inherit "/obj/monster";

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("poet");
   set_alt_name("smurf");
   set_short(""+HIB+"Poet Smurf"+NORM+"");
   set_race("smurf");
   set_long(
      "Poet Smurf just loves to write poems.  For every thing he\n"+ 
      "writes down, he thinks of three more.  It's a shame that no\n"+
      "one will publish any of his works.  Who reads Smurf anyway?\n");
   set_level(5);
   set_hp(150);
   set_wc(5);
   set_ac(4);
   set_al(80);
   set_chat_chance(11);
   load_chat("Poet Smurf writes something on the parchment.\n");
   load_chat("Poet Smurf rolls up the parchment.\n");
   load_chat("Poet Smurf thinks of another poem.\n");
   
   move_object(clone_object("/players/puppy/s/eq/quill.c"), this_object());
   move_object(clone_object("/players/puppy/s/eq/parchment.c"), this_object());
   
}
