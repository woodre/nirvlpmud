inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset (int arg){
 set_id("goldkey");
 set_alias("key");
 set_short("Intricately Carved Golden Key");
 set_long("This is an extremely elegant but robust golden key with some\n" +
          "arcane message written on it perhaps you should decipher it\n\n");
 set_weight(2);
 set_value(2000);
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
 write("To the great Vvlad keep this safe Queen Elizabeth\n");
 say(CAPTPLNM + " closely peruses the key looking for information.\n");
 return 1;
}

