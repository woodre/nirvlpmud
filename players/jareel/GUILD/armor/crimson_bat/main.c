#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("armor");
     set_ac(5);
     set_value(5000);
     set_weight(3);
     set_type("armor");
     set_short(
       ""+BOLD+BLK+"Iron Plate"+NORM+RED+" of the Bat"+NORM);
     set_long(
       "\n"+
       "\n"+
       "\n");
}

status id(string arg) { return ( ::id(arg) || arg == "crimson_bat_armor" || arg == "crimson bat plate" || arg == "crimson plate" || arg == "iron plate" || arg == "plate" ); }
