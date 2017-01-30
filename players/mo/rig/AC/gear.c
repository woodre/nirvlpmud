inherit "obj/armor";

#include <ansi.h>

reset(arg) {
   ::reset(arg);
   
   if(arg) return; 
   
   set_name("vest");
   set_alias("gear");
   set_short(YEL+"Reflective Gear"+NORM);
   set_long(
      "A yellow vest that covers your chest.  It is required to be\n"+
      "worn by all personnel working on the Chinle Oil Platform.\n");
   set_weight(1);
   set_value(300);
   
   set_ac(1);
   set_type("chest");
}

