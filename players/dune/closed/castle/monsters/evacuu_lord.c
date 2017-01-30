inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "sithi" || str == "lord" || str == "evacuu" || str == "evacu'u";
}


reset(arg)
{
   if (!present("stone"))
   {
      move_object(clone_object(CASTLEOBJECT+"/yasira.c"),
                  this_object());
   }

   ::reset(arg);
   if(arg) return;
   set_name("Evacu'u");
   set_race("sithi");
   set_alias("sithi");
   set_short("Evacu'u, the Sithi Lord");
   set_long(
"     Evacu'u is a very beautiful female Sithi. She wears a simlple\n"+
"shiny blue silk robe. Her hair is pure white but for a blue streak.\n"+
"Her eyes are of the deepest blue.\n");
   set_level(14);
   set_hp(random(20)+215);
   set_al(-600);
   set_wc(17);
   set_ac(12);
}
