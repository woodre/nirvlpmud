inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("gold");
 set_alias("bar");
 set_short("A Bar of Goldish Metal");
 set_long("A bar of soft gold coloured metal you think that it might have some\n" +
          "monetary value\n" +
          "\n");
 set_weight(3);
 set_value(random(2000));
}
get(){
 return 1;
}
