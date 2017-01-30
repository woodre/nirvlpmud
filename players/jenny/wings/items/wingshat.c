#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
   if(arg) return;
   set_name("Red Wings hat");
   set_alias("cap");
   set_id("hat");
   set_ac(1);
   set_value(35);
   set_weight(1);
   set_type("helmet");
   set_short("Detroit "+RED+"Red Wings "+NORM+"hat");
   set_long(
      "This is a red corduroy hat with a winged wheel on the front.  The \n"+
      "winged wheel is the logo of the "+RED+"Detroit Red Wings."+NORM+"\n");
}
