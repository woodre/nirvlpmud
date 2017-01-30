#include "/bin/ghost.c"
 
#pragma strict_types
#pragma save_types
 
int cmd_ping(string str) {
  object who;
  int idle;
  if(ghost())
    return 0;
  if(!str) return (notify_fail("Ping who?\n"), 0);
  who = present(str, environment(this_player()));
  if(who && living(who)) {
    if(who == this_player())
      return 0;
    if(who->query_level() >= 20 && this_player()->query_level() < 20) {
      write("You cannot ping a wizard.\n");
      return 1;
    }
    if(who->query_interactive())
      idle = query_idle(who);
    else
      idle = 666;
    write("You ping "+capitalize(str)+".\n");
    tell_object(who, this_player()->query_name()+" pings you.\n");
    say(this_player()->query_name()+" pings "+capitalize(str)+".\n",who);
    if(idle < 120)
      call_out("ack_back",0,({this_player(),who}));
  } else {
    who = find_player(str);
    if(!who || !living(who) || who == this_player() || in_editor(who) ||
       who->query_invis() > this_player()->query_level())
      return 0;
     if(who->query_level() >= 20 && this_player()->query_level() < 20) {
       write("You cannot ping a wizard.\n");
       return 1;
     }
    if(who->query_interactive())
      idle = query_idle(who);
    else
      idle = 666;
    write("You ping "+capitalize(str)+" from afar.\n");
    tell_object(who, this_player()->query_name()+" pings you from afar.\n");
    if(idle < 120)
      call_out("ack_back",0,({this_player(),who}));
  }
  return 1;
}
void ack_back(object *peeps) {
  object tp,who;
  string tpmsg,whomsg;
  tp = peeps[0];
  who = peeps[1];
  if(present(who,environment(tp))) {
    tpmsg = who->query_name()+" acks at you.\n";
    whomsg = "You ack at "+tp->query_name()+".\n";
  } else {
    tpmsg = who->query_name()+" acks at you from afar.\n";
    whomsg = "You ack at "+tp->query_name()+" from afar.\n";
  }
  tell_object(tp, tpmsg);
  tell_object(who, whomsg);
}
