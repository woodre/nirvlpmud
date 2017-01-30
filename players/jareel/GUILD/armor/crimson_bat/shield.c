#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("shield");
     set_ac(2);
     set_value(500);
     set_weight(2);
     set_type("shield");
     set_short(
       ""+BOLD+BLK+"Iron shield"+NORM+RED+" of the Bat"+NORM);
     set_long(
       "\n"+
       "\n"+
       "\n");
}

status id(string arg) { return ( ::id(arg) || arg == "crimson_bat_shield" || arg == "shield" || arg == "iron shield" || arg == "crimson bat shield" || arg == "shield of the bat" || arg == "crimson shield"  ); }
