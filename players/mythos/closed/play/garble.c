#define tp this_player()
int start_time,num;

query_auto_load() {
    return "/players/mythos/closed/play/garble.c:";
}

id(str) {
    return str == "hentai";
}
drop() {return 1;}

reset(arg) { 
  if(arg) return;
  num = 0;
}

init() {
  call_out("change",10);
    add_action("gtell","tell");
  add_action("ggos","gossip");
  add_action("ggos","farsong");
  add_action("ggos","farsonge");
  add_action("gshout","shout");
  add_action("gshout","emergency");
  add_action("gwh","whisper");
  add_action("gs","farem");
  add_action("gs","emto");
  add_action("ggos","echoall");
  add_action("gtell","echoto");
  add_action("gs","say");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("gs"); add_xverb("'");
  add_action("gtell");add_xverb(".te");
  add_action("gtell");add_xverb(".tf");
  add_action("gtell");add_xverb(".tt");
#else
  add_action("gs", "'", 3);
  add_action("gtell", ".te", 3);
  add_action("gtell", ".tf", 3);
  add_action("gtell", ".tt", 3);
#endif
  add_action("gs",";");
  add_action("gs","slap");
  add_action("gs","kick");
  add_action("gs","punch");
  add_action("gs","sex");
  add_action("gs","emote");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("gs"); add_xverb(":");
#else
  add_action("gs", ":", 3);
#endif
  add_action("gs","kiss");
  add_action("gs","dkiss");
  add_action("gs","french");
  add_action("gs","fondle");
  add_action("gs","lick");
  add_action("gs","grope");
  add_action("gs","hug");
}

gtell(str) {
  string who,msg;
  sscanf(str, "%s %s",who,msg);
  msg=crypt(msg,9);
  msg = format(msg, 60);
  if(!find_player(who)) { write("That person is not on.\n"); return 1; }
   if(find_player(who)->query_invis()) { write("That person is not on.\n"); return 1; }
  if(in_editor(find_player(who))) {
  write(capitalize(who)+" is editing. Please try again later.\n");
  return 1; }
  else {
  tell_object(find_player(who),capitalize(this_player()->query_name())+" tells you: "+msg+"\n");
  write("You tell "+who+": "+msg+"\n");
  num = num + 1;
  if(num > 20) {
    tp->quit();
  return 1;}
  return 1; }
  return 1;
}

ggos(str) {
  string who,msg;
  sscanf(str,"%s",msg);
  msg=crypt(msg,8);
  msg=format(msg, 60);
  emit_channel("gossip",capitalize(this_player()->query_name())+" gossips:"+msg+"\n");
  num = num + 1;
  if(num > 7) {
    tp->quit();
  return 1;}
  return 1;
}

gshout(str) {
  write("\nhahahaha\n\n");
  return 1; }

gwh(str) {
  string who, msg;
  sscanf(str,"%s %s",who,msg);
  msg=crypt(msg, 6);
  msg=format(msg,60);
  if(!find_player(who) || !present(who, environment(this_player()))) {
  write("No player with that name in this room.\n");
  return 1; }
  tell_object(find_player(who),capitalize(this_player()->query_name())+" whispers to you: "+msg+"\n");
  write("You whisper "+msg+" to "+who+"\n");
  num = num + 1;
  if(num > 20) {
    tp->quit();
  return 1;}
  return 1; }

gs(str) {
  string msg;
  if(!str) { write("What?\n"); return 1;}
  sscanf(str,"%s",msg);
  msg=crypt(msg,5);
  msg=format(msg,60);
  say(capitalize(this_player()->query_name())+" says: "+msg+"\n");
  write("You say "+msg+"\n");
  num = num + 1;
  if(num > 20) {
    tp->quit();
  return 1;}
  return 1; }

change() {
  if(environment(this_object()))
  move_object(this_object(),environment(this_object()));
  call_out("change",10);
  return 1;}

exit() {
  if(this_player() == environment(this_object())) return 1;
  if(this_player() && this_player()->query_level() > 100) return 0;
    else return 1;
}
