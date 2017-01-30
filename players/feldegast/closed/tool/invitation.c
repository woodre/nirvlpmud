#include "/players/feldegast/defines.h"
inherit "obj/treasure";

string inviter;
object dest;

void reset(int arg) {
  set_id("invitation");
  set_short("An invitation");
  set_long("A parchment scroll tied with a blue ribbon.  It is an invitation\n"+
          "that you may choose to 'accept' or decline by waiting two minutes.\n");
  call_out("time_out",120);
}

void init() {
  add_action("cmd_accept","accept");
}

int cmd_accept(string str) {
  write("An "+BLU+"azure"+NORM+" portal opens before you.\n"+
        "Boldly, you stride across its threshold and into another place.\n");
  say(TP->query_name()+" steps through an "+HIB+"azure"+NORM+" portal.\n");
  move_object(TP,dest);
  say(TP->query_name()+" enters the room through an "+HIB+"azure"+NORM+" portal.\n");
  command("look",TP);
  destruct(this_object());
  return 1;
}

void set_inviter(string str) { inviter=str; }
void set_place(object ob) { dest=ob; }
long(str) {
  write("This is an invitation from "+inviter+" to travel to "+
        dest->short()+".  All you have to do is 'accept invitation'.\n");
}

void time_out() {
  tell_object(environment(this_object()),"The invitation bursts into flame.\n");
  if(find_player(inviter))
    tell_object(find_player(inviter),(string)environment()->query_name()+"'s invitation timed out.\n");
  destruct(this_object());
}
