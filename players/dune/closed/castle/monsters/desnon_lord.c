inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "sithi" || str == "lord" || str == "desnon";
}


reset(arg)
{

   if (!present("stone"))
   {
      move_object(clone_object(CASTLEOBJECT+"/resurieni.c"),
                  this_object());
   }

   ::reset(arg);
   if(arg) return;
   set_name("Desnon");
   set_race("sithi");
   set_alias("sithi");
   set_short("Desnon, the Sithi Lord");
   set_long(
"     Tall Desnon, past Sithi Lord of Peace, has\n"+
"visibly digressed. His once beautiful tan brown\n"+
"hair has whitened and grown to his waist. Desnon's\n"+
"eyes have blackened, and his face wrinkled. Whatever\n"+
"trace of peace within him has died. Now only madness\n"+
"reigns.\n");
   set_level(14);
   set_hp(random(20)+255);
   set_al(0);
   set_wc(16);
   set_ac(13);
}
