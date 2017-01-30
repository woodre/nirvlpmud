#include "/players/fred/closed/bloodfist/defs.h"
int keep;
string gname;

reset(arg){
  if(arg) return;

  keep = 0;  /* don't keep */
}

short(){ return RED+"A drop of blood"+NORM; }
id(str){ return str == "drop" || str == "blood" ||
                str == "drop of blood" || str == "bloodfist_gob_chan"; }
get(){ return 0; }
can_put_and_get(){ return 0; }
drop(){ return 1; }
long(){
  if(keep)
  write("A deep red drop of blood.  This blood is in fact not real\n"+
    "but made of wax.  It signifies your temporary access to the\n"+
    "Bloodfist channel.  Type 'bf' for more information.\n");
  else
    write("A drop of wax blood that is your invitation to join the\n"+
    "Bloodfist channel.  Type 'accept invitation' to join.\n");
}

void init(){
  if(!environment() || !environment()->is_player()) destruct(this_object());
  else {
    add_action("talk", "bf");
    add_action("okay", "accept");
    add_action("quit", "quit");
  }
}

qk(){ return keep; }

talk(str){
  object *all, it;
  int a,sa;
  string msg,b,c;
  if(!keep) return 0;
  if(!str)
  {
    write("Bloodfist Channel commands:\n\n"+
      pad("  bf",24)+"Talk on the channel\n"+
      pad("  bf :",24)+"Emote on the channel\n"+
      pad("  bf list",24)+"See who is on the channel\n"+
      pad("  bf history",24)+"See recent messages\n"+
      pad("  bf mon",24)+"Display your monitor\n"+
      pad("  bf leave",24)+"Leave the channel\n\n");
  }
  else if(str == "leave")
  {
    CHAN_DAEMON->print(this_player(), "the "+gname+" leaves the channel.", 2);
    destruct(this_object());
  }
  else if(str == "history")
    CHAN_DAEMON->print_history(this_player(), 1);
  else if(str == "mon")
    CHAN_DAEMON->print(this_player(),str, 2);
  else if(sscanf(str, ":%s", b))
  {
    string em, arg, file;
    
    if(sscanf(b, "%s %s", em, arg) != 2) {
      em = b;
    }
    if(file_size(file="/bin/soul/_"+em+".c") > 0) {
      return (int)file->guildcast("bloodfist", arg);
    }
    CHAN_DAEMON->print(this_player(), b,2);
  }
  else
    CHAN_DAEMON->print(this_player(), str, 1);
  return 1;
}

dest(){ destruct(this_object()); }

decline(){
  if(!environment() || keep) return;
  if(!environment()->is_player()) return;
  tell_object(environment(), 
    "You decline the invitation to the Bloodfist channel.\n"+
    "The drop of blood melts into your hand and is gone.\n");
  destruct(this_object());
}

join(){
  if(!environment() || keep) return;
  if(!environment()->is_player()) return;
  call_out("decline", 40);
  tell_object(environment(),
    "You have been invited to join the Bloodfist channel.\n"+
    "Type 'accept invitation' to join the channel or\n"+
    "ignore this invitation and it will melt away.\n");
}

okay(str){
  if(str != "invitation" || keep) return 0;
  if(!present(this_object(), this_player())) return 0;
  if(this_player()->query_level() > 19)
    gname = "Wizard";
  else if((gname = (string)this_player()->query_guild_name()))
    gname = capitalize(gname);
  else gname = "Guildless";
  if(gname == "Rangers")
    gname = "Ranger";
  else if(gname == "Knights templar")
    gname = "Knight";
  keep = 1;
  tell_object(environment(),
    "You accept the invitation.  Type 'bf' for a list of commands.\n");
  CHAN_DAEMON->print(this_player(), "the "+gname+" joins the channel.", 2);
  return 1;
}

quit(){
  CHAN_DAEMON->print(this_player(), "the "+gname+" leaves the channel.", 2);
  destruct(this_object());
}

