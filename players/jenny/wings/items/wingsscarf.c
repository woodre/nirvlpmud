#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
   if(arg) return;
   set_name("scarf");
   set_alias("red wings scarf");
   set_id("scarf");
   set_ac(1);
   set_value(40);
   set_weight(1);
   set_type("misc");
   set_short("Detroit "+RED+"Red Wings "+NORM+"scarf");
   set_long(
      "This is a long red scarf with the winged wheel logo of the "+RED+"Detroit\n"+
      "Red Wings"+NORM+" on it.\n");
}
