inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("paper");
 set_alias("newspaper");
 set_short("The Stormhold Times");
 set_long("A local Newspaper that appears to be totally blank\n");
 set_weight(1);
 set_value(100);
}
get(){
 return 1;
}
