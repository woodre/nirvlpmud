#include "def.h"


object *members;
int num_members;

#include "cmds/emote_list.h"
#include "cmds/emotes.h"
#include "cmds/fog_who.h"
#include "cmds/fog_help.h"
#include "cmds/speak.h"
#include "cmds/fraternize.h"
#include "cmds/say.h"

void rebuild_channel();
void reset(int arg) {
  move_object(this_object(),"/players/feldegast/closed/tower/study.c");
  if(arg) return;
  members=({ });
  rebuild_channel();
}
void init() {
  this_object()->rebuild_channel();
}
string *query_cmds() {
  string *cmds;
  cmds=({
    "fog","foge",
    "fog_who",
    "fog_help",
    "speak","fraternize","say",
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
  max=sizeof(members)-1;
  for(i=0;i<=max;i++) {
    tell_object(members[i],
HIB+"|"+NORM+MAG+"~"+NORM+"FOG"+MAG+"~"+HIB+"|"+NORM+" "+str+"\n"
    );
  }
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
  write("Fog what?\n");
  return 1;
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
