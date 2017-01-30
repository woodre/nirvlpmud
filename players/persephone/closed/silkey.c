inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset (int arg){
 set_id("silverkey");
 set_alias("key");
 set_short("Finely Crafted Silver Key");
 set_long("This is an extremely elegant looking silverkey with some\n" +
          "arcane message written on it perhaps you should decipher it\n\n");
 set_weight(2);
 set_value(0);
}
get(){
 return 1;
}
init(){
 ::init();
  add_action("decipher","decipher");
  add_action("decipher","decode");
}
decipher(){
 write("This is the property of the Stormhold Police if found return\n" +
       "to the Sargeant Stormhold Police Station\n\n");
 say(CAPTPLNM + " closely peruses the key looking for information.\n");
 return 1;
}

