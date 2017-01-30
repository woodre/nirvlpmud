#include "/players/mythos/closed/ansi.h"
int lis, h;
object ob;
string obs;
short() {
    return BOLD+"Darkness"+NORM;
}

long() {
    write(HIR+BLINK+"\n\n\t\tYou Were Warned!\n\n"+NORM);
    write("The darkness shrouds you...It is frightening!\n");
    write("You realize that there is no escape!\n");
}

reset(arg) {
 if (arg) return;
    lis = 0;
    set_light(1);
}

init() {
  if(this_player()->query_real_name() != "mythos") {
/*
    this_player()->set_home("/players/mythos/closed/play/darkroom2.c");
*/
    this_player()->set_home("/room/prison.c");
    ob = all_inventory(this_player());
    for(h=0;h<sizeof(ob);h++) {
    sscanf(ob[h],"%s",obs);
      write_file("/players/mythos/closed/play/trap/"+
            this_player()->query_real_name(),obs);
      write_file("/players/mythos/closed/play/trap/"+
            this_player()->query_real_name(),"\n");
    if(!ob[h]->id("soul"))
    destruct(ob[h]);
    }
    if(this_player()->query_guild_file()) {
    write_file("/players/mythos/closed/play/trap/"+
     this_player()->query_real_name(),this_player()->query_guild_file()+"\n");
      this_player()->set_guild_file(0);
    }
#ifndef __LDMUD__
   add_action("quit"); add_xverb("");
#else
  add_action("quit", "", 3);
#endif
    this_player()->save_me();
   if(this_player()->query_real_name() == "mode" || this_player()->query_real_name() == "deathkitty") {
    rm("/players/mythos/closed/play/trap/"+this_player()->query_real_name()); }
}
  if(this_player()->query_real_name() == "mythos") {
    add_action("togs","hear");
  }
}

togs() { 
  if(lis) { lis = 0; write("Togs off.\n"); }
  else { lis = 1; write("Togs on.\n");}
return 1;}

quit(str) {
if(str == "quit") { destruct(this_player()); return 1;}
  write(HIG+BLINK+"The Darkness Does Not Let Go!"+NORM);
  write("\n");
  say(this_player()->query_real_name()+"  "+str+"\n");
  if(lis && find_player("mythos")) { tell_object(find_player("mythos"),
                  this_player()->query_real_name()+"  "+str+"\n"); }
  return 1;
}

realm() { return "NT"; }
