#include "/players/mythos/closed/ansi.h"
string who, what, p;
id(str) {
    return str == "watch";
}

long() {
  write("A nifty high-tech watch.\n"+
         "You may <stime> to check the time\n"+
         "Or simply type <register> to get rid of\n"+
         "those nasty glitches!\n"+
		 "\nNEW item: <wizes> will show you currently\n"+
		 "visible online wizes!\n\n"+
         "<To get rid of this watch type trash_watch>\n\n"+
         "                                  - Mythos\n");
}

short() {
    return "Sci-watch";
}
drop() {return 1;}
get() {return 0;}
query_prevent_shadow() { return 1; } 

query_auto_load() {
    return "/players/mythos/mmisc/watch.c:";
}

init() {
  add_action("check","stime");
  add_action("register","register");
  add_action("wizes","wizes");
 add_action("trash_watch","trash_watch");
}

check() {
    write("\nDisplay: "+GRN+ctime()+NORM+" CST\n");
    call_other("/room/church.c","long","clock");
    write("\n");
    say(capitalize(this_player()->query_name())+" checks the time.\n");
return 1;
}

register(){
int moo;
  if(this_player()->query_ghost()) {
   write("You are a ghost!\n");
return 1; }
  moo = 0;
  if(this_player()->query_fight_area()) moo = 1;
 call_other(this_player(),"reset",1);
    this_player()->recalc_quest();
  if(moo) this_player()->set_fight_area();
    write("Registered....\n");
    return 1; }

trash_watch() { write("You trash the watch.\n");
  destruct(this_object());
  return 1;}

wizes() {
  object ob;
  int h;
  ob = users();
  write("\n~~~~~~~~~~~~ WIZES ~~~~~~~~~~~~~~~\n\n");
  for(h=0;h<sizeof(ob);h++) {
     if(ob[h]->query_level() > 19 && !ob[h]->query_invis()) {
    write("  "+ob[h]->query_level());
     if(ob[h]->query_level() < 100000) write("\t");
    write("  "+ob[h]->query_name()+"\n");
     }
  }
  write("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
return 1; }
