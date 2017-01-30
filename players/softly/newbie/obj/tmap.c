#include "/players/softly/closed/ansi.h"
inherit "/obj/treasure";

reset(arg)  {
  if(arg) return;

   set_id("map" || "town map");
   set_short("Town Map");
   set_long("\n"+BOLD+
"             ~*~ Nirvana Town Center ~*~\n"+NORM+
"\n"+BLK+BOLD+                                      
"    N\n"+NORM+
"    |                                        Day   Weapon-\n"+
" "+BLK+BOLD+" W"+NORM+"-o-"+BLK+BOLD+"E"+NORM+"                                     Care +  smith\n"+
"    |                                            | \n"+BLK+BOLD+
"    S"+NORM+"                      Chapel          Magic + Hotel\n"+
"                             |                   | \n"+BOLD+
"  ENTRY-->"+NORM+" Church       Yard + Pub  Shop   Armor + Bank\n"+
"             |               |       |           |\n"+
"  Bridge -"+HIG+" Green"+NORM+" - Track - Road -  Road   -    Clock - "+RED+"Pizza\n"+NORM+
"                 |    |              |         Tower   "+RED+" Hut\n"+NORM+
"               Alley            Adventurers\n"+
"                      |            Guild\n"+
"                    Post\n"+
"                   Office\n\n"+
"  The"+HIB+" Hall of the Apprentices"+NORM+" is in the Village Green.\n\n");

   set_weight(0);
   set_value(0);
}
