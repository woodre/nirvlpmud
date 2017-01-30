#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/weapon.c";

prevent_insert() {
    write("You cant put that in there, it's rented!\n");
    return 1;
}


reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("cane");
set_alias("cane");
set_short(HIW+"White Walking Cane"+NORM);
set_long(
  "A shiney white walking cane.  The grip, made of solid gold, \n"+
  "is formed in the shape of an eagle head. \n")
;

set_type("cane");  /*  sword/knife/club/axe/bow/polearm  */
set_class(11);
set_weight(1);
set_value(50);
}
query_save_flag() { return 1; }