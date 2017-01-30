status loaded; /* added by verte */

inherit "/obj/treasure.c";
#include "../all.h"
int x, in;
object owner, maker;
string name;
reset(arg){
  if(arg) return;

    x = 0;
    in = 0;  /* not part of the channel yet */
    set_short(0);
    set_long(0);
    set_weight(0);
    set_value(0);
}

drop(){ return 1; }
get(){ return 0; }

check()
{
  if(!environment()) 
    return;
  if(!environment()->is_player())
  {
    destruct(this_object());
    return;
  }
  if(!owner) 
  {
    destruct(this_object());
    return;
  }
  write(capitalize((string)owner->query_real_name())+
    " would like to speak with you.\n"+
    "Type 'okay' to join, or ignore this.\n"+
    "You have 25 seconds to respond.\n");
}

void init(){
  ::init();
  check();
  call_out("dest", 25);
  add_action("speak_cmd", "speak");
  add_action("speak_cmd", "sp");
  add_action("join_cmd", "okay");
  add_action("quit_cmd", "quit");
  if(!loaded)
  {
    call_out("safety", 30);
    loaded ++;
  }
}

id(str){ return str == "zeus_chatter" || str == "chan_obj"; }
query_save_flag(){ return 1; }
set_owner(x){ owner = x; }
set_maker(x){ maker = x; }

query_maker(){ return maker; }

safety()
{
  if(environment() && !environment()->is_player())
    destruct(this_object());
  else if(!owner) 
    destruct(this_object());
  else
  {
    while(remove_call_out("safety") != -1);
    call_out("safety", 30);
  }
}

extra_look()
{
  if(!maker) { destruct(this_object()); return; }
  if(environment() == this_player())
    return "You are in a conversation with "+maker->QN+".  'speak / sp'";
}

dest()
{
  if(0 != x) 
    return;
  if(!environment()) 
    return;
  if(!owner)
  {
    destruct(this_object());
    return;
  }
  if(!environment()->is_player())
  {
    destruct(this_object());
    return;
  }
  name = capitalize((string)environment()->query_real_name());
  present("circle_object", owner)->dspeak(name,
    "has declined the invitation.",1);
  tell_object(environment(), "You decline the invitation.\n");
  destruct(this_object());
}

join_cmd()
{
  if(x) 
    return 0;
  if(!owner)
  {
    destruct(this_object());
    return;
  }
  name = capitalize((string)this_player()->query_real_name());
  present("circle_object", owner)->dspeak(name,
    "has joined the conversation.",1);
  write("Type 'speak' / 'sp' to talk, or for a list of commands.\n");
  x = 1;
  in = 1;
  return 1;
}

leave(object x)
{
  if(!owner)
  {
    destruct(this_object());
    return;
  }
  name = capitalize((string)x->query_real_name());
  if(present("circle_object", owner))
  {
    present("circle_object", owner)->dspeak(name,
      "has left the conversation.",1);
    destruct(this_object());
  }
}

speak_cmd(str)
{
  if(!owner)
  {
    destruct(this_object());
    return;
  }
  if(!str)
  {
    write(BOLD+BLK+"\n\tConversation commands...\n\n"+NORM+
      "\tspeak / sp\t\ttalk on channel\n"+
      "\t <:>\t\t\temote\n"+
      "\t <who>\t\t\tsee who is on the channel\n"+
      "\t <mon>\t\t\ttell everyone your status\n"+
      "\t <history>\t\tsee the channel history\n"+
      "\t <leave>\t\tclose the channel\n"+
      "\n");
    return 1;
  }
  if(str == "leave")
  {
    leave(this_player());
    return 1;
  }
  if(str == "mon")
    present("circle_object", owner)->mon(this_player());
  else 
  {
    name = capitalize((string)this_player()->query_real_name());
   if(present("circle_object", owner))
    present("circle_object", owner)->dspeak(name,str,0);
  }
  return 1;
}

quit_cmd(){  leave(this_player());  }
query_in(){ return in; }


