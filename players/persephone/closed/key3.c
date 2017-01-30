inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset (int arg){
 set_id("plastickey");
 set_alias("key");
 set_short("A Plastic Card");
 set_long("This is a plastic card that looks like it has a magnetic\n" +
          "strip running down the back of it you do not know what it is\n" +
          "as the writing on it is all rubbed away\n");
 set_weight(1);
 set_value(0);
}
get(){
 return 1;
}

