#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("amulet");
     set_ac(2);
     set_value(500);
     set_weight(1);
     set_type("amulet");
     set_short(
       ""+BOLD+BLK+"Iron amulet"+NORM+RED+" of the Bat"+NORM);
     set_long(
       "\n"+
       "\n"+
       "\n");
}

status id(string arg) { return ( ::id(arg) || arg == "crimson_bat_amulet" || arg == "amy" || arg == "bat amulet" || arg == "amulet" || arg == "crimson amulet" || arg == " guildamulet" ); }
