#include "/players/wocket/closed/ansi.h"

id(str){ return str == "matrix_silence"; }

drop(){ return 1; }
query_auto_load(){ return "/players/feldegast/junk/matrix_silence.c:"; }

init_arg(str) {
  write("Your lips begin to meld shut.\n");
  write(GRN+FLASH+"The matrix has you.\n"+OFF);
  call_out("hb",1);
}
init(){
  add_action("notell","tell");
  add_action("notell","gossip");
  add_action("notell","shout");
  add_action("notell","ste");
  add_action("notell","stt");
  add_action("notell");add_xverb("'");
  add_action("notell","say");
  add_action("notell","risque");
  add_action("notell","babble");
  add_action("notell","equip");
  add_action("notell","junk");
  add_action("notell","?");
  add_action("notell","vibe");
  add_action("notell","dt");
  add_action("notell","te");
  add_action("notell","tc");
  add_action("notell","derv");
  add_action("notell","net");
  add_action("notell","nem");
  add_action("notell","onet");
  add_action("notell","rt");
  add_action("notell","drt");
  add_action("notell","ht");
  add_action("notell",":");
  add_action("notell","emote");
  add_action("notell","mail");
  add_action("notell","chtell");
  add_action("notell","farem");
  add_action("notell","emto");
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

hb() {
  move_object(this_object(),environment());
  call_out("hb",10);
}
