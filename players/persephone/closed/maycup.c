inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("gold cup");
 set_alias("cup");
 set_short("A Tarnished Yellow Cup");
 set_long("A metallic cup that is grimy with years of use.\n" +
          "You cannot be sure but it might be very valuable\n" +
          "\n");
 set_weight(2);
 set_value(500);
}
get(){
 return 1;
}

