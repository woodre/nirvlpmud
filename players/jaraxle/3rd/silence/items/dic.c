#include "/players/jaraxle/define.h"
inherit "/obj/treasure.c";
reset(int arg) {
   if(arg) return;
   set_alias("dictionary");
   set_short(HIY+"Spanish"+NORM+" to "+RED+"En"+WHT+"gli"+BLU+"sh"+NORM+" Dictionary");
set_long("A pocket sized translation book.\n"+
"Translates "+HIY+"Spanish"+NORM+" to "+RED+"En"+WHT+"gli"+BLU+"sh"+NORM+" on the fly.\n"+
HIW+"("+NORM+MAG+"Only in Jaraxle's areas, at the moment"+HIW+")\n"+NORM);
   set_value(1000);
}
id(str){ return str == "s2e_dictionary" || str == "dic" || str == "book"; }

