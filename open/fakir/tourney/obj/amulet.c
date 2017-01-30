#include "defs.h"

inherit "/obj/treasure.c";

extra_look() { return " wears a Tournament amulet"; }

drop() { return 1; }

void reset(int arg) {
  if(arg) return;

  set_id("amulet");
  set_alias("tournament amulet");
  set_long(
    "This amulet is your entry ticket into the Grand Tournament of\n"+
    "Nirvana.  You must wear it at all times during the tournament\n"+
    "to receive announcements and to enter arenas.  The following\n"+
    "commands are available:\n"+
    "\tarena <msg>\n"+
    "\tarena :<emote>\n"+
    ""
  );
  CHANNEL->add_channel("arena",HIR+"["+NORM+"ARENA"+HIR+"]"+NORM,0);
}

void init() {
  CHANNEL->register(this_player(), "arena");
  add_action("cmd_arena","arena");
}

cmd_arena(str) {
  object *us;
  string *chats;
  int i;
  if(!str) {
    us=(object *)CHANNEL->users("arena");
    write("\t\t\tTournament Channel:\n");
    write("=====================================================\n");
    for(i=0; i<sizeof(us); i++) {
      write(pad(us[i]->query_name(),20));
      write(environment(us[i])->short()+"\n");
    }
    return 1;
  }
  if(str=="history") {
    write("Tournament History\n");
    write("==================\n");
    chats=(string *)CHANNEL->query_history("arena");
    for(i=0;i<sizeof(chats);i++)
      write(chats[i]);
    write("\n");
    return 1;
  }

  if(str[0]==':')
    CHANNEL->broadcast("arena", TPN+" "+str[1..strlen(str)]+"\n");
  else
    CHANNEL->broadcast("arena", TPN+" says: "+str+"\n");
  return 1;
}

remove_object(ob) {
  CHANNEL->deregister(environment(),"arena");
}
