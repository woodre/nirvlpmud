#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("cape");
     set_ac(2);
     set_value(500);
     set_weight(1);
     set_type("misc");
     set_short(
       ""+BOLD+BLK+"Iron Guard"+NORM+RED+" of the Bat"+NORM);
     set_long(
       "\n"+
       "\n"+
       "\n");
}

status id(string arg) { return ( ::id(arg) || arg == "crimson_bat_misc" || arg == "crimson bat guard" || arg == "guard" || arg == "crimson guard" || arg == "iron guard" || arg == "guard of the bat"  ); }
