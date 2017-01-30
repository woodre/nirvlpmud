#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
     set_name("loincloth");
     set_alias("loincloth");
     set_short(YEL+"Deerskin Loincloth"+NORM);
     set_long(
       "A small piece of tanned deerskin held on by strips of leather.\n");

     set_ac(1);
     set_type("underwear");
     set_weight(1);
     set_value(100);
}

