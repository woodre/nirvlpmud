/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        None
 *  Function:     special armor to have during Tour de France
 *  Create Date:  2004.07.03
 *  Last Edit:    2004.07.03 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/define.h"
inherit "obj/armor";

reset(arg) {
/* added next 2 lines - v */
  ::reset(arg);
  if(arg) return;
  set_name("livestrong bracelet");
  set_alias("bracelet");  
  set_short(HIY+"A small yellow bracelet"+NORM);
  set_long(
    "  This is a small, yellow bracelet that fits snugly on your wrist.\n"+
    "It is made from an elastic plastic, but also seems pretty strong.  The\n"+
    "words: "+HIY+"LIVE STRONG"+NORM+" have been molded into its surface.  The inside of\n"+
    "of it is inscribed with: "+HIY+"www.wearyellow.com"+NORM+".  Wear it with pride!\n");
  set_ac(0);
  set_type("bracelet");
  set_weight(1);
  set_value(0);
}

do_special(owner) {
  if(!random(6)) {
    tell_object(owner, 
      "You grimace from the hit...but then think to yourself, \""+(!random(2) ? HIW : HIY)+"Live Strong"+NORM+".\"\n"+
      "You catch a second wind.\n");
    (!random(2) ? owner->add_hit_point(1+random(4)) : owner->add_spell_point(1+random(4)));
    return 1;
  }
}




query_save_flag() { return 1; }
