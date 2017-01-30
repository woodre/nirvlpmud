inherit "/obj/user/one_chan";
#define CHANNELS ({ "risque","gossip","shout","wiz","announce","junk","msg","babble" })

reset(arg) { if(arg || root()) return ; enable_commands(); }
drop() { return 1; }
get() { return 1; }
id(str) { return str == "scooby" || str == "scooby doo"; }
short() { return 0; }
long() {
  write("Hey, Scooby Doo has a soul too.\n");
}
init() {
  int i;
  if(!living(environment())) destruct(this_object());
  write("Your arms and legs grow shorter.\n");
  write("Your back grows longer, and you feel the need to stand on all fours.\n");
  write("Your nose and mouth grow outwards from your face, and your ears grow flappy.\n");
  write("Yur skin turns a shade of brown...\n");
  write("You have become the legendary SCOOBY DOO!\n");
  this_player()->remote_say(this_player()->query_name()+" shakes briefly as his body contorts into that of Scooby Doo.\n");
  add_action("tell_str","tell");
  add_action("scoob_emote","em");
  add_action("scoob_say","ss");
  for(i = 0; i < 8; i++) {
    add_action("use_chan",CHANNELS[i]);
  }
}
query_np() { /* for tell */ return 1; }
catch_tell(str) {
  string w;
  string foo;
  if(sscanf(str, "%s %s", w, foo) < 2) tell_scoob(str);
  else if(!find_player(lower_case(w)) || find_player(lower_case(w)) != environment()) tell_scoob(str);
  else return ;
}
tell_scoob(str) {
  tell_object(environment(), "[S] "+str);
}
scoob_emote(str, flag) {
  if(!str) return 0;
  say("Scooby "+str+"\n",this_player());
  if(!flag)
  write("You emote: Scooby "+str+"\n");
  return 1;
}
scoob_say(str) {
  if(!str) return 0;
  scoob_emote("says: "+str, 1);
  return 1;
}
use_chan(str) {
  string chan;
  chan = query_verb();
  if(!str) return 0;
  if(str == "list") return 0;
  if(str[0] == ':') {
    sscanf(str,":%s",str);
    chan_msg("("+chan+") Scooby "+str+"\n",chan);
  } else {
    chan_msg("Scooby "+chan+"s: "+str+"\n",chan);
  }
  return 1;
}
tell_str(str) {
  string who,what;
  object w;
  if(!str || sscanf(str, "%s %s", who, what) < 2) return 0;
  if(!(w = find_player(who))) { write("Player not found.\n"); return 1; }
  if(w->query_invis()) write(capitalize(who)+" is invis.\n");
  if(in_editor(w)) write(capitalize(who)+" is editing.\n");
  if(!w->query_interactive()) write(capitalize(who)+" is disconnected.\n");
  write("You scooby tell "+capitalize(who)+": "+what+"\n");
  if(who != "boltar")
  tell_object(w,"Scooby tells you: "+what+"\n");
  else tell_object(w,"Wizardchild tells you: "+what+"\n");
  return 1;
}
