inherit "obj/weapon";
#include "/players/catacomb/misc/ansi.h"

reset(arg){
    if(arg) return;
set_name("despair");
set_alias("sword");
set_type("sword");
set_class(17);
set_short(HIW+"Despair"+NORM+", the longsword");
set_long(
"  A longsword created by Yeroc that channels all of his\n"+
"sadness into the blade.  Its blade is covered in carved\n"+
"runes.  The blade curves in then out then into a razor-sharp\n"+
"point giving it the look of an inverse hourglass.  The\n"+
"hilt has roses carved into it.  At the end an onyx gem is\n"+
"embedded onto Despair.\n");
set_value(5000);
set_weight(2);

set_hit_func(this_object());
}
mixed
weapon_hit(object attacker)
{
   string name;
   
   if(environment() && environment()->is_player()) 
   {
      name=(string)environment()->query_name(); 
   }
    if(!name) return 0;
}

   
