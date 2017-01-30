/*
An object for adding people to a chat channel.
Written by Mythos, modified for use with soul.c by Feldegast
4-15-00
*/

#define ESC ""
#define RED ESC+"[31m"       
#define BLU ESC+"[34m"
#define BOLD ESC+"[1m"          
#define NORM ESC+"[2;37;0m"     
#define MST "/obj/user/mchat.c"

object targ,from;
string ch;

id(str) { return str == "chat_ask"; }

drop() { return 1; }

set_target(ob) { targ = ob; }
set_from(ob) { from = ob; }
set_channel(str) { ch = str; }

init() { 
  string *members,dude;
  int scooby;
  if(this_player() == targ) {
    write(capitalize(from->query_real_name())+" wishes you to join the "+ch+" channel.\n");
    write("Current members of channel: \n");
      write(""+
  "name\t\tgender\tstatus\n"+RED+
  "_________________________________________________________\n\n"+NORM);

  members=MST->query_members(ch);
  if(!members) {
    destruct(this_object());
    return;
  }
  for(scooby=sizeof(members)-1; scooby >= 0; scooby--) {
    dude=members[scooby];  
    if(dude) {
      write(pad(capitalize(dude->query_real_name()),15));
      write("\t"+dude->query_gender()+"\t");
      if(dude->query_attack()) 
        write(BLU+"C"+NORM);
      if(dude->is_ghost()) 
        write(BOLD+"D"+NORM);
      if(!dude->query_interactive()) 
        write("dc");
      if(dude->query_idle()) 
        write("i");
      write("\n");
    }
  }
  write("\n"+RED+
  "_________________________________________________________\n"+
  "                                  "+ch+"\n"+NORM);
    write("To join type 'join yes' to refuse type 'join no'\n"+
          "Note: this will destruct in 30 secs.\n");
  add_action("join", "join");
  call_out("dd",40);
  }
}

join(str) {
  object ob;
  if(!str) { str = "no"; }
  if(str == "Y" || str == "y" || str == "yes") {
    if(!MST->addmem(ch,this_player()->query_real_name())) {
      write("You cannot be added to that channel or are already a member.\n");
      tell_object(from,"That person cannot be added to the channel.\n"+
                       "Check to see if they are already a member.\n");
    } 
    else {
      ob = present("soul",this_player());
      if(ob) {
        ob->add_chat(ch);
        write("You have been added to channel '"+ch+"'.\n");
        MST->chat(ch,":has joined the channel.\n");
        destruct(this_object());
        return 1;
      } 
    }
  }
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
