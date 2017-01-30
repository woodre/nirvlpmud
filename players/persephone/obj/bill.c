inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("dubloons");
 set_alias("gold");
 set_short("Gold Dubloons");
 set_long("Some extremely rare and valuable looking gold dubloons\n");
 set_weight(4);
 set_value(random(1000));
}
get(){
 return 1;
}
