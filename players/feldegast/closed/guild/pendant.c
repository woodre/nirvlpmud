#define GUILD_ID "feldegast-guild-object"
#define GUILD_NAME "enchanter"
#define GUILD_OBJ "/players/feldegast/guild/pendant.c"
#define SAVE_PATH "players/feldegast/guild/save/"
#define COMMANDS "/players/feldegast/guild/commands.c"
#define OWNER environment(this_object())

#define GUILD_WIZARD 11
#define GUILD_COMMANDER 10

#include "/players/feldegast/closed/ansi.h"
#include "/players/feldegast/closed/shortcut.h"

int rank;
int muffle;

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
    muffle=0;
    save_object(SAVE_PATH+OWNER->query_real_name());
    tell_object(OWNER,"Save file created.\n");
  }
}

drop(){ return 1; }
get(){ return 0; }

init(){
  add_action("guild_talk","gt");
  add_action("guild_emote","ge");
  add_action("update","polish");
  add_action("guild_who","gwho");
  add_action("muffle","ignore");
  add_action("score","sc");
  add_action("guild_save","gsave");
  add_action("guild_restore","grestore");
  if(this_player()->query_real_name() == "feldegast" || rank >= GUILD_WIZARD){
    add_action("gpromote","set_rank");
  }
}

int query_rank(){ return rank;}
int query_muffle(){ return muffle; }

set_rank(int arg){ rank = arg; guild_save(); }

static update(string str){
  if(str != "pendant"){
    notify_fail("What would you like to polish?\n");
    return 0;
  }
  move_object(clone_object(GUILD_OBJ),this_player());
  write("You polish your crystal star pendant until it is like new.\n");
  destruct(this_object());
  return 1;
}

guild_talk(string str) {
  return COMMANDS->guild_talk(str);
}
guild_emote(str) {
  return COMMANDS->guild_emote(str);
}
muffle() {
  if(muffle == 1){
    write("You stop ignoring your guild mates.\n");
    muffle=0;
    return 1;
  }
  else {
    write("You choose to ignore your guild mates.\n");
    muffle=1;
    return 1;
  }
}

static guild_who(){
  return COMMANDS->guild_who();
}

score() {
  return COMMANDS->score();
}
static guild_save(){
  save_object(SAVE_PATH+this_player()->query_real_name());
  write("Saving guild info...\n");
  return 1;
}

static guild_restore(){
  restore_object(SAVE_PATH+this_player()->query_real_name());
  write("Restoring guild info...\n");
  return 1;
}

static gpromote(string str){
  object member;
  string who;
  int x;
  if (!str){
    notify_fail("Usage set_rank <who> <rank>\n");
    return 0;
  }
  sscanf(str,"%s %d",who,x);
  if(!x){
    notify_fail("Usage: setrank <who> <rank>\n");
    return 0;
  }
  member = find_player(who);
  if (!member){
    notify_fail("That player is not on right now.\n");
    return 0;
  }
  if(!present(GUILD_ID,member)){
    notify_fail(member->query_name()+" is not a member of this guild.\n");
    return 0;
  }
  tell_object(member,"Your rank has been set to "+x+".\n");
  write("You have set "+member->query_name()+"'s rank to "+x+".\n");
  present(GUILD_ID,member)->set_rank(x);
  return 1;
}

