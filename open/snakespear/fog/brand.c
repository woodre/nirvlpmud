#include "def.h"
#include "cmds/emote_list.h"

static int silence;

query_auto_load() {
  return PATH+"brand.c:";
}

extra_look() {
  return OWNER->query_name()+" has a |FOG| brand on "+OWNER->query_possessive()+" left ankle";
}

long() {
  write(
"This is a brand of the letters |FOG| on your left ankle.  Type 'fog_help'\n"+
"for more information.\n");
}

id(str) { return str=="brand" || str==GUILD_ID; }

reset(arg) {
  if(!arg) call_out("delayed_reset", 1);
}

delayed_reset(){
  if(!environment()) return 1;
  move_object(this_object(),environment());
}


drop(){ return 1; }
get(){ return 0; }

query_muffle() { return silence; }

init(){
  string *cmd_list;
  int i;
  int max;
  if(!environment(this_object())) destruct(this_object());
  cmd_list=MASTER->query_cmds();
  max=sizeof(cmd_list)-1;
  for(i=0;i<=max;i++) {
    add_action("do_command",cmd_list[i]);
  }
  cmd_list=EMOTES;
  max=sizeof(EMOTES)-1;
  for(i=0;i<=max;i++) {
    add_action("do_emote",cmd_list[i]);
  }
  MASTER->rebuild_channel();
}

remove_object() {
  silence=1;
  tell_object(OWNER,"Leaving f.o.g. channel...\n");
  MASTER->rebuild_channel();
}
do_command(str) {
  return call_other(MASTER,"do_"+query_verb(),str);
}
do_emote(str) {
  return call_other(MASTER,"emote_check",str);
}
