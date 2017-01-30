inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("speed");
 set_alias("tablet");
 set_short("A tablet of Instant Speed");
 set_long("A pill with the name Speed on it you think it might be a amphetimine\n" +
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
 if(str=="speed" || str=="pill"){
  write("You suddenly feel ten feet tall and feel a rush of energy.\n");
  say(CAPTPLNM+" seems to have gotten a sudden burst of speed");
  destruct(this_object());
  return 1;
 }
}
