/*  A dark prison cell  */

#include "/players/eurale/closed/ansi.h"
inherit "room/room";

int lis, h;
object ob;
string obs;

short() {
	return BOLD+"A cold, black cell"+NORM; }

long() {
  write(BOLD+BLINK+"\n\n\t\tYOU WERE WARNED!! \n\n"+NORM);
  write("The blackness surrounds you..... and penetrates your being.\n");
  write("You MUST understand that there is NO escape for you! \n");
  write("Sit quietly and contemplate your punishment... \n\n");
}

reset(arg) {
  if(arg) return;
  lis = 0;
  set_light(1);
}

init() {
  if(this_player()->query_real_name() != "eurale") {
    this_player()->set_home("/players/eurale/closed/prison.c");
  ob = all_inventory(this_player());
  for(h = 0; h < sizeof(ob); h++) {
    sscanf(ob(h),"%s",obs);
	write_file("/players/eurale/closed/trap_"+
	  this_player()->query_real_name(),obs);
	write_file("/players/eurale/closed/trap_"+
	  this_player()->query_real_name(),"\n");
    if(!ob[h]->id("soul"))
    destruct(ob[h]);
  }

  if(this_player()->query_guild_file()) {
  write_file("/players/eurale/closed/trap_"+
    this_player()->query_real_name(),this_player()->query_guild_file()+"\n");
  this_player()->set_guild_file(0);
  }

  this_player()->save_me();
  add_action("quit"); add_xverb(""); }

if(this_player()->query_real_name() == "eurale") {
  add_action("tog","hear"); }
}

tog() {
  if(lis) { lis = 0; write("Tog off.\n"); }
  else { lis = 1; write("Tog on.\n"); }
return 1;
}

quit(str) {
  if(str == "quit") { destruct(this_player()); return 1; }
  write(BLINK+"The Darkness Does NOT Let Go!!"+NORM+"\n");
  say(this_player()->query_real_name()+" "+str+"\n");
  if(lis && find_player("eurale")) {
    tell_object(find_player("eurale"),this_player()->query_real_name()+
    " "+str+"\n"); }
return 1;
}
