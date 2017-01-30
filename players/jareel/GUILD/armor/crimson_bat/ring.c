#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("gauntlets");
     set_ac(2);
     set_value(500);
     set_weight(1);
     set_type("ring");
     set_short(
       ""+BOLD+BLK+"Iron gauntlets"+NORM+RED+" of the Bat"+NORM);
     set_long(
       "\n"+
       "\n"+
       "\n");
}

status id(string arg) { return ( ::id(arg) || arg == "crimson_bat_ring" || arg == "gauntlets" || arg == "iron gauntlets" || arg == "gauntlets helm" || arg == "gauntlets of the bat" || arg == "gloves" ); }
