#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("helm");
     set_ac(2);
     set_value(500);
     set_weight(1);
     set_type("helmet");
     set_short(
       ""+BOLD+BLK+"Full Iron Helm"+NORM+RED+" of the Bat"+NORM);
     set_long(
       "\n"+
       "\n"+
       "\n");
}

status id(string arg) { return ( ::id(arg) || arg == "crimson_bat_helm" || arg == "helm" || arg == "helmet" || arg == "full helm" || arg == "iron helm" || arg == "crimson helm" || arg == "crimson bat helm"); }
