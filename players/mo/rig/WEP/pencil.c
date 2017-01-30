inherit "/obj/weapon.c";

#include <ansi.h>

void reset(int arg) {
   ::reset(arg);
   if(arg) return;
   set_name("pencil");
   set_short("A mechanical pencil");
   set_long(
      "A simple 0.7 mm lead mechanical pencil.\n");
   set_type("knife");
   set_class(9);
   set_weight(1);
   set_value(100);
}

