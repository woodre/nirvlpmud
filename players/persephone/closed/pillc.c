inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("aspirin");
 set_alias("tablet");
 set_short("An aspirin");
 set_long("This is a white tablet with a big AH on it you can only\n" +
          "guess it stands for Akdov and Havoc Pharmaceuticals\n" +
          "\n");
 set_weight(0);
 set_value(50);
}
get(){
 return 1;
}
init(){
 ::init();
  add_action("swallow1","swallow");
}
swallow1(str){
 if(str=="aspirin" || str=="pill"){
  write("Nothing happens you feel quite disappointed but you sense this pill\n" +
        "was not for you at all but someone else.\n");
  say(CAPTPLNM+" looks disappointed.\n");
  destruct(this_object());
  return 1;
 }
}

