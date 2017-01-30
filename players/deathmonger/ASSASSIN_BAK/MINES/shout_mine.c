string message, who;
object target;
int set, armed;

id(str){ return str == "junkmine" || str == "mine"; }

get(){ return 0; }

value() { return 300; }

query_value(){ return 600; }

init()
{
  if(target && this_player() == target)
    blow_up();
  add_action("set","set");
  add_action("unset","unset");
  add_action("drop","drop");
  add_action("message", "message");
}

message(str)
{ 
  if(message)
  {
    write("A message has already been set.\n");
    return 1;
  }
  message = str;
  write("Mine message set to: "+str+"\n");
  return 1;
}

set(str)
{
  target = find_player(str);
  if(!str)
  {
    write("Usage: set <player>\n");
    return 1;
  }
 
  if(!set)
  {
    write("Land mine set for "+target->query_name()+".\n");
    set = 1;
    return 1;
  }
 
  if(set)
  {
    write("Land mine already set for someone.\n");
    return 1;
  }
}

short(){ return "A land mine"; }

long()
{
  write("This is a land mine.  To operate, here are the commands:\n"+
        "set <player>          sets which player will set off the mine.\n"+
        "unset                 unsets the mine.\n"+
        "drop mine             arms the mine and drops it in the room.\n"+
        "message <message>     sets a the mine's message when it goes off.\n\n"+
        "Remember that once dropped the mine cannot be picked up.\n"+
        "This particular mine:\n"+
        "Emits a message set by you when tripped off.\n");
}

unset()
{
  if(!set)
  {
    write("Land mine has not been set.\n");
    return 1;
  }
  if(set)
  {
    write("Land mine disarmed.\n");
    set = 0;
    return 1;
  }
}

drop(str)
{
  if(str == "mine")
  {
    if(!set)
    {
      write("You can't just go around dropping land mines randomly!\n");
      return 1;
    }
    if(set)
    {
      write("Land mine set and armed.\n");
      armed = 1;
      move_object(this_object(), environment(this_player()));
      return 1;
    }
  }
}

blow_up()
{
  
  tell_object(target, "You feel the force of a land mine blast!\n");
  tell_room(environment(this_object()), 
    capitalize(target->query_name())+" is blasted by a land mine!\n");
 
  if(message)
  {
    emit_channel("junk", "\n(junk) "+message+"\n");
    destruct(this_object());
    return 1;
  }
  else
    emit_channel("junk", "\n(junk) "+capitalize(target->query_name())+" is so stupid that "+target->query_pronoun()+"\n"+
                 "tripped on a land mine!\n");

    destruct(this_object());
    return 1;
}
