inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "sithi" || str == "lord" || str == "soul'tephar" ||
         str == "soultephar";
}


reset(arg)
{
   if (!present("stone"))
   {
      move_object(clone_object(CASTLEOBJECT+"/sesuadra.c"),
                  this_object());
   }

   ::reset(arg);
   if(arg) return;
   set_name("Soul'tephar");
   set_race("sithi");
   set_alias("sithi");
   set_short("Soul'tephar, the Sithi Lord");
   set_long(
"     Soul'tephar is one of the oldest Sithi Lords. His dazzling gold-\n"+
"silver robes suggest him very influential among the Sithi. His cat-eyes\n"+
"are golden, his hair coal black.\n");
   set_level(14);
   set_hp(random(20)+215);
   set_al(-600);
   set_wc(17);
   set_ac(12);
}
