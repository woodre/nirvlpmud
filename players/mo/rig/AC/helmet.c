inherit "obj/armor";

#include <ansi.h>

reset(arg) {
   ::reset(arg);
   
   if(arg) return; 
   
   set_name("hat");
   set_alias("helmet");
   set_short(BOLD+"A "+YEL+"yellow"+NORM+""+BOLD+" hard hat"+NORM);
   set_long(
      "This is a yellow hard hat this is required to be worn by\n"+
      "all personnel on the Chinle Oil Platform.\n");
   set_weight(2);
   set_value(300);
   
   set_ac(2);
   set_type("helmet");
}

