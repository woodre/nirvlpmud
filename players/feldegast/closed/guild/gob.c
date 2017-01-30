#include "/players/feldegast/closed/guild/defines.h"

int rank;
int silence;

query_auto_load() {
  return "players/feldegast/closed/guild/gob.c:";
}

extra_look() {
  return TPN+" wears a crystal star pendant";
}

long() {
  write(
"This is a beautiful crystal star pendant attached to a string.\n"+
"For information on the abilities it represents, type 'info'.\n"
  );
}

id(str) {  return str=="pendant" || str==GUILD_ID;}

reset(arg) {
  if(!arg) call_out("delayed_reset", 1);
}

delayed_reset(){
  if(!restore_object(SAVE_PATH+OWNER->query_real_name())) {
    tell_object(OWNER,"Creating new stats...\n");
    rank=1;
    silence=0;
    save_object(SAVE_PATH+OWNER->query_real_name());
    tell_object(OWNER,"Save file created.\n");
  }
}

drop(){ return 1; }
get(){ return 0; }

init(){
  string *cmd_list;
  int i;
  int max;
  if(!environment(this_object())) destruct(this_object());
  cmd_list=COMMANDS->query_cmds();
  max=sizeof(cmd_list)-1;
  for(i=0;i<=max;i++) {
    add_action("do_command",cmd_list[i]);
  }
  CHANNEL->add_member(this_player());
  if(!TP->query_guild_name()) TP->set_guild_name("guardian");
}

int query_rank() { return rank; }
int query_silence(){ return silence; }

set_silence(int arg) { silence=arg; }
set_rank(int arg){ rank = arg; guild_save(); }

do_command(str) {
  string path;
  path=CMDPATH+query_verb();
  return path->do_command(str);
}