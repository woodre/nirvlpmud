inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset (int arg){
 set_id("adamentite key");
 set_alias("key");
 set_short("A Square Key");
 set_long("A strange looking key that is totally square and made with some\n" +
          "strange metal perhaps Adamentite\n");
 set_weight(1);
 set_value(0);
}
get(){
 return 1;
}

