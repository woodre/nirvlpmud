/*
Held by goldcloak5.c
*/
#include "defs.h"

/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("helm");
  set_alias("helmet");
  set_short(BOLD+"Helm"+NORM+" of the "+BLU+"Guardian"+NORM);
  set_long(
    "This is a skillfully crafted helm with a silvery finish to\n"+
    "it that almost seems to glow.  According to legend, this helm\n"+
    "was given to a great knight by the deity known as The Guardian.\n"
  );
  set_ac(2);
  set_type("helmet");
  set_weight(3);
  set_value(1000);
  set_bf_guild_bonus(0, -5);
  set_bf_guild_bonus(1, 10);
  set_bf_guild_bonus(5, 5);
}
