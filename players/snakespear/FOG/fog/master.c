#include "def.h"
#include "/players/feldegast/std/add_array.h"
#include "/players/feldegast/std/colorize.h"

object *members;
int num_members;
string *history;

#include "cmds/emote_list.h"
#include "cmds/emotes.h"
#include "cmds/fog_who.h"
#include "cmds/fog_history.h"
#include "cmds/fog_help.h"
#include "cmds/femotes.h"
#include "cmds/speak.h"
#include "cmds/fraternize.h"
#include "cmds/say.h"
#include "cmds/bros.h"
#include "cmds/ftox.h"
#include "cmds/frep.h"
#include "cmds/freport.h"
#include "cmds/fogupdate.h"
void rebuild_channel();
void reset(int arg) {
  move_object(this_object(),"/players/feldegast/closed/tower/study.c");
  if(arg) return;
  members=({ });
  history=({ });
  rebuild_channel();
}
void init() {
  this_object()->rebuild_channel();
}
string *query_cmds() {
  string *cmds;
  cmds=({
    "fog","foge",
    "fog_who","bros",
    "fog_history",
    "fog_help",
    "femotes",
    "fogupdate",
    "speak","fraternize","say",
    "frep",
    "freport",
    "ftox",
  });
  return cmds;
}

int query_num_members() {
  return sizeof(members);
}
object *query_members() {
  return members;
}

void rebuild_channel() {
  object *world;
  object x;
  int i;
  members=({ });
  world=users();
  for(i=0;i<sizeof(world);i++)
    if(x=present(GUILD_ID,world[i])) {
        if(!(x->query_muffle()))
        members+= ({ world[i] });
  }
}

void broadcast(string str) {
  int i, max;
  str=colorize(str);
  max=sizeof(members)-1;
  for(i=0;i<=max;i++) {
    tell_object(members[i],
HIR+"|"+NORM+HIW+"~"+NORM+BOLD+BLK+"FOG"+NORM+HIW+"~"+HIR+"|"+NORM+" "+str+"\n"
    );
  }
    if(sizeof(history)<20)
      history=add_array(str,history[0..sizeof(history)]);
    else
      history=add_array(str,history[1..sizeof(history)]);
}
string short() {
  return "The Heart of Gentleness";
}
int id(string str) {
  return str=="heart";
}
void long() {
  write("This is The Heart of the Gentleman, the symbol of the FOG.\n");
}
int do_fog(string str) {
  if(!str) {
    return do_bros();
  }
  broadcast(TPN+" says: "+str);
  return 1;
}
int do_foge(string str) {
  if(!str) {
  write("Foge what?\n");
  return 1;
  }
  broadcast(TPN+" "+str);
  return 1;
}
