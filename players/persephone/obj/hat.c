inherit "obj/treasure";
#include "/players/persephone/rooms.h"
object tiar;
reset (int arg){
 if(!arg){
  set_id("bonnet");
  set_alias("hat");
  set_short("A Maid's Bonnet");
  set_long("This is a white maid's hat that looks sort of strange\n" +
           "and lumpy. It feels heavier than you think is reasonable\n\n");
  set_weight(3);
  set_value (20);
 }
}
init(){
 ::init();
  add_action("search1","search");
  add_action("search1","examine");
  add_action("pick1","pick");
  add_action("pick1","rip");
  add_action("pick1","pull");
}
search1(str){
 if(str=="hat"||str=="bonnet"||str=="cap"){
  write("You find a loose thread you might possibly be able to pull\n" +
        "but you feel you would ruin the maid's bonnet\n\n");
  say(CAPTPLNM + " closely examines the hat.\n\n");
  return 1;
 }
 write("what do you want to search????\n\n");
 return 1;
}
pick1(str){
 if(str=="thread"||str=="stitches"){
  write("You carefully try to pull the thread but you ruin the\n" +
        "bonnet and find something unexpected.\n\n");
  tiar=clone_object("players/persephone/closed/tiara");
  move_object(tiar, TPL);
  destruct(TOB);
  return 1;
 }
 write("What are you trying to do pick your nose or something??\n\n");
 return 1;
}
