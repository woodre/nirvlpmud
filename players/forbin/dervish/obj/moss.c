/* 
 * Forbin
 * Created:   2003.09.11
 * Last edit: 2003.09.12 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/obj/treasure";
#define ROOT "/players/snow/dervish/trials/trial1/"

id(str) { return (::id(str) || str == "moss" || str == "dervish quest moss"); }

reset(arg) {
  if(arg) return;
   
  set_short(YEL+"a strip of brown moss"+NORM);
  set_long("  A thick strip of brown moss; it is prickly on one side and\n"+
           "covered with short roots on the other.\n");
  set_weight(1);
  set_value(11);
}

init() {
  ::init();
}


