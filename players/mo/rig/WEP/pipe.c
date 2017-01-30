inherit "/obj/weapon.c";

#include <ansi.h>

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   set_name("pipe");
   set_short(BOLD+"A Metal Pipe"+NORM);
   set_long(
      "A 3in diameter metal pipe that is used on the \n"+
      "Chinle Oil Platform.\n");
   set_type("polearm");
   set_class(14);
   set_weight(4);
   set_value(500);
}

