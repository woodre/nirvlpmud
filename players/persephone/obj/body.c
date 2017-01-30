inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("body");
 set_alias("corpse");
 set_short("A human corpse");
 set_long("The corpse of a human who knows in these parts it might have\n" +
          "some monetary value and yes the cadaver is quite dead\n");
 set_weight(4);
 set_value(random(1000));
}
get(){
 return 1;
}
