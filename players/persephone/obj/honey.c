inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("honey");
 set_short("A Lump of Honey");
 set_long("A delicious looking piece of honeycomb by the smell of it you\n" +
          "guess that it is blueberry honey YUMMY!! However it does not look \n" +
          "like it has healing properties\n\n");
 set_weight(1);
 set_value(250);
}
get(){
 return 1;
}
init(){
 ::init();
  add_action("eat1","eat");
}
eat1(str){
 if(str=="honey" || str=="honeycomb"){
  write("You eat some really scumptious honey but feel guilty about\n" +
           "eating it.\n\n");
  destruct(this_object());
  return 1;
 }
 write("What do you want to eat\n\n");
return 1;
}
