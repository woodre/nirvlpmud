#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("boots");
     set_ac(2);
     set_value(500);
     set_weight(1);
     set_type("boots");
     set_short(
       ""+BOLD+BLK+"Iron vambraces"+NORM+RED+" of the Bat"+NORM);
     set_long(
       "\n"+
       "\n"+
       "\n");
}

status id(string arg) { return ( ::id(arg) || arg == "crimson_bat_boots" || arg == "bat boots" || arg == "boots" || arg == "crimson boots" || arg == "iron boots" || arg == "vambraces" || arg == "crimson vambraces" || arg == "iron vambraces" ); }
