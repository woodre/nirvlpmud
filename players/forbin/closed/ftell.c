/* device that allows players to speak to me while invis */
/* modified from vertebraker with his permission */

#include "/players/forbin/define.h"

status id(string str) { return str == "ftell"; }

string short() {
  object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) 
  return HIW+"A fTell ["+HIC+"invis"+HIW+"]"+NORM;
}

long() {
  object a, e;

  if((a = this_player()) && (e = environment()) && (e == a)) {
    write("  A small, round device implanted at the base of your spine and head affords\n"+
          "you a private communication line to Forbin.  To talk with him you may use\n");
    write(""+HIW+"'"+HIC+"tell forbin <"+NORM+"message"+HIC+">"+HIW+"'"+NORM+", "+HIW+"'"+HIC+"forb <"+NORM+"message"+HIC+">"+HIW+"'"+NORM+", or "+HIW+"'"+HIC+"ftell <"+NORM+"message"+HIC+">"+HIW+"'"+NORM+".  Your message\n"+
          "will go through whether he is on or not.  Forbin will respond if he is able.\n");
    return 1;
  }
}

void init() {
  add_action("cmd_ftell", "forb");
  add_action("cmd_ftell", "ftell");
  add_action("cmd_tell", "tell");
}

status cmd_tell(string arg) {
  string who, what, a;
  object c;
  if(!stringp(arg) || sscanf(arg, "%s %s", who, what) < 2) {
    write("Tell what?\n");
      return 1;
  }
  if(who != "forbin" && who != "f" && who != "forb") return 0;
  if(!(c = find_player("forbin")) || present("please_leave_me_the_FuCK_AlONe", c)) {
    write(""+HIW+"Establishing fLink..."+NORM+"\n");
    write("He is invis.\n");
    write("["+HIC+"ftell"+NORM+"] "+what+"\n");
    write_file("/players/forbin/closed/log/ftell", TP->query_real_name()+"  :  "+what+"  ["+ctime(time())+"]\n");  
      return 1;
  }
  write(""+HIW+"Establishing fLink..."+NORM+"\n");
  if(!environment(c) || !interactive(c)) {
    write("He is disconnected.\n");
      return 1;
  }
  if(in_editor(c)) {
    write("He is busy coding.  Please try again later.\n");
      return 1;
  }
  if((int)c->query_invis()) write("He is invis.\n");
  if(query_idle(c) > 120) write("He is idle.  He may not respond right away.\n");
  if(environment(c) && (file_name(environment(c)) != "players/forbin/workroom"))
    write("He may be busy.  He may not respond right away.\n");

  write("["+HIC+"ftell"+NORM+"] "+what+"\n");

  tell_object(c, HIC+""+HIW+"["+NORM+""+HIC+"ftell"+NORM+""+HIW+"]"+NORM+""+HIC+" "+ 
  (a = (string)this_player()->query_name())+" tells you: "+NORM+what+"\n");
  c->add_tellhistory(HIC+a+" told you: "+NORM+what);
    return 1;
}

status get() { return 1; }
status drop() { return 1; }

status cmd_ftell(string arg) {
  command("tell forbin "+arg, this_player());
    return 1;
}

query_auto_load() { return "/players/forbin/closed/ftell.c:"; }

