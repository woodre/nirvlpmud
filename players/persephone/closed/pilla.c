inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("mogodon");
 set_alias("pill");
 set_short("Mogodon Sleeping Tablet");
 set_long("A pill with the name Mogodon on it you think it might be a tranquilizer\n" +
          "and probably highly addictive I would not swallow it if I were you\n" +
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
 if(str=="mogodon" || str=="pill"){
  write("You are starting to feel sleepy.\n");
  say(CAPTPLNM+" is starting to doze off.\n");
  return 1;
 }
}
