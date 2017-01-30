#include "/players/tallos/ansi.h"
#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("earring") ;
   set_alias("earrings");
   set_short(""+HIC+"Earrings "+NORM+"of"+HIC+" Shielding"+NORM);
   set_long(" \n"+
            "                             "+NORM+""+WHT+"O-]"+HIC+"@    @"+NORM+""+NORM+""+WHT+"[-O"+NORM+"\n"+
            " \n"+
            "       This finely crafted set of earrings "+HIC+"GLOW"+NORM+" with a "+HIC+"pale blue\n"+
            "light"+NORM+".  They offer superior "+HIB+"protection"+NORM+" from all type of attacks.\n"+
            "The set appears to be quite valuable. \n");
   set_params("other|fire",0,5,0);
   set_params("other|ice",0,5,0);
   set_params("other|acid",0,5,0);
   set_params("other|poison",0,5,0);
   set_params("other|sonic",0,5,0);
   set_params("other|water",0,5,0);
   set_params("other|earth",0,5,0);
   set_params("other|wind",0,5,0);
   set_params("other|electric",0,5,0);      
   set_weight(1);
   set_value(10000);
   set_type("earring") ;
   set_ac(2) ;
}
