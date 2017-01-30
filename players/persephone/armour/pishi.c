#include "/players/persephone/rooms.h"
inherit "obj/armor";
reset(arg){
 if(arg) return;
  set_name("shield");
  set_short("Light Shield");
  set_long("A light but useful shield the type that pirates might\n" +
           "use if the decided to use a shield.\n");
  set_value (1000);
  set_weight(1);
  set_ac(1);
  set_type("shield");
}
