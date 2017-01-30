inherit "obj/treasure";
#include "/players/persephone/rooms.h"
string message;
reset (int arg){
 set_id("wreath");
 set_short("A Floral Wreath");
 set_weight(0);
 set_value(50);
}
drop(){
  write("You place the wreath at the base of the statue to show your\n" +
       "respect.\n\n");
  say(CAPTPLNM + " places the wreath at the base of the monument.");
  move_object(this_object(),environment(this_player()));
  return 1;
}
init(){
 add_action("write_me","write");
}
write_me(str){
 if(!str){
  notify_fail("Write what do you want to write???\n");
  return 0;
 }
 if (message){
  notify_fail("The wreath already has a message on it!\n");
 }
 message=str;
 write ("You scribe: "+str+" on the wreath.\n" +
        "It seems a superb piece of calligraphy\n\n");
 say (CAPTPLNM + " writes something on a wreath.\n\n");
 return 1;
}
long(foo) {
 write("A gorgeous floral wreath of beautiful yet solemn flowers with\n" +
       "the message "+message+" on it.\n");
 say(CAPTPLNM + " examines the wreath closely.\n");
}
 
