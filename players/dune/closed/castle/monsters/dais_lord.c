inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "sithi" || str == "lord" || str == "dais";
}

reset(arg)
{
   if (!present("stone"))
   {
      move_object(clone_object(CASTLEOBJECT+"/shisaeron.c"),
                  this_object());
   }

   ::reset(arg);
   if(arg) return;
   set_name("Dais");
   set_race("sithi");
   set_alias("sithi");
   set_short("Dais, the Sithi Lord");
   set_long(
"     Dais is a young handsome Sithi. He is strong and graceful in\n"+
"posture. His golden-dyed hair falls to his shoulders. He looks upon\n"+
"you with blue eyes.\n");
   set_level(14);
   set_hp(random(20)+215);
   set_al(-600);
   set_wc(17);
   set_ac(12);
}
