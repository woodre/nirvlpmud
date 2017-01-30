inherit "obj/monster";
#include "definitions.h"



id(str)
{
  return str == "sithi" || str == "lord" || str == "smaeonte" || 
         str == "smae'onte";
}


reset(arg)
{
   if (!present("stone"))
   {
      move_object(clone_object(CASTLEOBJECT+"/minneyar.c"),
                  this_object());
   }

   ::reset(arg);
   if(arg) return;
   set_name("Smae'onte");
   set_race("sithi");
   set_alias("sithi");
   set_short("Smae'onte, the Sithi Lord");
   set_long(
"     Smae'onte is a powerful looking Sithi. He wears red and black\n"+
"garbs. Amulets, rings, and various other ornamentation are fitted upon\n"+
"him. His hair is dyed an orange-red. His eyes are brown.\n");
   set_level(14);
   set_hp(random(20)+215);
   set_al(-600);
   set_wc(17);
   set_ac(12);
}
