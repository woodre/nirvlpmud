#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_alias("rubble");
set_short("A small pile of rubble");
set_long("A pile of small pieces of rock and thin sand.\n");
   set_weight(2);
   set_value(1+random(10));
}
id(str){ return str == "rubble" || str == "pile" || str == "pile rubble" || str == "pile"; }

