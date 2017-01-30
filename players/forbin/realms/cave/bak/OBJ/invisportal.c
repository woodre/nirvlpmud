/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Qual'tor Miniquest
//  Function:     room atmosphere
//  Create Date:  2005.02.17
//  Last Edit:    2005.02.17 -Forbin
*/

#include "/players/forbin/realms/cave/cavedefine.h"

inherit "/obj/treasure";

int PortalOnOff;

id(str) { return (::id(str) || str == "invisportal" || 
                               str == "ivory portal"); }

reset(arg) {
  if(arg) return;
  set_short(0);
  set_id("portal");
  set_alias("sfp_miniquest_portal");
  PortalOnOff = 0;
}

long() {
  if(PortalOnOff)
    long_desc = 
      "As wide as it is tall, a portal or gateway of some sort stands some\n"+
      "ten feet high.  It looks to be made from ivory, its slender, white\n"+
      "framework carved intricately in circles, spirals and many other\n"+
      "intersecting shapes.  A shimmering field of purple energy fills its\n"+
      "opening and flickers now and again.  It is immpossible to see through\n"+
      "to what lies on the other side.\n";
  else
    long_desc =
      "As wide as it is tall, a portal or gateway of some sort stands some\n"+
      "ten feet high.  It looks to be made from ivory, its slender, white\n"+
      "framework carved intricately in circles, spirals and many other\n"+
      "intersecting shapes.  An almost dull blackness fills its rectangular\n"+
      "opening, as if there is a total absence of anything there.\n";
  ::long();
}

get() { return 0; }

set_portal_onoff(int num) { PortalOnOff = num; }

query_portal_onoff() { return PortalOnOff; }