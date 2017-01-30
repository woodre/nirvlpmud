#include "/players/wocket/closed/ansi.h"
id(str){ return str == "notell.c"; }

init(){
  write("Your lips begin to meld shut.\n");
  write(GRN+FLASH+"The matrix has you.\n"+OFF);
  call_out("wake_up",10);
  add_action("notell","tell");
  add_action("notell","shout");
}

wake_up(){
  remove_call_out("wake_up");
  tell_object(environment(this_object()),"\n\nYou wake up.\nWas it all a dream?\n\n\n");
  destruct(this_object());
 }
notell(str){
  write("Your lips have somehow melded shut.\n");
  write(GRN+FLASH+"The matrix has you.\n"+OFF);
return 1;
}
