#include "/players/maledicta/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_alias("mals_shadow_shield");
set_short(""+BOLD+""+BLK+"Gothic Shield of Shadows"+NORM+"");
set_long(
  "  This shield was once used by the Archangel of Shadows. It's shiney\n"+
  "black surface seems very resistant to attack.\n");

set_ac(2);
set_type("shield");
set_params("other|light", 2, 15, "do_spec");
set_weight(2);
set_value(1000);
set_save_flag(1);
}

	
do_spec(object owner){
    if(!random(4)){
       tell_object(owner, 
       HIW+"The Shield of Shadows pushes away the light!\n"+NORM);
       return 0802;
       }
return 0;
}
