#include "/players/jenny/define.h"
inherit "/obj/armor.c";
reset(arg) {
   if(arg) return;
   set_name("bud bundy's hat");
   set_alias("cap");
   set_id("hat");
   set_ac(-1);
   set_value(1300);
   set_weight(1);
   set_type("helmet");
   set_short(""+RED+"Bud Bundy's hat"+NORM+"");
   
   set_long(
      "This is a black cap Bud Bundy wore backwards while calling himself\n"+
      "'Grandmaster B'.  Wearing this might make you look like a dork.\n");
}
