#include "/players/francesco/univ/ansi.h"
inherit "obj/treasure.c";

reset(arg) {
set_weight(1);
set_value(0);
set_id("ticket");}
short() { return HIB+"A piece of a ticket"+NORM; }

long(str) {
    write("One half of the cinema ticket.\n");
   return;}
  
