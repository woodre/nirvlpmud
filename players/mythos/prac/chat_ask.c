#include "/players/mythos/closed/ansi.h"
#define MST "/players/mythos/prac/mchat.c"
object targ,from;
string ch;
string dude;
int h;
int chnum;

id(str) { return str == "chat_ask"; }

drop() { return 1; }

set_target(ob) { targ = ob; }
set_from(ob) { from = ob; }
set_channel(str) { ch = str; chnum = MST->chat_name(ch);}

init() { 
  if(this_player() == targ) {
    write(from->query_real_name()+" wishes you to join the "+ch+" channel.\n");
    write("Current members of channel: \n");
      write(""+
  "name\t\tgender\tstatus\n"+RED+
  "_________________________________________________________\n\n"+NORM);
  h = 0;
dude = 0;
  while(h < 5) {
  if(h == 0) dude = MST->query_mem1(chnum);
  if(h == 1) dude = MST->query_mem2(chnum);
  if(h == 2) dude = MST->query_mem3(chnum);
  if(h == 3) dude = MST->query_mem4(chnum);
  if(h == 4) dude = MST->query_mem5(chnum);
  if(dude) if(find_player(dude)) {
    write(capitalize(dude));
    if(strlen(dude) < 8) write("\t");
    write("\t"+find_player(dude)->query_gender()+
          "\t");
    if(find_player(dude)->query_attack()) 
       write(BLU+"C"+NORM);
    if(find_player(dude)->is_ghost()) 
       write(BOLD+"D"+NORM);
    if(!find_player(dude)->query_interactive()) 
       write("dc");
    if(find_player(dude)->query_idle()) 
       write("i");
    write("\n");
  }
  dude = 0;
  h++; }
  write("\n"+RED+
  "_________________________________________________________\n"+
  "                                  "+ch+"\n"+NORM);
    write("To join type 'joinyes' to refuse type 'joinno'\n"+
          "Note: this will destruct in 30 secs.\n");
#ifndef __LDMUD__
  add_action("join");add_xverb("join");
#else
  add_action("join", "join", 3);
#endif
  call_out("dd",40);
  }
}

join(str) {
object ob;
  if(!str) {str = "no"; }
  ob = 0;
  if(str == "Y" || str == "y" || str == "yes") {
    if(!MST->addmem(ch,this_player()->query_real_name())) {
      write("Something is wrong. Contact Mythos.\n");
      tell_object(from,"Something is wrong with the chatter boxes.\n"+
                       "Contact Mythos.  \n"+
                       "Also check if that person is already in that channel.\n");
    } else {
    ob = present("chatter box",this_player());
    if(!ob) {
      ob = clone_object("/players/mythos/prac/chatter.c");
      write("You have a chatter box.\n"); }
    }
    if(ob) { ob->add_chat(ch);
    move_object(ob,this_player()); } 
    destruct(this_object());
  return 1;} 
  tell_object(from,targ->query_real_name()+" turns down the channel offer.\n");
  write("You turn down the channel offer.\n");
  destruct(this_object()); 
return 1; 
}

dd() {
  tell_object(from,targ->query_real_name()+" turns down the channel offer.\n");
  tell_object(environment(this_object()),"You turn down the channel offer.\n");
  destruct(this_object()); 
return 1; 
}
