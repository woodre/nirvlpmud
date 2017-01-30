#define FEEL "/players/snow/ITEMS/feeler.c"

string ff;
 
id(str) { return str == "feeler" || str == "discreet emoter"; }
short() { return "A Discreet Emoter (Feeler)"; }
long() { FEEL->long(); return 1; }
get() { return 1; }
drop() { return 1; }
can_put_and_get() { return 0; }
set_feelfollow(string str) { ff = str; }
query_feelfollow() { return ff; }
 
init() {
  if(this_player() == environment(this_object())) {
  if(this_player()->query_real_name() == "guest") { 
    destruct(this_object()); 
  return 1;}
  if(query_ip_number(this_player()) == "134.129.239.13" && this_player()->query_real_name() != "budah") {
    destruct(this_object()); return 1; }
  add_action("emote_to","emto");
  add_action("far_emote","farem");
  add_action("feelfollow","feelfollow");
  add_action("dest_feel","no_feeler");
  add_action("give_feeler","feelto");
  add_action("feeler_users","feelwho");
  add_action("feeler_help","feelerhelp");
  add_action("feeler_glow","fglow");
  if(this_player()->query_real_name() == "snow")
    add_action("feeler_say","feelsay");
  }
   }
 
emote_to(str) { FEEL->emote_to(str); return 1; }
far_emote(str) { FEEL->far_emote(str); return 1; }
feelfollow(str) { FEEL->feelfollow(str); return 1; }
dest_feel() { FEEL->dest_feel(); return 1; }
give_feeler(str) { FEEL->give_feeler(str); return 1; }
feeler_users() { FEEL->feeler_users(); return 1; }
feeler_say(str) { FEEL->feeler_say(str); return 1; }
feeler_help() { FEEL->feeler_help(); return 1; }

start_feelfollow() {
  object myenv, ob, obenv;
  string maker;
  myenv = environment(this_object());
  if(!myenv) return 1;
  if(!ff) return 1;
  ob = find_player(ff);
  if(!ob) {
    tell_object(myenv, "Feelfollow discontinued\n"); return 1; }
  obenv = environment(ob);
  maker = creator(obenv);
  if(maker != "snow" && maker != "zeus") {
    tell_object(myenv, "Feelfollow discontinued\n"); return 1; }
  if(environment(myenv) != environment(ob)) {
    if(environment(ob)->feel() != "no") {
  tell_room(environment(ob),
    myenv->query_name()+" follows "+ob->query_name()+" into the room.\n");
  tell_object(myenv, "You follow "+ob->query_name()+"\n");
  move_object(myenv, environment(ob));
  command("look", myenv); } }
  call_out("start_feelfollow", 5);
  return 1; }

feeler_glow() {
  if(this_player()->query_sp() < 100) return 1;
  this_player()->add_spell_point(-100);
  write("Your feeler begins to glow.\n");
  set_light(1);
  return 1; }
