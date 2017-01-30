inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("glasses");
 set_alias("specs");
 set_short("A pair of womble sized glasses");
 set_long("Womble Glasses are made out of any old bits and pieces they\n" +
          "can find bye the look of them they seem to belong to Heironomus\n" +
          "Womble\n\n");
 set_weight(1);
 set_value(150);
}
get(){
 return 1;
}
init(){
 ::init();
  add_action("wear1","wear");
}
wear1(str){
 if(str=="glasses" || str=="spectacles"){
  write("You think they would look rather silly on you and might\n" +
           "break if you tried them on\n\n");
  return 1;
 }
 write("What are you trying to wear\n\n");
return 1;
}
