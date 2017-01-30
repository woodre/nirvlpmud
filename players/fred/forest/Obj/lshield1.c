#include "/players/fred/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_short(HIY+"Light"+NORM+" Shield");
set_long(
"  A small box connected to a leather strap that can \n"+
"fit neatly around your waist.  As you look closer at \n"+
"it you notice it's a shield!\n");   

set_ac(1);
set_type("shield");  
set_weight(1);
set_value(200);
}

wear(str)
{
  if(!id(str)) return 0;
if(worn) return 0;
::wear(str);
write("Beams of light shoot out of the box to form a\n"+
      "translucent barrier around you!\n");
say(this_player()->query_name()+ " turns on the shield.\n");
return 1;
}

remove(str){
  if(!id(str)) return 0;
  if(!worn) return 0;
::remove(str);
write("The shield fades from around your body and disappears\n"+
      "back into the small box.\n");
say(this_player()->query_name()+" shuts off the shield.\n");
return 1; 
}