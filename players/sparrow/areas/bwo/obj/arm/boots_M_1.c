/*****************************************************************************
 *      File:                   monkboots.c
 *      Function:               BWO unidentified boots
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow All Rights Reserved.
 *      Source:                 03/24/2006
 *      Notes:                  
 *      Change History:         
 ****************************************************************************/
#include <ansi.h>
#include "/players/sparrow/areas/bwo/include/defs.h"
inherit "/players/sparrow/areas/bwo/include/gear_funcs.c";
inherit "obj/armor";

reset(arg){
   ::reset(arg);
   set_name("monk boots");
   set_short(HIK+"Black Willow Boots "+NORM+"<"+MAG+"[]"+NORM+">");
   set_alias("boots");
   set_long("These boots first appear to be common black boots. Under further\n"+
            "inspection, notice that they have been encrusted around the soles\n"+
            "with gems. These boots provide minor protection against magic.\n");
   set_type("boots");
   set_ac(1);
   set_weight(1);
   set_value(650);
   set_params("magical",0,3,0);
}

  
    
