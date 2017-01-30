#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_short("A water pail (held)");
  set_long("A small water pail.\n");
   set_weight(1);
   set_value(0);
}
id(str){ return str == "pail" || str == "water pail" ||  str == "water"; }

