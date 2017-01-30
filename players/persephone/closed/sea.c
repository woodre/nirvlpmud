inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("royal seal");
 set_alias("seal");
 set_short("A Red Seal");
 set_long("This is a royal looking seal as you examine it you notice that\n" +
          "there is some arcane writing on it perhaps you should read it!!!\n" +
          "\n");
 set_weight(0);
 set_value(50);
}
get(){
 return 1;
}
init(){
 ::init();
  add_action("read1","read");
}
read1(str){
 if(str=="writing" || str=="script" || str=="seal"){
  write("The Royal Seal of Lord Storm property of the Mayor of Stormhold\n");
  say(CAPTPLNM+"  deciphers the code on the seal\n");
  return 1;
 }
}
