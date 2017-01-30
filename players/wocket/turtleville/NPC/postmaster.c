#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/wocket/turtleville/OBJ/posthat.c"),this_object());
move_object(clone_object("/players/wocket/turtleville/OBJ/letters.c"),this_object());
  set_name("fred");
  set_alias("postmaster");
  set_gender("male");
  set_race("seussian");
  set_short("Fred the Postmaster");
  set_long("Fred wears a spiffy new blue uniform.  Brass buttons\n"+
           "and shiny shoes glint in the light.  His hat is crooked\n"+
           "to the center of his head but he pays no attention.  He\n"+
           "is carrying a bag filled to the brim with letters.\n");
  set_level(15);
  set_hp(225);
  set_wc(20);
  set_ac(12);
  set_al(500);
  set_a_chat_chance(15);
  load_a_chat("Fred screams in pain.\n");
  load_a_chat("Fred wimpers from the pain.\n");

}
