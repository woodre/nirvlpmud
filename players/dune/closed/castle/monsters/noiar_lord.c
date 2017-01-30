inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "sithi" || str == "lord" || str == "noiar";
}


reset(arg)
{
   if (!present("stone"))
   {
      move_object(clone_object(CASTLEOBJECT+"/zaeymiritha.c"),
                  this_object());
   }

   ::reset(arg);
   if(arg) return;
   set_name("Noiar");
   set_race("sithi");
   set_alias("sithi");
   set_short("Noiar, the Sithi Lord");
   set_long(
"     Noiar is a tall handsome Sithi. He wears satin red robes as\n"+
"shiny as silk. His hair is pure white, his eyes pure red. He has a\n"+
"commanding look about him.\n");
   set_level(14);
   set_hp(random(20)+215);
   set_al(-600);
   set_wc(17);
   set_ac(12);
}
