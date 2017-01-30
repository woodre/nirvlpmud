/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        City of Keats
 *  Function:     generic armor
 *  Create Date:  2004.06.03
 *  Last Edit:    2004.06.08 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/realms/keats/keatsdefine.h"

#define CRIMSON_WIZ_ROBE HIR+"Crim"+NORM+RED+"son "+HIR+"Wiz"+NORM+RED+"ard "+HIR+"Ro"+NORM+RED+"bes"+NORM

inherit "obj/armor";

reset(arg) {
  set_name("crimson wizard robes");
  set_alias("robes");  
  set_short(CRIMSON_WIZ_ROBE);
  set_long(
    "This beautifully hand-crafted garment shimmers and sparkles with an\n"+
    "incandescent life.  Silky smooth to the touch, yet incredibly stiff,\n"+
    "it appears that these robes may be enchanted in order to provide\n"+ 
    "added protection beyond their normal means.  The back of the robes\n"+
    "is woven with a magnificent design: a wide burgundy stripe runs the\n"+
    "length of the material, and an ellipitcal blue orb is been sewn onto\n"+
    "it.  Eight smaller orbs ring the blue one; each is a different color\n"+
    "and bears a single symbol embroidered in white silk thread.\n");
  set_ac(4);
  set_type("armor");
  set_weight(1);
  set_value(3000);
}

