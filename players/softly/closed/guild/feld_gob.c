#include "def.h"

int rank;
int silence;
int karma;

/*
query_auto_load() {
  return PATH+"gob.c:";
}
*/

extra_look() {
  return OWNER->query_name()+" wears a crystal star pendant";
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
  if(!environment()) return 1;
  if(!restore_object(SAVEPATH+OWNER->query_real_name())) {
    tell_object(OWNER,"Creating new stats...\n");
    rank=1;
    karma=10;
    silence=0;
    save_object(SAVEPATH+OWNER->query_real_name());
    tell_object(OWNER,"Save file created.\n");
  }
  move_object(this_object(),environment());
}

int guild_save() {
  string n;
  n=(string) OWNER->query_real_name();
  save_object(SAVEPATH+n);
  write("Saving guild info...\n");
  return 1;
}

drop(){ return 1; }
get(){ return 0; }

init(){
  string *cmd_list;
  int i;
  int max;
  if(!environment(this_object())) destruct(this_object());
  cmd_list=MASTER->query_cmds();
  add_action("guild_save","guild_save");
  max=sizeof(cmd_list)-1;
  for(i=0;i<=max;i++) {
    add_action("do_command",cmd_list[i]);
  }
  MASTER->rebuild_channel();
  if(!TP->query_guild_name()) TP->set_guild_name("healer");
  if(!TP->query_guild_file()) TP->set_guild_file(PATH+"gob.c");
}

remove_object() {
  silence=1;
  MASTER->rebuild_channel();
}
int query_rank() { return rank; }
int query_karma() { return karma; }
int query_muffle(){ return silence; }

void set_muffle(int arg) { silence=arg; }
int adj_karma(int arg) { return karma+=arg; }
void set_rank(int arg){ rank = arg; guild_save(); }

int query_skill() {
  int skill;
  if(karma>1500) skill=10;
  else if(karma>1200) skill=9;
  else if(karma>1000) skill=8;
  else if(karma>800) skill=7;
  else if(karma>600) skill=6;
  else if(karma>400) skill=5;
  else if(karma>200) skill=4;
  else if(karma>100) skill=3;
  else if(karma>50) skill=2;
  else if(karma>10) skill=1;
  else if(karma>0) skill=0;
  else if(karma>-10) skill=-1;
  else if(karma>-50) skill=-2;
  else if(karma>-100) skill=-3;
  else if(karma>-200) skill=-4;
  else if(karma>-400) skill=-5;
  else if(karma>-600) skill=-6;
  else if(karma>-800) skill=-7;
  else if(karma>-1000) skill=-8;
  else if(karma>-1200) skill=-9;
  else skill=-10;
  return skill;
}
do_command(str) {
  return call_other(MASTER,"do_"+query_verb(),str);
}
