#include "/players/wocket/closed/ansi.h"
id(str){ return str == "w_silence"; }

drop(){ return 1; }
query_auto_load(){ return "/players/wocket/junk/w_silence.c:"; }
init(){
  write(BOLD+"*  * *   *   * *   *   * *   *   * *  *  * *   *  * *\n"+OFF);
  write("Magic sparkles around you as pain gives way to fear.\n");
  write("Your voice floats up through your mouth before you only\n"+
        "to SHATTER before your eyes.\n");
  write("You have been silenced.\n");
  write(BOLD+"*  * *   *   * *   *   * *   *   * *  *  * *   *  * *\n"+OFF);
  call_out("wake_up",500);
  add_action("notell","tell");
  add_action("notell","gossip");
  add_action("notell","shout");
  add_action("notell","ste");
  add_action("notell","stt");
  add_action("notell","'");
  add_action("notell","say");
  add_action("notell","risque");
  add_action("notell","babble");
  add_action("notell","equip");
  add_action("notell","junk");
  add_action("notell","?");
  add_action("notell","vibe");
  add_action("notell","dt",2);
  add_action("notell","te");
  add_action("notell","tc");
  add_action("notell","derv");
  add_action("notell","net");
  add_action("notell","nem");
  add_action("notell","onet");
  add_action("notell","rt");
  add_action("notell","drt");
  add_action("notell","ht");
  add_action("notell",":",1);
  add_action("notell","emote");
  add_action("notell","mail");
  add_action("notell","chtell");
}

wake_up(){
  remove_call_out("wake_up");
  tell_object(environment(this_object()),HIM+"\n\nMagic "+HIY+"FLARES"+HIM+" around you as your voice returns.\n\n\n"+OFF);
  destruct(this_object());
 }
notell(str){
  write("You have no voice!\n");
move_object(this_object(),this_player());
return 1;
}
