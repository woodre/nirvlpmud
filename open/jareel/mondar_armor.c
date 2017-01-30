#include "/players/jareel/define.h"
inherit "/obj/armor.c";
object ob;
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset(arg) {
       ::reset(arg);

     set_name("death armor");
     set_ac(5);
     set_value(5000);
     set_weight(3);
     set_type("armor");
     set_short(
       "Iron "+BOLD+BLK+"armor"+NORM+" of death");
     set_long(
       "The armor of death is a dull grey with six\n"+
       "inch protruding spikes from each shoulder.\n"+
       "The armor appears to be finely crafted\n");
}


status id(string arg) { return ( ::id(arg) || arg == "mondar_armor" ); }
