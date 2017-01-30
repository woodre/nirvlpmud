#include "/players/wocket/closed/ansi.h"
id(str){ return str == "matrix_silence"; }

drop(){ return 1; }
query_auto_load(){ return "/players/wocket/junk/matrix_silence.c:"; }
init(){
  write("Your lips begin to meld shut.\n");
  write(GRN+FLASH+"The matrix has you.\n"+OFF);
  call_out("wake_up",1000);
  add_action("notell","tell");
  add_action("notell","gossip");
  add_action("notell","shout");
  add_action("notell","ste",1);
  add_action("notell","stt",1);
  add_action("notell","'");
  add_action("notell","say",1);
  add_action("notell","risque");
  add_action("notell","babble");
  add_action("notell","equip");
  add_action("notell","junk");
  add_action("notell","?",1);
  add_action("notell","vibe",1);
  add_action("notell","dt",1);
  add_action("notell","te",1);
  add_action("notell","tc",1);
  add_action("notell","derv",1);
  add_action("notell","net");
  add_action("notell","nem");
  add_action("notell","onet");
  add_action("notell","rt",1);
  add_action("notell","drt",1);
  add_action("notell","ht",1);
  add_action("notell",":",1);
  add_action("notell","emote");
  add_action("notell","mail");
  add_action("notell","chtell");
}

wake_up(){
  remove_call_out("wake_up");
  tell_object(environment(this_object()),"\n\nYou wake up.\nWas it all a dream?\n\n\n");
  destruct(this_object());
 }
notell(str){
  write("Your lips have somehow melded shut.\n");
  write(GRN+FLASH+"The matrix has you.\n"+OFF);
move_object(this_object(),this_player());
return 1;
}