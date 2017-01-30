inherit "obj/armor";
#include "/players/jareel/ansi.h"
#include "/players/jareel/define.h"
#define ATT USER->query_attack()
#define USER environment(this_object())

     reset() {
     set_name("beads");
     set_id("amulet");
     set_alias("beads");
     set_short(BLU+"Cheesy plastic beads"+NORM);
     set_long(
       "This is a cheep string of plastic beads.\n");
     set_ac(0);
     set_type("amulet");
     set_weight(1);
     set_value(1);
     }
